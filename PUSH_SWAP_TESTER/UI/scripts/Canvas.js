import Stack from "./Stack.js";

class Canvas {
    constructor({
        elementId,
        stack,
        height = 600,
        width = 512,
        dh,
        dw,
        widthMin,
    }) {
        this.element = document.getElementById(elementId);
        if (!this.element) {
            throw new Error(
                "ERROR - A ConsoleManager argument is required for creating a Console object"
            );
        }
        if (!(stack instanceof Stack)) {
            throw new Error(
                "ERROR - A Stack argument is required for creating a Canvas object"
            );
        }
        this.stack = stack;

        // Setting the right height and width (Because of screen ratio)
        this.height = height;
        this.width = width;
        this.element.height = this.height;
        this.element.width = this.width;
        this.widthMin = widthMin;

        // Colors
        this.minColor = [230, 230, 255];
        this.maxColor = [0, 0, 77];

        // Dimension attributes
        this.context = this.element.getContext("2d");
        this.dh = dh;
        this.dw = dw;
    }

    clear() {
        this.context.clearRect(0, 0, this.width, this.height);
    }

    updateDimensions(dh, dw) {
        if (Number.isNaN(dh) || Number.isNaN(dw)) {
            throw new Error(
                "ERROR - A Canvas dimensions steps update requires valid numbers"
            );
        }
        this.dh = dh;
        this.dw = dw;
    }

    writeEmptyStack() {
        const text = "The stack is empty";
        const fontSize = 20;
        this.context.imageSmoothingEnabled = false;
        this.context.font = `${fontSize}px Arial`;
        const textWidth = this.context.measureText(text).width;
        const x = (this.width - textWidth) / 2;
        const y = this.height / 2;
        this.context.fillStyle = "black";
        this.context.fillText(text, x, y);
    }

    drawStack(stacksGlobalContent) {
        let currentValue, sortedIndex, rectHeight, rectWidth, xPos, yPos, color;
        const stackLength = this.stack.length();

        this.clear();
        if (stackLength > 0) {
            for (let i = 0; i < stackLength; i++) {
                currentValue = this.stack.content[stackLength - 1 - i];
                sortedIndex = stacksGlobalContent.indexOf(currentValue);
                rectHeight = this.dh;
                rectWidth = this.widthMin + sortedIndex * this.dw;
                xPos = Math.floor(this.width / 2 - rectWidth / 2) * 0;
                yPos = this.height - (i + 1) * this.dh;
                color = this.getEltColor(
                    sortedIndex / stacksGlobalContent.length
                );
                this.drawRect(color, [xPos, yPos], rectWidth, rectHeight);
            }
        } else {
            this.writeEmptyStack();
        }
    }

    drawRect(color, pointA, width, height) {
        if (!Array.isArray(pointA) || pointA.length !== 2)
            throw new Error(
                "ERROR - In order to draw a rectangle, you have to pass to valid points"
            );
        this.context.fillStyle = color;
        this.context.fillRect(pointA[0], pointA[1], width, height);
    }

    // Fonction pour générer une couleur intermédiaire entre deux couleurs
    getEltColor(factor) {
        const result = this.minColor.map((channel, index) => {
            const diff = Math.abs(this.maxColor[index] - channel);
            if (this.maxColor[index] > channel) {
                return Math.round(channel + factor * diff);
            } else {
                return Math.round(channel - factor * diff);
            }
        });
        return `rgb(${result.join(",")})`;
    }
}

export default Canvas;
