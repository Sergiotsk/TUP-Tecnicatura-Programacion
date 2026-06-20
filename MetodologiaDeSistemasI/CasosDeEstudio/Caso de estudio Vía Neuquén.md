# Caso de estudio: Vía Neuquén

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
