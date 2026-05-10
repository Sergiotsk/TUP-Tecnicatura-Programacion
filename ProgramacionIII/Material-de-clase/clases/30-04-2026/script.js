// =========================================================================
// 1. CAPTURA DE ELEMENTOS DEL DOM (El puente entre HTML y JS)
// =========================================================================
// Acá estamos guardando en constantes (const) las referencias a los elementos 
// con los que el usuario interactúa (inputs y el botón).
const inputNombre = document.getElementById('nombre');
const inputProfesion = document.getElementById('profesion');
const inputImagen = document.getElementById('imagen');
const inputColor = document.getElementById('color');
const btnGenerar = document.getElementById('gperfil');

// Acá capturamos los elementos donde vamos a "pintar" o mostrar la información 
// que el usuario ingresó en los inputs de arriba.
const vistaNombre = document.getElementById('vista-nombre');
const vistaProfesion = document.getElementById('vista-profesion');
const vistaImagen = document.getElementById('vista-imagen');
const boxVista = document.getElementById('box-vista');

// =========================================================================
// 2. ESCUCHA DE EVENTOS (El flujo principal del script)
// =========================================================================
// addEventListener se queda "escuchando" a que ocurra un evento.
// En este caso, escucha el 'click' sobre el botón "btnGenerar".
// Cuando ese click ocurre, se ejecuta la función flecha ( () => { ... } ).
btnGenerar.addEventListener('click', () => {
    
    // a. Actualizar los textos:
    // Tomamos el `.value` (lo que escribió el usuario en el input) 
    // y se lo pasamos al `.textContent` (el texto visible) de las vistas.
    vistaNombre.textContent = inputNombre.value;
    vistaProfesion.textContent = inputProfesion.value;

    // b. Actualizar la imagen:
    // Si el usuario ingresó algo en inputImagen (si no está vacío)...
    if (inputImagen.value) {
        // ...cambiamos el atributo 'src' de la etiqueta <img>.
        vistaImagen.src = inputImagen.value;
    }

    // c. Actualizar color de fondo y texto:
    // Si el usuario eligió un color en inputColor...
    if (inputColor.value) {
        // ...modificamos el estilo CSS del contenedor para aplicarle ese color de fondo.
        boxVista.style.backgroundColor = inputColor.value;

        // --- Lógica extra para el contraste del texto ---
        // Verificamos si el color elegido empieza con ciertos valores hexadecimales (#1a o #2a).
        // Esto es un enfoque bastante rústico para saber si el fondo es "oscuro".
        const esFondoOscuro = inputColor.value.startsWith('#1a') || inputColor.value.startsWith('#2a');
        
        // Usamos un operador ternario: Si es fondo oscuro, ponemos un color claro. Si no, otro color.
        const colorTexto = esFondoOscuro ? '#daccccff' : '#caced3ff';
        
        // Finalmente, aplicamos ese color calculado al texto de nombre y profesión.
        vistaNombre.style.color = colorTexto;
        vistaProfesion.style.color = colorTexto;
    }
});
