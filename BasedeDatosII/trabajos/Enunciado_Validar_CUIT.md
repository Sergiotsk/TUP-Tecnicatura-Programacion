# Procedimiento para Obtener el Dígito Verificador (CUIT / CUIL)

---

Tanto el **CUIT** (Clave Única de Identificación Tributaria) como el **CUIL** (Código Único de Identificación Laboral) constan de tres partes separadas por guiones:

- **Tipo**
- **Número**
- **Dígito verificador**

Ejemplo: `20-12345678-X`
- `20` → tipo
- `12345678` → número de DNI o número de sociedad
- `X` → dígito verificador

---

## Tipos válidos

| Tipo | Categoría |
|------|-----------|
| 20, 23, 24, 27 | Personas Físicas |
| 30, 33, 34 | Empresas |

---

## Algoritmo Módulo 11

Se toma el número de **10 dígitos** formado por los 2 del tipo + los 8 del número, y se recorre **de derecha a izquierda** multiplicando cada dígito por la sucesión `2, 3, 4, 5, 6, 7, 2, 3, 4, 5`.

### Ejemplo con `20-12345678-X`

| Dígito | Multiplicador | Producto |
|--------|--------------|---------|
| 8 | 2 | 16 |
| 7 | 3 | 21 |
| 6 | 4 | 24 |
| 5 | 5 | 25 |
| 4 | 6 | 24 |
| 3 | 7 | 21 |
| 2 | 2 | 4 |
| 1 | 3 | 3 |
| 0 | 4 | 0 |
| 2 | 5 | 10 |

**Suma:** `16 + 21 + 24 + 25 + 24 + 21 + 4 + 3 + 0 + 10 = 148`

---

## Cálculo del dígito verificador

1. **Módulo 11:** `148 / 11 = 13`, resto `5`
2. **Diferencia:** `11 - 5 = 6`

### Reglas para determinar el dígito verificador

| Resultado de `11 - resto` | Dígito verificador |
|--------------------------|-------------------|
| 1 al 9 | Ese mismo número (`6` en el ejemplo) |
| 11 | `0` |
| 10 | Ver tabla de casos especiales |

### Casos especiales cuando el resultado es 10

| Categoría | Dígito verificador | Prefijo cambia a |
|-----------|-------------------|-----------------|
| Hombres | 9 | 23 (antes 20) |
| Mujeres | 4 | 23 (antes 27) |
| Sociedades | 9 | 33 (antes 30) |

> Si el número de documento estuviera **duplicado**, el prefijo cambia a `34` para Sociedades y a `24` para Personas Físicas.
