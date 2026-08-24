# 🐳 BDII: Comandos de Docker y SQL*Plus

Este archivo guarda los atajos y configuraciones para correr la base de Oracle localmente sin depender de SQL Developer.

## 1. Levantar la Base de Datos (Docker)

Siempre que vayas a trabajar, asegurate de tener abierto Docker Desktop y correr esto en la terminal (parado en la carpeta `BasedeDatosII`):

```bash
docker compose up -d
```

*Nota: Gracias al volumen configurado en el `docker-compose.yml` (`- ./:/mis_scripts`), toda tu carpeta de Windows queda "espejada" adentro de Docker bajo el nombre ficticio `/mis_scripts/`.*

## 2. Conectarse a SQL*Plus

Para abrir la consola interactiva de Oracle y dejar la conexión viva:

```bash
docker exec -it oracle-bdii sqlplus system/oracle@//localhost/XEPDB1
```

## 3. Ejecutar tus scripts

Una vez adentro de SQL*Plus (cuando el prompt te dice `SQL>`), podés correr cualquier archivo de tu compu usando la ruta espejada `/mis_scripts/`:

Si trabajás en la carpeta de la semana 2:

```sql
@/mis_scripts/semana-02/TP1.sql
```

Si trabajás en la carpeta de trabajos:

```sql
@/mis_scripts/trabajos/TP2.sql
```

## 4. Limpiar la consola

Para limpiar la pantalla de resultados adentro de SQL*Plus:

```sql
clear screen
-- O su versión corta:
cl scr
```

*(Si en algún momento el refresco visual falla, podés inyectar el comando a Linux usando `!clear`)*

---

### 💡 Recordatorios de sintaxis PL/SQL

- `:=` es para ASIGNAR (ej: `suma := 10`).
- `=` es para COMPARAR (ej: en un `IF` o un `WHERE`).
- **Scope local**: Las variables de bloques anónimos nacen en el `DECLARE` y mueren en el `END;`. No arrastran valores.
- **Constantes**: Llevan la palabra reservada `CONSTANT`, obligan a inicializarse en el `DECLARE` y si intentás reasignarlas en el `BEGIN`, Oracle escupe el error `PLS-00363: la expresión no se puede utilizar como destino de asignación`.
