function start(elm) {
    new Response(elm.files[0]).json().then(json => {
        console.log(json)
        document.getElementById("sim-container").toggleAttribute("hidden") // code de con
    }, err => {
        // not json
    })
}

let echelle = 1000000000;
let reader = new FileReader();
let file;
let dataJSON;
let method;
let bg;
let img;
let img_sun;
let oY = 400/2;
let oX = 720/2;

function readFile(input) {
    let file = input.files[0];

    let reader = new FileReader();

    reader.readAsText(file);

    reader.onload = function() {
        dataJSON = JSON.parse(reader.result);
        method = Object.keys(dataJSON)[0];
        
        console.log(dataJSON[method]);
        for(let i=0;i<3750;i++){
            point(oX + dataJSON[method][i][0][0]/echelle, oY + dataJSON[method][i][0][1]/echelle);
            i++;
        }
        imageMode(CENTER);
        image(img, oX + dataJSON[method][0][0][0]/echelle, oY + dataJSON[method][0][0][1]/echelle, 20, 20);
    
    };

    reader.onerror = function() {
        console.log(reader.error);
    };
}

function preload() {
    earth = loadImage('images/earth.png');
    jupiter = loadImage('images/mercury.png');
    mars = loadImage('images/mars.png');
    mercury = loadImage('images/mercury.png');
    moon = loadImage('images/moon.png');
    neptune = loadImage('images/neptune.png');
    pluto = loadImage('images/pluto.png');
    saturn = loadImage('images/saturn.png');
    sun = loadImage('images/sun.png');
    uranus = loadImage('images/uranus.png');
    venus = loadImage('images/venus.png');

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

function setup() {
    createCanvas(720, 400).addClass("monitor");
    bg = loadImage('images/sky.png');

    imageMode(CENTER);
    image(img_sun, oX, oY, 80, 80);

    noLoop()  
    a = 0;
}

function draw() {
    //background(bg);
    image(bg, width/2, height/2, width, height);

    image(img_sun, oX, oY, 80, 80)
    image(img, 
        oX + dataJSON[method][a][0][0]/echelle, 
        oY + dataJSON[method][a][0][1]/echelle, 
        20, 20);
    
    if (a < 36501)
        {a = a+1;}
    else 
        {a = 0;}
}

