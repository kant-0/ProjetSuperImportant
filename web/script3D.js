let echelle = 1000000000;
let dataJSON;
let method = "method_euler";
let bg;
let speed = 1;
let a = 0;

const planets = {
    sun:     { img: null, size: 30, rgb: null},
    mercury: { img: null, size: 10, rgb: 'rgb(57, 57, 57)'},
    venus:   { img: null, size: 20, rgb: 'rgb(230, 152, 89)'},
    earth:   { img: null, size: 25, rgb: 'rgb(47, 106, 105)'},
    mars:    { img: null, size: 20, rgb: 'rgb(153, 61, 0)'},
    jupiter: { img: null, size: 30, rgb: 'rgb(176, 127, 53)'},
    saturn:  { img: null, size: 30, rgb: 'rgb(176, 143, 54)'},
    uranus:  { img: null, size: 25, rgb: 'rgb(85, 128, 170)'},
    neptune: { img: null, size: 25, rgb: 'rgb(54, 104, 150)'},
    pluto:   { img: null, size: 15, rgb: 'rgb(57, 57, 57)'}
};

/*function drawTrajectory(name, method) {
    for(let i=0; i < dataJSON[method][name].length ;i++){
        if (name !== "sun")
            point(dataJSON[method][name][i][0][0] / echelle, dataJSON[method][name][i][0][1] / echelle);
    }
}*/

function drawTail(name) {
    const arr = dataJSON[method][name];
    const tail = 200; // longueur de la traînée

    beginShape();
    noFill();
    stroke(planets[name].rgb);

    for (let i = max(0, a-tail); i < a; i++) {
        const p = arr[i][0];
        vertex(p[0]/echelle, p[1]/echelle, p[2]/echelle);
    }

    endShape();
}


function preload() {

  dataJSON = loadJSON("data.json");

    for (const name in planets) {
        planets[name].img = loadImage(`images/${name}.png`);
    }

    bg = loadImage('images/panorama.png');
}

function reset() {
    a = 0;
    loop();
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
        translate(dataJSON[method][name][a][0][0] / echelle, dataJSON[method][name][a][0][1] / echelle, dataJSON[method][name][a][0][2] / echelle);
    }else {
        emissiveMaterial(70, 50, 50);
    }
    rotateY(frameCount * 0.01);
    noStroke();
    textureMode(NORMAL);
    texture(planet.img);
    sphere(planet.size);
    pop();
}

function drawPlanet2D(name) {
    imageMode(CENTER);
    const planet = planets[name];
    const pos = dataJSON[method][name][a][0];

    image(
        planet.img,
        oX + pos[0] / echelle,
        oY + pos[1] / echelle,
        planet.size,
        planet.size
    );
}

function draw() {
    background(0);

    orbitControl();

    ambientLight(80);
    pointLight(255, 255, 255, 0, 0, 0);
    drawPlanet3D("sun");

    for (const name of Object.keys(planets)) {
        if (name !== "sun") {
            drawPlanet3D(name);
            drawTail(name);
        }
    }
    
    if (a <= dataJSON[method]["earth"].length - 2 - speed) {
        a += speed;
    } else {
        reset();
    }
}

const select = document.querySelector("select");
if (select) {
    select.onchange = function(e) {
        method = e.target.value;
        console.log(method);
        reset()
    }
}

const btn = document.querySelector('.playpause');

btn.onclick = () => {
    btn.classList.toggle('playing');
    btn.classList.contains('playing') ? loop() : noLoop();
}

document.body.onkeyup = function(e) {
    if (e.key == " " || e.code == "Space" || e.keyCode == 32) {
        btn.classList.toggle('playing');
        btn.classList.contains('playing') ? loop() : noLoop();
    }
}

const resetBtn = document.querySelector('.reset');

resetBtn.onclick = () => {
    reset();
}

const slider = document.getElementById('slider');
slider.oninput = () => {
    speed = floor(slider.value/10) + 1;
    console.log(slider.value);
}