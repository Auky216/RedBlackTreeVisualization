<template>
  <div class="screen">
    <div class="video-bg">
      <img class="wallpaper" src="https://rare-gallery.com/uploads/posts/121866-sunset-landscape-summer-tuscany-italy-silhouette-red-hd-4k.png" alt="Background GIF">
    </div>
    <div class="bar-menu">
      <div style="background-color: #ec6a5e; margin-left:20px" class="cyrcle"></div>
      <div style="background-color: #f4bf4f; margin:10px" class="cyrcle"></div>
      <div style="background-color: #62c554; margin-right:10px" class="cyrcle"></div>

      

    </div>
    <div class="container">
      <div class="routers">
        <router-link to="/">Red Black Tree</router-link> 
        <router-link to="/about">Home</router-link> 
        <router-link to="/">Home</router-link> 
      </div>

      <div class="view">
        <router-view></router-view>
      </div>
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

.view{
  display: flex;
  flex:85%;
  background-color:rgba(44, 16, 41, 0.511)
  ;
  backdrop-filter: blur(10px);

}

.routers{
  flex:15%;
  display: flex;
  flex-direction: column;
  width: 100%;
  height: 100%;
  background-color: rgba(0, 0, 0, 0.511);
  margin: 0;
  backdrop-filter: blur(10px);
  text-align: center;
  

  
}
.routers a {
  text-decoration: none;
  color: rgba(255, 255, 255, 0.263);
  font-size: 20px;
  font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
  transition: color 0.3s; /* Agregamos una transición para suavizar el cambio de color en el hover */
  margin: 10px;
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
  display: flex;
  
  max-width: 100%; /* Limita el ancho máximo del contenido al 100% del contenedor */
  overflow: hidden; /* Oculta el contenido que se desborda del contenedor */
  width: 75%;
  height: 80%;
  
  border-radius: 0 0 15px 15px;
  
  
  margin: 0; /* Agrega un margen para separarlos */
}
.bar-menu {
  display: flex;
  width: 75%;
  height: 8%;
  background-color: rgba(0, 0, 0, 0.511);
  border-radius: 15px 15px 0 0;
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
