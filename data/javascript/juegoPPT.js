function getComputerChoice() {
    const choices = ["piedra", "papel", "tijeras"];
    const randomIndex = Math.floor(Math.random() * choices.length);
    return choices[randomIndex];
}

function determineWinner(playerChoice, computerChoice) {
    if (playerChoice === computerChoice) {
        return "Empate";
    }
    if (
        (playerChoice === "piedra" && computerChoice === "tijeras") ||
        (playerChoice === "papel" && computerChoice === "piedra") ||
        (playerChoice === "tijeras" && computerChoice === "papel")
    ) {
        return "Jugador gana";
    }
    return "Computadora gana";
}

function playGame(playerChoice) {
    const computerChoice = getComputerChoice();
    console.log(`Jugador elige: ${playerChoice}`);
    console.log(`Computadora elige: ${computerChoice}`);
    console.log(determineWinner(playerChoice, computerChoice));
}

const choices = ["piedra", "papel", "tijeras"];
choices.forEach(choice => playGame(choice));