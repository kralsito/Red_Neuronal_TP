let targetNumber = Math.floor(Math.random() * 100) + 1;
let attempts = 0;

console.log("Adivina el número entre 1 y 100");

function guessNumber(userGuess) {
    attempts++;
    if (userGuess > targetNumber) {
        console.log("El número es menor.");
    } else if (userGuess < targetNumber) {
        console.log("El número es mayor.");
    } else {
        console.log(`¡Correcto! Adivinaste el número en ${attempts} intentos.`);
        return true;
    }
    return false;
}

// Simulación de intentos del usuario
let guesses = [50, 25, 75, 62, 68, 70, 69]; // Simulando entradas del usuario
for (let guess of guesses) {
    if (guessNumber(guess)) break;
}
