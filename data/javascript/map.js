function MapGoogle() {
    // Crea un nuevo mapa de Google Maps en el elemento con id 'map'
    var map = new google.maps.Map(document.getElementById('map'), {
        center: {lat: 0, lng: 0}, // Centro del mapa en la latitud y longitud (0, 0)
        zoom: 2 // Nivel de zoom del mapa
    });
    // Devuelve el objeto del mapa
    return map;
}
