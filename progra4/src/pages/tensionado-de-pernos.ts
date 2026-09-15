import "../style.css";
import { initLayout } from "../layout";
import { renderProductGrid } from "../render-products";
import { TENSIONADO_DE_PERNOS_PRODUCTS } from "../data/products";

initLayout();
renderProductGrid("product-grid", TENSIONADO_DE_PERNOS_PRODUCTS);
