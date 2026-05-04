# Eventos en JavaScript

## addEventListener

Permite escuchar eventos en elementos HTML.

```javascript
elemento.addEventListener('evento', (e) => {
    // código a ejecutar
});
```

## Tipos de eventos

| Evento | Cuándo se dispara |
|--------|-------------------|
| `input` | **Mientras escribís** (tiempo real) |
| `change` | Cuando terminás y dejás el campo |
| `click` | Cuando hacés clic |
| `submit` | Cuando se envía un formulario |

## Objeto Evento (e)

| Propiedad | Descripción |
|-----------|-------------|
| `e.target` | El elemento que disparó el evento |
| `e.target.value` | El valor del elemento (para inputs) |
| `e.target.files` | Archivos seleccionados (para input type="file") |

## Ejemplo: Vista previa en tiempo real

```javascript
// Capturar elementos
const inputNombre = document.getElementById('nombre');
const vistaNombre = document.getElementById('vista-nombre');

// Escuchar mientras escribe
inputNombre.addEventListener('input', (e) => {
    vistaNombre.textContent = e.target.value;
});
```

## Ejemplo: Cargar imagen desde PC

```javascript
inputImagen.addEventListener('change', (e) => {
    const file = e.target.files[0];
    if (file) {
        const reader = new FileReader();
        reader.onload = (event) => {
            vistaImagen.src = event.target.result;
        };
        reader.readAsDataURL(file);
    }
});
```

## Concepto clave

> `addEventListener` = "escuchar" + "responder"
>
> No consulta el valor, **espera** a que el usuario haga algo y entonces reacciona.

## Fecha: 30-04-2026
## Tema: Simulador de Perfil Profesional - DOM y Eventos