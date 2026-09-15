import "../style.css";
import { initLayout } from "../layout";
import { renderProductGrid } from "../render-products";
import { ACCESORIOS_PRODUCTS } from "../data/products";

initLayout();
renderProductGrid("product-grid", ACCESORIOS_PRODUCTS);
