import Stack from "./Stack.js";

class StackManager {
    constructor({ stackA = null, stackB = null, updateStackEvent = null }) {
        if (
            stackA === null ||
            !(stackA instanceof Stack) ||
            stackB === null ||
            !(stackB instanceof Stack)
        ) {
            throw new Error(
                "ERROR - StackManager requires two valid instances of Stack"
            );
        }
        this.stackA = stackA;
        this.stackB = stackB;
        if (
            updateStackEvent != null &&
            !(updateStackEvent instanceof CustomEvent)
        ) {
            throw new Error(
                "ERROR - The parameter updateStackEvent is expected to be an instance of CustomEvent"
            );
        }
        this.updateStackEvent = updateStackEvent;
    }

    push(...nbs) {
        for (let nb of nbs) {
            if (
                this.stackA.content.indexOf(nb) !== -1 ||
                this.stackB.content.indexOf(nb) !== -1
            ) {
                this.triggerUpdateEvent();
                throw new Error(
                    `ERROR - The number ${nb} is already in one of your stacks`
                );
            }
            try {
                this.stackA.push(nb);
            } catch (error) {
                console.log("HERE");
                this.triggerUpdateEvent();
                throw error;
            }
        }
        this.triggerUpdateEvent();
    }

    pushValuesFromString(stack, values) {
        if (!(stack instanceof Stack) || stack !== this.stackA) {
            throw new Error("ERROR - The target stack is not valid");
        }
        let valuesArray = values.split(" ");
        valuesArray = valuesArray.map((x) => Number.parseInt(x));
        valuesArray = valuesArray.filter((x) => Number.isInteger(x));
        this.push(...valuesArray);
    }

    sa() {
        if (this.stackA.length() >= 2) {
            this.stackA.swap();
            this.triggerUpdateEvent();
            console.log("sa");
        }
    }

    sb() {
        if (this.stackB.length() >= 2) {
            this.stackB.swap();
            this.triggerUpdateEvent();
            console.log("sb");
        }
    }

    ss() {
        let swapped_a = false;
        let swapped_b = false;

        if (this.stackA.length() >= 2) {
            this.stackA.swap();
            swapped_a = true;
        }
        if (this.stackB.length() >= 2) {
            this.stackB.swap();
            swapped_b = true;
        }
        if (swapped_a && swapped_b) {
            console.log("ss");
        } else if (swapped_a) {
            console.log("sa");
        } else if (swapped_b) {
            console.log("sb");
        }
        this.triggerUpdateEvent();
    }

    pa() {
        if (this.stackB.length() >= 1) {
            try {
                this.stackA.push(this.stackB.pop());
                this.triggerUpdateEvent();
                console.log("pa");
            } catch (error) {
                throw error;
            }
        }
    }

    pb() {
        if (this.stackA.length() >= 1) {
            try {
                this.stackB.push(this.stackA.pop());
                this.triggerUpdateEvent();
                console.log("pb");
            } catch (error) {
                throw error;
            }
        }
    }

    ra() {
        if (this.stackA.length() >= 2) {
            this.stackA.rot();
            this.triggerUpdateEvent();
            console.log("ra");
        }
    }

    rb() {
        if (this.stackB.length() >= 2) {
            this.stackB.rot();
            this.triggerUpdateEvent();
            console.log("rb");
        }
    }

    rr() {
        let rot_a = false;
        let rot_b = false;

        if (this.stackA.length() >= 2) {
            this.stackA.rot();
            rot_a = true;
        }
        if (this.stackB.length() >= 2) {
            this.stackB.rot();
            rot_b = true;
        }
        if (rot_a && rot_b) {
            console.log("rr");
        } else if (rot_a) {
            console.log("ra");
        } else if (rot_b) {
            console.log("rb");
        }
        this.triggerUpdateEvent();
    }

    rra() {
        if (this.stackA.length() >= 2) {
            this.stackA.rev_rot();
            this.triggerUpdateEvent();
            console.log("rra");
        }
    }

    rrb() {
        if (this.stackB.length() >= 2) {
            this.stackB.rev_rot();
            this.triggerUpdateEvent();
            console.log("rrb");
        }
    }

    rrr() {
        let rot_a = false;
        let rot_b = false;

        if (this.stackA.length() >= 2) {
            this.stackA.rev_rot();
            rot_a = true;
        }
        if (this.stackB.length() >= 2) {
            this.stackB.rev_rot();
            rot_b = true;
        }
        if (rot_a && rot_b) {
            console.log("rr");
        } else if (rot_a) {
            console.log("ra");
        } else if (rot_b) {
            console.log("rb");
        }
        this.triggerUpdateEvent();
    }

    toString() {
        return `Stack_a: [${this.stackA.toString()}]\nStack_b: [${this.stackB.toString()}]`;
    }

    isSorted(stackLetter) {
        if (stackLetter === "a") {
            return this.stackA.isSorted();
        } else if (stackLetter === "b") {
            return this.stackB.isSorted();
        } else {
            return false;
        }
    }

    isRevSorted(stackLetter) {
        if (stackLetter === "a") {
            return this.stackA.isRevSorted();
        } else if (stackLetter === "b") {
            return this.stackB.isRevSorted();
        } else {
            return false;
        }
    }

    triggerUpdateEvent() {
        if (this.updateStackEvent != null) {
            document.dispatchEvent(this.updateStackEvent);
        }
    }
}

export default StackManager;
