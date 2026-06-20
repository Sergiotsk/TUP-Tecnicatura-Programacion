// ============================================================
// EJERCICIO 02 — EVENTOS
// ============================================================
// INSTRUCCIONES: Completá cada sección SIN copiar y pegar.
// Escribí la sintaxis de memoria. Si te trabás, intentá 5 min
// antes de consultar apuntes.
// ============================================================


// ============================================================
// A) CONTADOR
// ============================================================
// 1. Seleccioná los tres botones y el div#contador con getElementById
// 2. Guardá el valor del contador en una variable (empieza en 0)
// 3. Agregá addEventListener('click', ...) a cada botón:
//    - btn-sumar: incrementa el contador y actualiza el textContent
//    - btn-restar: decrementa el contador y actualiza el textContent
//    - btn-reset: vuelve el contador a 0 y actualiza el textContent

// TU CÓDIGO ACÁ:
const displayContador = document.getElementById('contador');
const sumar = document.getElementById('btn-sumar');
const restar = document.getElementById('btn-restar');
const reset = document.getElementById('btn-reset');
let cuenta = 0;

sumar.addEventListener('click', () => {
    cuenta++;
    displayContador.textContent = cuenta;
})

restar.addEventListener('click', () => {

    cuenta--;
    displayContador.textContent = cuenta;

})
reset.addEventListener('click', () => {

    cuenta = 0;
    displayContador.textContent = cuenta;

})
// ============================================================
// B) PREVIEW EN TIEMPO REAL
// ============================================================
// 1. Seleccioná el input#input-nombre y el p#preview
// 2. Agregá un addEventListener con el evento 'input' al input
// 3. Dentro del listener, actualizá el textContent del #preview
//    para que muestre: "Hola, [lo que escribió el usuario]"

// TU CÓDIGO ACÁ:

const nombre = document.getElementById('input-nombre');
const preview = document.getElementById('preview');


nombre.addEventListener('input', () => {

    preview.textContent = `Hola,${nombre.value}`;

})


// ============================================================
// C) FORMULARIO SIN RECARGAR
// ============================================================
// 1. Seleccioná el form#mi-form, el input#input-tarea y el p#resultado-form
// 2. Agregá addEventListener('submit', ...) al formulario
// 3. Dentro del listener:
//    a. Usá event.preventDefault() para que no recargue la página
//    b. Leé el value del input y guardalo en una variable
//    c. Si no está vacío, mostrá en #resultado-form: 'Tarea agregada: "[la tarea]"'
//    d. Limpiá el input (ponele value = "")

// TU CÓDIGO ACÁ:

const form = document.getElementById('mi-form');
const tarea = document.getElementById('input-tarea');
const resultado = document.getElementById('resultado-form');

form.addEventListener('submit', (e) => {
    e.preventDefault();
    if (tarea.value !== '') {
        resultado.textContent = `Tarea agregada,${tarea.value}`;
        tarea.value = '';
    } else {
        alert('el input esta vacio');
    }
})


// ============================================================
// D) CAMBIO DE COLOR CON SELECT
// ============================================================
// 1. Seleccioná el select#selector-color y el div#caja-color
// 2. Agregá addEventListener con el evento 'change'
// 3. Cuando cambia el select, actualizá el backgroundColor de #caja-color
//    con el value del select (si está vacío, dejalo en #ddd)

// TU CÓDIGO ACÁ:

const selector = document.getElementById('selector-color');
const caja = document.getElementById('caja-color');

selector.addEventListener('change', () => {

    switch (selector.value) {
        case 'tomato':
            caja.style.backgroundColor = '#ff0000';
            break;
        case 'steelblue':
            caja.style.backgroundColor = '#112fdaff';
            break;
        case 'mediumseagreen':
            caja.style.backgroundColor = '#0beb0bff';
            break;
        case 'goldenrod':
            caja.style.backgroundColor = 'yellow';
            break;
        default:
            caja.style.backgroundColor = '  #074955ff ';
            break;
    }
})

// ============================================================
// E) EFECTO HOVER CON JS (sin CSS :hover)
// ============================================================
// 1. Seleccioná el div#hover-box
// 2. Agregá un listener para 'mouseover': cambiá el background a "#4a90d9"
//    y el color del texto a "white"
// 3. Agregá un listener para 'mouseout': volvé al background "#c0c0c0"
//    y el color del texto a "" (vacío, para quitar el estilo inline)

// TU CÓDIGO ACÁ:

const box = document.getElementById('hover-box');


box.addEventListener('mouseover', () => {

    box.style.backgroundColor = '#4a90d9';
    box.style.color = '#c0c0c0';

})
box.addEventListener('mouseout', () => {

    box.style.backgroundColor = '#c0c0c0';
    box.style.color = '';

})