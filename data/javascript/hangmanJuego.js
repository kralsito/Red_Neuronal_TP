class Hangman {
    constructor(word, maxAttempts) {
        this.word = word.toLowerCase().split('');
        this.maxAttempts = maxAttempts;
        this.attempts = 0;
        this.guessedLetters = new Set();
        this.correctGuesses = new Set();
        this.gameOver = false;
    }

    guess(letter) {
        if (this.gameOver || this.guessedLetters.has(letter)) {
            return;
        }

        this.guessedLetters.add(letter);

        if (this.word.includes(letter)) {
            this.correctGuesses.add(letter);
        } else {
            this.attempts++;
        }

        this.checkGameOver();
    }

    getWordDisplay() {
        return this.word.map(letter => (this.correctGuesses.has(letter) ? letter : '_')).join(' ');
    }

    checkGameOver() {
        if (this.attempts >= this.maxAttempts) {
            this.gameOver = true;
            console.log(`Perdiste. La palabra era: ${this.word.join('')}`);
        } else if (this.word.every(letter => this.correctGuesses.has(letter))) {
            this.gameOver = true;
            console.log(`¡Ganaste! La palabra es: ${this.word.join('')}`);
        }
    }

    play() {
        while (!this.gameOver) {
            console.log(`Palabra: ${this.getWordDisplay()}`);
            console.log(`Intentos restantes: ${this.maxAttempts - this.attempts}`);
            let guess = prompt('Adivina una letra: ').toLowerCase();
            this.guess(guess);
        }
    }
}

const hangman = new Hangman('javascript', 6);
hangman.play();
