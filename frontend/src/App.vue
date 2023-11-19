<template>
  <div class="menu">
    <div class="menu-bar">
      <div class="menu-bar__logo">
        <img src="./components/icons/icono.png" alt="logo" />
      </div>
      <div class="menu-bar__links">
        <div>
          <router-link to="/">Home</router-link>
        </div>
        <div>
          <router-link to="/rbt">Red Black Tree Simulation</router-link>
        </div>
        <div>
          <router-link to="/about">About Us</router-link>
        </div>
      </div>
    </div>
  </div>

  <div>
    <RouterView />
  </div>
</template>

<style>
.menu-bar {
  display: flex;
  background-color: #000016;
  flex-direction: column;
  justify-content: center;
  align-items: center; /* Para centrar verticalmente */
}

.menu-bar__logo img {
  width: 100px;
  height: 100px;
  padding: 10px;
}

.menu-bar__links {
  display: flex;
  flex-direction: row; /* Para alinear verticalmente */
  align-items: end; /* Para centrar horizontalmente */
  color: white;
}

.menu-bar__links a {
  text-decoration: none;
  margin: 20px;
  color:white;
  
}
.menu-bar__links div {
  background-color: white;
}
.menu-bar__links div:hover {
  background-color: #ee3939;
  box-shadow: 0 0 10px #ee3939;
}
.menu-bar__links div a {
  text-decoration: none;
  margin: 20px;
  color:black;
  margin: 40px;
}


</style>
