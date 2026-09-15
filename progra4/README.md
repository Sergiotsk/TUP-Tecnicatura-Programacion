# Mecatorc — sitio estático (Vite + TypeScript)

Réplica estática del sitio [mecatorc.com](https://www.mecatorc.com), reconstruida
sin WordPress: HTML plano + TypeScript vanilla, buildeado con Vite.

## Stack

- **Vite** en modo multi-página (MPA) — cada `.html` de la raíz es un entry point.
- **TypeScript** estricto, sin framework de UI.
- Header/footer y las grillas de producto se renderizan por JS a partir de
  datos tipados en `src/data/`, para no repetir markup en cada página.

## Cómo correr

```bash
npm install
npm run dev       # servidor de desarrollo
npm run build     # type-check (tsc -b) + build de producción a dist/
npm run preview   # sirve el build de dist/
```

## Estructura

```
index.html, torque-hidraulico.html, rotacion-continua.html,
tensionado-de-pernos.html, accesorios-para-bridado-y-remocion-de-material.html,
contacto.html         → páginas (una por sección del sitio original)

src/
  layout.ts            → header + footer + menú móvil, inyectados en
                          #app-header / #app-footer
  render-products.ts    → renderiza la grilla de productos de una categoría
  contact-form.ts       → validación tipada del formulario de contacto
  data/nav.ts           → links de navegación y teléfono de contacto
  data/products.ts      → catálogo tipado por categoría (Product[])
  pages/*.ts             → entry point de cada página (importa layout + data)
  assets/img/            → imágenes descargadas del sitio original
  style.css              → paleta, tipografía y estilos
```

## Contenido replicado

Todo el copy (textos, nav, footer) y las imágenes se extrajeron del sitio en
producción el 2026-08-18. La paleta de colores y la tipografía (Roboto /
Roboto Slab) se extrajeron de las variables CSS del tema original
(`--customify-primary: #0e7c7b`, `--customify-secondary: #c3512f`,
`--customify-accent: #ffd042`).

## Pendientes para el cliente

- **Formulario de contacto**: hoy arma un `mailto:` client-side (no hay
  backend). Reemplazar por un servicio real (Formspree, EmailJS, endpoint
  propio) en `src/contact-form.ts` cuando el cliente lo defina.
- **"Chipping Hammers"** (página de accesorios): el sitio original tiene la
  descripción sin completar (`"bla bla bla"`). Se replicó tal cual — hay que
  pedirle la copy real al cliente.
- **Imagen de contacto** (`contacto-iso.jpg`): es una ilustración de un
  operario industrial (a pesar del nombre de archivo, no es un sello ISO).
- **Crédito "Desarrollado por"**: el sitio original lo atribuye a un estudio
  externo (estudiompi); no se replicó en el footer — agregar el crédito que
  corresponda.
- Sin analytics/tracking configurado.
