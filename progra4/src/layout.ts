import { NAV_LINKS, CONTACT_PHONE, CONTACT_PHONE_HREF } from "./data/nav";
import logoUrl from "./assets/img/logo.png";

/**
 * Normaliza un pathname a un nombre de archivo comparable contra NAV_LINKS,
 * para poder marcar el link activo del menú (ej: "/" y "/index.html" → "index.html").
 */
function currentPage(): string {
  const path = window.location.pathname;
  const file = path.substring(path.lastIndexOf("/") + 1);
  return file === "" ? "index.html" : file;
}

function renderNavLinks(): string {
  const active = currentPage();
  return NAV_LINKS.map((link) => {
    const linkFile = link.href.substring(link.href.lastIndexOf("/") + 1);
    const isActive = linkFile === active;
    return `<li>
      <a href="${link.href}"${isActive ? ' class="is-active" aria-current="page"' : ""}>${link.label}</a>
    </li>`;
  }).join("");
}

/** Inyecta el header con navegación en el contenedor #app-header. */
export function renderHeader(): void {
  const container = document.getElementById("app-header");
  if (!container) return;

  container.innerHTML = `
    <header class="site-header">
      <div class="site-header__inner">
        <a href="/index.html" class="site-header__brand">
          <img src="${logoUrl}" alt="Mecatorc" width="140" height="40" />
        </a>
        <button
          type="button"
          class="nav-toggle"
          aria-expanded="false"
          aria-controls="primary-nav"
          aria-label="Abrir menú"
        >
          <span class="nav-toggle__bar"></span>
          <span class="nav-toggle__bar"></span>
          <span class="nav-toggle__bar"></span>
        </button>
        <nav id="primary-nav" class="primary-nav">
          <ul>${renderNavLinks()}</ul>
        </nav>
      </div>
    </header>
  `;

  const toggle = container.querySelector<HTMLButtonElement>(".nav-toggle");
  const nav = container.querySelector<HTMLElement>(".primary-nav");
  toggle?.addEventListener("click", () => {
    const isOpen = nav?.classList.toggle("is-open") ?? false;
    toggle.setAttribute("aria-expanded", String(isOpen));
    toggle.setAttribute("aria-label", isOpen ? "Cerrar menú" : "Abrir menú");
  });
}

/** Inyecta el footer en el contenedor #app-footer. */
export function renderFooter(): void {
  const container = document.getElementById("app-footer");
  if (!container) return;

  const year = new Date().getFullYear();
  container.innerHTML = `
    <footer class="site-footer">
      <div class="site-footer__inner">
        <img src="${logoUrl}" alt="Mecatorc" width="120" height="34" />
        <p>Copyright &copy; ${year} Mecatorc</p>
        <a href="${CONTACT_PHONE_HREF}">Contáctanos al ${CONTACT_PHONE}</a>
      </div>
    </footer>
  `;
}

/** Arranca el layout compartido (header + footer) en la página actual. */
export function initLayout(): void {
  renderHeader();
  renderFooter();
}
