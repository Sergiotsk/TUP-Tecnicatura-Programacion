# Caso de Estudio: SDBAP — "Sistema de Despacho de Bultos de Air Patagonia"

**AirPatagonia** es una aerolínea que opera en el ámbito de la aviación civil comercial de la República Argentina.

La misma establece que el procedimiento de desarrollo de software a usar debe estar definido explícitamente (en manuales de procedimientos) y debe cumplir con los estándares ISO 9000, estableciendo como herramienta CASE a Visual Paradigm y la generación de reportes gerenciales quincenales que deben mostrar el esfuerzo invertido en los nuevos desarrollos.

Del mismo modo, establece que las pruebas de software deben ser gestionadas con herramientas de gestión de software testing, siendo ejecutadas por medio de la utilización de Selenium y Ruby como herramienta y lenguaje de scripting para la automatización de las pruebas mencionadas.

La empresa, presenta un sistema informático (llamado **SDBAP**), para registrar los despachos de bultos de sus pasajeros.

Dicho sistema conduce un proceso que se inicia cuando el pasajero se presenta, con su ticket y los bultos que desea despachar para transportar en la bodega de su avión, ante el mostrador de despacho de bultos de la aerolínea.

Allí, un empleado de la compañía (el **despachante**), que inició oportunamente sesión en esa terminal al comenzar su turno laboral, recibirá al pasajero con sus bultos y procesará el registro del despacho, restringiéndose esta operatoria estrictamente a los vuelos de la aerolínea cuya partida esté proyectada dentro del lapso máximo de las próximas dos horas.

Al momento de proceder al registro del despacho, el despachante ingresa el número de ticket y, conforme lo consultado al sistema **Gallius** de operaciones (vuelos) de la aerolínea, SDBAP verifica si se puede despachar bultos para el vuelo asociado. Además, consultando al sistema de gestión de ventas **APSale** de AirPatagonia despliega información acerca del pasajero y la ubicación adquirida (todo este proceso no puede exceder los 4 segundos de demora).

Luego, tantas veces como bultos lleve el pasajero, el despachante solicita a éste que lo deposite en balanza electrónica integrada para su pesado (la ART de la aerolínea no autoriza que lo haga el despachante), identifica la categoría del bulto (normal, frágil, refrigerado, etc.) e imprime y entrega para adherir al bulto, antes del pasaje manual a la cinta transportadora, una etiqueta con un código QR único, conteniendo todos los datos del despacho de ese bulto.

Finalizado el registro de todos los bultos del pasajero, el sistema remite automáticamente, como comprobante del despacho de bultos, un archivo de formato de documento portátil (pdf) a la cuenta de correo electrónico declarada por el pasajero al momento de la compra del boleto.

Es importante tener presente un par de considerandos.

El primero, las categorías de bultos no son arbitrarias, sino que están definidas dentro de los listados que periódicamente habilita la **Agencia Nacional de Aviación Civil (ANAC)** para cada uno de los aeropuertos de su jurisdicción a través del sistema **Cóndor**, el cual es consultado periódicamente por el SDBAP y similares de otras compañías.

El segundo, el equipaje debe cumplir, también, con:

- Las disposiciones del Código Aeronáutico (Ley 17.285, Título VI: "Aeronáutica Comercial", Capítulo II "Servicios de Transporte Aéreo Interno", Sección C "Transporte de Equipajes" – Artículos 116 a 118).
- Normas IATA sobre equipaje de pasajeros. IATA Resolution 753 "BaggageTracking - ImplementationGuide".

Conforme la aerolínea dispone de varios puestos de despacho de bultos, además del despachante, opera en el sector un **supervisor** que puede ejecutar en el sistema todas las funcionalidades del despachante, pero tiene, además, la potestad exclusiva de generar la consulta de actualización del listado de categorías de bultos al sistema Cóndor.

La validación de las credenciales ingresadas en cualquier inicio de sesión en el sistema, involucra la consulta de éste al sistema **AirExploiter** de recursos humanos de la compañía.

Todos los intercambios de información entre sistemas, según lo que establece la ICAO (International Civil Aviation Organization), deben realizarse siguiendo las especificaciones del estándar JSON (ISO/IEC 21778:2017), en su versión 2.7.2.
