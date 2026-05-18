# Cómo usar el template PRD-materia

## Flujo completo para una materia nueva

### Paso 1 — Copiar el template
```
PRD-materia-template.md  →  ../{{REPO_SLUG}}/PRD-{{MATERIA_SLUG}}.md
```

### Paso 2 — Completar los placeholders

Abrí el archivo y reemplazá todos los `{{PLACEHOLDER}}` en este orden:

#### Metadata (encabezado)
| Placeholder | Qué poner |
|---|---|
| `{{MATERIA}}` | Nombre completo. Ej: "Programación II" |
| `{{MATERIA_SLUG}}` | Nombre corto. Ej: "ProgII" |
| `{{REPO_SLUG}}` | Carpeta en TUP-REPO. Ej: "ProgramacionII" |
| `{{OBSIDIAN_SLUG}}` | Carpeta en Obsidian. Ej: "ProgramacionII" |
| `{{AÑO}}` | "2026" |
| `{{MES}}` | "Mayo" |
| `{{CUATRIMESTRE}}` | "1C-2026" |
| `{{DOCENTE}}` | Nombre del docente |
| `{{PLAN}}` | "UTN Haedo · Plan 2024" |
| `{{COMISION}}` | Comisión si aplica |
| `{{OBJETIVO_FINAL}}` | Una oración de qué vas a poder hacer al terminar |
| `{{TIEMPO_DIARIO}}` | "30–45 min/día · 3–4 veces/semana" |
| `{{TOTAL_CLASES}}` | Número total de clases (ej: 16) |
| `{{CLASE_PARCIAL_1}}` | Clase del 1° parcial (ej: 8) |
| `{{CLASE_PARCIAL_2}}` | Clase del 2° parcial (ej: 14) |
| `{{N_UNIDADES}}` | Cantidad de unidades temáticas |
| `{{FUENTE_PRIMARIA}}` | Bibliografía o apuntes principales |

#### Entorno (Sección 1)
- Completar los tipos de artefactos que genera la materia
- Describir la herramienta/IDE principal
- Agregar el uso diario resumido

#### Dashboard (Sección 2)
- Completar el array de unidades:
  ```js
  { num: 1, nombre: "Nombre de la unidad 1" },
  { num: 2, nombre: "Nombre de la unidad 2" },
  ```
- Definir `{{CAMPO_SEGUIMIENTO}}`: usar `semana` o `clase` según corresponda
- Definir `{{LABEL_SEGUIMIENTO}}`: "Semana" o "Clase"

#### Fases (Sección 6)
- Una FASE por bloque de parcial
- Una entrada por clase/semana dentro de cada fase
- Cada entrada: concepto + práctica + lectura + nota Obsidian + archivo TUP-REPO

### Paso 3 — Ejecutar el PRD

Una vez completado, pedirle al agente que ejecute el PRD:

```
ejecuta el prd para [nombre de la materia]
```

Esto crea automáticamente:
- Carpetas en TUP-REPO (`unidad-01/`, `unidad-02/`, etc.)
- Notas de teoría en Obsidian (con frontmatter completo)
- Archivos de seguimiento por clase/semana
- Dashboard con vistas DataviewJS

---

## Variables de decisión rápida

### ¿`semana` o `clase` en el seguimiento?

| Usar `semana` | Usar `clase` |
|---|---|
| Materia con clases regulares semanales y mucho material para practicar fuera de clase | Materia donde cada clase es un evento diferenciado a registrar individualmente |
| Ejemplo: BDII (hay que hacer ejercicios SQL toda la semana) | Ejemplo: MS1 (cada clase tiene un tema distinto y un artefacto concreto) |

### ¿Qué va al tipo de artefactos?

| Tipo de materia | Artefactos en TUP-REPO | Teoría en Obsidian |
|---|---|---|
| Código (SQL, Python, JS) | `.sql`, `.py`, `.ts`, `.js` | Conceptos, sintaxis, patrones |
| Diseño/Arquitectura | Diagramas `.drawio`, `.puml` | Conceptos, comparativas, análisis |
| Teórica | Documentos `.md` con análisis, tablas | Resúmenes, fichas conceptuales |
| Mixta | Todo lo anterior según el tema | Todo lo anterior |

---

## Materias ya ejecutadas (ejemplos)

| Materia | PRD | Dashboard |
|---|---|---|
| Base de Datos II | `TUP-REPO/BasedeDatosII/PRD-BaseDatos2.md` | `SB_Sergio/.../BDII/00-Dashboard-BDII.md` |
| Metodología de Sistemas I | `TUP-REPO/MetodologiaDeSistemasI/PRD-MetodologiaDeSistemas1.md` | `SB_Sergio/.../Metodologia de sistemas I/00-Dashboard-MS1.md` |
