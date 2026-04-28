# CHANGE PROPOSAL: programacion-iii-estructura
> Generated: 2026-04-26 | Status: proposed

## Intent
Crear estructura completa de directorios y archivos vacíos para ProgramacionIII en dos ubicaciones:
1. **SB_Sergio** (Obsidian vault) — teoría, prácticas, parciales, seguimiento con frontmatter correcto
2. **TUP-REPO** (código) — directorios por clase con `.gitkeep` + archivos Docker especiales para clase-20

**STRUCTURE ONLY** — sin contenido educativo todavía.

## Scope
| Ubicación | Contenido | Total |
|-----------|-----------|-------|
| SB_Sergio/teoria/ | 15 archivos .md con frontmatter | 15 files |
| SB_Sergio/practicas/ | 5 archivos .md | 5 files |
| SB_Sergio/parciales/ | 2 archivos .md | 2 files |
| SB_Sergio/seguimiento/ | 32 archivos clase-01 a clase-32 | 32 files |
| SB_Sergio/ | 00-Dashboard.md con dataview | 1 file |
| TUP-REPO/unidad-01 a 05 | 28 dirs de clase + .gitkeep | ~30 files |
| TUP-REPO/clase-20 | docker-compose.yml, .env, .gitignore | 3 files |
| TUP-REPO/proyecto-final | .gitkeep | 1 file |

## Clase-Unidad Mapping
- Clases 1-6 → Unidad 1 (Frontend)
- Clases 7-11 → Unidad 2 (JavaScript)
- Clase 12 → Parcial 1 (sin unidad)
- Clases 13-17 → Unidad 3 (Backend PHP)
- Clase 18 → Recuperatorio P1 (sin unidad)
- Clases 19-22 → Unidad 4 (Docker/Nginx)
- Clases 23-29 → Unidad 5 (React Native)
- Clases 30, 31, 32 → Parcial 2 / Recuperatorio / Cierre

## Approach
1. Crear dirs padre SB_Sergio (mkdir -p)
2. Generar archivos SB con frontmatter correcto por categoría
3. Crear estructura TUP-REPO (unidad-0N/clase-NN)
4. `.gitkeep` en cada directorio hoja
5. Archivos Docker especiales para clase-20 (PRD sección 6)
6. `proyecto-final/` con `.gitkeep`

## Rollback
- **TUP-REPO**: `rm -rf unidad-* proyecto-final/` dentro de ProgramacionIII/
- **SB_Sergio**: `rm -rf ProgramacionIII/` (no existía antes, sin pérdida de datos)

## Out of Scope
- Contenido educativo en los archivos
- Modificar `Material de clase/` o `PRD-Programacion-III-2026.md`
- Compilar o ejecutar código
- CI/CD o automatizaciones

## Risks
| Riesgo | Mitigación |
|--------|------------|
| Path SB_Sergio no existe | mkdir -p recursivo |
| Sobreescribir Material de clase/ | Implementación skipea paths existentes |
| Mapping clase-unidad incorrecto | Usar tabla exacta de arriba |
| Git no trackea dirs vacíos | .gitkeep en cada dir hoja |
