# RF, RNF, Reglas de Dominio — Caso de Estudio: Vía Neuquén

## Caso de estudio

La compañía de transporte público de pasajeros de larga distancia **Vía Neuquén** provee servicios micro ómnibus de diferentes categorías (semi-cama, cama, ejecutivo, etc.) entre la ciudad de Buenos Aires y diferentes localidades neuquinas.

A tal efecto, su director general, ha contratado a la consultora en la cual Ud. se desempeña como ingeniero/a de requisitos, con el objeto del desarrollo de un sitio web (https://www.vianqn.com.ar) que permita gestionar aspectos vinculados a la compra de pasajes.

La operatoria esencial del portal es muy sencilla, conforme facilitar tanto como sea posible la adquisición de pasajes.

El visitante escogerá la localidad de origen, la localidad de destino y la fecha de partida deseada. Luego de ello, de los servicios ofertados para el trayecto indicado y con disponibilidad, escogerá uno en particular en base al horario de partida y la categoría deseada.

Hecho esto, para cada pasaje a adquirir (pero sin exceder el máximo disponible para el servicio), informará el nombre completo del pasajero (puede ser el o un tercero), DNI y fecha de nacimiento (datos que deberán ser confirmados por el Registro Nacional de las Personas[^1] mediante su servicio automático de provisión de datos para sistemas externos) y elegirá un asiento de los disponibles.

Informado por el portal del importe total, el visitante elegirá una de las modalidades de pago aceptadas (tarjeta de crédito o de débito), escogerá compañía y entidad bancaria (de las que aceptará el portal), indicará número de tarjeta, fecha de vencimiento, titular y código de verificación y, además de ello y a los efectos de la facturación, informará su nombre completo (puede no ser el titular de la tarjeta), número de DNI, dirección de correo electrónico y, por último, confirmará su voluntad de adquirir los pasajes indicados.

Si la entidad bancaria confirma la imputación del pago, el portal web informará un código de compra y enviará a la cuenta de correo electrónico declarada, los pasajes adquiridos como un archivo pdf.

Como funcionalidad independiente, pero complementaria, el portal ofrecerá también al visitante, la posibilidad de cancelar uno más pasajes de una compra (obviamente, el porcentaje de devolución del importe abonado dependerá de la antelación a la fecha de partida).

Independientemente de todo lo anterior, para quienes lo deseen y en cualquier momento, el portal permitirá registrar una cuenta de cliente, a los efectos de acceder a beneficios adicionales, tales como descuentos en la compra de pasajes, el acceso a la consulta del historial de compras y la posibilidad de reprogramar la fecha de viaje de un pasaje a la de otro servicio con idénticas características.

Naturalmente, el sitio web www.vianqn.com.ar no puede operar aisladamente, interactuará con el sistema central de operaciones de la compañía, de nombre **Panóptico**, el cual le proveerá datos de los servicios y recabará información asociada a las ventas y cancelaciones.

Conforme las interacciones del portal web con los sistemas externos de medios de pago y del RENAPER, implican el tráfico de información personal y financiera sensible y dados los lineamientos que la norma ISO 27017-C indica para los servicios en la nube, la implementación del sitio debe contemplar el empleo en todo momento del Protocolo de Transferencia de Hipertexto (HTTP) cifrado sobre seguridad de la capa de transporte (TLS) en su versión 1.3.

[^1]: RENAPER.

---

## Actividad

1. Listar:
   - a) Funcionalidades requeridas.
   - b) Condicionantes y Determinantes detectados.
   - c) Reglas del dominio advertidas.
2. Tomando como base lo desarrollado en el punto anterior redactar, en lenguaje natural como requisitos del cliente, en alto nivel:
   - a) Requisitos Funcionales.
3. Partiendo de lo precedente, refinar, completar y redactar, en lenguaje natural como requisitos del sistema, en bajo nivel:
   - a) Los requisitos funcionales.
   - b) Los requisitos no funcionales. Y Clasificarlos según Ontología autor Sommerville.

---

## Funcionalidades Requeridas

- **Búsqueda y consulta de servicios:** Permitir al visitante buscar viajes ingresando localidad de origen, localidad de destino y fecha de partida, visualizando los servicios ofertados con su disponibilidad, horarios y categorías (semi-cama, cama, ejecutivo, etc.).
- **Selección de pasajes y asientos:** Permitir la selección de un servicio específico, el ingreso de los datos de los pasajeros (nombre completo, DNI y fecha de nacimiento) y la selección de asientos disponibles.
- **Gestión de pago y facturación:** Permitir al usuario elegir la modalidad de pago (tarjeta de crédito o débito), banco y compañía; ingresar los datos de la tarjeta; completar los datos de facturación (nombre completo, DNI y correo electrónico) y confirmar la compra.
- **Confirmación y emisión de pasajes:** Notificar el código de compra en pantalla y enviar automáticamente los pasajes adquiridos en formato PDF al correo electrónico del comprador una vez aprobado el pago.
- **Cancelación de pasajes:** Permitir de forma independiente la cancelación de uno o más pasajes asociados a una compra.
- **Registro y gestión de cuentas de cliente:** Permitir a los usuarios registrarse en el portal para crear una cuenta de cliente y autenticarse en el futuro.
- **Consulta de historial de compras:** Permitir a los clientes registrados acceder y revisar el registro de sus compras pasadas.
- **Reprogramación de pasajes:** Permitir a los clientes registrados cambiar la fecha de viaje de un pasaje por otro servicio con las mismas características.

---

## Condicionantes y Determinantes Detectados

- **Usabilidad (Atributo de calidad):** La operatoria esencial del portal debe ser muy sencilla para facilitar al máximo la adquisición de pasajes.
- **Seguridad y Cifrado (Normativa):** Obligatoriedad de emplear en todo momento el protocolo HTTPS cifrado sobre TLS en su versión 1.3, debido al tráfico de información sensible y en cumplimiento de la norma ISO 27017-C para servicios en la nube.
- **Integración con Sistemas Externos:**
  - **RENAPER:** Interconexión con su servicio automático de provisión de datos para validar de forma externa la identidad de los pasajeros (nombre, DNI y fecha de nacimiento).
  - **Pasarelas de Pago / Entidades Bancarias:** Interconexión con los sistemas de medios de pago externos para validar y confirmar la imputación del cobro de las tarjetas.
- **Integración con Sistemas Internos (Sistema Panóptico):** Interacción obligatoria con el sistema central de operaciones de la compañía para obtener los datos de los servicios y enviar la información de ventas y cancelaciones.

---

## Reglas del Dominio Advertidas

- **Límite de compra:** No se puede exceder el máximo de pasajes disponibles para un servicio en una misma transacción.
- **Validación de Identidad Obligatoria:** Todos los datos de los pasajeros (nombre, DNI y nacimiento) deben ser confirmados en tiempo real por el RENAPER.
- **Disociación de identidades en el pago:**
  - El pasajero del micro puede ser el visitante o un tercero.
  - Quien recibe la factura (datos de facturación) puede no ser el titular de la tarjeta de crédito o débito utilizada.
- **Política de Devolución Variable:** El porcentaje de dinero que se devuelve al cancelar un pasaje depende de la antelación con la que se realice el trámite respecto a la fecha de partida del viaje.
- **Acceso Restringido a Beneficios:** Los beneficios adicionales (descuentos, historial y reprogramación) son exclusivos para los usuarios que posean y hayan iniciado sesión en una cuenta de cliente.
- **Restricción de Reprogramación:** La reprogramación del viaje para clientes registrados está limitada estrictamente a servicios que cuenten con idénticas características al pasaje original.

---

## Requisitos Funcionales en Alto Nivel

- **RF01:** El Sitio Web deberá permitir al visitante buscar y seleccionar servicios de transporte de pasajeros ingresando la localidad de origen, la localidad de destino y la fecha de partida deseada.
- **RF02:** El Sitio Web deberá registrar la adquisición de pasajes capturando los datos personales del pasajero y del comprador, procesando el cobro mediante tarjetas de crédito o débito y emitiendo los boletos en formato PDF.
- **RF03:** El Sitio Web deberá permitir al visitante gestionar la cancelación de uno o más pasajes asociados a una compra realizada previamente.
- **RF04:** El Sitio Web deberá permitir al usuario registrar y gestionar una cuenta de cliente para acceder a beneficios adicionales en la plataforma.
- **RF05:** El Sitio Web deberá permitir a los clientes registrados reprogramar la fecha de viaje de sus pasajes hacia otros servicios que posean idénticas características.
- **RF06:** El Sitio Web deberá validar en tiempo real los datos filiatorios ingresados del pasajero (nombre completo, DNI y fecha de nacimiento) mediante la integración con el servicio automático del Registro Nacional de las Personas (RENAPER).
- **RF07:** El Sitio Web deberá permitir al usuario seleccionar la ubicación específica de sus asientos de entre aquellos que se encuentren disponibles para el servicio de micro-ómnibus elegido.
- **RF08:** El Sitio Web deberá enviar de forma automática un correo electrónico al comprador con el código de confirmación de la transacción y los pasajes adquiridos en formato PDF, una vez que la entidad bancaria apruebe el pago.
- **RF09:** El Sitio Web deberá interactuar con el sistema central Panóptico para consultar la oferta y disponibilidad de los servicios de transporte, así como para registrar la información de las ventas y cancelaciones efectuadas.
- **RF10:** El Sitio Web deberá permitir a los clientes registrados iniciar sesión en su cuenta para acceder de forma exclusiva a la consulta de su historial de compras y a la aplicación de descuentos especiales.

---

## Requisitos Funcionales en Bajo Nivel

**RF01 (Búsqueda y Selección de Servicios).** El Sitio Web deberá desplegar una interfaz de búsqueda que contenga campos obligatorios para seleccionar la localidad de origen, la localidad de destino y un selector de fecha para la partida. Al accionar la búsqueda, el sistema deberá procesar los parámetros y renderizar un listado con los servicios ofertados que coincidan con el trayecto y posean disponibilidad de plazas. Para cada servicio de transporte de pasajeros devuelto, la interfaz deberá mostrar de forma obligatoria el horario de partida exacto y la categoría asignada al vehículo (semi-cama, cama, ejecutivo, etc.), permitiendo al usuario seleccionar uno en particular mediante un botón de acción para avanzar en el flujo de compra.

**RF02 (Registro de Compra, Pago y Emisión).** El Sitio Web deberá habilitar un formulario de compra para capturar el nombre completo, número de DNI y fecha de nacimiento de cada pasajero. Acto seguido, el sistema deberá calcular e informar el importe total y proveer campos para que el visitante elija la modalidad de pago (tarjeta de crédito o débito), escoja la compañía y entidad bancaria de una lista predefinida, e ingrese el número de tarjeta, vencimiento, titular y código de verificación. Asimismo, exigirá los datos de facturación del comprador (nombre completo, DNI y correo electrónico). Al confirmar la operación y recibir la validación bancaria, el portal deberá generar en pantalla un código de compra único y emitir los pasajes adquiridos empaquetados en un archivo con formato PDF.

**RF03 (Gestión de Cancelación de Pasajes).** El Sitio Web deberá disponer de una sección independiente y complementaria orientada a la posventa, donde el visitante pueda ingresar los datos identificatorios de su compra para listar los pasajes asociados. El sistema deberá permitir la selección individual o múltiple de los pasajes que se deseen dar de baja dentro de una misma transacción. Ante la solicitud de baja, el sistema deberá evaluar la fecha y hora actual respecto a la fecha de partida del servicio y calcular automáticamente el porcentaje exacto de devolución económica que le corresponde al usuario en base a dicha antelación. Tras la confirmación del usuario, el sistema deberá actualizar el estado de los pasajes y liberar los asientos correspondientes.

**RF04 (Registro y Gestión de Cuenta de Cliente).** El Sitio Web deberá ofrecer un acceso público y permanente que permita a cualquier usuario iniciar un proceso de registro de cuenta de cliente de manera voluntaria y en cualquier momento. El formulario de registro deberá capturar los datos de identificación del usuario y una contraseña asociada, validando que las credenciales cumplan con las reglas de seguridad necesarias para su posterior almacenamiento. Una vez completado el registro, el sistema deberá crear un perfil único de cliente en la base de datos, habilitando el acceso a un panel privado que le otorgará de forma exclusiva los beneficios de descuentos, visualización de historial y herramientas de reprogramación.

**RF05 (Reprogramación de Pasajes para Clientes).** El Sitio Web deberá ofrecer a los clientes que posean una cuenta registrada y activa la opción de modificar la fecha de un pasaje previamente comprado. Al iniciar esta gestión, la interfaz deberá solicitar la nueva fecha de viaje deseada y buscar los servicios disponibles de la empresa. El sistema deberá aplicar una regla de validación estricta que compare los atributos del viaje original con los del nuevo viaje seleccionado, bloqueando la confirmación de la reprogramación a menos que el servicio de destino posea exactamente el mismo origen, mismo destino y la misma categoría de micro (idénticas características) que el pasaje que se pretende cambiar.

**RF06 (Validación en Tiempo Real con RENAPER).** El Sitio Web deberá conectarse automáticamente a través de la red con el servicio externo de provisión de datos del Registro Nacional de las Personas (RENAPER) ni bien el usuario complete los campos filiatorios del pasajero. El sistema deberá enviar el nombre completo, el número de DNI y la fecha de nacimiento ingresados para que el organismo externo valide su veracidad. En caso de que el RENAPER confirme la coincidencia y consistencia de los datos, el sistema guardará el registro del pasajero y permitirá continuar el flujo; si el servicio externo reporta un error o inconsistencia en la identidad, el portal deberá bloquear el avance del proceso y mostrar una alerta en la interfaz.

**RF07 (Selección de Ubicación de Asientos).** El Sitio Web deberá renderizar un mapa o esquema interactivo que represente la distribución física de la totalidad de las butacas que componen la categoría del micro-ómnibus elegido para el viaje. Este mapa deberá diferenciar visualmente, mediante códigos de color o estados, cuáles asientos se encuentran ocupados y cuáles están libres. El sistema deberá permitir al usuario hacer clic sobre los asientos disponibles para seleccionarlos individualmente según la cantidad de pasajes a adquirir. La interfaz deberá validar en tiempo real que el usuario no pueda seleccionar butacas previamente reservadas y que el total de asientos elegidos coincida exactamente con la cantidad de pasajeros informados, sin exceder el límite máximo disponible del servicio.

**RF08 (Notificación Automática Post-Pago).** El Sitio Web deberá activar un trigger o disparador automático de comunicación en el instante exacto en que la entidad bancaria externa emita la confirmación positiva de la imputación del cobro. El sistema deberá recuperar la dirección de correo electrónico que el comprador declaró en el formulario de facturación y componer un mensaje estructurado que incluya el código de compra alfanumérico generado por el portal. Asimismo, el sistema deberá adjuntar de forma obligatoria el archivo PDF que contiene los boletos de viaje correspondientes a la transacción, ejecutando el envío del correo de manera asíncrona e inmediata sin requerir acciones adicionales por parte del usuario.

**RF09 (Interacción con Sistema Central Panóptico).** El Sitio Web deberá conectarse con el sistema central de operaciones de la compañía, denominado "Panóptico", mediante interfaces de comunicación interna. Al momento de realizar búsquedas o consultas de viajes, el portal deberá interrogar a Panóptico para extraer la información actualizada de los horarios, categorías y disponibilidad real de los servicios. De igual manera, cada vez que una venta de pasajes sea confirmada mediante pago o se procese de forma efectiva una cancelación, el Sitio Web deberá transmitir inmediatamente todos los datos asociados a la transacción hacia Panóptico para actualizar el inventario y los registros centrales de la empresa.

**RF10 (Autenticación y Acceso a Beneficios Exclusivos).** El Sitio Web deberá proveer un módulo de inicio de sesión seguro que valide las credenciales (usuario y contraseña) introducidas por el cliente registrado. Una vez que la sesión sea autenticada de manera exitosa, el sistema deberá modificar el comportamiento de la pasarela de compras para aplicar de forma automática los porcentajes de descuento estipulados sobre el importe total de los pasajes seleccionados. En paralelo, el portal deberá desbloquear el acceso a una pantalla privada de consulta que se conectará con la base de datos para listar cronológicamente el historial completo de las compras que el cliente haya realizado bajo su cuenta.

---

## Requisitos No Funcionales (RNF) — Ontología Sommerville

### 1. Requisitos No Funcionales del Producto — Usabilidad

**RNF01:** EL SITIO WEB AL MOMENTO DE desplegar el flujo de adquisición de pasajes (RF02) DEBERÁ contar con una interfaz de usuario simplificada e intuitiva que minimice la cantidad de pasos requeridos para completar la transacción.

### 2. Requisitos No Funcionales del Producto — Eficiencia — Rendimiento

**RNF02:** EL SITIO WEB AL MOMENTO DE interactuar con el sistema central Panóptico para consultar la oferta y disponibilidad de viajes (RF09) DEBERÁ resolver las peticiones y renderizar los resultados en pantalla en un tiempo máximo de 3 segundos bajo condiciones normales de red.

### 3. Requisitos No Funcionales del Producto — Eficiencia — Espacio

**RNF03:** EL SITIO WEB AL MOMENTO DE enviar de forma automática los pasajes adquiridos (RF08) DEBERÁ optimizar la compresión del archivo adjunto en formato PDF para que su tamaño de almacenamiento en el servidor de correo no exceda los 500 KB por transacción.

### 4. Requisitos No Funcionales del Producto — Confiabilidad

**RNF04:** EL SITIO WEB DEBERÁ garantizar una disponibilidad operativa del 99.9% de las veces en modalidad 7x24, asegurando que las compras de pasajes, el registro de cuentas de cliente (RF04) y los accesos al historial (RF10) puedan realizarse en cualquier momento de manera ininterrumpida.

### 5. Requisitos No Funcionales del Producto — Seguridad

**RNF05:** EL SITIO WEB DEBERÁ emplear en todo momento y de manera mandatoria el Protocolo de Transferencia de Hipertexto (HTTP) cifrado sobre seguridad de la capa de transporte (TLS) en su versión 1.3 para proteger el tráfico de información personal y financiera sensible.

### 6. Requisitos No Funcionales de la Organización — Ambientales

**RNF06:** EL SITIO WEB AL MOMENTO DE emitir la confirmación de la transacción (RF02) DEBERÁ priorizar de forma exclusiva el formato digital PDF enviado por correo electrónico para desincentivar el uso innecesario de papel y la impresión física de comprobantes.

### 7. Requisitos No Funcionales de la Organización — Operacionales

**RNF07:** EL SITIO WEB AL MOMENTO DE registrar la información de las ventas y cancelaciones efectuadas (RF09) DEBERÁ sincronizar y volcar automáticamente las transacciones hacia la arquitectura del sistema central de operaciones de la compañía, denominado Panóptico.

### 8. Requisitos No Funcionales de la Organización — Desarrollo

**RNF08:** EL SITIO WEB DEBERÁ ser desarrollado utilizando tecnologías compatibles con infraestructuras y servicios en la nube que sigan estrictamente las directrices e infraestructuras modernas de despliegue para portales web institucionales.

### 9. Requisitos No Funcionales Externos — Regulatorios

**RNF09:** EL SITIO WEB DEBERÁ cumplir con los lineamientos, controles de seguridad y directivas tecnológicas que la norma internacional ISO 27017-C estipula y preescribe para los servicios provistos en la nube.

### 10. Requisitos No Funcionales Externos — Éticos

**RNF10:** EL SITIO WEB DEBERÁ asegurar la absoluta equidad y transparencia al momento de procesar la selección de la ubicación específica de asientos (RF07), impidiendo cualquier tipo de reserva preferencial o bloqueo oculto que discrimine entre visitantes y clientes comunes.

### 11. Requisitos No Funcionales Externos — Legales — Contables

**RNF11:** EL SITIO WEB AL MOMENTO DE calcular el porcentaje de devolución por la cancelación de pasajes (RF03) DEBERÁ aplicar estrictamente las políticas fiscales comerciales vigentes y auditar el flujo de re-imputación contable conforme a la antelación horaria registrada.

### 12. Requisitos No Funcionales Externos — Legales — Protección/Seguridad

**RNF12:** EL SITIO WEB AL MOMENTO DE interactuar con el servicio automático del Registro Nacional de las Personas (RF06) DEBERÁ ajustarse a las regulaciones nacionales de protección de datos personales vigentes, garantizando que la consulta de nombres, DNI y fechas de nacimiento sirva exclusivamente a fines de validación sistémica de identidad.

---

## Historias de Usuario

### HU1: Selección de Servicio y Carga de Pasajeros con Validación RENAPER

**Como** Visitante del sitio web,
**Quiero** buscar servicios disponibles e ingresar los datos de los pasajeros validándolos con el organismo oficial,
**Para** asegurar que la información de viaje sea correcta y poder seleccionar los asientos de mi preferencia.

**Criterios de Aceptación:**

**Título: Búsqueda y filtrado de servicios disponibles.**
- **Detalle sobre la prueba:** El evaluador ingresará al portal web y seleccionará una localidad de origen, una de destino y una fecha de partida. La prueba será exitosa si el sitio web interactúa con el sistema central "Panóptico" y despliega únicamente los servicios ofertados para ese trayecto que cuenten con disponibilidad, permitiendo al usuario escoger uno en base al horario de partida y a la categoría del micro ómnibus (semi-cama, cama, ejecutivo, etc.).

**Título: Carga de datos del pasajero y límite de pasajes.**
- **Detalle sobre la prueba:** Una vez seleccionado el servicio, el evaluador procederá a cargar los datos para cada pasaje a adquirir. La prueba será exitosa si el sistema permite ingresar de forma obligatoria el nombre completo del pasajero (sea el visitante o un tercero), su DNI y su fecha de nacimiento, bloqueando la carga si se intenta exceder el máximo de asientos disponibles para ese servicio en particular.

**Título: Validación automática con el servicio externo de RENAPER.**
- **Detalle sobre la prueba:** Al completar los campos de DNI, nombre y fecha de nacimiento de un pasajero, el sistema procesará los datos. La prueba será exitosa si el portal web invoca de manera automática al servicio de provisión de datos del Registro Nacional de Personas (RENAPER) y confirma la identidad del pasajero, permitiendo avanzar con la compra solo si el organismo externo valida que los datos coinciden y son correctos.

**Título: Selección de asientos disponibles.**
- **Detalle sobre la prueba:** El evaluador avanzará a la etapa de distribución de la unidad móvil. La prueba será exitosa si el portal web muestra el mapa del micro ómnibus con el estado real de la ocupación provisto por el sistema "Panóptico" y permite al usuario elegir un asiento de los que figuren exclusivamente como disponibles para los pasajes que desea adquirir.

---

### HU2: Procesamiento de Pago, Facturación y Emisión de Pasajes

**Como** Visitante del sitio web,
**Quiero** realizar el pago electrónico de los pasajes seleccionados e ingresar mis datos de facturación,
**Para** recibir mis pasajes adquiridos en formato digital de manera segura.

**Criterios de Aceptación:**

**Título: Carga de datos de la tarjeta y datos de facturación.**
- **Detalle sobre la prueba:** El evaluador visualizará en el portal el importe total informado de la compra. Seleccionará una modalidad de pago (tarjeta de crédito o débito), elegirá una compañía y entidad bancaria de la lista aceptada e ingresará el número de tarjeta, vencimiento, titular y código de verificación. Asimismo, completará los datos de facturación (nombre completo, DNI y correo electrónico). La prueba será exitosa si el sistema valida la presencia y el formato de todos estos campos y habilita el botón de confirmación de compra.

**Título: Confirmación bancaria de la imputación del pago.**
- **Detalle sobre la prueba:** El evaluador confirmará su voluntad de adquirir los pasajes presionando el botón de pago. El portal web enviará la transacción al sistema externo de medios de pago. La prueba será exitosa si, ante una respuesta positiva de la entidad bancaria confirmando la imputación del dinero, el portal web genera y muestra en pantalla un código de compra único para la transacción.

**Título: Envío de pasajes en formato PDF por correo electrónico.**
- **Detalle sobre la prueba:** Tras la confirmación exitosa del pago y la visualización del código de compra, se auditará la cuenta de correo electrónico que declaró el visitante en el formulario de facturación. La prueba será exitosa si el sistema envía de manera automatizada un mail a dicha casilla adjuntando los pasajes adquiridos estructurados en un archivo en formato PDF.

**Título: Seguridad y cifrado del tráfico de datos sensibles (HTTPS y TLS 1.3).**
- **Detalle sobre la prueba:** Durante todo el proceso de carga de datos personales, financieros y de interacción con RENAPER y medios de pago, el evaluador inspeccionará los protocolos de red del sitio web. La prueba será exitosa si se constata que el portal web emplea en todo momento el Protocolo de Transferencia de Hipertexto cifrado (HTTPS) bajo la versión 1.3 de seguridad de la capa de transporte (TLS), cumpliendo con los lineamientos de la norma ISO 27017-C para servicios en la nube.

---

### HU3: Cancelación y Devolución de Pasajes Adquiridos

**Como** Visitante o Cliente del sitio web,
**Quiero** solicitar la cancelación de uno o más pasajes asociados a una compra previa,
**Para** obtener el reintegro económico que me corresponda según la antelación de mi aviso.

**Criterios de Aceptación:**

**Título: Identificación de la compra y pasajes a cancelar.**
- **Detalle sobre la prueba:** El evaluador ingresará a la sección independiente de cancelaciones dentro del portal web. Indicará el código de compra o los datos requeridos para localizar su transacción. La prueba será exitosa si el sistema recupera la información desde el sistema central "Panóptico" y despliega de forma individual cada uno de los pasajes incluidos en esa compra, permitiendo al usuario tildar o seleccionar específicamente cuáles desea cancelar.

**Título: Cálculo del porcentaje de devolución por antelación.**
- **Detalle sobre la prueba:** El evaluador seleccionará un pasaje para cancelar y el sistema evaluará la fecha y hora actual respecto a la fecha de partida del micro ómnibus. La prueba será exitosa si la aplicación calcula y muestra en pantalla de manera clara el porcentaje de devolución del importe abonado que le corresponde recibir al usuario, verificando que dicho valor varíe de forma estricta según la cantidad de tiempo de antelación con la que se realiza el trámite.

**Título: Confirmación de la cancelación y actualización de asientos.**
- **Detalle sobre la prueba:** El evaluador confirmará la cancelación del o los pasajes seleccionados en el portal web. La prueba será exitosa si el sistema procesa la baja, libera inmediatamente los asientos cancelados en el mapa del micro ómnibus para que puedan ser comprados por otros visitantes y transmite la novedad al sistema central de operaciones de la compañía ("Panóptico").

**Título: Procesamiento del reembolso financiero.**
- **Detalle sobre la prueba:** Una vez confirmada la cancelación en el sistema, se verificará el estado de la transacción con el medio de pago original. La prueba será exitosa si el portal web inicia la orden de reembolso a la entidad bancaria correspondiente para acreditar al usuario el importe neto calculado según las políticas de devolución por antelación.

---

### HU4: Registro de Cuenta de Cliente

**Como** Visitante del sitio web,
**Quiero** registrar una cuenta de cliente personal en el portal en cualquier momento,
**Para** poder acceder a beneficios adicionales, descuentos y herramientas avanzadas de gestión de mis viajes.

**Criterios de Aceptación:**

**Título: Carga y validación de datos del formulario de registro.**
- **Detalle sobre la prueba:** El evaluador ingresará a la opción de registro del portal web www.vianqn.com.ar. Completará el formulario con sus datos de identificación personales y credenciales de acceso de forma obligatoria. La prueba será exitosa si el sistema valida que los campos cumplen con las condiciones de formato requeridas, permite el envío del formulario y bloquea el proceso si falta algún dato mandatorio.

**Título: Almacenamiento seguro del usuario mediante HTTPS y TLS 1.3.**
- **Detalle sobre la prueba:** Al momento de presionar el botón de confirmación de registro, el evaluador inspeccionará los protocolos de red del portal web. La prueba será exitosa si se constata que los datos de la nueva cuenta viajan de manera segura y cifrada a través del protocolo HTTPS bajo la versión 1.3 de TLS, resguardando la información personal del cliente según los lineamientos de la norma ISO 27017-C.

**Título: Confirmación de cuenta y habilitación en el sistema.**
- **Detalle sobre la prueba:** Una vez procesado el envío del formulario de registro, el sistema creará el perfil del nuevo usuario. La prueba será exitosa si el sitio web muestra un mensaje de alta confirmada en pantalla y habilita de inmediato la cuenta del cliente en la base de datos para que pueda iniciar sesión y acceder a su panel privado.

**Título: Autenticación inicial y acceso al panel de beneficios.**
- **Detalle sobre la prueba:** El evaluador iniciará sesión por primera vez utilizando el correo electrónico y la contraseña del cliente recién registrado. La prueba será exitosa si el portal web autentica correctamente al usuario, le otorga acceso al entorno privado y le permite visualizar la sección exclusiva orientada a los beneficios adicionales del programa de clientes de Vía Neuquén.

---

### HU5: Consulta del Historial de Compras de Clientes

**Como** Cliente registrado en el portal,
**Quiero** acceder a la consulta del historial de mis compras realizadas,
**Para** revisar el detalle de mis viajes pasados y descargar los pasajes vigentes cuando lo necesite.

**Criterios de Aceptación:**

**Título: Acceso exclusivo a la sección de historial mediante sesión activa.**
- **Detalle sobre la prueba:** El evaluador intentará ingresar de forma directa a la URL del historial de compras sin haber iniciado sesión en el portal. La prueba será exitosa si el sistema bloquea el acceso por seguridad y redirige al usuario a la pantalla de login, permitiendo la visualización del historial únicamente cuando un cliente se autentica de forma válida.

**Título: Recuperación y sincronización de datos con el sistema Panóptico.**
- **Detalle sobre la prueba:** Un cliente con sesión activa ingresará a la pestaña de su historial de compras. La prueba será exitosa si el portal web se conecta con el sistema central de operaciones "Panóptico", recupera cronológicamente la información asociada a todas las ventas previas vinculadas a ese usuario y las lista de forma clara en la pantalla.

**Título: Visualización detallada de pasajes adquiridos e importes.**
- **Detalle sobre la prueba:** El evaluador seleccionará una de las transacciones del listado de su historial. La prueba será exitosa si el sistema despliega el detalle completo de los pasajes asociados a esa compra, mostrando localidades de origen y destino, fechas de viaje, datos validados de los pasajeros, asientos elegidos e importes totales abonados con sus respectivos descuentos aplicados.

**Título: Descarga e impresión de pasajes históricos en formato PDF.**
- **Detalle sobre la prueba:** El evaluador identificará un viaje vigente dentro de su historial y presionará el botón para descargar los pasajes. La prueba será exitosa si el portal web genera en tiempo real el archivo correspondiente y permite al cliente descargar los pasajes adquiridos directamente a su dispositivo como un archivo con formato pdf.

---

### HU6: Reprogramación de Fecha de Viaje para Clientes

**Como** Cliente registrado en el portal,
**Quiero** reprogramar la fecha de viaje de un pasaje de manera digital,
**Para** cambiar el día de mi traslado hacia un nuevo servicio con idénticas características sin tener que realizar una cancelación.

**Criterios de Aceptación:**

**Título: Validación de características del servicio para reprogramación.**
- **Detalle sobre la prueba:** El evaluador seleccionará un pasaje activo desde su perfil de cliente y elegirá la opción de reprogramar fecha de viaje. Buscará un servicio en una nueva fecha deseada. La prueba será exitosa si el sistema restringe la selección y únicamente le permite elegir un nuevo servicio que posea idénticas características al original, validando de manera estricta que coincidan las localidades de origen y destino y la categoría del micro ómnibus (semi-cama, cama, ejecutivo, etc.).

**Título: Verificación de disponibilidad en el nuevo servicio elegido.**
- **Detalle sobre la prueba:** Una vez que el cliente selecciona una nueva fecha con un servicio idéntico, el sistema consultará el estado de ocupación. La prueba será exitosa si el portal web verifica mediante el sistema central de operaciones "Panóptico" que el nuevo servicio elegido posee asientos disponibles, permitiendo al usuario avanzar con el cambio de fecha solo si hay vacantes en la unidad.

**Título: Reasignación de asiento y actualización en Panóptico.**
- **Detalle sobre la prueba:** El evaluador escogerá un asiento de los disponibles en el mapa del nuevo servicio y confirmará la reprogramación de la fecha del viaje. La prueba será exitosa si el sistema libera el asiento del servicio original, reserva el nuevo asiento elegido en el coche de destino y transmite la actualización de forma inmediata al sistema central de operaciones "Panóptico".

**Título: Emisión y envío del nuevo pasaje reprogramado.**
- **Detalle sobre la prueba:** Al finalizar el proceso de reprogramación en el portal web, el sistema anulará el pasaje anterior. La prueba será exitosa si el sitio web genera el nuevo pasaje con la fecha de viaje modificada, actualiza el historial del cliente y envía de manera automatizada el nuevo pasaje actualizado en formato pdf a la dirección de correo electrónico del usuario.
