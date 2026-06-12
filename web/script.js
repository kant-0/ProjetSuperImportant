let echelle = 1000000000;
let reader = new FileReader();
let file;
let dataJSON;
let method;
let bg;
let earth; 
let jupiter;
let mars;
let mercury;
let moon;
let neptune;
let pluto;
let saturn;
let sun;
let uranus;
let venus;
let oY = 400/2;
let oX = 720/2;

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
        imageMode(CENTER);
        image(sun, oX, oY, 80, 80)
        image(mercury, 
            oX + dataJSON["mercury"][a][0][0]/echelle, 
            oY + dataJSON["mercury"][a][0][1]/echelle, 
            20, 20);
        image(venus, 
            oX + dataJSON["venus"][a][0][0]/echelle, 
            oY + dataJSON["venus"][a][0][1]/echelle, 
            20, 20);
        image(earth, 
            oX + dataJSON["earth"][a][0][0]/echelle, 
            oY + dataJSON["earth"][a][0][1]/echelle, 
            20, 20);
        image(mars, 
            oX + dataJSON["mars"][a][0][0]/echelle, 
            oY + dataJSON["mars"][a][0][1]/echelle, 
            20, 20);
        image(jupiter, 
            oX + dataJSON["jupiter"][a][0][0]/echelle, 
            oY + dataJSON["jupiter"][a][0][1]/echelle, 
            20, 20);
        image(saturn, 
            oX + dataJSON["saturn"][a][0][0]/echelle, 
            oY + dataJSON["saturn"][a][0][1]/echelle, 
            20, 20);
        image(uranus, 
            oX + dataJSON["uranus"][a][0][0]/echelle, 
            oY + dataJSON["uranus"][a][0][1]/echelle, 
            20, 20);
        image(neptune, 
            oX + dataJSON["neptune"][a][0][0]/echelle, 
            oY + dataJSON["neptune"][a][0][1]/echelle, 
            20, 20);
        image(pluto, 
            oX + dataJSON["pluto"][a][0][0]/echelle, 
            oY + dataJSON["pluto"][a][0][1]/echelle, 
            20, 20);
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

    bg = loadImage('images/sky.png');

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

    imageMode(CENTER);
    image(sun, oX, oY, 80, 80);

    noLoop()  
    a = 0;
}

function draw() {
    //background(bg);
    image(bg, width/2, height/2, width, height);

    image(sun, oX, oY, 80, 80)
    image(mercury, 
        oX + dataJSON["mercury"][a][0][0]/echelle, 
        oY + dataJSON["mercury"][a][0][1]/echelle, 
        20, 20);
    image(venus, 
        oX + dataJSON["venus"][a][0][0]/echelle, 
        oY + dataJSON["venus"][a][0][1]/echelle, 
        20, 20);
    image(earth, 
        oX + dataJSON["earth"][a][0][0]/echelle, 
        oY + dataJSON["earth"][a][0][1]/echelle, 
        20, 20);
    image(mars, 
        oX + dataJSON["mars"][a][0][0]/echelle, 
        oY + dataJSON["mars"][a][0][1]/echelle, 
        20, 20);
    image(jupiter, 
        oX + dataJSON["jupiter"][a][0][0]/echelle, 
        oY + dataJSON["jupiter"][a][0][1]/echelle, 
        20, 20);
    image(saturn, 
        oX + dataJSON["saturn"][a][0][0]/echelle, 
        oY + dataJSON["saturn"][a][0][1]/echelle, 
        20, 20);
    image(uranus, 
        oX + dataJSON["uranus"][a][0][0]/echelle, 
        oY + dataJSON["uranus"][a][0][1]/echelle, 
        20, 20);
    image(neptune, 
        oX + dataJSON["neptune"][a][0][0]/echelle, 
        oY + dataJSON["neptune"][a][0][1]/echelle, 
        20, 20);
    image(pluto, 
        oX + dataJSON["pluto"][a][0][0]/echelle, 
        oY + dataJSON["pluto"][a][0][1]/echelle, 
        20, 20);
    
    if (a < 36501)
        {a = a+1;}
    else 
        {a = 0;}
}