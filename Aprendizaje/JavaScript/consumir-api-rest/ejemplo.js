// Ejemplo: consumir una API REST con JavaScript usando fetch()
// API pública de prueba: https://jsonplaceholder.typicode.com

// ─── GET: obtener datos ───────────────────────────────────────────────────────

async function obtenerUsuarios() {
  try {
    const respuesta = await fetch("https://jsonplaceholder.typicode.com/users");

    if (!respuesta.ok) {
      throw new Error(`Error HTTP: ${respuesta.status}`);
    }

    const usuarios = await respuesta.json();
    console.log("Usuarios:", usuarios);
    return usuarios;
  } catch (error) {
    console.error("Error al obtener usuarios:", error.message);
  }
}

// ─── GET: obtener un recurso por ID ──────────────────────────────────────────

async function obtenerPost(id) {
  const respuesta = await fetch(`https://jsonplaceholder.typicode.com/posts/${id}`);
  const post = await respuesta.json();
  console.log("Post:", post);
  return post;
}

// ─── POST: enviar datos nuevos ────────────────────────────────────────────────

async function crearPost(titulo, cuerpo, usuarioId) {
  const respuesta = await fetch("https://jsonplaceholder.typicode.com/posts", {
    method: "POST",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify({
      title: titulo,
      body: cuerpo,
      userId: usuarioId,
    }),
  });

  const nuevoPost = await respuesta.json();
  console.log("Post creado:", nuevoPost);
  return nuevoPost;
}

// ─── PUT: actualizar un recurso completo ─────────────────────────────────────

async function actualizarPost(id, datos) {
  const respuesta = await fetch(`https://jsonplaceholder.typicode.com/posts/${id}`, {
    method: "PUT",
    headers: {
      "Content-Type": "application/json",
    },
    body: JSON.stringify(datos),
  });

  const postActualizado = await respuesta.json();
  console.log("Post actualizado:", postActualizado);
  return postActualizado;
}

// ─── DELETE: eliminar un recurso ─────────────────────────────────────────────

async function eliminarPost(id) {
  const respuesta = await fetch(`https://jsonplaceholder.typicode.com/posts/${id}`, {
    method: "DELETE",
  });

  if (respuesta.ok) {
    console.log(`Post ${id} eliminado correctamente`);
  }
}

// ─── Ejecutar ejemplos ────────────────────────────────────────────────────────

(async () => {
  console.log("=== GET usuarios ===");
  await obtenerUsuarios();

  console.log("\n=== GET post por ID ===");
  await obtenerPost(1);

  console.log("\n=== POST nuevo post ===");
  await crearPost("Mi título", "Contenido del post", 1);

  console.log("\n=== PUT actualizar post ===");
  await actualizarPost(1, { title: "Título nuevo", body: "Cuerpo nuevo", userId: 1 });

  console.log("\n=== DELETE eliminar post ===");
  await eliminarPost(1);
})();
