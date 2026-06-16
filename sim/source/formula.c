#include <stdlib.h>

#include "vector.h"
#include "formula.h"

#define CUBED(x) ((x)*(x)*(x))
#define SQ(x) ((x)*(x))

double acceleration(double radius) { // fonction permettant d'obtenir la valeur de l'accélération
    double G = 6.6743e-11;
    double m_Sun = 1.989e30;
    return -(G*m_Sun)/(radius*radius);
}

Vec3* radius(Vec3* pos1, Vec3* pos2) { // calcul du rayon entre deux astres
    Vec3 * r = malloc(sizeof(Vec3));
    r = addVec3(pos2, scaleVec3(pos1, -1.0)); // B - A
    return r;
}

Vec3* getAccelerationVec3(Vec3* pos) { // permet d'obtenir le vecteur accélération pour une position
    const double G = 6.6743e-11;
    const double m_S = 1.989e30;
    const double dist = normVec3(pos);
    const double accel_value = -(G*m_S)/(CUBED(dist));
    Vec3* accel = scaleVec3(pos, accel_value);

    return accel;
}

Vec3 * eulerMethodSpeed(Planet * trajectory, double deltaT) { // renvoie la vitesse suivante d'un point avec la méthode d'Euler
    return addVec3( // vxt+1 = vxt + axt x Δt
        trajectory->speed, 
        scaleVec3(
            getAccelerationVec3(trajectory->position), 
            deltaT
        )
    ); 
}

Vec3 * eulerMethodPosition(Planet * trajectory, double deltaT) { // renvoie la position suivante d'un point avec la méthode d'Euler
    return addVec3( // xt+1 = xt + vxt x Δt
        trajectory->position, 
        scaleVec3(
            trajectory->speed, 
            deltaT
        )
    ); 
}

Vec3 * eulerAsymetricSpeed(Planet * trajectory, double deltaT) { // renvoie la vitesse suivante d'un point avec la méthode d'Euler asymétrique
    Vec3 * posTn1 = eulerMethodPosition(trajectory, deltaT);

    return addVec3( // vxt+1 = vxt + axt+1 x Δt
        trajectory->speed, 
        scaleVec3(
            getAccelerationVec3(posTn1), 
            deltaT
        )
    ); 
}

Vec3 * eulerAsymetricPosition(Planet * trajectory, double deltaT) { // renvoie la position suivante d'un point avec la méthode d'Euler asymétrique
    return eulerMethodPosition(trajectory, deltaT); // ce qui est équivalent à la méthode d'Euler de base 
}

Vec3 * rungeKuttaSpeed(Planet * trajectory, double deltaT) { // renvoie la vitesse suivante d'un point avec la méthode d'Euler asymétrique
    Vec3 * k1r = scaleVec3(trajectory->speed, deltaT); // k1,r = Δt x vn

    Vec3 * kmidr = addVec3(trajectory->position, scaleVec3(k1r, 0.5)); // rn + k1,r/2 

    Vec3 * k2v = scaleVec3( // k2,v = Δt x a(kmidr)
        getAccelerationVec3(kmidr),
        deltaT
    );

    return addVec3(trajectory->speed, k2v);
}

Vec3 * rungeKuttaPosition(Planet * trajectory, double deltaT) { // renvoie la position suivante d'un point avec la méthode d'Euler asymétrique
    Vec3 * k1v = scaleVec3( // k1,v = Δt x an
        getAccelerationVec3(trajectory->position),
        deltaT
    );

    Vec3 * kmidv = addVec3(trajectory->speed, scaleVec3(k1v, 0.5)); // vn + k1,v/2

    Vec3 * k2r = scaleVec3( // k2,r = Δt x kmidv
        kmidv, 
        deltaT
    );

    return addVec3(trajectory->position, k2r);
}

double potentialEnergy(System * system, double solarMass) { // calcule l'énergie potentielle du système
    const double G = 6.6743e-11;
    double sum = 0;
    while (system) {
        sum += (G*(system->planet)->mass*solarMass)/normVec3((system->planet)->position);
        system = system->next;
    }
    return -sum/2;
}

double kineticEnergy(System * system) { // calcule l'énergie cinétique du système
    double sum = 0;
    while (system) {
        sum += (system->planet)->mass + SQ(normVec3((system->planet)->speed));
        system = system->next;
    }
    return sum/2;
}