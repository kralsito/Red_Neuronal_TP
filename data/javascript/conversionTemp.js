function celsiusToFahrenheit(celsius) {
    return (celsius * 9/5) + 32;
}

function fahrenheitToCelsius(fahrenheit) {
    return (fahrenheit - 32) * 5/9;
}

let temperaturesC = [0, 20, 30, 100];
let temperaturesF = temperaturesC.map(celsiusToFahrenheit);
console.log("Temperaturas en Fahrenheit:");
temperaturesF.forEach(temp => {
    console.log(`${temp}°F`);
});

let temperaturesF2 = [32, 68, 86, 212];
let temperaturesC2 = temperaturesF2.map(fahrenheitToCelsius);
console.log("Temperaturas en Celsius:");
temperaturesC2.for
