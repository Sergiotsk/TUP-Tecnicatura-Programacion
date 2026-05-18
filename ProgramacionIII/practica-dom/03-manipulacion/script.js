// ============================================================
// EJERCICIO 03 — CREACIÓN Y ELIMINACIÓN DE NODOS
// ============================================================
// Este es el nivel donde más gente se traba. La clave está en
// entender que crear un nodo NO lo inserta en la página.
// Tenés que crearlo y DESPUÉS insertarlo.
// Flujo: createElement → configurar → appendChild/insertAdjacentHTML
// ============================================================


// ============================================================
// A) AGREGAR ITEMS A UNA LISTA
// ============================================================
// 1. Seleccioná el input#input-item, el btn#btn-agregar y el ul#lista-items
// 2. Cuando se hace click en btn-agregar:
//    a. Leé el value del input
//    b. Si no está vacío:
//       - Creá un nuevo <li> con document.createElement('li')
//       - Asignale el textContent con el valor del input
//       - Usá appendChild para agregarlo al <ul>
//       - Limpiá el input
//    c. Si está vacío: no hacés nada

// TU CÓDIGO ACÁ:

const input = document.getElementById('input-item');
const agregar = document.getElementById('btn-agregar');
const item = document.getElementById('lista-items');



agregar.addEventListener('click', () => {
    let valor = input.value;
    if (valor != '') {
        const nuevoLi = document.createElement('li');// 1.crear
        nuevoLi.textContent = valor; //2.configurar
        item.appendChild(nuevoLi); //3. insertar en el padre
        valor = '';
    } else {
        alert('ERROR: No se ingreso NADA');
    }
});


// ============================================================
// B) LISTA DE TAREAS CON BOTÓN ELIMINAR
// ============================================================
// 1. Seleccioná input#input-tarea, btn#btn-nueva-tarea y div#contenedor-tareas
// 2. Cuando se hace click en btn-nueva-tarea:
//    a. Leé el value del input
//    b. Si no está vacío:
//       - Creá un <div> con clase "tarjeta"
//       - Dentro de la tarjeta, creá un <span> con el texto de la tarea
//       - Creá un <button> con texto "✕"
//       - Al button, agregale un addEventListener('click') que haga:
//            tarjeta.remove()   (o parentElement.remove())
//       - Apendá el span y el button a la tarjeta
//       - Apendá la tarjeta al contenedor
//       - Limpiá el input

// TU CÓDIGO ACÁ:


// ============================================================
// C) innerHTML vs textContent
// ============================================================
// Tenés dos botones. El comportamiento esperado es:
//
// btn-inner: Insertar el siguiente string en #resultado-c usando innerHTML:
//   '<strong>Texto en negrita</strong> y <em>texto en cursiva</em>'
//   → Resultado: el HTML debe renderizarse visualmente
//
// btn-text: Insertar el MISMO string usando textContent:
//   → Resultado: debe mostrarse el string literal con las etiquetas como texto plano
//
// Esto demuestra la diferencia entre los dos. Usá ambos botones y observá.

// TU CÓDIGO ACÁ:


// ============================================================
// D) CLONAR UNA TARJETA
// ============================================================
// 1. Seleccioná div#tarjeta-original, btn#btn-clonar y div#zona-clones
// 2. Cuando se hace click en btn-clonar:
//    a. Usá cloneNode(true) sobre la tarjeta original
//       (el true significa "clonar también todos los elementos internos")
//    b. Insertá el clon en #zona-clones con appendChild
//    NOTA: el botón ✕ dentro del clon ya funciona (viene del onclick inline)
//          pero si quisieras reemplazarlo con addEventListener, ¿cómo harías?

// TU CÓDIGO ACÁ:
