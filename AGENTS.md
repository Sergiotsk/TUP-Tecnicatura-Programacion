# AGENTS.md - TUP Learning Hub Guidelines

## Project Overview
This is a **student learning hub** for the **Tecnicatura Universitaria en Programación (TUP)** at UTN. It contains active coursework, approved subjects for review, and a structured learning system with progress tracking, notes, and templates.

### Directory Structure

#### Active Subjects (cursando ahora)
| Folder | Language | Description |
|--------|----------|-------------|
| `ProgramacionIII/` | JavaScript | Web programming - HTML/CSS/JS, OOP, DOM, APIs |
| `BasedeDatosII/` | PL/SQL | Oracle PL/SQL - procedures, triggers, packages, cursors |
| `InglesTecnico2/` | English | Technical vocabulary, reading comprehension, translation |
| `MetodologiasDeSistemas1/` | UML/Design | Software engineering, UML, SCRUM, design patterns |

#### Approved Subjects (ya rendidas - modo repaso)
| Folder | Language | Description |
|--------|----------|-------------|
| `Aprobadas/ProgramacionI/` | C | Intro programming - arrays, matrices, functions |
| `Aprobadas/ProgramacionII/` | C | Data structures - structs, linked lists, sorting |
| `Aprobadas/BasedeDatosI/` | SQL | Database fundamentals - Oracle SQL |
| `Aprobadas/ProbabilidadyEstadisticas/` | Python | Statistics - probability, confidence intervals |
| `Aprobadas/PracticasLibres/` | C++ | Free practice projects (Tetris, FolderOrganizer) |
| `Aprobadas/Matematica/` | Math | Algebra, calculus |
| `Aprobadas/ArquitecturaDeComputadoras/` | Architecture | Computer architecture, assembly |
| `Aprobadas/SistemasOperativos/` | OS | Processes, memory, file systems |
| `Aprobadas/Ingles1/` | English | Basic English |
| `Aprobadas/OrganizacionEmpresarial/` | Business | Organization management |

#### Learning System
| Folder | Description |
|--------|-------------|
| `Aprendizaje/Progreso/` | Progress checklists per subject |
| `Aprendizaje/Notas/` | Learning notes per topic |
| `Aprendizaje/Templates/` | Code templates with note sections |

## Agent Modes

The agent operates in different modes depending on context. You can explicitly request a mode:

| Mode | Trigger | Behavior |
|------|---------|----------|
| **Tutor** | `/tutor` or context: "ayudame a resolver" | Ask guiding questions, never give direct answers. Lead through discovery. |
| **Reviewer** | `/revisar` or context: "revisá mi código" | Review code, suggest improvements, explain errors. Be thorough but constructive. |
| **Explainer** | `/explicar` or context: "explicame" | Explain concepts with examples. Use analogies. Connect to previous knowledge. |
| **English** | `/traducir` or context: "traducí" / "cómo se dice" | Translate technical terms, explain vocabulary in context, provide examples. |
| **Review Mode** | `/repaso [materia]` | Quiz you on approved subjects. Ask questions from the progress checklist. |
| **Default** | No explicit mode | Adapt to context: tutor for exercises, reviewer for code, explainer for questions. |

## Conversation Commands

| Command | Description |
|---------|-------------|
| `/revisar` | Review code and suggest improvements |
| `/explicar` | Explain a concept or error |
| `/compilar` | Compile and execute (ONLY when explicitly requested) |
| `/progreso` | Show/update progress checklist for a subject |
| `/notas` | Add learning notes about a topic |
| `/traducir` | Translate technical text or explain vocabulary |
| `/repaso [materia]` | Start review quiz for an approved subject |
| `/tutor` | Switch to Socratic tutoring mode |

## Build Commands

### C Files (Aprobadas/ProgramacionI, II)
```bash
# Build single C file with gcc (MSYS2 MinGW64)
gcc -g "path/to/file.c" -o "path/to/file.exe"

# Build with warnings enabled
gcc -Wall -Wextra -Wpedantic -g "path/to/file.c" -o "path/to/file.exe"
```

### C++ Files (Aprobadas/PracticasLibres)
```bash
# Build single C++ file with g++
g++ -g "path/to/file.cpp" -o "path/to/file.exe" -static-libgcc -static-libstdc++

# Build multi-file C++ project (e.g., Tetris)
g++ -g main.cpp Board.cpp Game.cpp Tetromino.cpp -o tetris.exe -static-libgcc -static-libstdc++

# Build CMake project (FolderOrganizer)
cd Aprobadas/PracticasLibres/FolderOrganizer/build
cmake .. && cmake --build .
```

### Python Files (Aprobadas/ProbabilidadyEstadisticas)
```bash
# Run Python script
python Aprobadas/ProbabilidadyEstadisticas/estimar_tasa.py
```

### PL/SQL Files (BasedeDatosII)
- Execute in Oracle SQL*Plus, SQL Developer, or similar Oracle client.
- Use `SET SERVEROUTPUT ON;` before running PL/SQL blocks.

### SQL Files (Aprobadas/BasedeDatosI)
- Execute in Oracle SQL*Plus, SQL Developer, or similar Oracle client.

### Running Compiled Programs
```bash
# Run any .exe
./path/to/program.exe
```

## Testing
- **No automated test framework** is configured in this repository.
- Testing is done manually by running compiled executables and verifying console output.
- For Python: use `pytest` if adding tests (`pip install pytest`, then `pytest`).

## Code Style Conventions

### C/C++ (Programacion I, II, PracticasLibres)
- **Naming**: UPPERCASE for function names in coursework (e.g., `CARGAR`, `MEJOR_ALUMNO`). Modern C++ projects use PascalCase for classes/functions (e.g., `Board::IsCollision`).
- **Variables**: UPPERCASE in coursework (e.g., `M1`, `VsumaColumna`), camelCase in modern C++ (e.g., `currentPiece`, `newX`).
- **Structs/Classes**: UPPERCASE struct names in coursework (`struct ALUMNO`), PascalCase in modern C++ (`class Board`, `class Tetromino`).
- **Constants/Macros**: UPPERCASE with `#define` (e.g., `#define LARGO 20`, `#define BOARD_H` include guards).
- **Indentation**: Tabs or 4 spaces — follow existing file style.
- **Braces**: K&R style — opening brace on same line for functions, next line for control structures.
- **Headers**: Use `#ifndef`/`#define`/`#endif` include guards in `.h` files.
- **Comments**: `/* block */` and `//` line comments. Spanish comments are common.

### Python (ProbabilidadyEstadisticas)
- **Naming**: snake_case for functions/variables (e.g., `calcular_intervalo`, `p_hat`).
- **Docstrings**: Triple-quoted strings for function documentation.
- **Style**: Follow PEP 8 conventions.

### SQL/PLSQL (BasedeDatosI, II)
- **Keywords**: UPPERCASE (SELECT, FROM, WHERE, JOIN, etc.).
- **Identifiers**: lowercase or snake_case.
- **Formatting**: One clause per line, aligned keywords.
- **Comments**: `--` for line comments, `/* */` for blocks.
- **PL/SQL**: Use `SET SERVEROUTPUT ON;` for output, handle exceptions with `WHEN OTHERS THEN`.

### JavaScript (ProgramacionIII)
- **Naming**: camelCase for functions/variables, PascalCase for classes.
- **Style**: Follow standard JS conventions. Use `const` and `let`, avoid `var`.

## General Guidelines
- **Language**: Code comments and variable names are primarily in **Spanish** — preserve this convention.
- **Compiler**: MSYS2 MinGW64 at `C:/msys64/mingw64/bin/` (gcc, g++, gdb).
- **IDE**: VS Code with C/C++ extension. Build tasks defined in `.vscode/tasks.json`.
- **No linter/formatter** is configured — follow existing file conventions.
- **No package manager** — dependencies are manual (Python uses `.venv` virtual environment).
- When adding new files, match the style of the subject folder you're working in.

## ⚠️ CRITICAL RULE: Compilation

**NEVER compile or execute code unless the user explicitly requests it.**
- Do NOT auto-compile after writing code
- Do NOT run tests unless asked
- Do NOT execute scripts to "verify" they work
- Wait for `/compilar` or explicit request like "compilá esto" or "ejecutalo"

## Learning Workflow

When working on a new exercise:

1. **Start from template**: Copy from `Aprendizaje/Templates/` and fill in the header notes
2. **Write code**: Implement the exercise in the appropriate language
3. **Compile/Run**: ONLY when user requests `/compilar` or explicitly asks
4. **Review**: User can request `/revisar` for code review and suggestions
5. **Document**: Update progress checklist in `Aprendizaje/Progreso/` and add notes in `Aprendizaje/Notas/`

## Templates

All code templates include a header section for learning notes:
- **What I learned**: Key takeaways from the exercise
- **Common errors**: Mistakes to avoid
- **Key concepts**: Important ideas to remember

Use templates from `Aprendizaje/Templates/` when starting new exercises.
