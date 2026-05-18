// ============================================================
// EJERCICIO 04 — ARRAYS + DOM
// ============================================================
// Este es el patrón más usado en el mundo real:
// tenés datos (array) → los transformás (map/filter) → los mostrás (DOM)
// ============================================================


// DATOS — no los modifiques
const productos = [
  { id: 1, nombre: 'Auriculares Bluetooth', precio: 350 },
  { id: 2, nombre: 'Teclado mecánico',      precio: 890 },
  { id: 3, nombre: 'Mouse inalámbrico',      precio: 420 },
  { id: 4, nombre: 'Monitor 24"',            precio: 1200 },
  { id: 5, nombre: 'Webcam HD',              precio: 280 },
  { id: 6, nombre: 'Hub USB-C',              precio: 195 },
];

const personajes = [
  { nombre: 'Luke Skywalker',  rol: 'Jedi',   img: 'https://starwars-visualguide.com/assets/img/characters/1.jpg' },
  { nombre: 'Darth Vader',     rol: 'Sith',   img: 'https://starwars-visualguide.com/assets/img/characters/4.jpg' },
  { nombre: 'Han Solo',        rol: 'Piloto', img: 'https://starwars-visualguide.com/assets/img/characters/14.jpg' },
];


// ============================================================
// A) RENDERIZAR LISTA DESDE ARRAY
// ============================================================
// 1. Seleccioná el div#lista-productos
// 2. Usá forEach (o map + join) para recorrer el array `productos`
// 3. Por cada producto, creá un div con clase "producto" que tenga:
//    - Un <span> con clase "nombre" con el nombre del producto
//    - Un <span> con clase "precio" con el texto: "$350"
// 4. Insertá cada div en el contenedor
//
// PISTA: podés usar innerHTML dentro del forEach para construir la tarjeta,
//        o bien createElement/appendChild. Elegí la que prefieras.

// TU CÓDIGO ACÁ:


// ============================================================
// B) FILTRAR Y RE-RENDERIZAR
// ============================================================
// 1. Seleccioná los tres botones y el div#lista-filtrada
// 2. Creá una función renderProductos(lista) que reciba un array
//    y muestre los productos en #lista-filtrada (igual que el ejercicio A)
// 3. Cada botón aplica un filtro diferente al array original y
//    llama a renderProductos() con el resultado:
//    - btn-todos:    renderProductos(productos)
//    - btn-baratos:  filtrá los que tienen precio < 500, luego renderizá
//    - btn-caros:    filtrá los que tienen precio >= 500, luego renderizá
//
// PISTA para filtrar: productos.filter(p => p.precio < 500)

// TU CÓDIGO ACÁ:


// ============================================================
// C) BUSCADOR EN TIEMPO REAL
// ============================================================
// 1. Seleccioná input#buscador y div#lista-busqueda
// 2. Agregá un listener para el evento 'input'
// 3. En cada keystroke, tomá el value del input (en minúsculas)
// 4. Filtrá el array `productos` buscando los nombres que INCLUYAN
//    el texto buscado (usá .toLowerCase() e .includes())
// 5. Renderizá los resultados filtrados en #lista-busqueda
//
// PISTA: 'Teclado mecánico'.toLowerCase().includes('tec') → true

// TU CÓDIGO ACÁ:


// ============================================================
// D) GALERÍA DESDE ARRAY DE OBJETOS
// ============================================================
// 1. Seleccioná el div#galeria
// 2. Usá el array `personajes` para crear las cards
// 3. Cada card debe tener:
//    - Una <img> con el src de la imagen
//    - Un <h4> con el nombre
//    - Un <p> con el rol
// 4. Insertá todas las cards en el grid #galeria
//
// PISTA: Si la imagen falla, podés reemplazar los src por cualquier
//        imagen de placeholder: https://picsum.photos/150/100?random=1

// TU CÓDIGO ACÁ:
