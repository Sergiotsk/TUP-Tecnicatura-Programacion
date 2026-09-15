import type { Product } from "./types";

/** Renderiza una grilla de productos dentro de un contenedor por id. */
export function renderProductGrid(containerId: string, products: Product[]): void {
  const container = document.getElementById(containerId);
  if (!container) return;

  container.innerHTML = products
    .map(
      (product) => `
        <article class="product-card">
          <img
            src="${product.image}"
            alt="${product.imageAlt}"
            loading="lazy"
            width="768"
            height="768"
          />
          <h2>${product.title}</h2>
          <p>${product.description}</p>
        </article>
      `,
    )
    .join("");
}
