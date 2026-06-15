let echelle = 1000000000;
let reader = new FileReader();
let dataJSON;
let method;
let bg;
let a = 0;

const planets = {
    sun:     { img: null, size: 80 },
    mercury: { img: null, size: 10 },
    venus:   { img: null, size: 20 },
    earth:   { img: null, size: 25 },
    mars:    { img: null, size: 20 },
    jupiter: { img: null, size: 30 },
    saturn:  { img: null, size: 30 },
    uranus:  { img: null, size: 25 },
    neptune: { img: null, size: 25 },
    pluto:   { img: null, size: 15 }
};

function drawTrajectory(name) {
    for(let i=0; i < dataJSON[name].length ;i++){
        if (name !== "sun")
            point(dataJSON[name][i][0][0] / echelle, dataJSON[name][i][0][1] / echelle);
    }
}

function preload() {
    let file = loadJSON("data.json");
    dataJSON = file.method_euler;

    for (const name in planets) {
        planets[name].img = loadImage(`images/${name}.png`);
    }

    bg = loadImage('images/panorama.png');

    button = createButton("reset");
    button.mousePressed(reset);
}

function reset() {
    a = 0;
    loop();
    noLoop();
}

function mousePressed() {
    if (mouseButton === LEFT) {
        loop();
    }
}

function mouseReleased() {
    noLoop();
}

function windowResized() {
    resizeCanvas(windowWidth, windowHeight);
}

function setup() {
    createCanvas(windowWidth, windowHeight, WEBGL).addClass("monitor");

    imageMode(CENTER);

    noLoop()  
    a = 0;
}

function drawPlanet3D(name) {
    const planet = planets[name];

    push();
    if (name !== "sun") {
        translate(dataJSON[name][a][0][0] / echelle, dataJSON[name][a][0][1] / echelle, dataJSON[name][a][0][2] / echelle);
    }
    rotateY(frameCount * 0.01); // rotation pour l'effet sphère
    texture(planet.img);
    sphere(planet.size);
    pop();
}

function drawPlanet2D(name) {
    imageMode(CENTER);
    const planet = planets[name];
    const pos = dataJSON[name][a][0];

    image(
        planet.img,
        oX + pos[0] / echelle,
        oY + pos[1] / echelle,
        planet.size,
        planet.size
    );
}

function draw() {
    panorama(bg);
    imageLight(bg);

    //orbitControl();

    pointLight(255, 255, 255, 0, 0, 0);
    drawPlanet3D("sun");

    for (const name of Object.keys(planets)) {
        if (name !== "sun") {
            drawPlanet3D(name);
            drawTrajectory(name);
        }
    }
    
    if (a < 36501)
        {a = a+1;}
    else 
        {a = 0;}
}