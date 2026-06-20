// ============================================================
// EJERCICIO 01 — SELECTORES DEL DOM
// ============================================================
// INSTRUCCIONES: Completá cada función SIN mirar apuntes primero.
// Si no recordás la sintaxis, intentá primero. Después consultá.
// Objetivo: que la sintaxis se automatice con la repetición.
// ============================================================


// A) Usá getElementById para seleccionar el elemento con id "parrafo-a"
//    y cambiá su textContent a "¡Texto cambiado con getElementById!"
function ejercicioA() {

  document.getElementById("parrafo-a").textContent = "¡Texto cambiado con getElementById!";


}

// B) Usá querySelector para seleccionar el PRIMER elemento con clase "mensaje"
//    y agregale la clase CSS "resaltado"
function ejercicioB() {
  document.querySelector('.mensaje').classList.add('resaltado');
}


// C) Usá querySelectorAll para seleccionar TODOS los <li> dentro de #lista-c
//    Recorrelos con forEach y a cada uno cambiále el style.color a "blue"
function ejercicioC() {
  // TU CÓDIGO ACÁ:
  document.querySelectorAll('#lista-c').forEach(li => {
    li.style.color = 'blue';
  });

}


// D) Usá getElementById para obtener la imagen con id "imagen-d"
//    Luego usá setAttribute para cambiar el atributo "src" a: https://placecats.com/200/150?cat=2
//    Y cambiá también el atributo "alt" a "Gato 2"
function ejercicioD() {
  // TU CÓDIGO ACÁ:
  const img = document.getElementById('imagen-d');
  img.setAttribute('src', 'https://placecats.com/200/150?cat=2');
  img.setAttribute('alt', 'gato 2')

}


// E) Usá getElementById para obtener el elemento con id "parrafo-e"
//    Usá classList.toggle para alternar la clase "resaltado" cada vez que se hace click
function ejercicioE() {
  // TU CÓDIGO ACÁ:

  document.getElementById('parrafo-e').classList.toggle('resaltado');

}
