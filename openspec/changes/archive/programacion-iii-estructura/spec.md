# SPEC — `programacion-iii-estructura`
> Generated: 2026-04-26 | Status: draft

**Change:** Crear estructura completa para ProgramacionIII en SB_Sergio vault y TUP-REPO.
**Format:** Given/When/Then — RFC 2119 keywords.

---

## 1. SB_Sergio — Estructura de Directorios

**SC-DIR-01**
Given: vault root `E:\SERJITO\SB_Sergio\10-Proyectos\TUP-Materias\ProgramacionIII\`
When: se aplica el cambio
Then:
- `ProgramacionIII/` MUST crearse si no existe.
- Subdirectorios MUST crearse: `teoria/`, `practicas/`, `parciales/`, `seguimiento/`.

**SC-DIR-02**
Given: `ProgramacionIII/` existe en el vault
When: se aplica el cambio
Then: `00-Dashboard.md` MUST crearse en la raíz de `ProgramacionIII/` con contenido de PRD sección 8.

---

## 2. SB_Sergio — Contenido de Archivos (Frontmatter)

**SC-TEORIA-01**
Given: la lista de 15 archivos de teoría del PRD sección 8
When: se crean los archivos de teoría
Then:
- MUST crearse exactamente 15 archivos en `teoria/` con nombres exactos del PRD:
  U1-T1-arquitectura-cliente-servidor.md, U1-T2-html-semantica-formularios.md,
  U1-T3-css-layout-responsive.md, U2-T1-javascript-fundamentos.md,
  U2-T2-dom-validacion.md, U2-T3-fetch-asincronismo.md,
  U3-T1-php-crud.md, U3-T2-api-rest-json.md, U3-T3-integracion-frontend-backend.md,
  U4-T1-nginx.md, U4-T2-docker-compose.md, U4-T3-deploy.md,
  U5-T1-react-native-intro.md, U5-T2-navegacion-estado.md, U5-T3-consumo-api-mobile.md
- Frontmatter MUST contener:
  ```yaml
  ---
  tags: [teoria, programacion-3, unidad-N, TUP, 2026]
  unidad: N
  tema: "T-title"
  estado: pendiente
  fuente: ""
  ---
  ```

**SC-PRACTICAS-01**
Given: la lista de 5 prácticas del PRD sección 8
When: se crean los archivos de práctica
Then:
- MUST crearse exactamente 5 archivos:
  P1-pagina-html-css.md, P2-formulario-js-fetch.md, P3-crud-php-rest.md,
  P4-stack-docker.md, P5-app-react-native.md
- Frontmatter MUST contener:
  ```yaml
  ---
  tags: [practica, programacion-3, TUP, 2026]
  estado: pendiente
  tipo: practica
  ---
  ```

**SC-PARCIALES-01**
Given: los 2 archivos de parciales del PRD sección 8
When: se crean
Then:
- MUST crearse: `parcial-1-prep.md` y `parcial-2-prep.md`
- Frontmatter MUST contener:
  ```yaml
  ---
  tags: [parcial, programacion-3, TUP, 2026]
  estado: pendiente
  ---
  ```

**SC-SEGUIMIENTO-01**
Given: el cronograma de 32 clases
When: se crean los archivos de seguimiento
Then: MUST crearse exactamente 32 archivos `clase-01.md` a `clase-32.md`.

**SC-SEGUIMIENTO-02**
Given: clase con unidad asignada (todas excepto 12, 18, 30, 31, 32)
When: se crea `seguimiento/clase-NN.md`
Then: frontmatter MUST ser:
  ```yaml
  ---
  tags: [seguimiento, clase-NN, programacion-3]
  clase: NN
  unidad: N
  fecha: ""
  modalidad: presencial
  estado: pendiente
  ---
  ```
  Body MUST incluir template completo (h2: Contenido visto, Dudas, NotebookLM, Tarea, Archivos generados).

**SC-SEGUIMIENTO-03**
Given: clase sin unidad (12, 18, 30, 31, 32)
When: se crea `seguimiento/clase-NN.md`
Then: `unidad` MUST ser `""`.

---

## 3. TUP-REPO — Estructura de Directorios

**TR-DIR-01**
Given: `E:\SERJITO\TUP\TUP-REPO\ProgramacionIII\`
When: se aplica el cambio
Then: MUST crearse `unidad-01/` a `unidad-05/`.

**TR-DIR-02**
Given: el mapping clase-unidad del PRD (sección 9)
When: se crean subdirectorios de clase
Then la asignación MUST ser exactamente:
  | Unidad | Clases (solo las del PRD sección 9) |
  |--------|-------------------------------------|
  | unidad-01 | 03, 04, 05, 06 |
  | unidad-02 | 07, 08, 09, 10, 11 |
  | unidad-03 | 13, 14, 15, 16, 17 |
  | unidad-04 | 19, 20, 21, 22 |
  | unidad-05 | 23, 24, 25, 26, 27, 28, 29 |

  NOTA: clases 01, 02, 12, 18, 30, 31, 32 NO tienen directorio en TUP-REPO.

**TR-DIR-03**
Given: `clase-20/`
When: se aplica el cambio
Then: `src/` MUST crearse dentro de `clase-20/` con un `.gitkeep`.

**TR-DIR-04**
Given: `ProgramacionIII/`
When: se aplica el cambio
Then: `proyecto-final/` MUST crearse con `.gitkeep`.

---

## 4. TUP-REPO — Archivos Especiales (clase-20 Docker)

**TR-DOCKER-01** `docker-compose.yml` MUST crearse con nginx:alpine, php:8.2-fpm, mysql:8, volume mysql_data, env vars via ${}.

**TR-DOCKER-02** `.env` MUST crearse con placeholders `cambia_esta_password` y comentario `# .env — no subir a Git`.

**TR-DOCKER-03** `.gitignore` MUST crearse conteniendo exactamente `.env`.

---

## 5. Git Tracking

**TR-GIT-01** Toda dir vacía en TUP-REPO MUST contener `.gitkeep`.

**TR-GIT-02** `clase-20/` (tiene archivos reales) SHALL NOT tener `.gitkeep`. `src/` dentro sí MUST tenerlo.

**TR-GIT-03** SB_Sergio vault SHALL NOT tener `.gitkeep` (no es git repo).

---

## 6. Preservación

**PR-01** `PRD-Programacion-III-2026.md` MUST NOT modificarse.
**PR-02** `Material de clase/` MUST NOT tocarse.
**PR-03** Ningún archivo existente SHALL modificarse o eliminarse.

---

## Acceptance Criteria

| ID | Criterio |
|----|----------|
| AC-01 | SB_Sergio: 4 subdirs bajo ProgramacionIII/ |
| AC-02 | SB_Sergio: 00-Dashboard.md con dataview queries |
| AC-03 | SB_Sergio: 15 archivos de teoría con nombres exactos del PRD |
| AC-04 | SB_Sergio: 5 archivos de práctica |
| AC-05 | SB_Sergio: 2 archivos de parciales (parcial-1-prep.md, parcial-2-prep.md) |
| AC-06 | SB_Sergio: 32 archivos seguimiento/clase-NN.md |
| AC-07 | TUP-REPO: 5 unidad dirs |
| AC-08 | TUP-REPO: 27 clase-NN dirs en sus unidades correctas (NO clase-01, 02, 12, 18, 30-32) |
| AC-09 | TUP-REPO: clase-20 tiene docker-compose.yml + .env + .gitignore + src/.gitkeep |
| AC-10 | TUP-REPO: proyecto-final/ con .gitkeep |
| AC-11 | PRD y Material de clase/ intactos |
