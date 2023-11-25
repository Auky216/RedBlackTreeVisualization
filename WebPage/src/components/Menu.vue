<template>
  <div class="home">
    <h1>Definicion</h1>
    <p>
      Los árboles Red-Black, una forma fascinante de estructurar datos, son
      conocidos por su equilibrio y capacidad para mantener un rendimiento
      óptimo en diversas operaciones. En esta sección, exploraremos en
      profundidad los aspectos esenciales de estos árboles autoequilibrados y
      cómo impactan en la eficiencia de algoritmos y estructuras de datos.
    </p>

    <h1>¿Qué son los Red-Black Trees?</h1>
    <p>
      Los árboles Red-Black son una forma especial de árboles binarios de
      búsqueda que poseen propiedades únicas para mantener un equilibrio entre
      la profundidad del árbol y la complejidad de las operaciones. Están
      diseñados para optimizar la búsqueda, inserción y eliminación de
      elementos, ofreciendo un rendimiento predecible y eficiente en una amplia
      gama de aplicaciones.
    </p>
    <center><img src="./icons/homeIcons/cero.jpg" /></center>

    <h1>Propiedades</h1>
    

    <div class="div-information">
      <div class="block">
        <img class="img-profile" src="./icons/homeIcons/uno.jpg" />
        <p>Cada nodo es rojo o negro.</p>
     
      </div>

      <div class="block">
        <img class="img-profile" src="./icons/homeIcons/dos.jpg" />
        <p>La raíz siempre es negra.</p>
 
      </div>

      <div class="block">
        <img class="img-profile" src="./icons/homeIcons/tres.jpg" />
        <p>Todas las hojas nulas (externas) son negras</p>
      
      </div>

      <div class="block">
        <img class="img-profile" src="./icons/homeIcons/cuatro.jpg" />
        <p>Un nodo rojo nunca tiene hijos rojos directos.</p>
      
      </div>

      <div class="block">
        <img class="img-profile" src="./icons/homeIcons/cinco.jpg" />
        <p>Cada camino desde un nodo hacia sus hojas vacías debe tener la misma cantidad de nodos negros.</p>
      
      </div>
    </div>

    
    <h1>Características Clave</h1>
    <p>
      Estos árboles poseen características particulares que los distinguen de
      otras estructuras de datos. Sus propiedades fundamentales, como la
      coloración de nodos y reglas de balanceo, garantizan un comportamiento
      balanceado y un tiempo de ejecución predecible en operaciones críticas.
    </p>

    <div class="div-information">
      <div class="block">
        <img class="img-profile" src="./icons/homeIcons/seis.jpg" />
        <p>Arbol sin balanceo</p>
     
      </div>

      <div class="block">
        <img class="img-profile" src="./icons/homeIcons/siete.jpg" />
        <p>Balanceando</p>
        
        
      </div>

      <div class="block">
        <img class="img-profile" src="./icons/homeIcons/ocho.jpg" />
        <p>Arbol balanceado</p>
        
        
      </div>
      

      
    </div>
    <h1>Aplicaciones y Uso en la Práctica</h1>
    <p>
      Desde algoritmos de búsqueda hasta la implementación de bases de datos y
      sistemas de archivos, los Red-Black Trees encuentran aplicaciones en
      diversas áreas de la informática. Su capacidad para mantener un
      rendimiento estable los convierte en una elección preferida en escenarios
      donde se requiere un equilibrio entre la velocidad y la complejidad.
    </p>

    <center><img src="./icons/homeIcons/diez.jpg" /></center>
  </div>
</template>

<script>
export default {};
</script>

<style>
embed {
  margin: 0 auto;
  display: block;
  width: 100%;
  height: 100vh;
}

.home {
  margin: 10px;
}

.div-information {
  display: flex;
  flex-direction: row;
  justify-content: center;
  align-items: center;
  margin: 10px;
}

.about {
  margin: 10px;
}

.img-profile {
  width: 200px;
  height: 200px;
  border-radius: 20%;
  margin: 20px;
}
.block {
  /* Restringe el tamaño máximo del cuadro */
  max-width: 500px;
  height: 300px;
  border: 5px solid #000;
  margin: 10px;
  transition: all 0.3s ease;
  position: relative;
  text-align: center;
  overflow: hidden; /* Evita desbordamiento horizontal */
}

.block p {
  /* Asegura que el texto no haga crecer el cuadro más allá del límite */
  max-width: 180px; /* Deja algo de espacio para el borde */
  margin: 0 auto;
  
  word-wrap: break-word; /* Permite ajuste de palabras */
  overflow-y: auto; /* Agrega desplazamiento vertical */
  max-height: 5em; /* Limita la altura para mostrar el scroll si es necesario */
}

.block:hover {
  border-color: #ee3939; /* Cambio del color del borde a rojo */
  transform: scale(1.1); /* Aumentar tamaño en el hover */
  z-index: 1; /* Para superposición */
  box-shadow: 0 0 10px #ee3939; /* Sombra al hacer hover */
  text-align: center;
}
</style>