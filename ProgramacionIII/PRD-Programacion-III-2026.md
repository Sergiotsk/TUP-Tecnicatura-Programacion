# PRD — Programación III · TUP 2026

**Autor:** Sergio (Sergiotsk) · Estudiante TUP · Electricista · PC Técnico · Argentina  
**Fecha:** Abril 2026  
**Tipo:** materia  
**Opción:** B — materia con programa oficial (PDF adjunto procesado)  
**Objetivo final:** Aprobar Programación III con 6 o más puntos en ambos parciales, dominando el stack completo: HTML/CSS/JS → PHP/REST → Docker/Nginx → React Native  
**Tiempo disponible:** 30–45 min/día de estudio autónomo + 8 hs semanales de clase  
**Duración estimada:** 32 clases · cuatrimestre 2026  
**Agente recomendado:** Claude Code (acceso a archivos) o ChatGPT web (solo contenido)  
**Docente:** Lic. Osvaldo Cantone · UTN HAEDO  
**Entorno:** Windows 11 Pro · ASUS ROG Strix · Ryzen 7 · 16GB RAM · Docker Desktop + WSL2  

**Fuentes verificadas:**
- [ ] Context7 disponible y activo
- [ ] Web search habilitado
- [ ] MDN Web Docs verificada: https://developer.mozilla.org/
- [ ] Docker Docs verificada: https://docs.docker.com/
- [ ] React Native Docs verificada: https://reactnative.dev/docs/getting-started
- [ ] NotebookLM cargado con bibliografía obligatoria

---

## 1. Visión general

Programación III es la materia bisagra de la TUP: integra frontend, backend, infraestructura y mobile en un stack completo. El aprendizaje es 100% orientado a construir — cada unidad produce algo funcional que se acumula hasta el proyecto integrador final. El estudio autónomo complementa las 8 hs semanales de clase con sesiones cortas de repaso, práctica y consulta a NotebookLM.

---

## 2. Objetivos medibles

| # | Objetivo | Criterio de éxito |
|---|---|---|
| 1 | Dominar HTML/CSS semántico y responsive | Página funcional con flex/grid que pasa en mobile y desktop |
| 2 | Programar en JavaScript con DOM y async | Formulario con validación + consumo de API pública funcionando |
| 3 | Desarrollar backend PHP con CRUD y API REST | Endpoints JSON operativos con operaciones create/read/update/delete |
| 4 | Integrar frontend y backend | App completa funcionando end-to-end |
| 5 | Levantar entorno con Nginx + Docker Compose | Stack corriendo en contenedores con `docker compose up` |
| 6 | Construir app mobile básica en React Native | App que consume la API REST propia desde el teléfono |
| 7 | Aprobar ambos parciales | Nota ≥ 6 en Parcial 1 (clase 12) y Parcial 2 (clase 30) |

---

## 3. Stack / herramientas / materiales

### Principal
- HTML5, CSS3 (Flex, Grid, Responsive)
- JavaScript (DOM, Fetch, async/await)
- PHP (formularios, CRUD, API REST)
- Nginx, Docker, Docker Compose
- React Native

### Complementario
- VS Code como editor principal
- Postman o Thunder Client para probar endpoints
- Android Studio / Expo Go para mobile
- Git para versionar los trabajos prácticos

### Bibliografía obligatoria
| Título | Fuente |
|---|---|
| El gran libro de HTML5, CSS3 y Javascript — Gauchat | NotebookLM |
| MDN Web Docs (HTML, CSS, JS) | https://developer.mozilla.org/ |
| Docker Documentation | https://docs.docker.com/ |
| React Native Documentation | https://reactnative.dev/docs/getting-started |

### NotebookLM
Subir a NotebookLM antes de arrancar:
- PDF del programa oficial (ya disponible)
- "El gran libro de HTML5, CSS3 y Javascript" — Gauchat (si tenés el PDF)
- Apuntes o slides que el docente comparta durante la cursada

### Agente IA para este PRD
- **Agente:** Claude Code para crear estructura + archivos · ChatGPT/Claude web para dudas conceptuales
- **Por qué:** Claude Code crea las notas en Obsidian y el código en el repo. NotebookLM responde consultas sobre la bibliografía cargada.
- **Limitaciones:** No usar memoria del modelo para explicaciones técnicas — anclar siempre en MDN, docs oficiales o NotebookLM

---

## 4. Fases de aprendizaje

> Las fases respetan el orden del cronograma oficial (32 clases).
> Cada clase = 4 hs presenciales. El estudio autónomo es complementario entre clases.

---

### FASE 1 — Fundamentos de la Web y Frontend (Clases 1–6 · Unidad 1)
**Meta:** Entender la arquitectura web y construir páginas HTML/CSS responsivas.  
**Parcial cubierto:** Base del Parcial 1

#### Clases 1–2 — Arquitectura cliente–servidor y HTTP
- Concepto: cliente, servidor, request/response, métodos HTTP (GET, POST, PUT, DELETE), códigos de estado
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Web/HTTP/Overview
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"Explicame la diferencia entre cliente y servidor con un ejemplo cotidiano"*
  - *"¿Qué pasa paso a paso cuando escribo una URL en el navegador?"*
  - *"¿Cuáles son los métodos HTTP más usados y para qué sirve cada uno?"*
- 🗒️ **Nota Obsidian:** crear `teoria/U1-T1-arquitectura-cliente-servidor.md`

#### Clases 3–4 — HTML estructura, semántica y formularios
- Concepto: estructura base, etiquetas semánticas (header, main, section, article, footer), formularios y tipos de input
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Learn/HTML/Introduction_to_HTML
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Learn/Forms
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Qué diferencia hay entre etiquetas semánticas y no semánticas en HTML5?"*
  - *"¿Cuáles son los atributos más importantes de un formulario HTML?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-01/clase-03/index.html`
- 🗒️ **Nota Obsidian:** crear `teoria/U1-T2-html-semantica-formularios.md`

#### Clases 5–6 — CSS layout y responsive design
- Concepto: Flexbox, CSS Grid, media queries, mobile-first
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Learn/CSS/CSS_layout/Flexbox
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Learn/CSS/CSS_layout/Grids
- 🎥 **Ver:** búsqueda sugerida en YouTube: *"CSS Flexbox vs Grid en español 2024"*
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Cuándo conviene usar Flexbox y cuándo Grid?"*
  - *"¿Cómo funciona mobile-first en CSS?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-01/clase-05/styles.css`
- 🗒️ **Nota Obsidian:** crear `teoria/U1-T3-css-layout-responsive.md`

---

### FASE 2 — Programación con JavaScript (Clases 7–11 · Unidad 2)
**Meta:** Manipular el DOM, validar formularios y consumir APIs con fetch.  
**Parcial cubierto:** Núcleo del Parcial 1

#### Clases 7–8 — Sintaxis, variables, control de flujo, funciones y eventos
- Concepto: let/const/var, tipos de datos, if/else/switch, for/while, funciones, addEventListener
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Learn/JavaScript/First_steps
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Learn/JavaScript/Building_blocks/Events
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Cuál es la diferencia entre let, const y var en JavaScript?"*
  - *"¿Cómo funciona addEventListener y para qué sirve?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-02/clase-07/script.js`
- 🗒️ **Nota Obsidian:** crear `teoria/U2-T1-javascript-fundamentos.md`

#### Clase 9 — DOM y validación de formularios
- Concepto: querySelector, getElementById, innerHTML, classList, validación con JS
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Web/API/Document_Object_Model/Introduction
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Qué es el DOM y cómo lo manipula JavaScript?"*
  - *"¿Cómo valido un formulario con JavaScript sin librerías?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-02/clase-09/formulario.html`
- 🗒️ **Nota Obsidian:** crear `teoria/U2-T2-dom-validacion.md`

#### Clases 10–11 — Fetch, asincronismo y consumo de APIs
- Concepto: async/await, fetch, Promises, manejo de errores, consumo de API pública
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Web/API/Fetch_API/Using_Fetch
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Learn/JavaScript/Asynchronous
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Qué es async/await y cómo simplifica el uso de Promises?"*
  - *"¿Cómo manejo errores en un fetch de JavaScript?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-02/clase-10/api.js`
- 🗒️ **Nota Obsidian:** crear `teoria/U2-T3-fetch-asincronismo.md`

---

### ⚠️ PARCIAL 1 — Clase 12
**Contenido evaluado:** Unidades 1 y 2 completas (HTML/CSS/JS/DOM/Fetch)  
**Modalidad:** Presencial, escrita e individual, resolución de problemas / código funcional  
**Nota mínima para promoción directa:** 6  
**Recuperatorio:** Clase 18  

**Preparación sugerida la semana previa:**
- Repasar todas las notas de teoría de U1 y U2 en Obsidian
- 🤖 **NotebookLM — prompts de repaso:**
  - *"Haceme 5 preguntas conceptuales sobre HTTP y arquitectura web"*
  - *"Describí el flujo completo de un formulario HTML validado con JS que hace un fetch a una API"*
  - *"¿Cuáles son los errores más comunes con async/await?"*

---

### FASE 3 — Backend y Servicios Web (Clases 13–17 · Unidad 3)
**Meta:** Construir un backend PHP con CRUD completo y API REST funcional.  
**Parcial cubierto:** Base del Parcial 2

#### Clases 13–14 — PHP, formularios y CRUD
- Concepto: sintaxis PHP, variables, $_GET/$_POST, conexión a BD, SELECT/INSERT/UPDATE/DELETE
- 📖 **Leer:** https://www.php.net/manual/es/getting-started.php
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Cuál es la diferencia entre $_GET y $_POST en PHP?"*
  - *"¿Cómo hago un CRUD básico en PHP con MySQL?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-03/clase-13/`
- 🗒️ **Nota Obsidian:** crear `teoria/U3-T1-php-crud.md`

#### Clases 15–17 — API REST, JSON, endpoints e integración
- Concepto: qué es REST, verbos HTTP en una API, respuestas JSON, integrar el frontend al backend
- 📖 **Leer:** https://developer.mozilla.org/es/docs/Glossary/REST
- 📖 **Leer:** https://www.json.org/json-es.html
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Qué hace que una API sea RESTful?"*
  - *"¿Cómo estructuro una respuesta JSON correcta desde PHP?"*
  - *"¿Cómo conecta el fetch del frontend con un endpoint PHP del backend?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-03/clase-15/api/`
- 🗒️ **Nota Obsidian:** crear `teoria/U3-T2-api-rest-json.md` y `teoria/U3-T3-integracion-frontend-backend.md`

---

### FASE 4 — Infraestructura y Despliegue (Clases 19–22 · Unidad 4)
**Meta:** Levantar el stack completo en contenedores Docker con Nginx.

#### Clase 19 — Nginx
- Concepto: qué es un servidor web, configuración básica de Nginx, virtual hosts
- 📖 **Leer:** https://nginx.org/en/docs/beginners_guide.html
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Qué hace Nginx y en qué se diferencia de Apache?"*
  - *"¿Qué es un virtual host en Nginx?"*
- 🗒️ **Nota Obsidian:** crear `teoria/U4-T1-nginx.md`

#### Clases 20–21 — Docker y Docker Compose
- Concepto: imagen, contenedor, volumen, red, docker-compose.yml
- 📖 **Leer:** https://docs.docker.com/get-started/
- 📖 **Leer:** https://docs.docker.com/compose/
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Cuál es la diferencia entre una imagen y un contenedor en Docker?"*
  - *"¿Qué ventaja tiene Docker Compose frente a correr contenedores individuales?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-04/clase-20/docker-compose.yml`
- 🗒️ **Nota Obsidian:** crear `teoria/U4-T2-docker-compose.md`

#### Clase 22 — Deploy de aplicación
- Concepto: levantar la app completa (Nginx + PHP + MySQL) en contenedores
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-04/clase-22/stack-completo/`
- 🗒️ **Nota Obsidian:** crear `teoria/U4-T3-deploy.md`

---

### FASE 5 — Desarrollo Mobile con React Native (Clases 23–29 · Unidad 5)
**Meta:** Construir una app mobile que consuma la API REST propia.  
**Parcial cubierto:** Cierre del Parcial 2

#### Clases 23–24 — Intro React Native y componentes
- Concepto: diferencia con React web, componentes básicos (View, Text, TextInput, Button), StyleSheet
- 📖 **Leer:** https://reactnative.dev/docs/getting-started
- 📖 **Leer:** https://reactnative.dev/docs/components-and-apis
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿En qué se diferencia React Native de React para web?"*
  - *"¿Cuáles son los componentes más básicos de React Native?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-05/clase-23/`
- 🗒️ **Nota Obsidian:** crear `teoria/U5-T1-react-native-intro.md`

#### Clases 25–26 — Navegación, estado y eventos
- Concepto: React Navigation, useState, useEffect, manejo de eventos touch
- 📖 **Leer:** https://reactnavigation.org/docs/getting-started
- 📖 **Leer:** https://reactnative.dev/docs/state
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Cómo funciona useState en React Native?"*
  - *"¿Qué es React Navigation y cómo se instala?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-05/clase-25/`
- 🗒️ **Nota Obsidian:** crear `teoria/U5-T2-navegacion-estado.md`

#### Clases 27–29 — Consumo de API y app completa
- Concepto: fetch desde mobile, integración con el backend PHP, app integrada
- 📖 **Leer:** https://reactnative.dev/docs/network
- 🤖 **NotebookLM — prompts sugeridos:**
  - *"¿Cómo hago un fetch a mi propia API REST desde React Native?"*
  - *"¿Qué problemas comunes hay al conectar React Native con un backend local?"*
- 💾 **Práctica:** `TUP-REPO/ProgramacionIII/unidad-05/clase-27/app-completa/`
- 🗒️ **Nota Obsidian:** crear `teoria/U5-T3-consumo-api-mobile.md`

---

### ⚠️ PARCIAL 2 — Clase 30
**Contenido evaluado:** Unidades 3, 4 y 5 (PHP/REST/Docker/React Native)  
**Modalidad:** Presencial, escrita e individual  
**Nota mínima:** 6  
**Recuperatorio:** Clase 31  

**Preparación sugerida la semana previa:**
- 🤖 **NotebookLM — prompts de repaso:**
  - *"Describí el flujo completo de una app con frontend JS, backend PHP en Docker y app mobile en React Native"*
  - *"¿Cuáles son los conceptos clave de Docker Compose que debo dominar para el parcial?"*
  - *"Haceme 5 preguntas de examen sobre API REST y JSON"*

---

## 5. Recursos de aprendizaje

| Recurso | URL | Unidades |
|---|---|---|
| MDN Web Docs | https://developer.mozilla.org/ | 1, 2, 3 |
| PHP Manual oficial | https://www.php.net/manual/es/ | 3 |
| Docker Docs | https://docs.docker.com/ | 4 |
| React Native Docs | https://reactnative.dev/docs/getting-started | 5 |
| React Navigation | https://reactnavigation.org/docs/getting-started | 5 |
| NotebookLM | Vault personal con bibliografía cargada | Todas |

---

## 6. Archivos de referencia

### docker-compose.yml de la materia (Unidad 4)

```
TUP-REPO/ProgramacionIII/unidad-04/clase-20/
├── docker-compose.yml
├── .env
└── .gitignore
```

```yaml
version: '3.8'
services:
  nginx:
    image: nginx:alpine
    ports:
      - "8080:80"
    volumes:
      - ./nginx.conf:/etc/nginx/conf.d/default.conf
      - ./src:/var/www/html
    depends_on:
      - php

  php:
    image: php:8.2-fpm
    volumes:
      - ./src:/var/www/html
    depends_on:
      - mysql

  mysql:
    image: mysql:8
    environment:
      - MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}
      - MYSQL_DATABASE=${MYSQL_DATABASE}
      - MYSQL_USER=${MYSQL_USER}
      - MYSQL_PASSWORD=${MYSQL_PASSWORD}
    volumes:
      - mysql_data:/var/lib/mysql

volumes:
  mysql_data:
```

```env
# .env — no subir a Git
MYSQL_ROOT_PASSWORD=cambia_esta_password
MYSQL_DATABASE=prog3_db
MYSQL_USER=prog3_user
MYSQL_PASSWORD=cambia_esta_password
```

---

## 7. Criterios de finalización

- [ ] Aprobé el Parcial 1 con nota ≥ 6 (clase 12)
- [ ] Aprobé el Parcial 2 con nota ≥ 6 (clase 30)
- [ ] Tengo una página HTML/CSS responsive funcionando
- [ ] Tengo un formulario JS con validación y fetch a API pública
- [ ] Tengo un CRUD PHP con API REST y respuestas JSON
- [ ] Tengo el stack completo corriendo en Docker Compose
- [ ] Tengo una app React Native consumiendo mi API
- [ ] Cumplí con el 75% de asistencia (mínimo 24 clases de 32)

---

## 8. Second Brain en Obsidian

### Path del vault
```
E:\SERJITO\SB_Sergio\
```

### Ubicación del proyecto en PARA
```
E:\SERJITO\SB_Sergio\10-Proyectos\TUP-Materias\ProgramacionIII\
├── 00-Dashboard.md
├── teoria/
│   ├── U1-T1-arquitectura-cliente-servidor.md
│   ├── U1-T2-html-semantica-formularios.md
│   ├── U1-T3-css-layout-responsive.md
│   ├── U2-T1-javascript-fundamentos.md
│   ├── U2-T2-dom-validacion.md
│   ├── U2-T3-fetch-asincronismo.md
│   ├── U3-T1-php-crud.md
│   ├── U3-T2-api-rest-json.md
│   ├── U3-T3-integracion-frontend-backend.md
│   ├── U4-T1-nginx.md
│   ├── U4-T2-docker-compose.md
│   ├── U4-T3-deploy.md
│   ├── U5-T1-react-native-intro.md
│   ├── U5-T2-navegacion-estado.md
│   └── U5-T3-consumo-api-mobile.md
├── practicas/
│   ├── P1-pagina-html-css.md
│   ├── P2-formulario-js-fetch.md
│   ├── P3-crud-php-rest.md
│   ├── P4-stack-docker.md
│   └── P5-app-react-native.md
├── parciales/
│   ├── parcial-1-prep.md
│   └── parcial-2-prep.md
└── seguimiento/
    ├── clase-01.md
    ├── clase-02.md
    └── ... (hasta clase-32)
```

### Dashboard (`00-Dashboard.md`)

```markdown
---
tags: [proyecto, programacion-3, TUP, 2026]
estado: activo
inicio: 2026-04-01
tipo: materia
docente: Lic. Osvaldo Cantone
parcial-1: clase-12
parcial-2: clase-30
asistencia-minima: 75%
---

# Programación III — Dashboard 2026

> **Objetivo:** Aprobar con ≥ 6 en ambos parciales · 8 hs/semana · 32 clases

## 🗓️ Fechas clave
| Evento | Clase | Estado |
|---|---|---|
| Parcial 1 | 12 | ⬜ |
| Recuperatorio P1 | 18 | ⬜ |
| Parcial 2 | 30 | ⬜ |
| Recuperatorio P2 | 31 | ⬜ |

## 📚 Estado de teoría

```dataview
TABLE unidad AS "Unidad", estado AS "Estado"
FROM "10-Proyectos/TUP-Materias/ProgramacionIII/teoria"
SORT file.name ASC
```

## ⚙️ Estado de prácticas

```dataview
TABLE estado AS "Estado", tipo AS "Tipo"
FROM "10-Proyectos/TUP-Materias/ProgramacionIII/practicas"
SORT file.name ASC
```

## ✅ Criterios de aprobación
- [ ] Parcial 1 ≥ 6
- [ ] Parcial 2 ≥ 6
- [ ] Asistencia ≥ 75% (24/32 clases)
```

### Seguimiento por clase

Usar una nota por clase (en vez de semanal) ya que la unidad natural es la clase:

```markdown
---
tags: [seguimiento, clase-NN, programacion-3]
clase: NN
unidad: N
fecha: YYYY-MM-DD
modalidad: presencial | remoto
estado: pendiente | en-progreso | completa
---

# Clase NN — [Tema]

## Contenido visto

## Dudas / preguntas para la próxima clase

## Prompts que usé en NotebookLM
-

## Tarea o práctica asignada
- [ ]

## Archivos generados
- `TUP-REPO/ProgramacionIII/unidad-0N/clase-NN/`
```

---

## 9. Paths del sistema

| Path | Propósito |
|---|---|
| `E:\SERJITO\SB_Sergio\` | Vault Obsidian — teoría, seguimiento, notas de clase |
| `E:\SERJITO\TUP\TUP-REPO\ProgramacionIII\` | Código, ejercicios, prácticas y TPs de la materia |

### Criterio: qué va a cada lugar

| Contenido | Dónde va |
|---|---|
| Resumen de un concepto teórico | `SB_Sergio/.../teoria/` |
| Notas de clase | `SB_Sergio/.../seguimiento/clase-NN.md` |
| Preparación de parcial | `SB_Sergio/.../parciales/` |
| Código HTML/CSS/JS de práctica | `TUP-REPO/ProgramacionIII/unidad-0N/clase-NN/` |
| Código PHP del backend | `TUP-REPO/ProgramacionIII/unidad-03/` |
| docker-compose.yml | `TUP-REPO/ProgramacionIII/unidad-04/clase-20/` |
| Proyecto React Native | `TUP-REPO/ProgramacionIII/unidad-05/` |
| App integrada final | `TUP-REPO/ProgramacionIII/proyecto-final/` |

### Estructura de TUP-REPO para esta materia

```
E:\SERJITO\TUP\TUP-REPO\ProgramacionIII\
├── unidad-01/
│   ├── clase-03/          ← HTML semántica
│   ├── clase-04/          ← Formularios HTML
│   ├── clase-05/          ← CSS Flex
│   └── clase-06/          ← CSS Grid + responsive
├── unidad-02/
│   ├── clase-07/          ← JS variables y control
│   ├── clase-08/          ← Funciones y eventos
│   ├── clase-09/          ← DOM y validación
│   ├── clase-10/          ← Fetch y async
│   └── clase-11/          ← APIs públicas
├── unidad-03/
│   ├── clase-13/          ← PHP intro + formularios
│   ├── clase-14/          ← CRUD
│   ├── clase-15/          ← REST intro
│   ├── clase-16/          ← JSON y endpoints
│   └── clase-17/          ← Integración frontend-backend
├── unidad-04/
│   ├── clase-19/          ← Nginx config
│   ├── clase-20/          ← Docker (docker-compose.yml + .env + .gitignore)
│   ├── clase-21/          ← Docker Compose avanzado
│   └── clase-22/          ← Deploy stack completo
├── unidad-05/
│   ├── clase-23/          ← React Native intro
│   ├── clase-24/          ← Componentes
│   ├── clase-25/          ← Navegación
│   ├── clase-26/          ← Estado y eventos
│   ├── clase-27/          ← Consumo de API
│   ├── clase-28/          ← App mobile
│   └── clase-29/          ← Integración final
└── proyecto-final/        ← App completa integrada
```

---

## 10. Flujo de sesión de estudio autónomo (30–45 min)

```
[ 5 min ]   Apertura
[ 25–35 min ] Estudio / práctica
[ 5 min ]   Cierre
```

### Apertura
1. Abrir `00-Dashboard.md` — ver qué clase sigue y qué está pendiente
2. Abrir la nota `seguimiento/clase-NN.md` de la clase más reciente
3. Definir **un solo objetivo** para esta sesión — repasar un concepto, completar un ejercicio, o preparar el próximo tema

### Trabajo principal
- **Post-clase:** completar la nota de seguimiento con lo visto, dudas y código generado
- **Pre-clase:** leer el recurso de teoría de la próxima clase y crear la nota vacía con frontmatter
- **Práctica:** trabajar el ejercicio de la unidad en TUP-REPO
- **Repaso parcial:** usar NotebookLM con los prompts de repaso de la sección 4

> **Regla:** si en 10 min no avanzás, anotarlo en "Dudas" y seguir con otra cosa.

### Cierre
1. Actualizar `seguimiento/clase-NN.md` con lo hecho
2. Cambiar `estado` a `completa` si terminaste la nota
3. Guardar código en TUP-REPO
4. Anotar objetivo de la próxima sesión

### Instrucciones para el agente IA

Cuando el usuario diga **"arrancamos sesión"**:
```
1. Preguntar qué clase fue la última
2. Leer la nota de seguimiento de esa clase en SB_Sergio
3. Mostrar el próximo tema según el cronograma del PRD
4. Proponer: ¿post-clase, pre-clase o práctica?
5. Esperar confirmación antes de arrancar
```

Cuando el usuario diga **"cerramos sesión"**:
```
1. Preguntar qué se hizo y cuánto tiempo
2. Actualizar seguimiento/clase-NN.md
3. Cambiar estados en frontmatter si corresponde
4. Proponer objetivo de la próxima sesión
```

---

## 11. Control de alucinaciones — Fuentes y herramientas

### Regla base
> **Si no podés verificarlo con una fuente de la lista permitida, no lo escribas. Indicá explícitamente que necesitás verificarlo.**

### Fuentes permitidas para este PRD

| Fuente | Uso |
|---|---|
| MDN Web Docs (developer.mozilla.org) | Todo lo de HTML, CSS, JavaScript, HTTP, REST |
| PHP Manual oficial (php.net/manual/es) | Todo lo de PHP |
| Docker Docs (docs.docker.com) | Docker, Docker Compose, Nginx en contenedor |
| React Native Docs (reactnative.dev) | React Native, componentes, navegación, fetch mobile |
| React Navigation Docs (reactnavigation.org) | Navegación en React Native |
| NotebookLM con bibliografía cargada | Explicaciones conceptuales, preguntas de repaso |
| Programa oficial PDF | Orden de contenidos, criterios de evaluación, fechas |

**Fuentes prohibidas:** memoria del modelo, blogs, Medium, tutoriales de terceros no verificados, Stack Overflow como fuente primaria (solo para debugging puntual)

### Herramientas requeridas

**Context7 (MCP):** usar para anclar snippets de código en la versión correcta de las tecnologías del stack. Verificar disponibilidad antes de arrancar.

**Web search:** usar para verificar que una URL de doc sigue activa o para confirmar versiones actuales de herramientas.

**NotebookLM:** fuente primaria para consultas sobre la bibliografía cargada. Usar los prompts sugeridos en cada fase de la sección 4.

### Protocolo por acción

| Acción | Protocolo |
|---|---|
| Explicar un concepto | Citar MDN, PHP.net, Docker Docs o React Native Docs antes de explicar |
| Escribir un snippet | Verificar en Context7 o doc oficial que la sintaxis es correcta |
| Responder duda de parcial | Anclar en el programa oficial o en la bibliografía de NotebookLM |
| Generar prompts para NotebookLM | Basarlos en los temas del cronograma oficial, no en suposiciones |

### Señales de alerta
Si el agente dice alguna de estas frases sin citar fuente verificable, detenerlo:
- *"Generalmente en PHP..."* · *"Típicamente en React Native..."* · *"Creo que..."* · *"Debería funcionar..."*

---

## NOTAS PARA EL AGENTE IA

- **Entorno:** Windows 11 + Docker Desktop + WSL2. Comandos en WSL2 (username: `administrador`)
- **Seguridad:** nunca hardcodear contraseñas — siempre `.env` + `.gitignore`
- **Antes de crear:** verificar que los paths de TUP-REPO y SB_Sergio existen
- **Metodología:** SDD — estructura y frontmatter vacío primero, contenido después, clase por clase
- **Orden de ejecución:** crear estructura Obsidian primero (sección 8), luego estructura TUP-REPO (sección 9)
- **Antihallucinación:** verificar disponibilidad de Context7 y web search antes de generar contenido técnico (sección 11)
- **NotebookLM:** no reemplaza al agente — es una fuente de consulta paralela para la bibliografía
- **Código:** siempre va a TUP-REPO, nunca al vault de Obsidian
- **Seguimiento:** usar nota por clase (no por semana) — la unidad natural es la clase de 4 hs
- **Guardar este PRD en:** `E:\SERJITO\SB_Sergio\10-Proyectos\TUP-Materias\ProgramacionIII\PRD.md`

---

*PRD generado desde TEMPLATE-PRD-Aprendizaje v1.2 · Sergio (Sergiotsk) · Abril 2026*  
*Fuente: Programa Analítico Oficial — Programación III · UTN HAEDO · Lic. Osvaldo Cantone*
