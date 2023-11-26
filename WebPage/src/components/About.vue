<template>
  <div class="about">
    <h1>Integrantes</h1>
    <div>
      <p>
        Este proyecto de Algoritmo y Estructuras de Datos del ciclo 2023-2, fue desarrollado por alumnos de la Universidad de Ingeniería y Tecnología : 
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
            <p>Brigitte Dayane Perez</p>
            <p>19 años</p>
            <p>Team Python</p>
            <p>Programar</p>
        </div>
        
      </div>
    </div>

    <h1>Tecnologias Usadas</h1>

    <div class="team">
      <div class="person">
        <img class="img-profile" src="https://w7.pngwing.com/pngs/46/626/png-transparent-c-logo-the-c-programming-language-computer-icons-computer-programming-source-code-programming-miscellaneous-template-blue.png">
     
    </div>

      <div class="person">
          <img class="img-profile" src="https://upload.wikimedia.org/wikipedia/commons/f/f4/Raylib_logo.png">
      
      </div>

      <div class="person">
        <img class="img-profile" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1f/WebAssembly_Logo.svg/1200px-WebAssembly_Logo.svg.png">
     
    </div>

      <div class="person">
          <img class="img-profile" src="https://avatars.githubusercontent.com/u/6128107?s=280&v=4">
          
       
      </div>

      <div class="person">
        <img class="img-profile" src="https://a0.awsstatic.com/libra-css/images/logos/aws_logo_smile_1200x630.png">
      
    </div>
      
    </div>


    <h1>Nuestro Paper</h1>

    

    <a href="https://drive.google.com/file/d/151YRE8Xfawx8MssZsludHrjVwu7qjRBU/view?usp=sharing" download="Red-Black-Tree-Informe-2023-2.pdf">Descargar Nuestro Informe</a>

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