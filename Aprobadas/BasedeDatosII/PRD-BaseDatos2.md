# PRD — Base de Datos II — TUP 2026

**Autor:** Sergio (Sergiotsk) · Estudiante TUP · Electricista · PC Técnico · Argentina
**Fecha:** Mayo 2026
**Tipo:** materia
**Opción:** B — materia con programa oficial (UTN Haedo · Plan 2024)
**Objetivo final:** Dominar PL/SQL Oracle y la administración de bases de datos relacionales para poder crear procedimientos, funciones, triggers y paquetes en contextos profesionales reales.
**Tiempo disponible:** 30–45 min/día · 3–4 veces por semana
**Duración estimada:** 1 cuatrimestre (abril–julio 2026)
**Agente recomendado:** Claude Code (claude.ai)
**Entorno:** Windows 11 Pro · ASUS ROG Strix · Ryzen 7 · 16GB RAM · Docker Desktop + WSL2

**Fuentes verificadas:**
- [x] Programa oficial verificado: UTN Haedo · Base de Datos II · Plan 2024 (PDF adjunto)
- [x] Bibliografía del PRD verificada: Apuntes de PL/SQL Oracle Partes 1–8 (Lic. Vilma Giudice · UTN FRH)
- [x] Web search habilitado
- [ ] Context7 disponible y activo *(verificar antes de arrancar cada sesión)*

---


## 1. Entorno de desarrollo

### Paths del sistema


| Path | Propósito |
|---|---|
| `E:\SERJITO\SB_Sergio\` | Vault de Obsidian — notas, teoría, seguimiento |
| `E:\SERJITO\TUP\TUP-REPO\BasedeDatosII\` | Código, ejercicios, prácticas SQL |

### Criterio: qué va a cada lugar

| Contenido | Dónde va |
|---|---|
| Resumen de un concepto PL/SQL | `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/` |
| Apuntes de clase o del libro de Giudice | `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/` |
| Código de ejercicio o práctica SQL | `TUP-REPO/BasedeDatosII/` |
| TP o trabajo entregable | `TUP-REPO/BasedeDatosII/trabajos/` |
| Proyecto final | `TUP-REPO/BasedeDatosII/proyecto-final/` |

### Estructura de TUP-REPO para este proyecto

```
E:\SERJITO\TUP\TUP-REPO\BasedeDatosII\
    ├── semana-01\   ← repaso SQL, índices, secuencias
    ├── semana-02\   ← bloques anónimos, condicionales, bucles
    ├── semana-03\   ← procedimientos, funciones, %TYPE
    ├── semana-04\   ← SELECT INTO, cursores implícitos
    ├── semana-05\   ← cursores explícitos, SYS_REFCURSOR
    ├── semana-06\   ← triggers DML básicos
    ├── semana-07\   ← triggers avanzados, excepciones
    ├── semana-08\   ← excepciones avanzadas, repaso
    ├── semana-09\   ← paquetes
    ├── semana-10\   ← colecciones, variables bind
    ├── semana-11\   ← BULK COLLECT, FORALL
    ├── semana-12\   ← admin, usuarios, roles
    ├── semana-13\   ← perfiles, privilegios
    ├── semana-14\   ← índices, vistas, optimización
    ├── semana-15\   ← normalización, NoSQL
    ├── semana-16\   ← BD móviles, repaso final
    ├── proyecto-final\   ← proyecto integrador de la materia
    └── trabajos\    ← TPs y entregas de la materia
```

---

### Contenedor Docker — Oracle XE 21c

Entorno local de práctica. Permite ejecutar PL/SQL desde VS Code sin abrir SQL Developer. Los datos persisten entre reinicios gracias al volumen nombrado.

> **Nota:** todo el setup se hace manualmente siguiendo los pasos de abajo. El archivo `docker-compose.yml` va en `E:\SERJITO\TUP\TUP-REPO\BasedeDatosII\` junto al código.

---

#### Paso 1 — Crear el archivo `docker-compose.yml`

Ubicación: `E:\SERJITO\TUP\TUP-REPO\BasedeDatosII\docker-compose.yml`

```yaml
services:
  oracle-bdii:
    image: gvenzl/oracle-xe:21-slim
    container_name: oracle-bdii
    restart: unless-stopped
    ports:
      - "1521:1521"
    environment:
      ORACLE_PASSWORD: oracle
    volumes:
      - oracle-bdii-data:/opt/oracle/oradata
    healthcheck:
      test: ["CMD", "sqlplus", "-L", "system/oracle@//localhost/XEPDB1", "-S", "/nolog"]
      interval: 30s
      timeout: 10s
      retries: 10
      start_period: 120s

volumes:
  oracle-bdii-data:
```

---

#### Paso 2 — Levantar el contenedor (primera vez y uso diario)

Desde PowerShell o terminal WSL2, parado en la carpeta `BasedeDatosII\`:

```bash
# Levantar
docker compose up -d

# Ver que Oracle terminó de iniciar (esperar el mensaje DATABASE IS READY, ~2 min)
docker logs -f oracle-bdii

# Detener al terminar la sesión
docker compose down
```

> `restart: unless-stopped` hace que el contenedor arranque solo si Docker Desktop está corriendo y fue detenido manualmente antes. No arranca si lo paraste con `docker compose down`.

---

#### Paso 3 — Crear el schema de trabajo (una sola vez)

Una vez que Oracle está listo, conectarse como `system` y ejecutar:

```sql
-- Conectar como: system / oracle / host: localhost / port: 1521 / service: XEPDB1

CREATE USER serjito IDENTIFIED BY oracle
  DEFAULT TABLESPACE users
  QUOTA UNLIMITED ON users;

GRANT CREATE SESSION,
      CREATE TABLE,
      CREATE PROCEDURE,
      CREATE TRIGGER,
      CREATE SEQUENCE,
      CREATE VIEW
TO serjito;
```

---

#### Paso 4 — Conectar VS Code

- Instalar extensión: `Oracle Developer Tools for VS Code` (ID: `oracle.oracledevtools`)
- Crear nueva conexión con estos datos:

| Campo | Valor |
|---|---|
| Host | `localhost` |
| Port | `1521` |
| Service name | `XEPDB1` |
| User | `serjito` |
| Password | `oracle` |

Con esta conexión podés abrir cualquier `.sql` del repo y ejecutarlo directo desde VS Code con Ctrl+Enter, sin pasar por SQL Developer.

---

#### Uso diario resumido

| Acción | Cómo |
|---|---|
| Iniciar Oracle | `docker compose up -d` desde `BasedeDatosII\` |
| Verificar que está listo | `docker logs oracle-bdii` → buscar `DATABASE IS READY` |
| Conectar VS Code | Usar la conexión guardada `serjito@XEPDB1` |
| Ejecutar ejercicio | Abrir `.sql` del repo → Ctrl+Enter |
| Parar Oracle | `docker compose down` |

---

## 2. Second Brain en Obsidian


### Estructura de carpetas en el vault

```
E:\SERJITO\SB_Sergio\10-Proyectos\TUP-Materias\BDII\
├── 00-Dashboard-BDII.md
├── teoria\
│   ├── 01-repaso-sql-indices-secuencias.md
│   ├── 02-bloques-anonimos-variables.md
│   ├── 03-case-bucles.md
│   ├── 04-procedimientos-funciones.md
│   ├── 05-select-into-cursores-implicitos.md
│   ├── 06-cursores-explicitos.md
│   ├── 07-triggers.md
│   ├── 08-excepciones.md
│   ├── 09-paquetes.md
│   ├── 10-colecciones.md
│   ├── 11-administracion-seguridad.md
│   ├── 12-optimizacion-indices-vistas.md
│   ├── 13-normalizacion-nosql.md
│   └── 14-bd-moviles-repaso.md
└── seguimiento\
    ├── semana-01.md
    ├── semana-02.md
    └── ... (semana-16.md)
```

### Dashboard 00-Dashboard-BDII.md

```markdown
---
materia: Base de Datos II
cuatrimestre: 1C-2026
docente: Lic. Vilma Giudice
estado: en-progreso
---

# Dashboard — Base de Datos II

## Estado del cuatrimestre
- Fase actual: <!-- COMPLETAR -->
- Semana actual: <!-- COMPLETAR -->
- Próxima entrega: <!-- COMPLETAR -->

## Progreso por fase
- [ ] Fase 1 — Repaso SQL + Intro PL/SQL (sem. 1–2)
- [ ] Fase 2 — SQL en PL/SQL: cursores (sem. 3–5)
- [ ] Fase 3 — Triggers y Excepciones (sem. 6–8)
- [ ] Fase 4 — Paquetes y Colecciones (sem. 9–11)
- [ ] Fase 5 — Administración y temas finales (sem. 12–16)

## Notas de teoría
```dataview
TABLE estado FROM "10-Proyectos/TUP-Materias/BDII/teoria"
SORT file.name ASC
```

## Seguimiento semanal
```dataview
TABLE estado, objetivo FROM "10-Proyectos/TUP-Materias/BDII/seguimiento"
SORT file.name ASC
```
```

### Frontmatter de notas de teoría

```yaml
---
tema: [nombre del tema]
unidad: [número de unidad según el programa]
apunte-fuente: Parte [número] — Lic. Giudice
estado: pendiente
tags: [bdii, plsql, oracle, tup]
---
```

### Frontmatter de notas de seguimiento semanal

```yaml
---
semana: [número]
fase: [nombre de la fase]
objetivo: [qué se estudia esta semana]
tiempo-real: [minutos/horas efectivos]
estado: pendiente
bloqueos: []
---
```

### Valores válidos de `estado`

| Valor | Cuándo usarlo |
|---|---|
| `pendiente` | Al crear la nota |
| `en-progreso` | Al arrancar esa semana/unidad |
| `completa` | Al terminar |

### Plugins requeridos
- **Dataview** — para las queries del Dashboard
- **Tasks** — para los checkboxes con filtros
- **Kanban** — para vista de tablero
- **Periodic Notes** — para notas semanales automáticas
- **Remotely Save** — sync con Google Drive


---

## 3. Visión general

Base de Datos II es una materia de nivel 3 de la Tecnicatura Superior en Programación de UTN Haedo. El eje central es PL/SQL, la extensión procedimental de SQL de Oracle, que permite programar lógica compleja directamente en el motor de la base de datos: procedimientos almacenados, funciones, triggers, paquetes y manejo de excepciones. También cubre administración y seguridad (usuarios, roles, perfiles), que es conocimiento clave para trabajar en entornos de producción.

El aprendizaje se organiza en fases que respetan el orden del programa analítico: se arranca repasando SQL y creando índices/secuencias, luego se profundiza en PL/SQL unidad por unidad siguiendo los apuntes de la cátedra, y se cierra con administración, NoSQL y bases para móviles. La práctica se hace en SQL Developer contra Oracle Database Express 21c, que es el entorno oficial de la materia.


---

## 4. Objetivos medibles

| # | Objetivo | Criterio de éxito |
|---|---|---|
| 1 | Dominar la estructura y sintaxis de bloques PL/SQL (bloques anónimos, procedimientos, funciones) | Resolver los 10 ejercicios de bloques anónimos de la Parte 1 sin errores de compilación |
| 2 | Usar cursores implícitos y explícitos para recorrer resultados de consultas | Implementar los ejercicios de cursores de la Parte 3 usando FOR de cursor y FETCH correctamente |
| 3 | Crear y gestionar triggers DML (INSERT, UPDATE, DELETE) a nivel fila y sentencia | Completar los 10 ejercicios de disparadores de la Parte 4 incluyendo :NEW/:OLD y RAISE_APPLICATION_ERROR |
| 4 | Diseñar paquetes PL/SQL con especificación y cuerpo, aplicando sobrecarga de subprogramas | Armar el paquete `gest_emple` completo del ejercicio 4 de la Parte 6 |
| 5 | Administrar usuarios, roles, perfiles y privilegios en Oracle | Completar los 16 ejercicios de administración de la Parte 8 en SQL Developer |
| 6 | Aprobar los parciales de la materia | Nota igual o superior a 6 en ambos parciales |


---

## 5. Stack / herramientas / materiales

### Principal
- Oracle Database Express Edition 21c en Docker (`gvenzl/oracle-xe:21-slim`) — entorno local de estudio
- VS Code + extensión Oracle Developer Tools — IDE principal para el PRD
- SQL Developer — IDE oficial de la cátedra (para entregas y clases)
- PL/SQL (lenguaje de programación procedimental de Oracle)

### Complementario
- Oracle HR schema (tabla `employees`/`empleados` usada en todos los ejemplos)
- DBMS_OUTPUT (para debug de bloques anónimos)
- DBMS_UTILITY (paquete de utilidades Oracle)

### Bibliografía / documentación oficial
- Apuntes de PL/SQL Oracle — Partes 1 al 8 (Lic. Vilma Giudice · UTN FRH) — **fuente primaria**
- Programa analítico oficial UTN Haedo · Base de Datos II · Plan 2024
- Documentación oficial Oracle PL/SQL: https://docs.oracle.com/en/database/oracle/oracle-database/21/lnpls/
- Oracle SQL Developer: https://www.oracle.com/tools/downloads/sqldev-downloads.html

### Agente IA para este PRD
- **Agente:** Claude (claude.ai) — modo chat para sesiones de estudio y resolución de ejercicios
- **Por qué:** Acceso a los apuntes subidos como contexto; puede explicar conceptos, revisar código PL/SQL y generar variantes de ejercicios
- **Limitaciones:** No ejecuta código directamente; el código se pega en VS Code o se corre con `sqlplus` via Docker


---

## 6. Fases de aprendizaje

### FASE 1 — Repaso SQL + Intro PL/SQL (Semanas 1–2)
**Meta:** Repasar SQL del curso anterior, entender qué es PL/SQL y ejecutar los primeros bloques anónimos con variables, condicionales y bucles.

#### Semana 1 — Repaso SQL + Índices + Secuencias (Unidad I del programa)

**Revisión SQL y creación de índices/secuencias**
- Concepto: Repaso de SELECT, INSERT, UPDATE, DELETE. Creación de índices (CREATE INDEX) y secuencias (CREATE SEQUENCE). Son la base para Unidad II.
- Práctica: Crear índices sobre tablas del esquema HR. Crear una secuencia para generar IDs automáticos.
- 📖 **Leer:** Apunte Parte 1 — sección "¿Qué es PL/SQL?" y "Componentes básicos"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/01-repaso-sql-indices-secuencias.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-01/ejercicios-indices-secuencias.sql`

#### Semana 2 — Bloques anónimos, variables y condicionales (Unidad II + Parte 1)

**Arquitectura PL/SQL — DECLARE / BEGIN / EXCEPTION / END**
- Concepto: Estructura de un bloque PL/SQL. Variables locales y globales. Prefijos l_ y g_. DBMS_OUTPUT.put_line para mostrar resultados. Identificadores válidos en Oracle (máx 30 chars, case-insensitive).
- Práctica: Ejercicios 1 al 5 de "Ejercicios de Bloques Anónimos" (Parte 1).
- 📖 **Leer:** Apunte Parte 1 completo — secciones "Ejecución de bloques PL/SQL" y "Bifurcación Condicional en el Código" (IF-THEN, IF-THEN-ELSE, IF-ELSIF)
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/02-bloques-anonimos-variables.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-02/bloques-anonimos.sql`

**CASE y bucles (FOR, WHILE, LOOP)**
- Concepto: Sentencias CASE simple y de búsqueda. Bucle FOR numérico y de cursor. Bucle WHILE. Bucle simple (LOOP…EXIT WHEN). Principio "una entrada, una salida".
- Práctica: Ejercicios 6 al 10 de "Ejercicios de Bloques Anónimos" + ejercicios 1 al 5 de "Ejercicios de Bloques Almacenados" (Parte 2).
- 📖 **Leer:** Apunte Parte 1 — "CASE - Una alternativa útil a IF" y "Procesamiento Iterativo con Bucles" · Apunte Parte 2 — "Conversión de Datos"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/03-case-bucles.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-02/case-bucles.sql`

---

### FASE 2 — SQL en PL/SQL: procedimientos, funciones y cursores (Semanas 3–5)
**Meta:** Poder escribir procedimientos y funciones almacenados con parámetros IN/OUT y manejar cursores implícitos y explícitos para acceder a datos de tablas Oracle. Corresponde a Unidad III del programa.

#### Semana 3 — Procedimientos y funciones (Parte 2)

**Subprogramas almacenados: PROCEDURE y FUNCTION**
- Concepto: Diferencia entre procedimiento (acción) y función (retorna valor). Parámetros IN, OUT, IN OUT. CREATE OR REPLACE. Llamada desde bloques y desde SQL. DROP PROCEDURE.
- Práctica: Ejercicios 6 al 10 de "Ejercicios de Bloques Almacenados" (Parte 2). Crear `saludos` y `saludar` del apunte.
- 📖 **Leer:** Apunte Parte 2 — "Bloques Almacenados", "CASE - Una alternativa útil a IF", "Procedimientos con parámetros"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/04-procedimientos-funciones.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-03/procedimientos-funciones.sql`

**%TYPE y %ROWTYPE**
- Concepto: %TYPE para anclar variable al tipo de una columna. %ROWTYPE para declarar un registro completo de una tabla. Evitan errores si cambia la estructura de la tabla.
- Práctica: Reescribir 3 procedimientos de semana anterior usando %TYPE y %ROWTYPE.
- 📖 **Leer:** Apunte Parte 2 — "Más sobre Declaración de Variables"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/04-procedimientos-funciones.md` *(ampliar)*
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-03/type-rowtype.sql`

#### Semana 4 — SELECT INTO y cursores implícitos (Parte 3)

**SELECT INTO y cursores implícitos**
- Concepto: SELECT INTO recupera exactamente una fila. Errores SQL%NO_DATA_FOUND y SQL%TOO_MANY_ROWS. Atributos de cursor: %FOUND, %NOTFOUND, %ROWCOUNT, %ISOPEN.
- Práctica: Ejercicios 1 al 5 de "Ejercicios de Cursores" (Parte 3).
- 📖 **Leer:** Apunte Parte 3 — "Introducción", "El Cursor SELECT-INTO", "Cursores Implícitos"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/05-select-into-cursores-implicitos.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-04/select-into.sql`

#### Semana 5 — Cursores explícitos y variables de cursor (Parte 3)

**Cursores explícitos: OPEN, FETCH, CLOSE**
- Concepto: CURSOR nombre IS SELECT… Ciclo OPEN → FETCH → EXIT WHEN %NOTFOUND → CLOSE. Bucle FOR de cursor (abre y cierra automáticamente). Variables de cursor SYS_REFCURSOR.
- Práctica: Ejercicios 6 al 10 de "Ejercicios de Cursores" (Parte 3).
- 📖 **Leer:** Apunte Parte 3 — "Los Cursores Explícitos - Obtención de Cursores", "Usando el Bucle FOR del Cursor", "Variables de cursor"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/06-cursores-explicitos.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-05/cursores-explicitos.sql`

---

### FASE 3 — Triggers y Excepciones (Semanas 6–8)
**Meta:** Crear disparadores DML para automatizar lógica de negocio y manejar excepciones propias y predefinidas de Oracle de manera robusta.

#### Semana 6 — Triggers DML (Parte 4)

**Sintaxis de triggers: BEFORE/AFTER, STATEMENT/FOR EACH ROW**
- Concepto: CREATE OR REPLACE TRIGGER. Momento (BEFORE/AFTER/INSTEAD OF). Evento (INSERT/UPDATE/DELETE). Nivel (STATEMENT vs FOR EACH ROW). Pseudoregistros :NEW y :OLD. INSERTING, UPDATING, DELETING. RAISE_APPLICATION_ERROR.
- Práctica: Ejercicios 1 al 5 de "Ejercicios de Disparadores" (Parte 4). Crear tabla `control` para auditoría.
- 📖 **Leer:** Apunte Parte 4 completo — "Los Disparadores – Los Triggers", "Sintaxis de un Disparador", "Disparadores de Inserción a Nivel de Sentencia", "Disparadores de Actualización a Nivel de Fila"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/07-triggers.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-06/triggers.sql`

#### Semana 7 — Triggers avanzados + Excepciones (Partes 4 y 5)

**Triggers INSTEAD OF + habilitar/deshabilitar**
- Concepto: INSTEAD OF sobre vistas. ALTER TRIGGER ENABLE/DISABLE. DROP TRIGGER. Consulta de disparadores en user_triggers y user_objects.
- Práctica: Ejercicios 6 al 10 de "Ejercicios de Disparadores" (Parte 4).
- 📖 **Leer:** Apunte Parte 4 — "Creación de un Disparador INSTEAD OF", "Habilitar y Deshabilitar Disparadores", "Eliminar un Disparador"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/07-triggers.md` *(ampliar)*
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-07/triggers-avanzados.sql`

**Manejo de excepciones (Parte 5)**
- Concepto: Tres categorías: definidas internamente, predefinidas (NO_DATA_FOUND, TOO_MANY_ROWS, ZERO_DIVIDE, DUP_VAL_ON_INDEX, etc.) y definidas por el usuario. RAISE, RAISE_APPLICATION_ERROR. Sección EXCEPTION con cláusulas WHEN. Transacciones autónomas (PRAGMA AUTONOMOUS_TRANSACTION). SQLCODE y SQLERRM.
- Práctica: Ejercicios 1 al 5 de "Ejercicios de Excepciones" (Parte 5).
- 📖 **Leer:** Apunte Parte 5 completo — "Las Excepciones", "Levantar Excepciones", "Definición de Excepciones Propias", "Manejo de Excepciones", "Registro de errores"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/08-excepciones.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-07/excepciones.sql`

#### Semana 8 — Excepciones avanzadas + repaso Fases 1-3

**Excepciones avanzadas y repaso general**
- Concepto: Volver a lanzar excepciones (RAISE sin argumento). Excepciones generadas en la declaración. Manejador OTHERS. Relación excepciones–transacciones y ROLLBACK.
- Práctica: Ejercicios 6 al 10 de "Ejercicios de Excepciones" (Parte 5). Repaso global de fases 1–3.
- 📖 **Leer:** Apunte Parte 5 — "Volver a Lanzar Excepciones", "Excepciones Generadas durante la Declaración", "Excepciones y Reversiones"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/08-excepciones.md` *(completar)*
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-08/excepciones-avanzadas.sql`

---

### FASE 4 — Paquetes y Colecciones (Semanas 9–11)
**Meta:** Organizar código PL/SQL en paquetes reutilizables y manejar estructuras de datos complejas con colecciones.

#### Semana 9 — Paquetes PL/SQL (Parte 6)

**CREATE PACKAGE y CREATE PACKAGE BODY**
- Concepto: Especificación (interfaz pública) vs cuerpo (implementación). Variables a nivel de paquete y su persistencia en sesión. Sobrecarga de subprogramas. Directrices para escritura de paquetes. Estado del paquete y error ORA-04068.
- Práctica: Ejercicios 1 y 2 de "Ejercicios de Paquetes" (Parte 6). Crear `empleado_pkg` y `timer_pkg` del apunte.
- 📖 **Leer:** Apunte Parte 6 completo — "Los Paquetes", "Especificación", "Cuerpo", "Datos a nivel de paquete", "Sobrecarga de Subprogramas", "Directrices para la Escritura de Paquetes"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/09-paquetes.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-09/paquetes.sql`

#### Semana 10 — Variables de sustitución y colecciones (Partes 7 y 7)

**Variables de sustitución y bind, colecciones PL/SQL**
- Concepto: Variables de sustitución (&, &&). Variables de enlace/bind (VARIABLE, EXEC). Tres tipos de colecciones: VARRAY (tamaño fijo, denso), tabla anidada (escasa o densa, operadores MULTISET), matriz asociativa (INDEX BY). Métodos: FIRST, LAST, COUNT, EXTEND, DELETE, TRIM, NEXT, PRIOR.
- Práctica: Ejercicios 3 al 5 de "Ejercicios de Paquetes" (Parte 6). Implementar ejemplos de Varrays y Tablas Anidadas (Parte 7).
- 📖 **Leer:** Apunte Parte 7 — "Ingresar un Dato por Teclado", "Trabajando con Colecciones en PL/SQL", "Tres tipos de colecciones", "Inicializar Colecciones", "Poblando Colecciones", "Iterando a Través de Colecciones"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/10-colecciones.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-10/colecciones.sql`

#### Semana 11 — BULK COLLECT y FORALL (Parte 7)

**Procesamiento masivo de datos**
- Concepto: BULK COLLECT: recuperar múltiples filas en una colección con un solo cambio de contexto (SELECT * BULK COLLECT INTO). FORALL: ejecutar DML masivo sobre colecciones. Cambios de contexto PL/SQL↔SQL y por qué BULK COLLECT/FORALL mejoran el rendimiento. DBMS_UTILITY.
- Práctica: Implementar los ejemplos de BULK COLLECT y FORALL del apunte (Parte 7). Ejercicios 4 y 5 de Paquetes.
- 📖 **Leer:** Apunte Parte 7 — "BULK COLLECT y FORALL", "Cambios de contexto y rendimiento", "El Paquete DBMS_UTILITY"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/10-colecciones.md` *(ampliar con BULK COLLECT)*
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-11/bulk-collect-forall.sql`

---

### FASE 5 — Administración, Seguridad y Temas Finales (Semanas 12–16)
**Meta:** Administrar una base de datos Oracle creando usuarios, roles y perfiles. Entender los conceptos de las unidades 4–8 del programa (gestión de índices/vistas, administración, mantenimiento, normalización avanzada, NoSQL, BD móviles).

#### Semanas 12–13 — Administración y seguridad (Unidades 4 y 5 · Parte 8)

**Usuarios, privilegios, roles y perfiles**
- Concepto: DBA y sus responsabilidades. CREATE USER, DROP USER CASCADE, ALTER USER. Privilegios de sistema (CREATE SESSION, CREATE TABLE, etc.) y de objeto (SELECT, INSERT, etc.). GRANT y REVOKE. Roles predefinidos (DBA, CONNECT). CREATE ROLE. CREATE PROFILE con LIMITS. Tablespace y quota. Esquema = conjunto de objetos del usuario.
- Práctica: Ejercicios 1 al 16 de "Ejercicios de Administración" (Parte 8). Crear usuario de prueba con rol y perfil personalizado.
- 📖 **Leer:** Apunte Parte 8 completo — "Administración de Bases de Datos", "Los Usuarios – Privilegios, Roles y Perfiles", "Seguridad y Acceso a la Base de Datos", "Crear un Usuario", "Permisos y Privilegios", "Roles", "Crear un Perfil"
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/11-administracion-seguridad.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-12/admin-usuarios-roles.sql`

#### Semana 14 — Optimización, índices, vistas y mantenimiento (Unidades 2, 3 y 5)

**Optimización de consultas, gestión de índices y vistas, mantenimiento de BD**
- Concepto: Fundamentos de optimización de consultas. Tipos de índices (B-tree, bitmap). Vistas y vistas materializadas. Tareas de mantenimiento de una base de datos Oracle. Backup y recuperación básica (conceptos DBA).
- Práctica: Crear índices sobre tablas del laboratorio. Crear vistas y analizar planes de ejecución con EXPLAIN PLAN.
- 📖 **Leer:** Documentación Oracle — sección sobre índices y optimización (verificar URL con web search antes de estudiar)
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/12-optimizacion-indices-vistas.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-14/indices-vistas.sql`

#### Semana 15 — Normalización avanzada y NoSQL (Unidades 6 y 7)

**Normalización hasta 5FN y tecnologías NoSQL**
- Concepto: Repaso de formas normales. 4FN y 5FN. Eliminación de redundancia. Introducción a NoSQL: modelos documento (MongoDB), clave-valor (Redis), columnar (Cassandra), grafo (Neo4j). Diferencias con el modelo relacional.
- Práctica: Ejercicios de normalización con esquemas propuestos por la docente. Explorar la interfaz de MongoDB Atlas (free tier).
- 📖 **Leer:** Material de la cátedra + documentación introductoria de MongoDB (https://www.mongodb.com/docs/manual/introduction/)
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/13-normalizacion-nosql.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-15/normalizacion.sql`

#### Semana 16 — BD para dispositivos móviles + repaso final (Unidad 8)

**Base de datos para dispositivos móviles y repaso integral**
- Concepto: Características de BD móviles (SQLite, Room para Android). Sincronización offline-online. Repaso integral de PL/SQL, triggers, paquetes y administración en preparación para el final.
- Práctica: Repaso de todos los ejercicios clave. Resolver ejercicios combinados de parcial.
- 📖 **Leer:** Material de la cátedra sobre BD móviles + documentación SQLite: https://www.sqlite.org/docs.html
- 🗒️ **Nota Obsidian:** `SB_Sergio/10-Proyectos/TUP-Materias/BDII/teoria/14-bd-moviles-repaso.md`
- 💾 **Guardar en:** `TUP-REPO/BasedeDatosII/semana-16/repaso-final.sql`


---

## 7. Recursos de aprendizaje

| Recurso | URL / Referencia | Para qué fase |
|---|---|---|
| Apuntes PL/SQL Partes 1–8 (Giudice) | `/mnt/user-data/uploads/Apunte_de_PL_SQL_-_Parte_*.pdf` | Todas |
| Programa oficial UTN Haedo | `/mnt/user-data/uploads/Programa_BDII.pdf` | Planificación general |
| Documentación Oracle PL/SQL 21c | https://docs.oracle.com/en/database/oracle/oracle-database/21/lnpls/ | Fases 2–4 |
| Oracle SQL Developer descarga | https://www.oracle.com/tools/downloads/sqldev-downloads.html | Configuración inicial |
| SQLite docs (BD móviles) | https://www.sqlite.org/docs.html | Fase 5 — Semana 16 |
| MongoDB docs introducción | https://www.mongodb.com/docs/manual/introduction/ | Fase 5 — Semana 15 |


---

## 8. Archivos de referencia

La materia no requiere configuración de entorno compleja. El entorno ya está dado por SQL Developer + Oracle 21c XE.

Estructura mínima de un bloque PL/SQL de referencia:
```sql
-- Template bloque anónimo completo
DECLARE
  l_variable TIPO_DATO := valor_inicial;
BEGIN
  -- sentencias ejecutables
  DBMS_OUTPUT.put_line('resultado: ' || l_variable);
EXCEPTION
  WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.put_line('No se encontraron datos');
  WHEN OTHERS THEN
    DBMS_OUTPUT.put_line(SQLERRM);
    RAISE;
END;
/
```

Template de procedimiento almacenado:
```sql
CREATE OR REPLACE PROCEDURE nombre_proc (
  p_param1 IN  tabla.columna%TYPE,
  p_param2 OUT NUMBER
) IS
  l_variable VARCHAR2(100);
BEGIN
  SELECT columna INTO l_variable FROM tabla WHERE condicion;
  p_param2 := /* resultado */;
EXCEPTION
  WHEN OTHERS THEN
    RAISE_APPLICATION_ERROR(-20001, 'Error: ' || SQLERRM);
END nombre_proc;
/
```

Template de trigger con :NEW/:OLD:
```sql
CREATE OR REPLACE TRIGGER nombre_trigger
  BEFORE UPDATE ON nombre_tabla
  FOR EACH ROW
BEGIN
  IF UPDATING('campo') THEN
    INSERT INTO control VALUES (USER, SYSDATE, :OLD.campo, :NEW.campo);
  END IF;
END nombre_trigger;
/
```


---

## 9. Criterios de finalización

- [ ] Completar y guardar en TUP-REPO los ejercicios de bloques anónimos (Parte 1, 10 ejercicios)
- [ ] Completar y guardar los ejercicios de bloques almacenados (Parte 2, 10 ejercicios)
- [ ] Completar y guardar los ejercicios de cursores (Parte 3, 10 ejercicios)
- [ ] Completar y guardar los ejercicios de triggers (Parte 4, 10 ejercicios)
- [ ] Completar y guardar los ejercicios de excepciones (Parte 5, 10 ejercicios)
- [ ] Completar y guardar los ejercicios de paquetes (Parte 6, 5 ejercicios)
- [ ] Completar los ejercicios de administración (Parte 8, 16 ejercicios)
- [ ] Tener todas las notas de teoría creadas en Obsidian (notas 01 al 14)
- [ ] Aprobar el primer parcial con nota ≥ 6
- [ ] Aprobar el segundo parcial o final con nota ≥ 6


---

## 10. Flujo de sesión diaria

```
[ 5 min ]   Apertura
[ 25–35 min ] Trabajo principal
[ 5 min ]   Cierre
```

### Apertura
1. Abrir `00-Dashboard-BDII.md` — ver qué está `en-progreso` o `pendiente`
2. Abrir nota de seguimiento de la semana actual
3. Definir **un solo objetivo** para esta sesión
4. Cambiar estado a `en-progreso` si corresponde

### Trabajo principal
- **Teoría:** leer sección del apunte de Giudice → completar nota en Obsidian
- **Práctica:** escribir y ejecutar el ejercicio en SQL Developer → guardar .sql en TUP-REPO/BasedeDatosII
- **Mixto:** 15 min teoría del apunte + 15 min ejercicio en SQL Developer

> **Regla:** si en 10 min no avanzás por un bloqueo, anotarlo en "Bloqueos y dudas" y seguir con lo próximo.

### Cierre
1. Registrar en seguimiento: qué hiciste + tiempo real
2. Cambiar `estado` a `completa` si terminaste
3. Guardar los .sql en TUP-REPO/BasedeDatosII
4. Anotar objetivo de la próxima sesión

### Instrucciones para el agente IA

Cuando el usuario diga **"arrancamos sesión"** o similar:
```
1. Preguntar en qué semana/unidad está
2. Mostrar el objetivo pendiente más próximo según este PRD
3. Proponer trabajo concreto de esta sesión (teoría de apunte, ejercicio específico o mixto)
4. Indicar qué apunte (Parte X, sección Y) debe leer
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

### Fuentes válidas para este PRD (tipo: materia)

| Tipo de contenido | Fuente permitida | Fuente prohibida |
|---|---|---|
| Sintaxis PL/SQL | Apuntes de Giudice (Partes 1–8) + Docs Oracle 21c | Blogs, Medium, tutoriales de terceros, memoria del modelo |
| Estructura del programa | Programa oficial UTN Haedo (PDF) | Otros programas de BD de otras universidades |
| Ejercicios | Apuntes de Giudice (única fuente) | Ejercicios generados desde memoria sin verificar |
| Administración Oracle | Apunte Parte 8 + Docs Oracle oficiales | Wikipedia, resúmenes de terceros |
| NoSQL / BD móviles | Documentación oficial MongoDB y SQLite | Tutoriales de terceros |

### Protocolo antihallucinación por acción

| Acción del agente | Protocolo |
|---|---|
| Explicar sintaxis PL/SQL | Citar el apunte de Giudice (Parte X, sección Y) antes de explicar |
| Revisar código del estudiante | Comparar contra ejemplos de los apuntes; indicar la fuente |
| Recomendar una herramienta | Verificar con web search que sigue activa y es versión correcta |
| Completar una nota de teoría | Cada afirmación debe tener fuente en los apuntes de Giudice o docs Oracle |
| Generar ejercicio variante | Indicar que es variante generada, no del apunte oficial |

### Señales de alerta para el usuario

Si el agente dice alguna de estas frases **sin citar el apunte de Giudice o la doc Oracle oficial**, detenerlo y pedir verificación:
- *"Generalmente en PL/SQL..."*
- *"Típicamente en Oracle..."*
- *"Creo que la sintaxis es..."*
- *"Debería funcionar..."*
- *"En la mayoría de los casos..."*

---

*PRD generado por Claude (claude.ai) · Mayo 2026*
*Basado en: Programa oficial UTN Haedo Base de Datos II Plan 2024 + Apuntes de PL/SQL Oracle Partes 1–8 (Lic. Vilma Giudice · UTN FRH)*
*Compatible con: Claude · Claude Code · Cursor · cualquier agente con acceso a archivos*
