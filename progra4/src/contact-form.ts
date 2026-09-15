interface ContactFormValues {
  nombre: string;
  email: string;
  asunto: string;
  mensaje: string;
}

type ContactFormErrors = Partial<Record<keyof ContactFormValues, string>>;

const EMAIL_PATTERN = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

function validate(values: ContactFormValues): ContactFormErrors {
  const errors: ContactFormErrors = {};

  if (values.nombre.trim().length < 2) {
    errors.nombre = "Ingresá tu nombre completo.";
  }
  if (!EMAIL_PATTERN.test(values.email.trim())) {
    errors.email = "Ingresá un correo electrónico válido.";
  }
  if (values.asunto.trim().length < 3) {
    errors.asunto = "Contanos brevemente el motivo de tu consulta.";
  }
  if (values.mensaje.trim().length < 10) {
    errors.mensaje = "El mensaje debe tener al menos 10 caracteres.";
  }

  return errors;
}

function showFieldError(form: HTMLFormElement, field: keyof ContactFormValues, message: string | undefined): void {
  const errorEl = form.querySelector<HTMLElement>(`[data-error-for="${field}"]`);
  if (!errorEl) return;
  errorEl.textContent = message ?? "";
  errorEl.hidden = !message;
}

/**
 * Inicializa el formulario de contacto: valida en el cliente y arma un
 * enlace mailto: con los datos cargados.
 *
 * TODO: reemplazar el envío por mailto con una integración real
 * (Formspree, EmailJS o un endpoint propio) cuando el cliente lo defina.
 */
export function initContactForm(formId: string): void {
  const form = document.getElementById(formId) as HTMLFormElement | null;
  if (!form) return;

  const statusEl = form.querySelector<HTMLElement>("[data-form-status]");

  form.addEventListener("submit", (event) => {
    event.preventDefault();

    const values: ContactFormValues = {
      nombre: (form.elements.namedItem("nombre") as HTMLInputElement)?.value ?? "",
      email: (form.elements.namedItem("email") as HTMLInputElement)?.value ?? "",
      asunto: (form.elements.namedItem("asunto") as HTMLInputElement)?.value ?? "",
      mensaje: (form.elements.namedItem("mensaje") as HTMLTextAreaElement)?.value ?? "",
    };

    const errors = validate(values);
    (Object.keys(values) as (keyof ContactFormValues)[]).forEach((field) =>
      showFieldError(form, field, errors[field]),
    );

    if (Object.keys(errors).length > 0) {
      if (statusEl) {
        statusEl.textContent = "Revisá los campos marcados antes de enviar.";
        statusEl.dataset.state = "error";
      }
      return;
    }

    const body = encodeURIComponent(
      `Nombre: ${values.nombre}\nEmail: ${values.email}\n\n${values.mensaje}`,
    );
    const mailto = `mailto:contacto@mecatorc.com?subject=${encodeURIComponent(values.asunto)}&body=${body}`;
    window.location.href = mailto;

    if (statusEl) {
      statusEl.textContent = "Abriendo tu cliente de correo…";
      statusEl.dataset.state = "success";
    }
    form.reset();
  });
}
