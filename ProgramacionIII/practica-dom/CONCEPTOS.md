# Conceptos clave — DOM y Eventos

Notas basadas en los errores más comunes al empezar con JavaScript y el DOM.

---

## 1. El parámetro `e` en addEventListener — ¿cuándo va y cuándo no?

`addEventListener` ejecuta una función cuando ocurre un evento. Esa función **recibe automáticamente un objeto** con información sobre el evento que pasó. Ese objeto se llama por convención `e` o `event`.

```js
elemento.addEventListener('click', (e) => {
    console.log(e);  // objeto con toda la info del evento
});
```

### ¿Cuándo lo necesitás?

Solo cuando necesitás **usar información del evento** adentro de la función.

| Situación | ¿Necesitás `e`? | Por qué |
|-----------|-----------------|---------|
| `submit` de un formulario | **Sí** | Necesitás `e.preventDefault()` para que no recargue la página |
| Saber en qué elemento hiciste click | **Sí** | `e.target` te da el elemento clickeado |
| `click` simple en un botón | No | No necesitás info del evento, solo que ocurrió |
| `input` leyendo el valor con `element.value` | No | Ya leés el valor directo del elemento |

### Ejemplos de tu código

```js
// No necesita e — solo le importa que ocurrió el click
sumar.addEventListener('click', () => {
    cuenta++;
    displayContador.textContent = cuenta;
});

// SÍ necesita e — hay que cancelar el comportamiento por defecto del form
form.addEventListener('submit', (e) => {
    e.preventDefault();  // sin esto, la página se recarga
});
```

### ¿Qué pasa si no lo declarás pero lo usás?

```js
form.addEventListener('submit', () => {
    Event.preventDefault();  // ERROR — Event (mayúscula) es una clase, no el objeto del evento
});
```

`Event` (con mayúscula) es una clase del navegador. El objeto del evento que te llega en tu función es una instancia de esa clase, pero tenés que recibirlo en el parámetro con el nombre que vos le pongas (`e`, `event`, lo que sea).

---

## 2. Elemento del DOM vs dato — no confundas los dos

Este fue el error más repetido. Cuando hacés `getElementById`, obtenés una referencia al **elemento HTML**, no al dato que contiene.

```js
const displayContador = document.getElementById('contador');
// displayContador es el <div id="contador"> — un nodo del DOM

let cuenta = 0;
// cuenta es el número — el dato
```

Son cosas completamente distintas. El elemento **muestra** el dato, pero no **es** el dato.

```js
// Para leer el número: usá la variable
if (cuenta > 0) { ... }

// Para mostrarlo en la página: usá el elemento
displayContador.textContent = cuenta;
```

### El caso de los inputs

Con un `<input>`, el **elemento** es el input HTML, y el **dato** (lo que escribió el usuario) está en `.value`:

```js
const inputNombre = document.getElementById('input-nombre');

inputNombre          // el elemento <input> del DOM
inputNombre.value    // el texto que escribió el usuario
```

Por eso comparás así:
```js
if (inputNombre.value !== '') { ... }   // correcto
if (inputNombre !== '')        { ... }  // incorrecto — comparás el elemento con un string
```

---

## 3. `const` vs `let` — cuándo usar cada uno

```js
const displayContador = document.getElementById('contador');
// const: la referencia al elemento NUNCA cambia — siempre va a ser ese <div>

let cuenta = 0;
// let: el número SÍ cambia — suma, resta, reset
```

La regla práctica:
- **`const`** para referencias a elementos del DOM — nunca vas a reasignarlos
- **`let`** para datos que cambian (contadores, flags, strings que se actualizan)

Error típico:
```js
const contador = document.getElementById('contador');
contador = 0;  // ERROR — no podés reasignar una const
```

---

## 4. Los selectores y su sintaxis

JavaScript es **case sensitive** — una letra en mayúscula o minúscula cambia todo.

```js
document.getElementById('mi-id')       // correcto
Document.getelementbyid('mi-id')       // error — no existe nada de esto
```

Los selectores de CSS dentro de `querySelector` siguen las mismas reglas que CSS:

```js
document.querySelector('#mi-id')       // por id — con #
document.querySelector('.mi-clase')    // por clase — con .
document.querySelector('li')           // por etiqueta — sin prefijo
document.querySelector('#lista li')    // li dentro de #lista
```

`querySelectorAll` devuelve **todos** los que coincidan (como una lista), `querySelector` devuelve solo **el primero**.

---

## 5. innerHTML vs textContent

```js
elemento.innerHTML   = '<strong>negrita</strong>'  // interpreta el HTML → muestra en negrita
elemento.textContent = '<strong>negrita</strong>'  // texto plano → muestra las etiquetas literales
```

Regla práctica:
- `textContent` cuando mostrás texto del usuario (más seguro — no ejecuta HTML)
- `innerHTML` cuando construís HTML desde tu código (strings de etiquetas que vos armás)

---

## 6. Template literals — la sintaxis exacta

```js
// Comillas simples o dobles: NO interpretan variables
'Hola, ${nombre}'        // muestra literalmente: Hola, ${nombre}
"Hola, ${nombre}"        // ídem

// Backticks: SÍ interpretan variables
`Hola, ${nombre.value}`  // muestra: Hola, Juan  (o lo que haya en el input)
```

El backtick está en la tecla a la izquierda del `1` en el teclado (junto al `~` en teclado en inglés, o debajo del `Esc` en algunos).

---

## 7. El flujo que se repite siempre

```
1. Seleccionar elementos del DOM (getElementById, querySelector)
2. Escuchar evento (addEventListener)
3. Dentro del listener:
   a. Leer datos (input.value, variable numérica...)
   b. Transformar o validar (if, filter, map...)
   c. Actualizar el DOM (textContent, innerHTML, style...)
```

Todo el JavaScript de interfaz sigue este patrón. Cuando no sabés por dónde empezar, escribí estos tres pasos como comentarios y completá uno por uno.
