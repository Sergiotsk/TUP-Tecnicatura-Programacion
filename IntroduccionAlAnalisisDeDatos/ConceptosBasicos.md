# Conceptos Básicos — Introducción al Análisis de Datos

Apunte de arranque de la materia. Complementa al [README.md](README.md), que tiene la guía completa de UV.

---

## 1. Entornos virtuales con UV

### El concepto clave

El entorno virtual encapsula **las dependencias del proyecto**, no el contenido del proyecto. Un *entorno* = una *caja de herramientas* que contiene exactamente los paquetes que tu proyecto necesita (y las versiones exactas).

### La regla de oro

> **Un proyecto = un entorno.**

Toda la materia usa el mismo stack (pandas, numpy, matplotlib, jupyter), así que alcanza con UN solo entorno en la raíz:

```
IntroduccionAlAnalisisDeDatos/
├── pyproject.toml     ← UN solo proyecto UV
├── uv.lock
├── notebooks/         ← la separación LÓGICA de prácticas va acá
└── data/
```

### Por qué NO un entorno por práctica

- **Desperdicio de disco**: cada entorno con pandas + jupyter pesa 1-2 GB (numpy trae librerías compiladas). Cinco prácticas = cinco copias idénticas.
- **Confusión**: entornos anidados compiten por el `PATH` y los lockfiles se solapan.
- **Reproducibilidad al pedo**: versionás el mismo resultado varias veces.

### Cómo se separan las prácticas

Con **carpetas**, no con entornos:

```
notebooks/clase-01/
notebooks/clase-02/
```

Recién se separa en un proyecto UV aparte cuando una práctica pide dependencias **incompatibles** con el resto (ej: `pandas==1.5` vs `pandas==2.2`). Para eso falta mucho en una materia introductoria.

### Comandos que no fallan

| Comando | Qué hace |
|---|---|
| `uv init` | Inicializa el proyecto (crea `pyproject.toml`, `main.py`, `.python-version`) |
| `uv add pandas` | Agrega dependencia y crea/actualiza el entorno `.venv/` |
| `uv sync` | Reconstruye el entorno exactamente como dice `uv.lock` (después de un clone/pull) |
| `uv run <comando>` | Ejecuta cualquier cosa DENTRO del entorno del proyecto |

**Nunca** actives el venv a mano ni instales nada con `pip` directo. Ese es el camino del dolor.

---

## 2. Jupyter e ipykernel

### La analogía: el auto y el motor

| Pieza | Rol | Analogía |
|---|---|---|
| **Jupyter** | Interfaz de notebooks (Jupyter Lab es el sucesor moderno de Notebook) | El auto: tablero, volante, pantalla |
| **Kernel** | Proceso aparte que recibe el código, lo ejecuta y devuelve resultados | El motor: hace el trabajo real |
| **ipykernel** | Kernel específico de **Python** | El motor que habla el idioma Python |

**Jupyter NO ejecuta código. Jupyter es solo la pantalla.** Detrás de cada notebook hay un kernel que hace el trabajo. Por eso existen kernels por lenguaje:

- `ipykernel` → Python
- `IRkernel` → R
- `IJulia` → Julia

(el nombre Jupyter viene de **Ju**lia + **Py**thon + **R**)

### Por qué se instalan los DOS

```bash
uv add jupyter ipykernel
```

- `jupyter` = el auto (la interfaz)
- `ipykernel` = el motor (el adaptador Python)

Falta uno y no andás. Además, `ipykernel` debe estar DENTRO del `.venv` del proyecto para que los notebooks usen el Python que tiene las dependencias instaladas (con `uv add` queda ahí automáticamente).

### El bloque de celdas / kernel

- Un notebook (`.ipynb`) es un archivo JSON con celdas de tipo `code`, `markdown` y `raw`.
- Las variables viven en el **kernel**, no en el archivo.
- Por eso importa el **orden de ejecución**: si corrés una celda que usa una variable definida en otra celda que nunca ejecutaste, explota o te da resultados viejos. *"Funciona en mi máquina"*, versión notebook.

---

## 3. Ejecutar scripts con Python (y UV)

### El intérprete correcto

Tu código no lo ejecuta "Python a secas" — lo ejecuta **UN intérprete específico**. `uv run` se asegura de que uses SIEMPRE el del proyecto:

| Comando | Usa | Cuándo |
|---|---|---|
| `uv run main.py` | Python del `.venv` (con todas las dependencias) | ✅ **Siempre, en este repo** |
| `python main.py` | Python del sistema (sin pandas ni nada del proyecto) | ❌ No — `ModuleNotFoundError` asegurado |
| `py main.py` | Launcher de Windows | Solo fuera de un proyecto UV |

Si el script no se llama `main`, da igual — se ejecuta igual con su ruta:

```bash
uv run notebooks/ejercicio_01.py
```

### La variante explícita

```bash
uv run python main.py
```

Es 100% equivalente a `uv run main.py`. Ser explícito sobre el programa deja más claro qué está pasando cuando alguien lee la terminal.

### `if __name__ == "__main__":`

La estructura canónica que genera `uv init`:

```python
def main():
    print("Hello from tu-proyecto!")

if __name__ == "__main__":
    main()
```

Le dice a Python: "ejecutá esto SOLO si corren este archivo directamente". Si el archivo se importa como módulo desde otro programa, ese bloque NO se ejecuta. La diferencia entre "el protagonista" y "el ayudante de otro".

---

## Resumen mental (lo que sale en el parcial)

1. **Entorno virtual** = caja de herramientas del proyecto. Un proyecto, un entorno.
2. **Jupyter** = la interfaz (el auto). **Kernel** = el proceso que ejecuta (el motor). **ipykernel** = el motor de Python.
3. **`uv run`** = el operario que siempre te hace usar la máquina correcta.