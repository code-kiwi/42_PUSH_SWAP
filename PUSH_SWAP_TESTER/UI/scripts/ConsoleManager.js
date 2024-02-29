import Console from "./Console.js";

class ConsoleManager {
    constructor() {
        this.consoles = [];
    }

    addConsole(console) {
        if (!(console instanceof Console)) {
            throw new Error(
                "ERROR - A ConsoleManager only manages Console objects"
            );
        }
        if (this.consoles.indexOf(console) === -1) {
            this.consoles.push(console);
        }
    }

    activate(console) {
        let consoleIndex = this.consoles.indexOf(console);
        if (consoleIndex === -1) {
            throw new Error(
                "ERROR - The given console is not managed by the consoleManager"
            );
        }
        this.deactivateAll();
        this.consoles[consoleIndex].activate();
    }

    deactivateAll() {
        for (const console of this.consoles) {
            console.deactivate();
        }
    }
}

export default ConsoleManager;
