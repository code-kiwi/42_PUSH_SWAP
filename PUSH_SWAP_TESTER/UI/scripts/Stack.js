/**
 * Represents a stack with various operations.
 * @class
 */
class Stack {
    /**
     * Creates an instance of the Stack class.
     * @constructor
     * @param {string} name - The name of the stack.
     */
    constructor(name) {
        /**
         * The name of the stack.
         * @type {string}
         */
        this.name = name;

        /**
         * The content of the stack.
         * @type {Array<number>}
         */
        this.content = [];

        /**
         * The sorted content of the stack.
         * @type {Array<number>}
         */
        this.sortedContent = [];
    }

    /**
     * Pushes one or more integers onto the stack (updates sortedContent).
     * @param  {...number} nbs - Integers to push.
     * @throws {Error} Error if any parameter is not an integer.
     * @throws {Error} Error if the stack's size is greater than or equal to 500.
     * @throws {Error} Error if any integer parameter is already in the stack.
     */
    push(...nbs) {
        for (const nb of nbs) {
            if (!Number.isInteger(nb)) {
                throw new Error(
                    "ERROR - The given number has to be an integer"
                );
            } else if (this.content.length >= 500) {
                throw new Error(
                    "ERROR - The stack cannot contain more than 500 integers"
                );
            } else if (this.content.indexOf(nb) != -1) {
                throw new Error(
                    "ERROR - The stack cannot contain duplicate integers"
                );
            }
            this.content.unshift(nb);
            this.sortedContent.unshift(nb);
            this.sortedContent.sort((a, b) => a - b);
        }
    }

    /**
     * Removes and returns the top integer from the stack.
     * @returns {number} The removed integer.
     * @throws {Error} Error if the stack is empty.
     */
    pop() {
        let popped, sortedIndex;

        if (this.content.length === 0) {
            throw new Error("ERROR - The stack is empty");
        }
        popped = this.content.shift();
        sortedIndex = this.sortedContent.indexOf(popped);
        if (sortedIndex !== -1) {
            this.sortedContent.splice(sortedIndex, 1);
        }
        return popped;
    }

    /**
     * Removes integers with specified values from the stack.
     * @param {...number} nbs - Integers to remove.
     */
    remove(...nbs) {
        for (const nb of nbs) {
            const index = this.content.indexOf(nb);
            if (index !== -1) {
                this.content.splice(index, 1);
                this.sortedContent.splice(sortedIndex, 1);
            }
        }
    }

    /**
     * Swaps the top two integers on the stack.
     */
    swap() {
        if (this.content.length >= 2) {
            [this.content[0], this.content[1]] = [
                this.content[1],
                this.content[0],
            ];
        }
    }

    /**
     * Puts first element of the stack at the end
     */
    rot() {
        if (this.content.length >= 2) {
            this.content.push(this.content.shift());
        }
    }

    /**
     * Puts the last element of the stack at first position
     */
    rev_rot() {
        if (this.content.length >= 2) {
            this.content.unshift(this.content.pop());
        }
    }

    /**
     * Clears the stack.
     */
    clear() {
        this.content = [];
        this.sortedContent = [];
    }

    /**
     * Returns a string representation of the stack.
     * @returns {string} The string representation of the stack.
     */
    toString() {
        return this.content.toString();
    }

    /**
     * Returns the length of the stack
     * @returns {number} The length of the stack
     */
    length() {
        return this.content.length;
    }

    /**
     * Checks if the elements in the stack are sorted in ascending order.
     * @returns {boolean} True if the stack is sorted, false otherwise.
     */
    isSorted() {
        for (let i = 0; i < this.content.length - 1; i++) {
            if (this.content[i] > this.content[i + 1]) {
                return false;
            }
        }
        return true;
    }

    /**
     * Checks if the elements in the stack are sorted in descending order.
     * @returns {boolean} True if the stack is reverse sorted, false otherwise.
     */
    isRevSorted() {
        for (let i = 0; i < this.content.length - 1; i++) {
            if (this.content[i] < this.content[i + 1]) {
                return false;
            }
        }
        return true;
    }
}

export default Stack;
