#include <stdio.h>
#include <stdlib.h>

#include "vector.h"
#include "math.h"

double acceleration(double radius) {
    double G = 6.6743e-11;
    double m_Sun = 1.989e30;
    return -(G*m_Sun)/(radius*radius);
}