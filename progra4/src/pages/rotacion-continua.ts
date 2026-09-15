import "../style.css";
import { initLayout } from "../layout";
import { renderProductGrid } from "../render-products";
import { ROTACION_CONTINUA_PRODUCTS } from "../data/products";

initLayout();
renderProductGrid("product-grid", ROTACION_CONTINUA_PRODUCTS);
