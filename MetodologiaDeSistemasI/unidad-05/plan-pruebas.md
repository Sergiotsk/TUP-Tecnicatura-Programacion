# Plan de Pruebas — Sistema de Biblioteca

**Unidad:** 5 | **Clase:** 13 | **Fuente:** Pressman Cap. 17 · Toledo

## Módulo bajo prueba: Préstamo de Libros

## Casos de Prueba — Caja Negra

| ID | Descripción | Precondiciones | Datos de entrada | Resultado esperado | Resultado real | Estado |
|---|---|---|---|---|---|---|
| CP-001 | Préstamo exitoso | Socio activo, libro disponible | isbn válido | Préstamo registrado, libro marcado no disponible | | Pendiente |
| CP-002 | Libro no disponible | Socio activo, libro prestado | isbn de libro prestado | Error: libro no disponible | | Pendiente |
| CP-003 | Socio inexistente | — | nroSocio inválido | Error: socio no encontrado | | Pendiente |
| CP-004 | ISBN inválido | Socio activo | isbn con formato incorrecto | Error: ISBN inválido | | Pendiente |
| CP-005 | Socio con mora | Socio con préstamo vencido | isbn válido | Error: socio con mora pendiente | | Pendiente |

## Casos de Prueba — Caja Blanca

| ID | Descripción | Precondiciones | Datos de entrada | Resultado esperado | Resultado real | Estado |
|---|---|---|---|---|---|---|
| CP-006 | Verificar rama disponible=true | libro.disponible = true | isbn válido | Flujo principal ejecutado | | Pendiente |
| CP-007 | Verificar rama disponible=false | libro.disponible = false | isbn válido | Flujo alternativo ejecutado | | Pendiente |
| CP-008 | Cálculo fecha vencimiento | — | fechaInicio = hoy | fechaVencimiento = hoy + 15 días | | Pendiente |
| CP-009 | Cálculo mora por día | Préstamo vencido hace 3 días | — | mora = 3 × tarifa diaria | | Pendiente |
| CP-010 | Actualización estado libro post-préstamo | — | isbn válido | libro.disponible = false en BD | | Pendiente |

## Resultado general
- Casos ejecutados: 0 / 10
- Pasaron: 0
- Fallaron: 0
- Pendientes: 10
