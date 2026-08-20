# Introducción al Análisis de Datos — 2026-2C

Materia en la que trabajamos con **Python** y la librería **pandas** para análisis de datos.

El entorno de este proyecto se gestiona con **[UV](https://docs.astral.sh/uv/)**, un gestor de paquetes y entornos virtuales para Python (escrito en Rust, muchísimo más rápido que `pip` + `venv` tradicional).

## ¿Por qué UV y no pip/venv a mano?

Con el flujo clásico de Python tenés que hacer manualmente: crear un venv (`python -m venv .venv`), activarlo, instalar paquetes con `pip install`, y llevar un `requirements.txt` a mano que se desactualiza solo. UV resuelve todo eso en un único flujo:

- Gestiona la versión de Python por vos (si no tenés la que hace falta, la descarga).
- Crea y administra el entorno virtual (`.venv`) automáticamente.
- Mantiene un **lockfile** (`uv.lock`) con las versiones EXACTAS de cada dependencia (y sus sub-dependencias), para que el entorno sea reproducible byte a byte en cualquier máquina.

## Guía paso a paso (hacelo vos, en la terminal, en esta carpeta)

No copies y pegues sin pensar. Ejecutá cada comando, mirá qué archivos aparecen o cambian, y preguntate por qué.

### 1. Inicializar el proyecto

```bash
uv init
```

Esto crea:

- `pyproject.toml` → el archivo de configuración del proyecto (nombre, versión, dependencias, versión mínima de Python requerida). Es el equivalente al `package.json` de Node.
- `main.py` → un script de ejemplo.
- `.python-version` → fija qué versión de Python usa este proyecto.

### 2. Agregar pandas como dependencia

```bash
uv add pandas
```

Fijate qué pasa acá — es importante:

- UV crea el entorno virtual `.venv/` si todavía no existe.
- Descarga pandas y sus dependencias (numpy, python-dateutil, pytz, etc.).
- Actualiza `pyproject.toml` (agrega `pandas` a la lista de dependencias).
- Genera/actualiza `uv.lock` con las versiones exactas resueltas.

**Dato importante que vas a descubrir vos solo:** puede que UV NO use la versión de Python más nueva que tengas instalada en el sistema (`python --version`). UV elige una versión compatible con las dependencias que estás instalando, para evitar romper el entorno. Corré `uv python list` y `cat .python-version` (o `bat .python-version`) para ver qué versión terminó usando y pensá por qué.

### 3. (Opcional) Agregar Jupyter para trabajar con notebooks

```bash
uv add jupyter ipykernel
```

### 4. Correr código dentro del entorno

Nunca actives el venv a mano ni instales nada con `pip` directo. Usá siempre:

```bash
uv run main.py          # corre un script dentro del entorno del proyecto
uv run jupyter lab       # levanta Jupyter Lab dentro del entorno del proyecto
```

`uv run` garantiza que SIEMPRE estás usando el Python y las dependencias de `.venv`, sin tener que activarlo manualmente.

### 5. Comandos que vas a usar seguido durante la materia

| Comando | Qué hace |
|---|---|
| `uv add <paquete>` | Agrega una dependencia nueva (ej: `uv add matplotlib`) |
| `uv remove <paquete>` | Saca una dependencia |
| `uv sync` | Reinstala el entorno exactamente como dice `uv.lock` (útil después de un `git clone` o `git pull`) |
| `uv run <comando>` | Ejecuta algo dentro del entorno del proyecto |
| `uv python list` | Ver qué versiones de Python tiene UV disponibles/instaladas |

## Qué NO va al repositorio (`.gitignore` del repo raíz)

- `.venv/` → el entorno virtual no se versiona nunca. Se reconstruye con `uv sync` a partir de `uv.lock`.
- `pyproject.toml` y `uv.lock` **SÍ se versionan** — son los que garantizan que cualquiera que clone el repo pueda reproducir el mismo entorno.

## Estructura sugerida a medida que avance la materia

```
IntroduccionAlAnalisisDeDatos/
├── README.md
├── pyproject.toml
├── uv.lock
├── notebooks/       # ejercicios y análisis exploratorios (.ipynb)
└── data/            # datasets de la cátedra (considerar si van al repo o al .gitignore según tamaño/licencia)
```
