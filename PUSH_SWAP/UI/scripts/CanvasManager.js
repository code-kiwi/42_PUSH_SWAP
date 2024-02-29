import Canvas from "./Canvas.js";
import Stack from "./Stack.js";

class CanvasManager {
    constructor({ stackA = null, stackB = null, height = 600, width = 512 }) {
        if (!(stackA instanceof Stack) || !(stackB instanceof Stack)) {
            throw new Error(
                "ERROR - Both stackA and stackB must be instances of Stack"
            );
        }
        this.stackA = stackA;
        this.stackB = stackB;
        this.width = width;
        this.height = height;
        this.widthMin = 20;
        this.widthMax = this.width;
        this.evalDimensions();

        this.canvasA = null;
        this.canvasB = null;
    }

    evalDimensions() {
        this.stacksGlobalContent = [
            ...this.stackA.sortedContent,
            ...this.stackB.sortedContent,
        ];
        this.stacksGlobalContent.sort((a, b) => a - b);
        const nbElt = this.stacksGlobalContent.length;
        if (nbElt === 0) {
            this.dh = 0;
            this.dw = 0;
        } else {
            this.dh = Math.floor(this.height / nbElt);
            this.dw = Math.floor((this.widthMax - this.widthMin) / nbElt);
        }
    }

    addCanvas(letter, canvas) {
        if (letter !== "A" && letter !== "B") {
            throw new Error(
                "ERROR - The CanvasManager only accepts A and B as letter identifier for canvas"
            );
        }
        if (!(canvas instanceof Canvas)) {
            throw new Error(
                "ERROR - The CanvasManager only accepts instances of Canvas class"
            );
        }
        if (letter === "A") {
            this.canvasA = canvas;
        } else {
            this.canvasB = canvas;
        }
    }

    drawStacks() {
        if (this.canvasA === null || this.canvasB === null) {
            throw new Error(
                "ERROR - The CanvasManager requires two valid canvas in order to work"
            );
        }
        this.canvasA.updateDimensions(this.dh, this.dw);
        this.canvasA.drawStack(this.stacksGlobalContent);
        this.canvasB.updateDimensions(this.dh, this.dw);
        this.canvasB.drawStack(this.stacksGlobalContent);
    }

    updateStacksHandler() {
        this.evalDimensions();
        this.drawStacks();
    }
}

export default CanvasManager;
