const inputNombre = document.getElementById('nombre');
const inputProfesion = document.getElementById('profesion');
const inputImagen = document.getElementById('imagen');
const inputColor = document.getElementById('color');
const btnGenerar = document.getElementById('gperfil');
const vistaNombre = document.getElementById('vista-nombre');
const vistaProfesion = document.getElementById('vista-profesion');
const vistaImagen = document.getElementById('vista-imagen');
const boxVista = document.getElementById('box-vista');

// Evento click en el botón "Generar Perfil"
btnGenerar.addEventListener('click', () => {
    // Actualizar nombre
    vistaNombre.textContent = inputNombre.value;

    // Actualizar profesión
    vistaProfesion.textContent = inputProfesion.value;

    // Actualizar imagen
    if (inputImagen.value) {
        vistaImagen.src = inputImagen.value;
    }

    // Actualizar color de fondo
    if (inputColor.value) {
        boxVista.style.backgroundColor = inputColor.value;

        // Cambiar color de texto para fondos oscuros
        const esFondoOscuro = inputColor.value.startsWith('#1a') || inputColor.value.startsWith('#2a');
        const colorTexto = esFondoOscuro ? '#daccccff' : '#caced3ff';
        vistaNombre.style.color = colorTexto;
        vistaProfesion.style.color = colorTexto;
    }
});
