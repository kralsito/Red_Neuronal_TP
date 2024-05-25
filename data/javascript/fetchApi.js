// Hacer una solicitud GET a una API y obtener los datos
fetch('https://api.example.com/data')
    .then(response => response.json())
    .then(data => {
        console.log('Datos obtenidos:', data);
    })
    .catch(error => {
        console.error('Error al obtener datos:', error);
    });
