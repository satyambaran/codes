class Game {
    constructor(n, m) {
        this.playerList = [];
        this.lastPlayed = -1;
        this.gameStatusArray = ["yet_to_start", "playing", "finished"];
        this.gameStatus = 0;
        this.boardSize = n * m;
    }
}
class Snake {
    constructor() {
        this.startIdxs = [];
        this.endIdxs = [];
    }
    insert(start, end) {
        this.startIdxs.push(start);
        this.endIdxs.push(end);
    }
}
class Ladder {
    constructor() {
        this.startIdxs = [];
        this.endIdxs = [];
    }
    insert(start, end) {
        this.startIdxs.push(start);
        this.endIdxs.push(end);
    }
}
class Player {
    constructor(name) {
        this.name = name;
        this.currentPos = 0;
        this.status = "playing";
    }
}
class Dice {
    constructor(n) {
        this.n = n;
    }
    roll(player) {
        let rollValue = 1 + Math.floor(Math.random() * n);
        console.log("Rolling for " + player.name + ", got " + rollValue);
        return rollValue;
    }
}
function startGame() {
    let n = window.prompt("Board length: ");
    let m = window.prompt("Board width: ");
    let game = new Game(n, m);
    n = window.prompt("Number of ladder: ");
    let ladders = new Ladder(n);
    for (let i = 0; i < n; i++) {
        let a = window.prompt("start of " + i + "th ladder: ");
        let b = window.prompt("end of " + i + "th ladder: ");
        if (b < a) {
            console.log("Not possible");
        } else {
            ladders.insert(a, b);
        }
    }

    n = window.prompt("Number of snake: ");
    let snakes = new Snake(n);
    for (let i = 0; i < n; i++) {
        let a = window.prompt("start of " + i + "th snake: ");
        let b = window.prompt("end of " + i + "th snake: ");
        if (b > a) {
            console.log("Not possible");
        } else {
            ladders.insert(a, b);
        }
    }
    for (let i = 0; i < n; i++) {}
    n = window.prompt("Number of players: ");
    let players = new PlayerList();
    for (let i = 0; i < n; i++) {}
}
startGame();
