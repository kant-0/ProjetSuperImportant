function start(elm) {
    new Response(elm.files[0]).json().then(json => {
        console.log(json)
        document.getElementById("sim-container").toggleAttribute("hidden")
    }, err => {
        // not json
    })
}

