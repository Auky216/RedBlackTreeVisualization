<template>
  <div class="about">
    <h1>About Us</h1>
    <div>
      <p>
        Este proyecto de Algoritmo y Estructuras de Datos del ciclo 2023-2, fue desarrollado por: 
      </p>
      
      <div class="team">
        <div class="person">
            <img class="img-profile" src="./icons/adrian.jpeg">
            <p>Adrian Antonio Auqui Perez</p>
            <p>19 años</p>
            <p>Team Python</p>
            <p>Caminar y hablar</p>
        </div>

        <div class="person">
          <img class="img-profile" src="./icons/iran.png">
          <p>Irán María Alvarez Flores  </p>
          <p>19 años</p>
          <p>Team Assembler </p>
          <p>Ver peliculas y programar</p>
      </div>
      
        <div class="person">
            <img class="img-profile" src="./icons/brigit.png">
            <p>Adrian Antonio Auqui Perez</p>
            <p>19 años</p>
            <p>Team Python</p>
            <p>Programar</p>
        </div>
        
      </div>
    </div>

  </div>
</template>

<script>
export default {

}
</script>

<style>

.team{
    display: flex;
    flex-direction: row;
    justify-content: center;
    align-items: center;
    margin : 10px;
    
}

.about {
  margin: 10px;
}

.img-profile{
    width: 200px;
    height: 200px;
    border-radius: 20%;
    margin: 20px;
}
.person {
    border: 5px solid #000;
    margin: 10px;
    transition: all 0.3s ease; /* Transición suave para todos los cambios */
    position: relative; /* Para efecto de superposición */
    text-align: center;
}

.person:hover {
    border-color: #ee3939; /* Cambio del color del borde a rojo */
    transform: scale(1.1); /* Aumentar tamaño en el hover */
    z-index: 1; /* Para superposición */
    box-shadow: 0 0 10px #ee3939; /* Sombra al hacer hover */
    text-align: center;
}



</style>