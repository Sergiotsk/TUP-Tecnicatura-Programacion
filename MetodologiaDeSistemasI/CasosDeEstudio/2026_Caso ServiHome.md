# RF, RNF, Reglas de Dominio — Caso de Estudio: ServiHome

---

## Caso de estudio: ServiHome

**ServiHome** es una empresa que opera en la República Argentina y se dedica al negocio de intermediar entre proveedores de servicios de mantenimiento doméstico a domicilio (plomeros, electricistas, jardineros, albañiles, pintores, decoradores, etc.) y sus potenciales clientes, los residentes de casas, departamentos, quintas, etc.

Actualmente, la empresa ofrece gestionar toda su operatoria, tanto a los clientes como a los proveedores de servicio, a través de un portal web (http://www.servihome.com), que se ejecuta mediante un servidor Apache v2.4.58 (protocolo HTTP/1.1 y RFC 2616), alojado en un servidor de alojamiento (host) virtual (en la nube), que opera sobre un sistema operativo LINUX.

Adicionalmente, el mismo servidor da soporte a un servicio web (web service) de provisión de datos para sitios y aplicaciones externas, empleando algún estándar de intercambio de información entre aplicaciones, y observando rigurosamente, los protocolos específicos particulares del mismo.

En esta oportunidad, ServiHome, ha contratado los servicios de su consultora a los efectos de desarrollar una aplicación para teléfonos inteligentes, de nombre **ServiApp** que, operando sobre equipos con sistema operativo Android (10 a 14) o iOS (14.5.1 a 16.2) e interactuando con el servicio web, permita al cliente, registrar una cuenta personal, iniciar (y cerrar) sesión, registrar sus viviendas y contactar uno o más proveedores de servicios afines a la tarea a realizar, con el objeto de que, si es de su interés, estos oferten un presupuesto para ella.

De ser así, el proveedor, a través de su cuenta en el portal web (única forma de interacción como tal), deberán hacer llegar al cliente (que lo recibirá automáticamente en la aplicación), su presupuesto, el cual contendrá (entre otros datos): su fecha de emisión, un detalle del trabajo a realizar, una fecha de disponibilidad para el inicio de la prestación del servicio, la cantidad de días de trabajo estimados, el costo total de mano de obra y un listado de insumos a emplear (si los hubiera).

Es importante destacar que los presupuestos tienen una validez de **15 (quince) días** y cumplido dicho plazo, caducan automáticamente.

Un proceso de particular interés, es la funcionalidad de registrar una solicitud de presupuestos para un servicio a domicilio. Para ello, una vez activada por el cliente la correspondiente opción en el menú general de la aplicación, deberá indicar, para cuál de sus viviendas desea presupuestar un servicio.

A continuación, indicará un detalle con la mayor cantidad de información posible acerca de dicho servicio, pudiendo agregar las fotografías que considere, las cuales, por criterios de seguridad informática, sólo podrán ser en formato jpg, y que, por gestión eficiente de los espacios de almacenamiento, no podrán exceder la cantidad de 8 fotografías ni el tamaño máximo total de 25 MB.

El cliente proseguirá después, estableciendo el rango de fechas en el cual desea que se inicie la prestación del servicio, informará las formas de pago que está dispuesto a cumplir (efectivo, transferencia bancaria, débito, crédito o Mercado Pago) y, si lo desea, agregará un comentario textual con todas las observaciones que considere relevante asentar.

Por último, registrando efectivamente su solicitud, el cliente visualizará en la aplicación, el mensaje de confirmación conteniendo el correspondiente código alfanumérico identificador (en estándar Unicode).

En cualquier momento, y mediante otra funcionalidad de la ServiApp, podrá consultar, para cada solicitud de presupuestos efectuada, el listado de los presupuestos recibidos, a fin de que, si hubiera interés en alguno, comunicarle al proveedor la aceptación del mismo. Además, junto con ello, recién entonces podrá visualizar los datos completos del proveedor (nombres o razón social, dirección, teléfono, correo electrónico, etc.), conforme los mismos se encontraban ocultos, salvo el nombre de la cuenta, la calificación general y los comentarios que anteriores clientes (también a través de la aplicación), eventualmente pudieran haber registrado.

Por cada presupuesto aceptado, ServiHome debitará automáticamente de las tarjetas de crédito asociadas a las respectivas cuentas, el 1% del costo total de mano de obra al cliente, y el 2% del mismo al proveedor.

---

## Actividad

1. **Listar:**
   - a) Funcionalidades requeridas.
   - b) Condicionantes y Determinantes detectados.
   - c) Reglas del dominio advertidas.
2. **Tomando como base lo desarrollado en el punto anterior, redactar en lenguaje natural como requisitos del cliente, en alto nivel:**
   - a) Requisitos Funcionales.
3. **Partiendo de lo precedente, refinar, completar y redactar en lenguaje natural como requisitos del sistema, en bajo nivel:**
   - a) Los requisitos funcionales.
   - b) Los requisitos no funcionales. Y clasificarlos según Ontología autor Sommerville.

---

## Funcionalidades Requeridas

### Para el Cliente (en la ServiApp):

- Registrar una cuenta personal.
- Iniciar y cerrar sesión.
- Registrar viviendas.
- Registrar una solicitud de presupuestos para un servicio a domicilio en una vivienda específica.
- Cargar detalles del servicio solicitado, incluyendo comentarios de texto y hasta 8 fotografías en formato JPG.
- Establecer rango de fechas de inicio del servicio y seleccionar las formas de pago aceptadas.
- Visualizar un mensaje de confirmación con un código alfanumérico identificador tras registrar la solicitud.
- Consultar el listado de presupuestos recibidos para cada solicitud realizada.
- Aceptar un presupuesto específico de la lista.
- Visualizar los datos completos del proveedor una vez aceptado el presupuesto.
- Calificar y dejar comentarios sobre los proveedores tras la prestación del servicio.
- Recibir automáticamente en la aplicación los presupuestos enviados por los proveedores.

---

## Condicionantes y Determinantes Detectados

- **Plataformas y Sistemas Operativos Móviles:** La aplicación ServiApp debe ser compatible y operar sobre equipos con Android (versiones 10 a 14) e iOS (versiones 14.5.1 a 16.2).
- **Infraestructura Servidor Actual:** El portal web actual corre sobre un servidor Apache v2.4.58, utiliza el protocolo HTTP/1.1 (RFC 2616) y está alojado en un entorno virtual (en la nube) con sistema operativo LINUX.
- **Interoperabilidad:** El servidor debe dar soporte a un servicio web que emplee un estándar de intercambio de información entre aplicaciones y observe rigurosamente sus protocolos específicos.
- **Canales de Interacción:** Los proveedores únicamente pueden interactuar con el sistema a través del portal web, mientras que los clientes gestionarán las solicitudes y presupuestos mediante la aplicación móvil (ServiApp).
- **Restricciones de Almacenamiento y Seguridad (Fotos):** Para las fotos de las solicitudes, solo se admite el formato `.jpg`. El límite máximo de almacenamiento es de hasta 8 fotografías y el tamaño total acumulado no puede exceder los 25 MB.
- **Estándar de Codificación:** El código alfanumérico identificador de la confirmación de la solicitud debe cumplir con el estándar Unicode.
- **Ubicación Geográfica:** La empresa opera dentro del territorio de la República Argentina.

---

## Reglas del Dominio Advertidas

- **Validez del Presupuesto:** Todo presupuesto emitido por un proveedor tiene una validez estricta de 15 (quince) días corridos; una vez cumplido este plazo, expira automáticamente.
- **Estructura Obligatoria del Presupuesto:** El presupuesto enviado por el proveedor debe contener obligatoriamente: fecha de emisión, detalle del trabajo, fecha de disponibilidad para inicio, cantidad de días estimados de trabajo, costo total de la mano de obra y listado de insumos (si aplica).
- **Formas de Pago Admitidas:** El cliente solo puede seleccionar entre las siguientes opciones de pago para el servicio: efectivo, transferencia bancaria, débito, crédito o Mercado Pago.
- **Políticas de Privacidad de Datos (Ocultamiento de Datos del Proveedor):** Los datos identificatorios y de contacto del proveedor (nombre/razón social completa, dirección, teléfono, correo) permanecen rigurosamente ocultos para el cliente hasta que este acepte explícitamente su presupuesto. Antes de la aceptación, el cliente solo puede ver el nombre de usuario de la cuenta, su calificación general y los comentarios históricos.
- **Monetización y Comisiones (Débito Automático):** Por cada presupuesto que el cliente acepte, ServiHome cobra una comisión que se debita de forma automática de las tarjetas de crédito adheridas al sistema:
  - Al Cliente: Se le debita el **1%** del costo total de la mano de obra.
  - Al Proveedor: Se le debita el **2%** del costo total de la mano de obra.

---

## Requisitos Funcionales en Alto Nivel

- **RF1.** EL SISTEMA DEBERÁ permitir a los usuarios clientes registrar una cuenta personal, iniciar sesión y cerrar sesión desde la aplicación móvil ServiApp.
- **RF2.** EL SISTEMA DEBE permitir al cliente registrar una solicitud de presupuesto para una vivienda específica, detallando la tarea, indicando el rango de fechas de inicio, seleccionando las formas de pago aceptadas y permitiendo adjuntar comentarios y hasta 8 fotografías en formato JPG que no superen los 25 MB en total.
- **RF3.** EL SISTEMA DEBERÁ permitir a los proveedores de servicios confeccionar y enviar presupuestos detallados a los clientes exclusivamente a través del portal web.
- **RF4.** EL SISTEMA DEBE listar al cliente los presupuestos recibidos para cada solicitud y permitirle seleccionar uno para su aceptación, revelando recién en ese momento los datos de contacto completos del proveedor.
- **RF5.** EL SISTEMA DEBERÁ realizar el débito automático de las comisiones en las tarjetas de crédito asociadas una vez que un presupuesto sea aceptado, cobrando el 1% del costo de mano de obra al cliente y el 2% al proveedor.
- **RF6.** EL SISTEMA DEBERÁ permitir a los usuarios clientes registrar y administrar sus diferentes viviendas (casas, departamentos, quintas, etc.) dentro de su perfil en la aplicación móvil.
- **RF7.** EL SISTEMA DEBE emitir un mensaje de confirmación en la aplicación móvil que contenga un código alfanumérico identificador único en estándar Unicode inmediatamente después de que el cliente registre con éxito una solicitud de presupuesto.
- **RF8.** EL SISTEMA DEBERÁ enviar y notificar de forma automática al cliente, directamente en la aplicación ServiApp, los presupuestos que los proveedores emitan y remitan desde el portal web.
- **RF9.** EL SISTEMA DEBE dar de baja y caducar de manera automática cualquier presupuesto que haya cumplido el plazo estricto de 15 días de validez desde su fecha de emisión sin haber sido aceptado.
- **RF10.** EL SISTEMA DEBERÁ permitir al cliente calificar el servicio y registrar comentarios sobre el proveedor a través de la aplicación móvil una vez finalizada la prestación.

---

## Requisitos Funcionales en Bajo Nivel

- **RF1.** EL SISTEMA DEBE validar que las fotografías adjuntas a una solicitud de presupuesto estén exclusivamente en formato `.jpg`, que la cantidad total no supere las 8 unidades y que el peso acumulado de los archivos no exceda los 25 MB, rechazando la carga y mostrando un error si no se cumplen estas condiciones.
- **RF2.** EL SISTEMA DEBERÁ generar y mostrar al cliente una pantalla de confirmación con un código identificador alfanumérico codificado bajo el estándar Unicode inmediatamente después de guardar de manera exitosa una solicitud de presupuesto en la base de datos.
- **RF3.** EL SISTEMA DEBE restringir la visualización de los datos de contacto del proveedor (nombres/razón social, dirección, teléfono y correo electrónico), mostrando únicamente el nombre de la cuenta, la calificación y comentarios históricos hasta que el cliente presione el botón de aceptar presupuesto.
- **RF4.** EL SISTEMA DEBERÁ ejecutar un proceso en segundo plano cada 24 horas que compare la fecha actual con la fecha de emisión de los presupuestos activos, cambiando automáticamente el estado a "Caducado" para todos aquellos que hayan superado los 15 días corridos de validez.
- **RF5.** EL SISTEMA DEBE procesar un débito automático a través de la pasarela de pagos en las tarjetas de crédito asociadas a las cuentas al momento de la aceptación del presupuesto, calculando y aplicando de forma exacta el 1% sobre el costo de mano de obra al cliente y el 2% sobre ese mismo concepto al proveedor.
- **RF6.** EL SISTEMA DEBE proveer en la aplicación móvil un formulario de registro de vivienda que valide de forma obligatoria el ingreso del tipo de propiedad (casa, departamento, quinta, etc.) y la dirección antes de persistir los datos en el perfil del cliente.
- **RF7.** EL SISTEMA DEBERÁ validar que el formulario de confección de presupuesto en el portal web incluya obligatoriamente los campos de fecha de emisión, detalle del trabajo, fecha de disponibilidad de inicio, cantidad de días estimados, costo total de mano de obra y, de forma opcional, el listado de insumos, impidiendo el envío si alguno de los obligatorios está vacío.
- **RF8.** EL SISTEMA DEBE restringir la selección de formas de pago en el módulo de solicitudes de la aplicación móvil, permitiendo únicamente el marcado de las opciones de verificación equivalentes a: efectivo, transferencia bancaria, débito, crédito o Mercado Pago.
- **RF9.** EL SISTEMA DEBERÁ invocar de forma automática el servicio web (web service) de interoperabilidad para sincronizar y renderizar en la interfaz de la aplicación móvil (ServiApp) cualquier nuevo presupuesto que el proveedor haya registrado y enviado desde el portal web.
- **RF10.** EL SISTEMA DEBE habilitar un formulario de calificación en la aplicación móvil una vez que el estado del presupuesto figure como "Prestado/Finalizado", el cual constará de un selector numérico para la calificación general y un campo de texto libre para los comentarios del cliente.

---

## Requisitos No Funcionales (RNF) según la Ontología de Sommerville

### Requisitos No Funcionales del Producto — Usabilidad

**RNF1.** EL SISTEMA SERVIAPP DEBE presentar una interfaz de usuario adaptativa e intuitiva diseñada para operar correctamente en pantallas de dispositivos móviles que corran bajo los sistemas operativos Android (versiones 10 a 14) e iOS (versiones 14.5.1 a 16.2).

### Requisitos No Funcionales del Producto — Eficiencia / Rendimiento

**RNF2.** EL SISTEMA SERVIAPP AL MOMENTO DE consultar el listado de presupuestos recibidos (RF04) DEBERÁ procesar y renderizar la información en la pantalla del dispositivo móvil de forma automática e inmediata tras la recepción del flujo de datos del servicio web.

### Requisitos No Funcionales del Producto — Eficiencia / Espacio

**RNF3.** EL SISTEMA SERVIAPP AL MOMENTO DE registrar una solicitud de presupuestos para un servicio a domicilio (RF02) DEBE limitar la carga de archivos adjuntos en la memoria local y de subida a un máximo estricto de 8 fotografías que no superen los 25 MB en su conjunto.

### Requisitos No Funcionales del Producto — Confiabilidad

**RNF4.** EL SISTEMA SERVIAPP DEBERÁ mantener la persistencia y disponibilidad de las funciones de consulta de solicitudes y presupuestos de forma ininterrumpida mediante la comunicación continua con el servicio web de provisión de datos.

### Requisitos No Funcionales del Producto — Seguridad

**RNF5.** EL SISTEMA SERVIAPP AL MOMENTO DE adjuntar fotografías en una solicitud de servicio (RF02) DEBE restringir la selección de archivos en el dispositivo del usuario basándose en criterios de seguridad informática, aceptando única y exclusivamente el formato `.jpg`.

### Requisitos No Funcionales de la Organización — Operacionales

**RNF6.** EL SISTEMA SERVIAPP DEBE conectarse e interactuar con la plataforma central a través del servicio web externo observando rigurosamente los protocolos específicos particulares de intercambio de información provistos por el servidor.

### Requisitos No Funcionales de la Organización — Desarrollo

**RNF7.** EL SISTEMA SERVIAPP DEBERÁ ser desarrollado siguiendo las pautas de compilación y empaquetado nativas o híbridas necesarias para su correcta instalación en las tiendas de aplicaciones correspondientes a los entornos Android e iOS especificados.

### Requisitos No Funcionales Externos — Regulatorios

**RNF8.** EL SISTEMA SERVIAPP AL MOMENTO DE visualizar el mensaje de confirmación de registro (RF02) DEBE codificar y mostrar el correspondiente código alfanumérico identificador bajo los estándares internacionales de caracteres Unicode.

### Requisitos No Funcionales Externos — Éticos

**RNF9.** EL SISTEMA SERVIAPP AL MOMENTO DE listar un presupuesto (RF04) DEBE garantizar el acceso transparente y equitativo a la calificación general y comentarios que anteriores clientes hayan registrado históricamente sobre el proveedor.

### Requisitos No Funcionales Externos — Legales / Contables

**RNF10.** EL SISTEMA SERVIAPP AL MOMENTO DE registrar la aceptación de un presupuesto (RF04) DEBERÁ iniciar la instrucción financiera para debitar de forma automática de la tarjeta de crédito asociada a la cuenta del cliente el 1% exacto del costo total de la mano de obra.

### Requisitos No Funcionales Externos — Legales / Protección / Privacidad

**RNF11.** EL SISTEMA SERVIAPP AL MOMENTO DE consultar el listado de presupuestos recibidos (RF04) DEBE proteger la privacidad comercial y civil manteniendo ocultos los datos de contacto y filiación del proveedor (nombres, dirección, teléfono, correo electrónico), liberándolos en la interfaz únicamente después de que el usuario presione la opción de aceptación formal.

---

## Historias de Usuario

### HU1: Registro de una Solicitud de Presupuesto

**Como** Cliente de ServiApp,
**Quiero** registrar una solicitud de presupuesto para un servicio doméstico detallando mi necesidad, las fechas y los archivos adjuntos,
**Para** que los proveedores afines puedan conocer mi requerimiento y enviarme sus ofertas.

**Criterios de Aceptación:**

1. **Título: Selección de vivienda y carga de datos obligatorios.**
   El evaluador ingresará a la opción correspondiente del menú general de ServiApp y seleccionará una de las viviendas registradas del usuario. Luego, completará la descripción detallada del servicio, definirá el rango de fechas estimadas para el inicio de la prestación y tildará al menos una de las formas de pago válidas (efectivo, transferencia bancaria, débito, crédito o Mercado Pago). La prueba será exitosa si el sistema valida que los campos obligatorios están completos y habilita el botón para guardar la solicitud.

2. **Título: Restricción de formato, cantidad y tamaño de fotografías.**
   El evaluador intentará adjuntar archivos de imagen a la solicitud. Se realizarán tres intentos de fallo: primero, subiendo un archivo con extensión distinta a `.jpg`; segundo, intentando cargar 9 fotografías; y tercero, subiendo imágenes que sumen más de 25 MB en total. La prueba será exitosa si en los tres casos la aplicación bloquea la carga, muestra un mensaje de alerta sobre seguridad o almacenamiento, y solo permite avanzar cuando se corrigen las fotos para cumplir con los límites estipulados.

3. **Título: Confirmación de registro con identificador Unicode.**
   El evaluador presionará el botón para registrar efectivamente la solicitud de presupuesto. La prueba será exitosa si la aplicación procesa la información y despliega de inmediato en la pantalla un mensaje confirmando el éxito de la operación junto con un código alfanumérico identificador único generado bajo el estándar Unicode.

4. **Título: Envío y persistencia de datos mediante el Servicio Web.**
   Al momento de confirmarse el registro en ServiApp, se verificará a nivel técnico que la aplicación invoque correctamente al servicio web externo de la empresa. La prueba será exitosa si los datos viajan utilizando el protocolo correspondiente y la solicitud impacta de forma íntegra en el servidor Apache de ServiHome, quedando disponible para su visualización y gestión por parte de los proveedores a través del portal web.

---

### HU2: Consulta de Presupuestos Recibidos

**Como** Cliente de ServiApp,
**Quiero** consultar la lista de presupuestos recibidos para una solicitud específica manteniendo la privacidad del proveedor,
**Para** evaluar las opciones técnicas y económicas antes de tomar una decisión de contratación.

**Criterios de Aceptación:**

1. **Título: Visualización del listado de ofertas vigentes.**
   El evaluador abrirá la sección de consultas dentro de ServiApp y seleccionará una solicitud de presupuesto previamente enviada. La prueba será exitosa si la aplicación se conecta con el servicio web y renderiza correctamente un listado en pantalla que muestre todos los presupuestos activos que los proveedores han emitido desde el portal web para esa solicitud en particular.

2. **Título: Ocultamiento estricto de los datos de contacto del proveedor.**
   El evaluador revisará las ofertas del listado de presupuestos recibidos antes de realizar cualquier aceptación. La prueba será exitosa si el sistema comprueba que los únicos datos visibles del proveedor son el nombre de la cuenta, su calificación general y los comentarios de clientes anteriores, garantizando que los datos de contacto sensibles (nombres completos o razón social, dirección, teléfono y correo electrónico) permanezcan totalmente ocultos e inaccesibles en esta etapa.

3. **Título: Integridad de los datos técnicos y comerciales del presupuesto.**
   El evaluador seleccionará y abrirá una de las ofertas del listado para ver su detalle. La prueba será exitosa si la interfaz de la aplicación muestra la totalidad de los datos obligatorios enviados por el proveedor: fecha de emisión, detalle del trabajo a realizar, fecha de disponibilidad de inicio, cantidad de días de trabajo estimados, costo total de mano de obra y el listado de insumos a emplear con sus respectivas especificaciones.

4. **Título: Control de caducidad automática de 15 días.**
   Se introducirá en la base de datos un presupuesto cuya fecha de emisión sea mayor a 15 días corridos respecto a la fecha actual del sistema. El evaluador ingresará a la aplicación para consultar esa solicitud. La prueba será exitosa si el sistema detecta que se cumplió el plazo de validez, marca automáticamente el presupuesto con el estado "Caducado" y deshabilita por completo cualquier botón o funcionalidad que permita al cliente aceptarlo.

---

### HU3: Aceptación de Presupuesto y Débito de Comisión

**Como** Cliente de ServiApp,
**Quiero** aceptar un presupuesto de interés y autorizar el cobro automático de las comisiones del servicio,
**Para** revelar los datos de contacto del proveedor y dar inicio formal a la coordinación del trabajo.

**Criterios de Aceptación:**

1. **Título: Envío de comunicación de aceptación.**
   El evaluador abrirá un presupuesto válido (no caducado) y presionará el botón para comunicar la aceptación del mismo. La prueba será exitosa si la aplicación transmite la orden de confirmación a través del servicio web y el estado del presupuesto se actualiza de manera inmediata en el sistema, notificando al proveedor correspondiente.

2. **Título: Revelación inmediata de datos completos del proveedor.**
   Inmediatamente después de haber registrado la aceptación de la oferta, el evaluador ingresará al detalle de ese presupuesto específico en la aplicación. La prueba será exitosa si la interfaz actualiza los permisos de visualización y muestra en pantalla todos los datos del proveedor que antes estaban ocultos, incluyendo sus nombres o razón social, dirección, número de teléfono y dirección de correo electrónico.

3. **Título: Débito automático de comisión al cliente.**
   Tras confirmarse la aceptación del presupuesto, se auditará el módulo de facturación y pagos de ServiHome. La prueba será exitosa si el sistema identifica la tarjeta de crédito asociada a la cuenta del cliente y realiza un débito automático equivalente al valor exacto del 1% del costo total de la mano de obra estipulado en ese presupuesto específico.

4. **Título: Débito automático de comisión al proveedor.**
   De manera simultánea al procesamiento de la aceptación de la oferta, se auditará la cuenta del prestador del servicio en el sistema de cobros. La prueba será exitosa si la plataforma de ServiHome identifica la tarjeta de crédito vinculada a la cuenta del proveedor y le debita de forma automática el importe correspondiente al 2% del costo total de la mano de obra detallado en el presupuesto aceptado.

---

### HU4: Registro de Cuenta de Cliente en la Aplicación

**Como** Residente de una vivienda (potencial cliente),
**Quiero** registrar una cuenta personal directamente desde la aplicación móvil,
**Para** poder acceder a las funcionalidades de ServiApp y comenzar a gestionar mis solicitudes de servicio.

**Criterios de Aceptación:**

1. **Título: Validación y carga de datos de registro del cliente.**
   El evaluador abrirá la aplicación por primera vez y seleccionará la opción de registrar una cuenta personal. Procederá a ingresar sus datos de identificación obligatorios (como nombre, apellido, correo electrónico y contraseña). La prueba será exitosa si el sistema valida que todos los campos mandatorios cumplen con las reglas básicas de formato, permite enviar el formulario y deniega el registro si algún dato esencial queda vacío.

2. **Título: Persistencia del nuevo usuario a través del Servicio Web.**
   Una vez enviado el formulario de registro desde el dispositivo móvil, se verificará la comunicación con el backend. La prueba será exitosa si ServiApp invoca de forma correcta al servicio web externo y los datos del nuevo cliente se guardan de manera íntegra en la base de datos alojada en el servidor Linux de la empresa, permitiendo que la cuenta quede inmediatamente activa para operar.

3. **Título: Compatibilidad de la interfaz según el sistema operativo del teléfono.**
   El evaluador ejecutará el flujo completo de registro en diferentes dispositivos de prueba que cubran los rangos del negocio. Se utilizarán smartphones con sistemas operativos Android (versiones 10 a 14) y iPhones con sistemas operativos iOS (versiones 14.5.1 a 16.2). La prueba será exitosa si la interfaz gráfica de registro se adapta, se renderiza correctamente y es 100% funcional en todas las versiones de software mencionadas.

4. **Título: Asociación inicial de una tarjeta de crédito a la cuenta.**
   Durante o inmediatamente después del proceso de registro, el sistema solicitará al cliente la vinculación de una tarjeta de crédito válida para futuros cobros de comisiones. El evaluador ingresará los datos de la tarjeta. La prueba será exitosa si la aplicación valida la estructura del plástico y la asocia correctamente a la cuenta personal del cliente en el repositorio central.

---

### HU5: Registro y Gestión de Viviendas

**Como** Cliente de ServiApp,
**Quiero** registrar y dar de alta mis diferentes propiedades en mi perfil de usuario,
**Para** tenerlas disponibles al momento de emitir una solicitud de presupuesto a domicilio.

**Criterios de Aceptación:**

1. **Título: Carga de datos de la vivienda y tipos de residencia.**
   El evaluador iniciará sesión en ServiApp, irá al perfil de usuario y seleccionará la opción para registrar una nueva vivienda. Completará los campos de dirección, localidad y seleccionará el tipo de residencia (casa, departamento, quinta, etc.). La prueba será exitosa si la aplicación permite guardar la información y valida que la vivienda quede correctamente guardada en el dispositivo móvil y en el servidor a través del servicio web.

2. **Título: Registro múltiple de propiedades por cuenta.**
   El evaluador intentará agregar más de una propiedad en la misma cuenta personal del cliente. Registrará secuencialmente un departamento y luego una casa de quinta. La prueba será exitosa si la aplicación permite la carga múltiple sin sobrescribir los datos anteriores, listando claramente cada vivienda registrada de manera independiente dentro del perfil del usuario.

3. **Título: Disponibilidad de las viviendas en el flujo de solicitudes.**
   El evaluador simulará la creación de una nueva solicitud de presupuesto para un servicio técnico. La prueba será exitosa si, al desplegar el menú de selección de vivienda dentro del formulario de la solicitud, aparecen listadas de manera exacta todas las propiedades que el usuario registró previamente en su perfil, obligándolo a elegir una para poder avanzar.

4. **Título: Modificación o eliminación de una vivienda registrada.**
   El evaluador seleccionará una vivienda existente de su lista e intentará editar sus datos o darla de baja. La prueba será exitosa si el sistema actualiza los cambios en tiempo real a través del servicio web y restringe la eliminación de la propiedad si esta posee actualmente una solicitud de presupuesto activa o un trabajo en proceso de cotización.

---

### HU6: Control de Sesión y Autenticación de Usuarios

**Como** Cliente de ServiApp,
**Quiero** iniciar y cerrar sesión de manera segura con mis credenciales personales en la aplicación,
**Para** proteger mis datos privados, mis viviendas registradas y el historial de presupuestos de accesos no autorizados.

**Criterios de Aceptación:**

1. **Título: Validación de credenciales en el inicio de sesión.**
   El evaluador intentará ingresar a la aplicación colocando un correo electrónico o contraseña incorrectos. La prueba será exitosa si la aplicación deniega el acceso, muestra un mensaje de error genérico que no comprometa la seguridad y bloquea el paso hacia el menú general hasta que se ingresen las credenciales correctas registradas en el sistema.

2. **Título: Conexión segura con el servidor web (Autenticación exitosa).**
   El evaluador ingresará las credenciales válidas de un cliente y presionará "Iniciar Sesión". La prueba será exitosa si ServiApp realiza una petición segura interactuando con el servicio web, el servidor Apache valida la identidad del usuario y la aplicación móvil descarga la configuración de la sesión, redirigiendo al cliente directamente al menú principal de forma fluida.

3. **Título: Funcionalidad de Cierre de Sesión Seguro.**
   El usuario, estando dentro del menú principal o de configuración de ServiApp, seleccionará la opción de "Cerrar Sesión". La prueba será exitosa si la aplicación destruye de inmediato los tokens o datos temporales de autenticación en el teléfono, interrumpe la comunicación activa con el servicio web para esa sesión y redirige al usuario de vuelta a la pantalla de bienvenida/login, impidiendo regresar con el botón "Atrás" del dispositivo.

4. **Título: Persistencia del estado de la sesión ante interrupciones de la app.**
   Con la sesión del cliente iniciada activamente, el evaluador minimizará ServiApp, abrirá otras aplicaciones o bloqueará la pantalla del teléfono. Al volver a abrir ServiApp, la prueba será exitosa si el sistema mantiene al usuario autenticado en su sesión activa sin forzarlo a loguearse nuevamente, siempre y cuando no haya presionado de forma explícita el botón de cierre de sesión.
