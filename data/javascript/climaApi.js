document.addEventListener('DOMContentLoaded', () => {
    const apiKey = 'TU_API_KEY';
    const apiUrl = `https://api.openweathermap.org/data/2.5/weather?q=London&appid=${apiKey}`;

    fetch(apiUrl)
        .then(response => response.json())
        .then(data => {
            const cityName = data.name;
            const temperature = Math.round(data.main.temp - 273.15); // Convert Kelvin to Celsius
            const weatherDescription = data.weather[0].description;
            console.log(`El clima en ${cityName} es ${temperature}°C y ${weatherDescription}.`);
        })
        .catch(error => {
            console.error('Error al obtener el clima:', error);
        });
});
