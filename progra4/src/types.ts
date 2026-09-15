/** Un ítem de navegación del header. */
export interface NavLink {
  label: string;
  href: string;
}

/** Un producto/servicio mostrado en una grilla de categoría. */
export interface Product {
  title: string;
  description: string;
  image: string;
  imageAlt: string;
}
