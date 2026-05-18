# PRD —} — TUP}

<!--
╔══════════════════════════════════════════════════════════════════╗
║              INSTRUCCIONES DE USO — LEER ANTES DE COMPLETAR     ║
╠══════════════════════════════════════════════════════════════════╣
║  1. Reemplazá TODOS los {{PLACEHOLDER}} con los datos reales.   ║
║  2. Eliminá los bloques <!-- INSTRUCCIÓN --> antes de usar.      ║

║  3. En las FASES: creá una por bloque temático hasta el parcial. ║
║     Cada FASE tiene SEMANAS/CLASES con tareas concretas.        ║
║  4. Una vez completo, ejecutá el PRD:                           ║
║     → crear carpetas en TUP-REPO                                ║
║     → crear notas de teoría en Obsidian (con frontmatter)       ║
║     → crear archivos de seguimiento por clase/semana            ║
║     → crear el Dashboard en Obsidian                            ║
╚══════════════════════════════════════════════════════════════════╝

GLOSARIO DE PLACEHOLDERS:
  {{MATERIA}}          → Nombre completo. Ej: "Base de Datos II"
  {{MATERIA_SLUG}}     → Nombre corto para carpetas. Ej: "BDII"
  {{REPO_SLUG}}        → Nombre de carpeta en TUP-REPO. Ej: "BasedeDatosII"
  {{OBSIDIAN_SLUG}}    → Nombre de carpeta en Obsidian. Ej: "BDII"
  {{AÑO}}              → Ej: "2026"
  {{CUATRIMESTRE}}     → Ej: "1C-2026"
  {{DOCENTE}}          → Nombre del docente. Si hay más de uno, listá todos.
  {{PLAN}}             → Ej: "UTN Haedo · Plan 2024"
  {{COMISION}}         → Ej: "M3" o dejá en blanco si no aplica
  {{OBJETIVO_FINAL}}   → Una oración: qué vas a poder hacer al terminar la materia.
  {{TIEMPO_DIARIO}}    → Ej: "30–45 min/día · 3–4 veces por semana"
  {{TOTAL_CLASES}}     → Número total de clases. Ej: 16
  {{CLASE_PARCIAL_1}}  → Número de clase del 1° parcial. Ej: 8
  {{CLASE_PARCIAL_2}}  → Número de clase del 2° parcial. Ej: 14
  {{HERRAMIENTA_PRINCIPAL}} → IDE/herramienta central. Ej: "Oracle SQL Developer"
  {{FUENTE_PRIMARIA}}  → Bibliografía o apuntes principales de la cátedra.
  {{N_UNIDADES}}       → Cantidad de unidades temáticas. Ej: 5
-->

**Autor:** Sergio (Sergiotsk) · Estudiante TUP · Electricista · PC Técnico · Argentina
**Fecha:** {{MES}} {{AÑO}}
**Tipo:** materia
**Plan:** {{PLAN}}
**Objetivo final:** {{OBJETIVO_FINAL}}
**Tiempo disponible:** {{TIEMPO_DIARIO}}
**Duración estimada:** 1 cuatrimestre
**Agente recomendado:** Claude Code (claude.ai)
**Entorno:** Windows 11 Pro · ASUS ROG Strix · Ryzen 7 · 16GB RAM

**Fuentes verificadas:**

- [X] Programa oficial verificado: {{PLAN}} (PDF / documento adjunto)
- [X] Bibliografía del PRD verificada: {{FUENTE_PRIMARIA}}
- [X] Web search habilitado
- [X] Context7 disponible y activo *(verificar antes de arrancar cada sesión)*

---

## 1. Entorno de trabajo

### Paths del sistema

| Path                                       | Propósito                                       |
| ------------------------------------------ | ------------------------------------------------ |
| `E:\SERJITO\SB_Sergio\`                  | Vault de Obsidian — notas, teoría, seguimiento |
| `E:\SERJITO\TUP\TUP-REPO\{{REPO_SLUG}}\` | Código, ejercicios, artefactos y entregas       |

### Criterio: qué va a cada lugar

<!--
Ajustá estas filas según la naturaleza de la materia:
- Si es una materia de código → ejercicios .sql / .py / .ts en TUP-REPO
- Si es una materia teórica → artefactos (diagramas, documentos) en TUP-REPO
- La teoría y los apuntes SIEMPRE van al vault de Obsidian
-->

| Contenido                        | Dónde va                                                         |
| -------------------------------- | ----------------------------------------------------------------- |
| Resumen de un concepto           | `SB_Sergio/10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/teoria/` |
| Apuntes de clase o bibliografía | `SB_Sergio/10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/teoria/` |
| {{TIPO_ARTEFACTO_1}}             | `TUP-REPO/{{REPO_SLUG}}/{{CARPETA_UNIDAD}}/`                    |
| {{TIPO_ARTEFACTO_2}}             | `TUP-REPO/{{REPO_SLUG}}/{{CARPETA_UNIDAD}}/`                    |
| TP o trabajo entregable          | `TUP-REPO/{{REPO_SLUG}}/entregas/`                              |
| Proyecto final                   | `TUP-REPO/{{REPO_SLUG}}/proyecto-final/`                        |

### Estructura de TUP-REPO

<!--
Creá una carpeta por unidad. El comentario ← describe qué va adentro.
Ajustá la cantidad de unidades a {{N_UNIDADES}}.
-->

```
E:\SERJITO\TUP\TUP-REPO\{{REPO_SLUG}}\
    ├── unidad-01\   ← {{DESCRIPCION_U1}}
    ├── unidad-02\   ← {{DESCRIPCION_U2}}
    ├── unidad-03\   ← {{DESCRIPCION_U3}}
    ├── ...
    ├── proyecto-final\
    └── entregas\
```

---

### Herramienta / entorno principal:}

<!--
Describí el entorno de trabajo específico de esta materia:
- Si usa Docker: instrucciones de docker-compose
- Si usa un IDE específico: cómo configurarlo
- Si es teórica: herramientas de diagramación, documentación, etc.
Eliminá esta sección si la materia no requiere setup especial.
-->

{{DESCRIPCION_HERRAMIENTA}}

#### Uso diario resumido

| Acción      | Cómo      |
| ------------ | ---------- |
| {{ACCION_1}} | {{COMO_1}} |
| {{ACCION_2}} | {{COMO_2}} |
| {{ACCION_3}} | {{COMO_3}} |

---

## 2. Second Brain en Obsidian

### Estructura de carpetas en el vault

```
E:\SERJITO\SB_Sergio\10-Proyectos\TUP-Materias\{{OBSIDIAN_SLUG}}\
├── 00-Dashboard-{{MATERIA_SLUG}}.md
├── teoria\
│   ├── 01-{{TEMA_1}}.md
│   ├── 02-{{TEMA_2}}.md
│   ├── 03-{{TEMA_3}}.md
│   └── ...
└── seguimiento\
    ├── {{UNIDAD_SEGUIMIENTO}}-01.md
    ├── {{UNIDAD_SEGUIMIENTO}}-02.md
    └── ...
```

<!--
{{UNIDAD_SEGUIMIENTO}} = "semana" si la materia se sigue por semanas,
                          "clase" si se sigue por clase individual.
-->

### Dashboard 00-Dashboard-}.md

```markdown
---
tags:
  - proyecto
  - {{MATERIA_SLUG_LOWER}}
  - TUP
estado: en-progreso
inicio: {{FECHA_INICIO}}
tipo: materia
docente: {{DOCENTE}}
parcial-1: {{FECHA_PARCIAL_1}}
parcial-2: {{FECHA_PARCIAL_2}}
asistencia-minima: 75%
---

# 📊 {{MATERIA}} — Dashboard {{AÑO}}

> **Objetivo:** Aprobar con ≥ 6 en ambos parciales · {{TIEMPO_DIARIO}}
> **Docente:** {{DOCENTE}}

---

## 🗓️ Calendario — Próximos eventos

```dataviewjs
const parciales = [
  { nombre: "1° Parcial", clase: {{CLASE_PARCIAL_1}}, fecha: "{{FECHA_PARCIAL_1}}" },
  { nombre: "Recuperatorio P1", clase: {{CLASE_PARCIAL_1}} + 1, fecha: "TBD" },
  { nombre: "2° Parcial", clase: {{CLASE_PARCIAL_2}}, fecha: "{{FECHA_PARCIAL_2}}" },
  { nombre: "Recuperatorio / Final", clase: {{TOTAL_CLASES}}, fecha: "TBD" }
];

const seguimientoList = [...dv.pages('"10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/seguimiento"').where(x => x.{{CAMPO_SEGUIMIENTO}})];
const actuales = seguimientoList.filter(c => c.estado === "completa").length;

dv.table(["🎯 Evento", "📅 Fecha", "⏱️ Clases restantes", "📊 Urgencia"],
  parciales.map(p => {
    const rest = (p.clase * 1) - actuales;
    const urgencia = rest <= 2 ? "🔥 URGENTE" : rest <= 4 ? "⚠️ Pronto" : "✅ Tiempo";
    return [p.nombre, p.fecha, `${rest} clases`, urgencia];
  })
);
```

---

## 📈 Progreso general

```dataviewjs
const temas = [...dv.pages('"10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/teoria"').where(t => t.tema)];
const completa = temas.filter(t => t.estado === "completa").length;
const enProgreso = temas.filter(t => t.estado === "en-progreso").length;
const total = temas.length;
const pct = total > 0 ? Math.round(((completa + enProgreso * 0.5) / total) * 100) : 0;
const bloques = Math.floor(pct / 5);
const barra = "█".repeat(bloques) + "░".repeat(20 - bloques);
dv.paragraph(`\`${barra}\` **${pct}%** — ${completa} completos · ${enProgreso} en progreso · ${total - completa - enProgreso} pendientes`);
```

---

## 📚 Estado de teoría por unidad

```dataviewjs
const unidades = [
  {{UNIDADES_ARRAY}}
];

const rows = [];
for (const u of unidades) {
  const temas = [...dv.pages('"10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/teoria"').where(t => t.unidad == u.num)];
  const completa = temas.filter(t => t.estado === "completa").length;
  const enProgreso = temas.filter(t => t.estado === "en-progreso").length;
  const total = temas.length;
  const pct = total > 0 ? Math.round(((completa + enProgreso * 0.5) / total) * 100) : 0;
  const barra = "█".repeat(Math.floor(pct / 10)) + "░".repeat(10 - Math.floor(pct / 10));
  const label = enProgreso > 0 ? `${completa}✅ ${enProgreso}🔄` : `${completa}/${total}`;
  rows.push([`U${u.num} — ${u.nombre}`, `\`${barra}\``, `${pct}%`, label]);
}
dv.table(["Unidad", "Progreso", "%", "Temas"], rows);
```

---

## 📋 Teoría — Detalle por tema

```dataview
TABLE without id
  choice(row.estado = "completa", "✅", choice(row.estado = "en-progreso", "🔄", "⏳")) AS "",
  row.unidad AS "Unidad",
  row.tema AS "Tema",
  row.estado AS "Estado"
FROM "10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/teoria"
SORT [row.unidad, row.file.name] ASC
```

---

## 📅 Cronograma — Fechas de clases

| Clase | Fecha | Tema | Examen |
|-------|-------|------|--------|
| 01 | | {{TEMA_CLASE_01}} | |
| ... | | | |
| **{{CLASE_PARCIAL_1}}** | | **🎯 1° EXAMEN PARCIAL** | |
| ... | | | |
| **{{CLASE_PARCIAL_2}}** | | **🎯 2° EXAMEN PARCIAL** | |
| **{{TOTAL_CLASES}}** | | **🎯 RECUPERATORIO** | |

---

## 📅 Seguimiento dictado

```dataview
TABLE without id
  row.{{CAMPO_SEGUIMIENTO}} AS "{{LABEL_SEGUIMIENTO}}",
  choice(row.estado = "completa", "✅", choice(row.estado = "en-progreso", "🔄", "⏳")) AS "Estado",
  row.fecha AS "Fecha",
  row.objetivo AS "Tema"
FROM "10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/seguimiento"
WHERE row.{{CAMPO_SEGUIMIENTO}}
SORT [row.{{CAMPO_SEGUIMIENTO}}] DESC
LIMIT 10
```

---

## 🧠 Tracker de estudio

```dataview
TABLE without id
  row.{{CAMPO_SEGUIMIENTO}} AS "{{LABEL_SEGUIMIENTO}}",
  choice(row.estado = "completa", "✅", choice(row.estado = "en-progreso", "🔄", "⏳")) AS "Asistencia",
  row["tiempo-real"] AS "Tiempo",
  row.bloqueos AS "Bloqueos"
FROM "10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/seguimiento"
WHERE row.{{CAMPO_SEGUIMIENTO}}
SORT [row.{{CAMPO_SEGUIMIENTO}}] DESC
LIMIT 10
```

*⚠️ Para usar el tracker: completar `tiempo-real` y `bloqueos` en el frontmatter de cada {{LABEL_SEGUIMIENTO_LOWER}}*

---

## 📌 Planificador — Próxima {{LABEL_SEGUIMIENTO_LOWER}}

```dataviewjs
const seguimientoList = [...dv.pages('"10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/seguimiento"').where(s => s.{{CAMPO_SEGUIMIENTO}})];
const completas = seguimientoList.filter(s => s.estado === "completa").length;
const temas = [...dv.pages('"10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/teoria"').where(t => t.estado !== "completa" && t.tema)];

const hastaP1 = {{CLASE_PARCIAL_1}} - completas;
const hastaP2 = {{CLASE_PARCIAL_2}} - completas;
const prioritarios = temas.sort((a, b) => a.unidad - b.unidad).slice(0, 5);

if (hastaP1 <= 3 && hastaP1 > 0) {
  dv.list(["🔥 PRIORIDAD: Repaso para 1° Parcial (Clase {{CLASE_PARCIAL_1}})"]);
} else if (hastaP2 <= 3 && hastaP2 > 0) {
  dv.list(["🔥 PRIORIDAD: Repaso para 2° Parcial (Clase {{CLASE_PARCIAL_2}})"]);
} else {
  dv.list(prioritarios.map(t => `📖 ${t.tema} (Unidad ${t.unidad})`));
}
```

---

## ✅ Criterios de aprobación

- [ ] 1° Parcial ≥ 6
- [ ] 2° Parcial ≥ 6
- [ ] Asistencia ≥ 75%
- [ ] {{CRITERIO_EXTRA}}

---

## 📂 Recursos rápidos

- 📖 **Teoría:** `E:\SERJITO\SB_Sergio\10-Proyectos\TUP-Materias\{{OBSIDIAN_SLUG}}\teoria\`
- 💾 **Artefactos:** `E:\SERJITO\TUP\TUP-REPO\{{REPO_SLUG}}\`
- 📄 **Programa oficial:** `{{PATH_PROGRAMA}}`
- 📋 **PRD:** `E:\SERJITO\TUP\TUP-REPO\{{REPO_SLUG}}\PRD-{{MATERIA_SLUG}}.md`
```

### Frontmatter de notas de teoría

```yaml
---
tema: [nombre del tema]
unidad: [número de unidad]
bibliografía: "{{FUENTE_PRIMARIA}} · Cap. X"
estado: pendiente
tags: [{{MATERIA_SLUG_LOWER}}, tup]
---
```

### Frontmatter de notas de seguimiento

```yaml
---
{{CAMPO_SEGUIMIENTO}}: [número]
fecha: YYYY-MM-DD
fase: [nombre de la fase]
objetivo: [qué se estudia]
tiempo-real: ""
estado: pendiente
bloqueos: []
---
```

### Valores válidos de `estado`

| Valor           | Cuándo usarlo               |
| --------------- | ---------------------------- |
| `pendiente`   | Al crear la nota             |
| `en-progreso` | Al arrancar esa unidad/clase |
| `completa`    | Al terminar                  |

### Plugins requeridos

- **Dataview** — para todas las queries del Dashboard
- **Tasks** — para checkboxes con filtros
- **Kanban** — para vista de tablero
- **Periodic Notes** — para notas de seguimiento automáticas
- **Remotely Save** — sync con Google Drive

---

## 3. Visión general

<!--
3–4 párrafos que respondan:
1. ¿Qué es esta materia dentro del plan de estudios? (nivel, correlativas)
2. ¿Cuál es el eje central de aprendizaje?
3. ¿Cómo se organiza el aprendizaje? (fases, bibliografía, entorno)
-->

{{VISION_GENERAL}}

---

## 4. Objetivos medibles

<!--
6–8 objetivos. Cada uno debe tener:
- Un verbo de acción concreto (dominar, implementar, crear, resolver)
- Un criterio de éxito verificable (ejercicio X completo, nota ≥ Y, etc.)
-->

| # | Objetivo                            | Criterio de éxito                           |
| - | ----------------------------------- | -------------------------------------------- |
| 1 | {{OBJETIVO_1}}                      | {{CRITERIO_1}}                               |
| 2 | {{OBJETIVO_2}}                      | {{CRITERIO_2}}                               |
| 3 | {{OBJETIVO_3}}                      | {{CRITERIO_3}}                               |
| 4 | {{OBJETIVO_4}}                      | {{CRITERIO_4}}                               |
| 5 | {{OBJETIVO_5}}                      | {{CRITERIO_5}}                               |
| 6 | Aprobar los parciales de la materia | Nota igual o superior a 6 en ambos parciales |

---

## 5. Stack / herramientas / materiales

### Principal

- {{HERRAMIENTA_PRINCIPAL}} — {{DESCRIPCION_CORTA}}
- {{HERRAMIENTA_2}} — {{DESCRIPCION_CORTA_2}}

### Complementario

- {{HERRAMIENTA_COMPLEMENTARIA}}

### Bibliografía / documentación oficial

| Recurso     | Referencia                   | Para qué unidad |
| ----------- | ---------------------------- | ---------------- |
| {{LIBRO_1}} | {{AUTOR_1}} · {{EDICION_1}} | {{UNIDADES_1}}   |
| {{LIBRO_2}} | {{AUTOR_2}} · {{EDICION_2}} | {{UNIDADES_2}}   |
| {{LIBRO_3}} | {{AUTOR_3}} · {{EDICION_3}} | {{UNIDADES_3}}   |

### Agente IA para este PRD

- **Agente:** Claude (claude.ai)
- **Por qué:** {{RAZON_IA}}
- **Limitaciones:** {{LIMITACIONES_IA}}

---

## 6. Fases de aprendizaje

<!--
REGLA: una FASE por bloque temático. Los bloques suelen coincidir con
los parciales: Fase 1 = todo lo que entra al 1° parcial,
Fase 2 = todo lo que entra al 2° parcial.

Dentro de cada fase: una sección por CLASE o SEMANA, según la materia.

PATRON DE CADA CLASE/SEMANA:
─────────────────────────────
#### Clase/Semana N — [Título del tema] (Unidad X)

**[Subtema A]**
- Concepto: [qué se aprende]
- Práctica: [ejercicio concreto a resolver]
- 📖 **Leer:** [libro, capítulo, sección]
- 🗒️ **Nota Obsidian:** `ruta/al/archivo.md`
- 💾 **Guardar en:** `TUP-REPO/.../archivo`
─────────────────────────────
-->

### FASE 1 —} (Clases}–})

**Meta:** {{META_FASE_1}}

---

#### Clase} —} (Unidad})

**{{SUBTEMA}}**

- Concepto: {{CONCEPTO}}
- Práctica: {{PRACTICA}}
- 📖 **Leer:** {{REFERENCIA_BIBLIOGRAFICA}}
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/teoria/{{NOMBRE_NOTA}}.md`
- 💾 **Guardar en:** `TUP-REPO/{{REPO_SLUG}}/{{CARPETA}}/{{ARCHIVO}}`

<!--
Repetir bloque para cada clase de la Fase 1.
La última clase antes del parcial es el repaso.
-->

---

#### Clase} — Repaso Fase 1 (pre-parcial)

- Concepto: Repaso integral de {{TEMAS_FASE_1}}.
- Práctica: Resolver ejercicios tipo parcial sobre todos los temas.
- 📖 **Leer:** Todo lo anterior.
- 💾 **Guardar en:** `TUP-REPO/{{REPO_SLUG}}/entregas/repaso-parcial-1.md`

---

#### Clase} — 1° Examen Parcial

> Cubre todo el contenido de las Clases {{INICIO_F1}} al {{CLASE_PARCIAL_1 - 1}}.

---

### FASE 2 —} (Clases}–})

**Meta:** {{META_FASE_2}}

---

#### Clase} —} (Unidad})

**{{SUBTEMA}}**

- Concepto: {{CONCEPTO}}
- Práctica: {{PRACTICA}}
- 📖 **Leer:** {{REFERENCIA_BIBLIOGRAFICA}}
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/{{OBSIDIAN_SLUG}}/teoria/{{NOMBRE_NOTA}}.md`
- 💾 **Guardar en:** `TUP-REPO/{{REPO_SLUG}}/{{CARPETA}}/{{ARCHIVO}}`

<!--
Repetir bloque para cada clase de la Fase 2.
-->

---

#### Clase} — Repaso Fase 2 (pre-parcial)

- Concepto: Repaso integral de {{TEMAS_FASE_2}}.
- Práctica: Resolver ejercicios tipo parcial.
- 💾 **Guardar en:** `TUP-REPO/{{REPO_SLUG}}/entregas/repaso-parcial-2.md`

---

#### Clase} — 2° Examen Parcial

> Cubre todo el contenido de las Clases {{INICIO_F2}} al {{CLASE_PARCIAL_2 - 1}}.

---

#### Clases}–} — Devoluciones y Recuperatorio

> - Clase {{CLASE_PARCIAL_2 + 1}}: Devolución de calificaciones. Repaso pre-recuperatorio.
> - Clase {{TOTAL_CLASES}}: Examen Recuperatorio (integra todos los contenidos).

---

## 7. Recursos de aprendizaje

| Recurso       | URL / Referencia | Para qué fase |
| ------------- | ---------------- | -------------- |
| {{RECURSO_1}} | {{URL_1}}        | {{FASE_1}}     |
| {{RECURSO_2}} | {{URL_2}}        | {{FASE_2}}     |
| {{RECURSO_3}} | {{URL_3}}        | {{FASE_3}}     |

---

## 8. Archivos de referencia

<!--
Incluí aquí los templates, snippets o estructuras de referencia
que vas a usar repetidamente en esta materia.

Ejemplos:
- Materia de código → template del bloque/función más común
- Materia de diseño → template de diagrama o documento
- Materia teórica → template de análisis de caso, tabla comparativa, etc.
-->

{{TEMPLATE_REFERENCIA_1}}

{{TEMPLATE_REFERENCIA_2}}

---

## 9. Criterios de finalización

<!--
Lista de checkboxes con TODO lo que hay que completar para
considerar la materia terminada correctamente.
Incluí tanto los artefactos como los objetivos académicos.
-->

- [ ] Tener todas las notas de teoría creadas en Obsidian (notas 01 al {{N_NOTAS}})
- [ ] {{CRITERIO_ARTEFACTO_1}}
- [ ] {{CRITERIO_ARTEFACTO_2}}
- [ ] {{CRITERIO_ARTEFACTO_3}}
- [ ] Aprobar el primer parcial con nota ≥ 6
- [ ] Aprobar el segundo parcial o final con nota ≥ 6

---

## 10. Flujo de sesión diaria

```
[ 5 min ]     Apertura
[ 25–35 min ] Trabajo principal
[ 5 min ]     Cierre
```

### Apertura

1. Abrir `00-Dashboard-{{MATERIA_SLUG}}.md` — ver qué está `en-progreso` o `pendiente`
2. Abrir nota de seguimiento de la clase/semana actual
3. Definir **un solo objetivo** para esta sesión
4. Cambiar estado a `en-progreso` si corresponde

### Trabajo principal

- **Teoría:** leer sección de la bibliografía → completar nota en Obsidian
- **Práctica:** resolver el ejercicio/artefacto concreto → guardar en TUP-REPO
- **Mixto:** 15 min teoría + 15 min práctica

> **Regla:** si en 10 min no avanzás por un bloqueo, anotarlo en "Bloqueos y dudas" y seguir con lo próximo.

### Cierre

1. Registrar en seguimiento: qué hiciste + tiempo real
2. Cambiar `estado` a `completa` si terminaste
3. Guardar los artefactos en TUP-REPO/{{REPO_SLUG}}
4. Anotar objetivo de la próxima sesión

### Instrucciones para el agente IA

Cuando el usuario diga **"arrancamos sesión"** o similar:

```
1. Preguntar en qué clase/semana está
2. Mostrar el objetivo pendiente más próximo según este PRD
3. Proponer trabajo concreto de esta sesión (teoría, ejercicio específico o mixto)
4. Indicar qué bibliografía (libro, parte, sección) debe leer
5. Esperar confirmación antes de arrancar
```

Cuando el usuario diga **"cerramos sesión"** o similar:

```
1. Preguntar qué se hizo y cuánto tiempo tomó
2. Preguntar si hay bloqueos o dudas para registrar
3. Proponer objetivo de la próxima sesión según el PRD
```

---

## 11. Control de alucinaciones — Fuentes y herramientas

### Regla base

> **Si no podés verificarlo con una fuente de la lista permitida, no lo escribas. Indicá explícitamente que necesitás verificarlo.**

### Fuentes válidas para este PRD

<!--
Completá esta tabla con las fuentes reales de la materia.
La columna "Fuente prohibida" es tan importante como la permitida:
define explícitamente qué NO debe usar el agente.
-->

| Tipo de contenido       | Fuente permitida          | Fuente prohibida                                  |
| ----------------------- | ------------------------- | ------------------------------------------------- |
| {{TIPO_CONTENIDO_1}}    | {{FUENTE_PERMITIDA_1}}    | Blogs, tutoriales de terceros, memoria del modelo |
| {{TIPO_CONTENIDO_2}}    | {{FUENTE_PERMITIDA_2}}    | Resúmenes sin citar fuente académica            |
| Estructura del programa | Programa oficial {{PLAN}} | Programas de otras universidades                  |
| Ejercicios              | {{FUENTE_EJERCICIOS}}     | Ejercicios generados desde memoria sin verificar  |

### Protocolo antihallucinación por acción

| Acción del agente                         | Protocolo                                                          |
| ------------------------------------------ | ------------------------------------------------------------------ |
| Explicar un concepto                       | Citar el libro/apunte (Parte/Cap. X, sección Y) antes de explicar |
| Revisar código o artefacto del estudiante | Comparar contra ejemplos de la bibliografía; indicar la fuente    |
| Recomendar una herramienta                 | Verificar con web search que sigue activa y es versión correcta   |
| Completar una nota de teoría              | Cada afirmación debe tener fuente en la bibliografía oficial     |
| Generar un ejercicio variante              | Indicar que es variante generada, no del material oficial          |

### Señales de alerta para el usuario

Si el agente dice alguna de estas frases **sin citar la fuente verificada**, detenerlo y pedir verificación:

- *"Generalmente en {{MATERIA}}..."*
- *"Típicamente..."*
- *"Creo que la definición es..."*
- *"Debería funcionar así..."*
- *"En la mayoría de los casos..."*

---

*PRD generado por Claude (claude.ai) · {{MES}} {{AÑO}}*
*Basado en: Programa oficial {{PLAN}}*
*Compatible con: Claude · Claude Code · Cursor · cualquier agente con acceso a archivos*
