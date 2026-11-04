# Visualización de árboles rojo-negro

Proyecto académico que combina una implementación de árbol rojo-negro en C++ con una interfaz web para explorar inserción, búsqueda y eliminación. La visualización web incluye una compilación WebAssembly y una aplicación Vue.

## Estructura

- `RedBlackTreeVisualizationCode/`: implementación C++ y archivo CMake.
- `RaylibExportWeb/`: versión gráfica y recursos exportados a WebAssembly.
- `WebPage/`: aplicación Vue que integra la visualización.

## Ejecutar la web localmente

Con Node.js y npm instalados:

```bash
git clone https://github.com/Auky216/RedBlackTreeVisualization.git
cd RedBlackTreeVisualization/WebPage
npm ci
npm run dev
```

Abre la dirección que indique Vite. Para generar la web, ejecuta `npm run build` desde `WebPage/`.

## Compilar el código C++

El directorio `RedBlackTreeVisualizationCode/` contiene `CMakeLists.txt`. Requiere un compilador C++ y las dependencias gráficas que use esa configuración. La compilación WebAssembly de `WebPage/RBT/` se conserva para la demostración; no se regenera con `npm run build`.

## Alcance

Este repositorio conserva el trabajo académico original. Los enlaces a despliegues externos del README anterior no se consideran una instalación reproducible. No se ha definido una licencia de reutilización para el código y recursos de los participantes.
