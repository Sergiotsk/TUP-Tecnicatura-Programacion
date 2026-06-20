# Caso de Estudio: ServiHome

**ServiHome** es una empresa que opera en la República Argentina y se dedica al negocio de intermediar entre proveedores de servicios de mantenimiento doméstico a domicilio (plomeros, electricistas, jardineros, albañiles, pintores, decoradores, etc.) y sus potenciales clientes, los residentes de casas, departamentos, quintas, etc.

Actualmente, la empresa ofrece gestionar toda su operatoria, tanto a los clientes como a los proveedores de servicio, a través de un portal web (http://www.servihome.com), que se ejecuta mediante un servidor *Apache v2.4.58* (protocolo HTTP/1.1 y RFC 2616), alojado en un servidor de alojamiento (*host*) virtual (*en la nube*), que opera sobre un sistema operativo *LINUX*.

Adicionalmente, el mismo servidor da soporte a un servicio web (*web service*) de provisión de datos para sitios y aplicaciones externas, empleando algún estándar de intercambio de información entre aplicaciones[^1], y observando rigurosamente, los protocolos específicos particulares del mismo.

En esta oportunidad, ServiHome, ha contratado los servicios de su consultora a los efectos de desarrollar una aplicación para teléfonos inteligentes, de nombre **ServiApp** que, operando sobre equipos con sistema operativo Android (10 a 14) o iOS (14.5.1 a 16.2) e interactuando con el servicio web, permita al cliente, registrar una cuenta personal, iniciar (y cerrar) sesión, registrar sus viviendas y contactar uno o más proveedores de servicios afines a la tarea a realizar, con el objeto de que, si es de su interés, estos oferten un presupuesto para ella.

De ser así, el proveedor, a través de su cuenta en el portal web (única forma de interacción como tal), deberán hacer llegar al cliente (que lo recibirá automáticamente en la aplicación), su presupuesto, el cual contendrá (entre otros datos): su fecha de emisión, un detalle del trabajo a realizar, una fecha de disponibilidad para el inicio de la prestación del servicio, la cantidad de días de trabajo estimados, el costo total de mano de obra y un listado de insumos a emplear (si los hubiera).

Es importante destacar que los presupuestos tienen una validez de **15 (quince) días** y cumplido dicho plazo, caducan automáticamente.

Un proceso de particular interés, es la funcionalidad de registrar una solicitud de presupuestos para un servicio a domicilio.

Para ello, una vez activada por el cliente la correspondiente opción en el menú general de la aplicación, deberá indicar, para cuál de sus viviendas desea presupuestar un servicio.

A continuación, indicará un detalle con la mayor cantidad de información posible acerca de dicho servicio, pudiendo agregar las fotografías que considere, las cuales, por criterios de seguridad informática, sólo podrán ser en formato *jpg*, y que, por gestión eficiente de los espacios de almacenamiento, no podrán exceder la cantidad de 8 fotografías ni el tamaño máximo total de 25 MB.

El cliente proseguirá después, estableciendo el rango de fechas en el cual desea que se inicie la prestación del servicio, informará las formas de pago que está dispuesto a cumplir (efectivo, transferencia bancaria, débito, crédito o *Mercado Pago*) y, si lo desea, agregará un comentario textual con todas las observaciones que considere relevante asentar.

Por último, registrando efectivamente su solicitud, el cliente visualizará en la aplicación, el mensaje de confirmación conteniendo el correspondiente código alfanumérico identificador (en estándar *Unicode*).

En cualquier momento, y mediante otra funcionalidad de la ServiApp, podrá consultar, para cada solicitud de presupuestos efectuada, el listado de los presupuestos recibidos, a fin de que, si hubiera interés en alguno, comunicarle al proveedor la aceptación del mismo. Además, junto con ello, recién entonces podrá visualizar los datos completos del proveedor[^2] (nombres o razón social, dirección, teléfono, correo electrónico, etc.), conforme los mismos se encontraban ocultos, salvo el nombre de la cuenta, la calificación general y los comentarios que anteriores clientes (también a través de la aplicación), eventualmente pudieran haber registrado.

Por cada presupuesto aceptado, ServiHome debitará automáticamente de las tarjetas de crédito asociadas a las respectivas cuentas, el 1% del costo total de mano de obra al cliente, y el 2% del mismo al proveedor.

[^1]: Son tecnologías de intercambio de información entre aplicaciones: SOAP (Simple Object Access Protocol), CORBA (Common Object Request Broker Architecture), REST (Representational State Transfer), etc.
[^2]: Los datos del proveedor permanecen ocultos hasta la aceptación del presupuesto.
