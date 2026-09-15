import "../style.css";
import { initLayout } from "../layout";
import { renderProductGrid } from "../render-products";
import { TORQUE_HIDRAULICO_PRODUCTS } from "../data/products";

initLayout();
renderProductGrid("product-grid", TORQUE_HIDRAULICO_PRODUCTS);
