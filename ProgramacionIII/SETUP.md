# Setup — ProgramacionIII 2026

## Requisitos

- [Docker Desktop](https://www.docker.com/products/docker-desktop/) instalado y corriendo
- Node.js + npm (para React Native / Expo)
- Expo Go en tu celular (App Store / Play Store)

---

## Paso a paso para levantar el stack de Unidad 4

### 1. Crear el archivo `.env`

El archivo `.env` contiene las credenciales de la base de datos. **Nunca se sube a Git** (está en `.gitignore`).

Navegá a la carpeta del docker stack:

```
ProgramacionIII/unidad-04/clase-20/
```

Creá un archivo llamado `.env` (sin extensión) con este contenido:

```bash
# .env — credenciales locales de desarrollo
MYSQL_ROOT_PASSWORD=cambia_esta_password
MYSQL_DATABASE=prog3_db
MYSQL_USER=prog3_user
MYSQL_PASSWORD=cambia_esta_password
```

Podés cambiar los valores de las passwords por lo que quieras — son solo para desarrollo local.

> **¿Por qué existe este archivo?**
> El `docker-compose.yml` usa variables como `${MYSQL_PASSWORD}` en lugar de escribir
> las passwords directamente. Así el código puede subirse a Git de forma segura y cada
> desarrollador usa sus propias credenciales locales sin pisar las del resto.

---

### 2. Levantar el stack

```bash
cd ProgramacionIII/unidad-04/clase-20

docker compose up -d --build
```

Esto levanta 3 contenedores:
- **nginx** — servidor web en `http://localhost:8080`
- **php** — ejecuta los scripts PHP (PHP-FPM 8.2)
- **mysql** — base de datos MySQL 8

### 3. Verificar que todo está corriendo

```bash
docker compose ps
```

Los 3 servicios deben aparecer como `running`.

### 4. Detener el stack

```bash
docker compose down
```

> `docker compose down -v` elimina también los datos de MySQL. Usalo solo si querés
> empezar desde cero.

---

## Estructura del proyecto

```
ProgramacionIII/
├── SETUP.md              ← este archivo
├── unidad-01/            ← HTML + CSS
├── unidad-02/            ← JavaScript
├── unidad-03/            ← PHP + MySQL
├── unidad-04/
│   └── clase-20/         ← Docker stack (Nginx + PHP + MySQL)
│       ├── docker-compose.yml
│       ├── .gitignore
│       ├── .env          ← CREAR MANUALMENTE (no está en git)
│       └── src/          ← archivos PHP
└── unidad-05/            ← React Native
```
