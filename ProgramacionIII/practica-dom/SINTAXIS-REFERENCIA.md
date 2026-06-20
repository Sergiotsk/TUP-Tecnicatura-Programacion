# Referencia Rápida de Sintaxis DOM

Usá esta hoja como **último recurso**, después de intentar escribirlo de memoria.

---

## Selectores

```js
document.getElementById('mi-id')
document.querySelector('.mi-clase')      // solo el primero
document.querySelector('#mi-id')
document.querySelectorAll('li')          // todos → NodeList
```

## Leer y escribir contenido

```js
elemento.textContent = 'texto plano'     // solo texto, sin HTML
elemento.innerHTML   = '<b>negrita</b>'  // interpreta HTML
input.value                              // leer lo que escribió el usuario
input.value = ''                         // limpiar el input
```

## Estilos y clases

```js
elemento.style.color           = 'red'
elemento.style.backgroundColor = '#fff'
elemento.style.display         = 'none'    // ocultar
elemento.style.display         = 'block'   // mostrar

elemento.classList.add('activo')
elemento.classList.remove('activo')
elemento.classList.toggle('activo')
elemento.classList.contains('activo')  // → true/false
```

## Atributos

```js
elemento.getAttribute('src')
elemento.setAttribute('src', 'nueva-url.jpg')
elemento.removeAttribute('disabled')
```

## Crear e insertar nodos

```js
const nuevo = document.createElement('div')
nuevo.textContent = 'Hola'
nuevo.classList.add('tarjeta')

padre.appendChild(nuevo)                       // al final
padre.insertBefore(nuevo, referencia)          // antes de otro

// Alternativa rápida con HTML string:
padre.insertAdjacentHTML('beforeend', '<li>Item</li>')
```

## Eliminar nodos

```js
elemento.remove()                   // el más simple
padre.removeChild(hijo)             // viejo estilo
```

## Clonar

```js
const clon = original.cloneNode(true)   // true = copia profunda (con hijos)
padre.appendChild(clon)
```

## Eventos

```js
btn.addEventListener('click', function() { ... })
btn.addEventListener('click', () => { ... })        // arrow function

input.addEventListener('input', (e) => {            // en tiempo real
  console.log(e.target.value)
})

form.addEventListener('submit', (e) => {
  e.preventDefault()    // ← SIEMPRE en forms para no recargar la página
})

elemento.addEventListener('change', (e) => { ... })   // select, checkbox
elemento.addEventListener('mouseover', () => { ... })
elemento.addEventListener('mouseout',  () => { ... })
```

## Arrays más usados con DOM

```js
// forEach — recorrer sin devolver nada
array.forEach(item => {
  contenedor.innerHTML += `<li>${item}</li>`
})

// map — transformar cada elemento
const html = array.map(item => `<li>${item}</li>`).join('')
contenedor.innerHTML = html

// filter — quedarse con los que cumplen una condición
const resultado = array.filter(item => item.precio < 500)

// find — encontrar el primero que cumple
const encontrado = array.find(item => item.id === 3)

// includes — verificar si un string contiene otro
'Teclado mecánico'.toLowerCase().includes('tec')  // → true
```

---

## El flujo más común (memorizalo)

```
1. Seleccionar elementos del DOM
2. Escuchar evento (click, input, submit...)
3. Leer datos (input.value, array...)
4. Transformar datos (filter, map...)
5. Renderizar en el DOM (innerHTML, appendChild...)
```
