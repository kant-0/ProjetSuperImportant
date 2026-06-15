let echelle = 1000000000;
let reader = new FileReader();
let file;
let dataJSON;
let method;
let bg;

let oY = 400/2;
let oX = 720/2;

const planets = {
    sun:     { img: null, size: 80 },
    mercury: { img: null, size: 20 },
    venus:   { img: null, size: 20 },
    earth:   { img: null, size: 20 },
    mars:    { img: null, size: 20 },
    jupiter: { img: null, size: 20 },
    saturn:  { img: null, size: 20 },
    uranus:  { img: null, size: 20 },
    neptune: { img: null, size: 20 },
    pluto:   { img: null, size: 20 }
};

function readFile(input) {
    let file = input.files[0];

    let reader = new FileReader();

    reader.readAsText(file);

    reader.onload = function() {
        dataJSON = JSON.parse(reader.result);
        dataJSON = dataJSON[calculMethod];

        for(let i=0;i<3750;i++){
            point(oX + dataJSON[method][i][0][0]/echelle, oY + dataJSON[method][i][0][1]/echelle);
            i++;
        }
    }

    reader.onerror = function() {
        console.log(reader.error);
    };
}

function preload() {
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
    const [x, y, z] = dataJSON[name][a][0];

    push();
    translate(x / ECHELLE, y / ECHELLE, z / ECHELLE);

    rotateY(frameCount * 0.01); // rotation pour l'effet sphère
    texture(planet.img);
    sphere(planet.size);
    pop();
}

function draw() {
    panorama(img);
    imageLight(img);

    orbitControl();

    pointLight(255, 255, 255, 0, 0, 0);
    drawPlanet3D("sun");

    // Autres planètes
    for (const name of Object.keys(planets)) {
        if (name !== "sun") drawPlanet3D(name);
    }
    
    if (a < 36501)
        {a = a+1;}
    else 
        {a = 0;}
}