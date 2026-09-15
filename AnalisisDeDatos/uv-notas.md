# uv — Beneficios y funcionamiento

Notas para la materia Análisis de Datos (entorno con numpy/pandas).

## ¿Qué es uv?

`uv` es un gestor de paquetes y entornos de Python hecho por Astral (los de Ruff), escrito en Rust.
Reemplaza en una sola herramienta a `pip`, `venv`, `virtualenv` y `pip-tools`.

## Beneficios frente al flujo clásico (pip + venv)

- **Velocidad**: instala paquetes 10-100x más rápido que pip (cache global + resolución en paralelo). Se nota bastante con paquetes pesados como numpy/pandas, sobre todo en reinstalaciones.
- **Lockfile determinístico**: `uv add` genera `uv.lock` con las versiones exactas resueltas. Mismo lockfile = mismas versiones en cualquier máquina, evita el clásico "en mi compu funciona".
- **Resolución de dependencias más robusta**: detecta conflictos de versiones antes de instalar, no a mitad de instalación como puede pasar con pip.
- **Todo en un binario**: no hace falta `pip`, `venv`, `virtualenv` ni `pip-tools` por separado.
- **`uv run`**: corre scripts sin activar el venv a mano (`uv run python script.py`), detecta y usa el entorno del proyecto automáticamente.
- **Gestión de versiones de Python**: `uv python install 3.12` baja e instala versiones de Python sin depender de pyenv.
- **Cache global compartido**: si dos proyectos usan numpy 2.0, no se descarga dos veces — usa hardlinks desde un cache central en disco.
- **No contamina el Python del sistema**: cada proyecto tiene su propio `.venv/` local, aislado.

## Cómo funciona `uv sync`

`uv sync` es el comando que **reconstruye el entorno virtual (`.venv/`) para que coincida exactamente con lo que dice `uv.lock`**.

Flujo típico:

1. El proyecto tiene un `pyproject.toml` (declara las dependencias, ej. `numpy`, `pandas`) y un `uv.lock` (versiones exactas resueltas y congeladas, generado automáticamente por `uv add`/`uv lock`).
2. Al correr `uv sync`:
   - Si no existe `.venv/`, lo crea.
   - Instala/actualiza/desinstala paquetes en el venv hasta que coincida **exactamente** con `uv.lock` (no resuelve versiones nuevas, solo aplica lo que ya está fijado en el lockfile).
   - Es rápido porque usa el cache global — si ya tenés numpy 2.0 descargado para otro proyecto, lo enlaza en vez de descargarlo de nuevo.
3. Resultado: un entorno reproducible bit a bit, igual en tu PC, en la del profesor, o en un servidor/CI.

### Cuándo usarlo

- Después de clonar el repo en otra máquina: `uv sync` te deja el entorno listo en segundos, con las mismas versiones que usaste vos.
- Después de que alguien (o vos) modifique `pyproject.toml`/`uv.lock` a mano o vía `git pull`.
- Como paso de "instalación" en vez de `pip install -r requirements.txt`.

### Comandos relacionados

```bash
uv init                  # crea pyproject.toml en la carpeta actual
uv add numpy pandas      # agrega dependencias, actualiza pyproject.toml y uv.lock, sincroniza el venv
uv sync                  # reconstruye .venv/ para que coincida con uv.lock
uv run python script.py  # ejecuta usando el entorno del proyecto, sin activar nada a mano
uv lock                  # recalcula uv.lock sin tocar el venv
```

## Setup rápido para esta materia

```bash
cd D:/DEV/Tup-repo/AnalisisDeDatos
uv init
uv add numpy pandas
uv run python -c "import numpy, pandas; print('ok')"
```

En otra máquina, para reproducir el entorno exacto:

```bash
git clone <repo>
cd AnalisisDeDatos
uv sync
```
