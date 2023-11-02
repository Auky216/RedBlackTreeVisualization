<template>
  <div class="implementation">
    <div class="input">
      <div class="insert">
        <input v-model="insertValue" />
        <button @click="insert">Insertar</button>
      </div>

      <div class="delete">
        <input v-model="deleteValue" />
        <button>Eliminar</button>
      </div>

      <div class="find">
        <input v-model="findValue" />
        <button>Encontrar</button>
      </div>

      
    </div>

    <div class="output">
      <canvas id="canvas"></canvas>

    </div>

    
    
      
    
    
  </div>
</template>
  <script>
//Script del Red Black Tree START
const canvas = document.getElementById('canvas');
    const ctx = canvas.getContext('2d');

    class Node {
      constructor(value, x, y, color) {
        this.value = value;
        this.x = x;
        this.y = y;
        this.color = color;
        this.radius = 20;
        this.lineWidth = 2;
        this.textColor = "#fff";
        this.lineColor = "#000";
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

    const rootNode = new Node(10, 400, 50, "black");
    drawNode(rootNode);
//Script del Red Black Tree END

export default {
  data() {
    return {
      insertValue: "",
      deleteValue: "",
      findValue: "",
    };
  },

  methods: {
    async insert() {
      try {
        const response = await fetch(
          "http://localhost:8080/insert/" + this.insertValue,
          {
            method: "POST",
            headers: {
              "Content-Type": "application/json",
            },
            body: JSON.stringify({
              value: this.insertValue,
            }),
          }
        );

        if (response.ok) {
          console.log("Insertion successful");
        } else {
          console.error("Insertion failed");
        }
      } catch (error) {
        console.error("Error:", error);
      }
    },
    delete() {
      console.log(this.deleteValue);
    },
    find() {
      console.log(this.findValue);
    },
  },
};
</script>
  
  <style>

  .output canvas{
    background-color: rgba(255, 255, 255, 0.354);
    height: 90%;
    width: 91%;
    margin-left: 50px;
    margin-right: 50px;
    margin-top: 10px;
    border-radius: 15px;
    

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
  background-color: #3a6df0;
  border-radius: 0 15px 15px 0;
  border: none;
  color: white;
  width: 100px;
  padding: 5px;
  cursor: pointer;
}
</style>