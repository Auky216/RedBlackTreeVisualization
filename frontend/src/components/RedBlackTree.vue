<template>
  <div class="implementation">
    <div class="input">
      <!-- Your input elements here -->
    </div>

    <div class="output">
      <canvas
        id="canvas"
        ref="canvas"
        width="800"
        height="400"
        @wheel="handleZoom"
        @mousedown="startDragging"
        @mousemove="dragCanvas"
        @mouseup="stopDragging"
      ></canvas>
    </div>
  </div>
</template>

  <script>
//Script del Red Black Tree START

export default {
  data() {
    return {
      insertValue: "",
      deleteValue: "",
      findValue: "",
      translationX: 0,
      translationY: 0,
      scale: 1,
      isDragging: false,
      lastX: 0,
      lastY: 0,
      
    };
  },

 methods: {
  handleZoom(event) {
      const delta = event.deltaY > 0 ? -0.1 : 0.1;
      this.scale += delta;
      this.scale = Math.min(Math.max(0.2, this.scale), 3);
      this.translationX -= event.offsetX * delta;
      this.translationY -= event.offsetY * delta;
      this.drawCanvas();
    },

    startDragging(event) {
      this.isDragging = true;
      this.lastX = event.clientX;
      this.lastY = event.clientY;
    },

    dragCanvas(event) {
      if (this.isDragging) {
        const deltaX = event.clientX - this.lastX;
        const deltaY = event.clientY - this.lastY;

        this.translationX += deltaX;
        this.translationY += deltaY;

        this.lastX = event.clientX;
        this.lastY = event.clientY;

        this.drawCanvas();
      }
    },

    stopDragging() {
      this.isDragging = false;
    },

    drawCanvas() {
      const canvas = this.$refs.canvas;
      const ctx = canvas.getContext("2d");

      ctx.clearRect(0, 0, canvas.width, canvas.height);

      ctx.setTransform(this.scale, 0, 0, this.scale, this.translationX, this.translationY); 
      class Node {
      constructor(value, x, y, color) {
        this.value = value;
        this.x = x;
        this.y = y;
        this.color = color;
        this.radius = 20;
        this.lineWidth = 2;
        this.textColor = "#fff";
        this.lineColor = "black";
        this.highlighted = false;
        this.left = null;
        this.right = null;
      }
    }

    function drawNode(node) {
      ctx.beginPath();
      ctx.arc(node.x, node.y, node.radius, 0, Math.PI * 2);
      ctx.fillStyle = node.color;
      ctx.fill();
      ctx.lineWidth = node.lineWidth;
      ctx.strokeStyle = node.lineColor;
      ctx.stroke();

      if (node.highlighted) {
        ctx.fillStyle = "#FF5733"; // Highlight color
        ctx.fill();
      }

      ctx.fillStyle = node.textColor;
      ctx.font = "bold 16px Arial";
      const textWidth = ctx.measureText(node.value).width;
      ctx.fillText(node.value, node.x - textWidth / 2, node.y + 6);
    }

    function drawLine(fromX, fromY, toX, toY, color) {
      ctx.beginPath();
      ctx.moveTo(fromX, fromY);
      ctx.lineTo(toX, toY);
      ctx.strokeStyle = color;
      ctx.lineWidth = 2;
      ctx.stroke();
    }

    // Crear nodos de ejemplo
    const rootNode = new Node(10, 400, 50, "black");
    const node1 = new Node(5, 250, 150, "#f85840");
    const node2 = new Node(15, 550, 150, "#f85840");
    const node3 = new Node(3, 200, 250, "black");
    const node4 = new Node(7, 300, 250, "black");

    // Conectar los nodos
    rootNode.left = node1;
    rootNode.right = node2;
    node1.left = node3;
    node1.right = node4;

    // Dibujar las líneas que los conectan
    drawLine(rootNode.x, rootNode.y, node1.x, node1.y, "black");
    drawLine(node1.x, node1.y, node3.x, node3.y, "black");
    drawLine(node1.x, node1.y, node4.x, node4.y, "black");
    drawLine(rootNode.x, rootNode.y, node2.x, node2.y, "black");

    // Dibujar los nodos
    drawNode(rootNode);
    drawNode(node1);
    drawNode(node2);
    drawNode(node3);
    drawNode(node4);
    }
 },

  
};
</script>
  
  <style>

.input{
  display: flex;
  justify-content: center;
  align-items: center;
  width: 100%;

}

.output{
  position: relative;
  margin:0;
  align-content: center;
  justify-content: center;

  
}
  
.output canvas {
  background-color: rgba(255, 255, 255, 1);
  height: 100%;
  width: 100%;
  
  margin-top: 10px;
  border-radius: 15px;
  box-shadow: 0 0 20px rgba(255, 255, 255, 0.3); /* Efecto gaussiano en los bordes */

}

.implementation {
  display: flex;
  flex-direction: column;
  max-height: 100%;
  overflow-y: auto;
  position: relative; /* Para establecer una posición relativa en el contenedor */
}

.implementation::-webkit-scrollbar {
  width: 12px; /* Ancho del scrollbar en navegadores WebKit (Chrome, Safari, etc.) */
}

.implementation::-webkit-scrollbar-thumb {
  background-color: #00000091; /* Color de la barra del scrollbar en navegadores WebKit */
  border-radius: 15px;
}

.implementation::-webkit-scrollbar-track {
  background-color: transparent; /* Color de fondo del scrollbar en navegadores WebKit */
}

.implementation::-webkit-scrollbar-button {
  display: none; /* Oculta los botones de inicio y fin del scrollbar en navegadores WebKit */
}

.implementation::-webkit-scrollbar-corner {
  background-color: transparent; /* Color de la esquina del scrollbar en navegadores WebKit */
}

.implementation::-webkit-scrollbar-thumb:hover {
  background-color: #00000091; /* Color de la barra del scrollbar en estado hover en navegadores WebKit */
}
.implementation .input {
  display: flex;
}
.insert,
.delete,
.find {
  display: flex;
  justify-content: center;
  align-items: center;
  width: 100%;
  height: 100%;
  margin: 10px;
}

.insert input,
.delete input,
.find input {
  background-color: rgba(255, 255, 255, 0.1);
  border-radius: 15px 0 0 15px;
  border: none;
  backdrop-filter: blur(10px);
  padding: 5px;
  outline: none;
  text-align: center;
  color: white;
}

.insert button,
.delete button,
.find button {
  background-color: #f85840;
  border-radius: 0 15px 15px 0;
  border: none;
  color: white;
  width: 100px;
  padding: 5px;
  cursor: pointer;
}
</style>