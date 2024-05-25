class TicTacToe {
    constructor() {
        this.board = Array(9).fill(null);
        this.currentPlayer = 'X';
        this.gameOver = false;
    }

    makeMove(index) {
        if (!this.board[index] && !this.gameOver) {
            this.board[index] = this.currentPlayer;
            if (this.checkWin()) {
                this.gameOver = true;
                console.log(`Jugador ${this.currentPlayer} gana!`);
            } else if (this.board.every(cell => cell)) {
                this.gameOver = true;
                console.log("Es un empate!");
            } else {
                this.currentPlayer = this.currentPlayer === 'X' ? 'O' : 'X';
            }
        }
    }

    checkWin() {
        const winPatterns = [
            [0, 1, 2], [3, 4, 5], [6, 7, 8],
            [0, 3, 6], [1, 4, 7], [2, 5, 8],
            [0, 4, 8], [2, 4, 6]
        ];

        return winPatterns.some(pattern => 
            pattern.every(index => this.board[index] === this.currentPlayer)
        );
    }

    displayBoard() {
        console.log(`
          ${this.board[0] || ' '} | ${this.board[1] || ' '} | ${this.board[2] || ' '}
         ---+---+---
          ${this.board[3] || ' '} | ${this.board[4] || ' '} | ${this.board[5] || ' '}
         ---+---+---
          ${this.board[6] || ' '} | ${this.board[7] || ' '} | ${this.board[8] || ' '}
        `);
    }

    play() {
        while (!this.gameOver) {
            this.displayBoard();
            let index = parseInt(prompt(`Jugador ${this.currentPlayer}, elige una posición (0-8): `), 10);
            this.makeMove(index);
        }
        this.displayBoard();
    }
}

const game = new TicTacToe();
game.play();
