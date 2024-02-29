class CommandQueue {
    static availableCommands = [
        "sa",
        "sb",
        "pa",
        "pb",
        "ra",
        "rb",
        "rr",
        "rra",
        "rrb",
        "rrr",
    ];

    constructor() {
        this.queue = [];
        this.history = [];
    }

    push(...commands) {
        let index;
        for (let command of commands) {
            index = CommandQueue.availableCommands.findIndex(command);
            if (index == -1) {
                throw new Error("ERROR - The given command is not valid");
            }
            this.queue.unshift(command);
        }
    }

    pop() {
        if (this.queue.length == 0) {
            throw new Error("ERROR - The command queue is empty");
        }
        const command = this.queue.pop();
        this.history.unshift(command);
        return command;
    }
}

export default CommandQueue;
