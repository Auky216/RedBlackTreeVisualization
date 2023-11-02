<template>
  <div class="screen">
    <div class="video-bg">
      <img class="wallpaper" src="https://i.pinimg.com/originals/d7/33/34/d733345e4f11231904e7634a04439e21.gif" alt="Background GIF">
    </div>
    <div class="bar-menu">
      <div style="background-color: #ec6a5e" class="cyrcle"></div>
      <div style="background-color: #f4bf4f" class="cyrcle"></div>
      <div style="background-color: #62c554" class="cyrcle"></div>

      <div class="routers">
        <router-link to="/">Red Black Tree</router-link> 
        <router-link to="/about">Home</router-link> 
        <router-link to="/">Home</router-link> 
      </div>

    </div>
    <div class="container">
      <router-view></router-view>
    </div>
  </div>
</template>

<style>

.screen {
  display: flex;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  height: 100vh;
}

.routers{
  display: flex;
  justify-content: center;
  align-items: center;
  width: 100%;
  height: 100%;
  
}
.routers a {
  margin: 10px;
  text-decoration: none;
  color: rgba(255, 255, 255, 0.263);
  font-size: 20px;
  font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
  margin: 4px;
  transition: color 0.3s; /* Agregamos una transición para suavizar el cambio de color en el hover */
}

.routers a:hover,
.routers a:active,
.routers a:visited {
  color: white;
}


.cyrcle{

  width: 20px;
  height: 20px; /* Añade una altura para que sea un círculo */
  border-radius: 50%; /* Establece el radio del borde al 50% para hacerlo circular */
  display: flex;
  justify-content: center;
  align-items: center;
  color: white; /* Color del texto en el círculo */
  font-size: 20px; /* Tamaño del texto */
  margin: 4px;
}

.container{
  max-width: 100%; /* Limita el ancho máximo del contenido al 100% del contenedor */
  overflow: hidden; /* Oculta el contenido que se desborda del contenedor */
  width: 75%;
  height: 75%;
  background-color: rgba(0, 0, 0, 0.374);
  border-radius: 0 0 15px 15px;
  padding: 10px;
  margin: 0; /* Agrega un margen para separarlos */
  backdrop-filter: blur(10px);
}
.bar-menu {
  display: flex;
  width: 75%;
  height: 5%;
  background-color: rgba(0, 0, 0, 0.511);
  border-radius: 15px 15px 0 0;
  padding: 10px;
  margin: 0; /* Agrega un margen para separarlos */
  align-items: center;
  backdrop-filter: blur(10px);
}

.video-bg {
  position: fixed;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  z-index: -1; /* Coloca el video detrás de otros elementos */
}

/* Asegúrate de que el video se ajuste al tamaño de la ventana */
.wallpaper {
  object-fit: cover;
  width: 100%;
  height: 100%;
}
</style>
