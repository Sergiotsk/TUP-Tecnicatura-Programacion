import { defineConfig } from "vite";
import { resolve } from "path";

// Sitio estático multipágina (MPA). Cada .html es un entry point independiente;
// Vite hace code-splitting y hashing de assets igual que en una SPA.
export default defineConfig({
  server: {
    // Escucha en todas las interfaces (IPv4 + IPv6) para que ngrok pueda conectarse.
    host: true,
    // Dominios externos permitidos para acceder al dev server (ngrok, etc).
    allowedHosts: [".ngrok-free.dev", ".ngrok-free.app", ".ngrok.io"],
  },
  build: {
    rollupOptions: {
      input: {
        inicio: resolve(__dirname, "index.html"),
        torqueHidraulico: resolve(__dirname, "torque-hidraulico.html"),
        rotacionContinua: resolve(__dirname, "rotacion-continua.html"),
        tensionadoDePernos: resolve(__dirname, "tensionado-de-pernos.html"),
        accesorios: resolve(
          __dirname,
          "accesorios-para-bridado-y-remocion-de-material.html",
        ),
        contacto: resolve(__dirname, "contacto.html"),
      },
    },
  },
});
