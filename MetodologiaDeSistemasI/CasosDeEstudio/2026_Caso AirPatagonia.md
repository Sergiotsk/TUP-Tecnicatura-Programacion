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
- Normas IATA sobre equipaje de pasajeros. IATA Resolution 753 "Baggage Tracking - Implementation Guide".

Conforme la aerolínea dispone de varios puestos de despacho de bultos, además del despachante, opera en el sector un **supervisor** que puede ejecutar en el sistema todas las funcionalidades del despachante, pero tiene, además, la potestad exclusiva de generar la consulta de actualización del listado de categorías de bultos al sistema Cóndor.

La validación de las credenciales ingresadas en cualquier inicio de sesión en el sistema, involucra la consulta de éste al sistema **AirExploiter** de recursos humanos de la compañía.

Todos los intercambios de información entre sistemas, según lo que establece la ICAO (International Civil Aviation Organization), deben realizarse siguiendo las especificaciones del estándar JSON (ISO/IEC 21778:2017), en su versión 2.7.2.

---

## Actividad

1. **Listar:**
   - a) Funcionalidades requeridas.
   - b) Condicionantes y Determinantes detectados.
   - c) Reglas del dominio advertidas.

2. **Tomando como base lo desarrollado en el punto anterior redactar, en lenguaje natural como requisitos del cliente, en alto nivel:**
   - a) Requisitos Funcionales.

3. **Partiendo de lo precedente, refinar, completar y redactar, en lenguaje natural como requisitos del sistema, en bajo nivel:**
   - a) Los requisitos funcionales.
   - b) Los requisitos no funcionales. Y Clasificarlos según Ontología autor Sommerville.

---

## Funcionalidades Requeridas

- Iniciar sesión en el sistema por parte del despachante al comienzo de su turno.
- Seleccionar un vuelo disponible que despegue en las próximas 2 (dos) horas.
- Verificar el número de boleto del pasajero.
- Registrar cada bulto con las siguientes acciones:
  - Seleccionar la categoría del bulto (normal, frágil, refrigerado, etc.).
  - Pesar el bulto utilizando la balanza electrónica integrada.
  - Generar una etiqueta con un código QR único para cada bulto.
- Imprimir y adherir la etiqueta a cada bulto.
- Generar e imprimir un comprobante final del despacho para el pasajero.

---

## Condicionantes y Determinantes Detectados

- Sólo se pueden registrar bultos de vuelos que despeguen en las próximas 2 (dos) horas.
- El sistema debe estar vinculado a una balanza electrónica para registrar el peso.
- Cada bulto debe tener un código QR único que contenga los datos del despacho.
- El despachante debe iniciar sesión para operar el sistema.

---

## Reglas del Dominio Advertidas

- Cada vuelo tiene un tiempo límite de despacho (2 horas antes de la salida).
- Un pasajero puede registrar múltiples bultos en una sola operación.
- El número de boleto debe validarse antes de proceder con el registro.
- El sistema debe garantizar la unicidad del código QR por bulto.

---

## Requisitos Funcionales en Alto Nivel

**RF1: Autenticación y Validación de Usuarios**
El sistema debe permitir el inicio de sesión de los despachantes y supervisores, validando sus credenciales de acceso mediante la consulta externa al sistema AirExploiter de recursos humanos de la compañía.

**RF2: Verificación de Vuelos y Pasajeros**
El sistema debe permitir al despachante ingresar el número de ticket del pasajero para verificar si el vuelo asociado está programado dentro de las próximas dos horas (consultando al sistema Gallius) y desplegar la información del pasajero y su ubicación (consultando al sistema APSale).

**RF3: Registro y Pesaje de Bultos**
El sistema debe registrar de forma iterativa cada bulto del pasajero, capturando el peso desde la balanza electrónica integrada y permitiendo al usuario asignar la categoría correspondiente (normal, frágil, refrigerado, etc.) según el listado vigente.

**RF4: Generación e Impresión de Etiquetas QR**
El sistema debe generar un código QR único para cada bulto que contenga todos los datos de su despacho, y enviar la orden de impresión para que la etiqueta sea adherida al equipaje.

**RF5: Emisión y Envío Digital de Comprobante de Despacho**
Una vez finalizado el registro de la totalidad de los bultos de un pasajero, el sistema debe generar de forma automática un comprobante en formato PDF y enviarlo por correo electrónico a la cuenta declarada por el pasajero.

**RF6: Restricción de Despacho por Ventana Horaria**
El sistema debe validar de forma automática que la partida del vuelo asociado al ticket esté proyectada estrictamente dentro del lapso máximo de las próximas dos horas para habilitar la operatoria de despacho.

**RF7: Actualización de Categorías de Bultos (Exclusivo Supervisor)**
El sistema debe permitir al rol de Supervisor solicitar de forma exclusiva la consulta y actualización del listado de categorías de bultos, conectándose con el sistema Cóndor de la Agencia Nacional de Aviación Civil (ANAC).

**RF8: Sincronización Periódica con el Sistema Cóndor**
El sistema debe consultar periódicamente al sistema Cóndor de la ANAC para mantener actualizado el listado de categorías de bultos habilitadas para el aeropuerto de la jurisdicción correspondiente.

**RF9: Control de Permisos por Perfil de Usuario (Supervisor vs. Despachante)**
El sistema debe otorgar al rol de Supervisor el acceso a la totalidad de las funcionalidades del despachante, restringiendo a su vez la función de actualización del listado de categorías para que no pueda ser ejecutada por un despachante común.

**RF10: Generación de Reportes Gerenciales de Esfuerzo**
El sistema debe contar con un módulo capaz de generar reportes gerenciales con una periodicidad quincenal, los cuales deben calcular y mostrar el esfuerzo invertido en los nuevos desarrollos de software de la organización.

---

## Requisitos Funcionales en Bajo Nivel

**RF1:** El sistema SDBAP deberá permitir el ingreso de las credenciales de acceso (Usuario/Legajo y Contraseña) por parte del operador desde la interfaz de inicio de sesión, para luego cifrar la contraseña introducida y emitir una consulta externa en formato JSON v2.7.2 al sistema AirExploiter de recursos humanos con el fin de validar la autenticidad de los datos; ante una respuesta exitosa, identificará el rol asignado (Despachante o Supervisor) e iniciará la sesión registrando la fecha, hora y terminal correspondiente, bloqueando el acceso y mostrando un mensaje de error si las credenciales son inválidas o si no se recibe respuesta del sistema externo.

**RF2:** El sistema SDBAP deberá permitir al despachante el ingreso manual o mediante lector del número de ticket del pasajero para iniciar el proceso de despacho, enviando de forma automática una petición en formato JSON al sistema Gallius de operaciones para verificar el estado y horario del vuelo asociado, realizando en simultáneo una consulta al sistema de gestión de ventas APSale para requerir la información de la identidad del pasajero junto con su ubicación adquirida en la aeronave, y desplegando en la pantalla de la terminal los datos consolidados del pasajero y su asiento en un tiempo de respuesta total que no exceda los 4 segundos de demora.

**RF3:** El sistema SDBAP deberá habilitar un flujo interactivo cíclico que se repita de forma consecutiva tantas veces como bultos declare transportar el pasajero, capturando de forma automatizada el peso del equipaje mediante una lectura directa de la balanza electrónica integrada en el mostrador sin permitir la carga manual por parte del operador, y desplegando un menú de selección para que el despachante asigne la categoría correspondiente al bulto (normal, frágil, refrigerado, etc.) basándose en las opciones vigentes cargadas en la base de datos.

**RF4:** El sistema SDBAP deberá procesar la información de cada bulto registrado (peso, categoría, datos del pasajero y del vuelo) y codificarla en una cadena de texto única, transformando dicha cadena en un gráfico de código QR de identificación única antes de habilitar su paso manual a la cinta transportadora, y enviando la orden de impresión de forma inmediata a la ticketera del mostrador para generar la etiqueta física autoadhesiva que se adherirá al equipaje.

**RF5:** El sistema SDBAP deberá consolidar la información técnica de la totalidad de los bultos registrados una vez que el despachante confirme el cierre de la transacción, compilar y generar de manera automatizada un documento digital inmutable en formato de documento portátil (PDF) que funcione como comprobante del despacho, recuperar la dirección de correo electrónico que el pasajero declaró al momento de la compra del boleto en el sistema APSale, y remitir de forma automática el archivo PDF generado como adjunto a dicha cuenta de correo electrónico.

**RF6:** El sistema SDBAP deberá calcular de forma automática la diferencia de tiempo entre la hora actual de la terminal del mostrador y el horario programado de partida del vuelo obtenido desde el sistema Gallius, validando que la partida proyectada de la aeronave se encuentre estrictamente dentro del lapso máximo de las próximas dos horas respecto al momento del registro, y denegando la operación de despacho mediante el bloqueo de los campos de carga y mostrando una alerta en pantalla si el tiempo faltante para el despegue del vuelo es superior a las dos horas.

**RF7:** El sistema SDBAP deberá validar que la sesión activa corresponda al rol de Supervisor al momento de recibir una solicitud de actualización manual de categorías de bultos, estableciendo una conexión externa mediante el estándar JSON v2.7.2 con el sistema Cóndor de la Agencia Nacional de Aviación Civil (ANAC) ante la petición de dicho perfil, para descargar e incorporar a la base de datos local el listado actualizado de categorías de bultos habilitadas por la autoridad para el aeropuerto específico de su jurisdicción.

**RF8:** El sistema SDBAP deberá ejecutar de manera automatizada un proceso en segundo plano con una periodicidad preconfigurada para realizar consultas de sincronización de datos de forma transparente, conectándose mediante el estándar JSON con el sistema Cóndor de la ANAC para verificar si existen modificaciones en los catálogos oficiales de equipaje, y actualizando la tabla local de categorías de bultos de la base de datos de manera automatizada sin interrumpir las operaciones de las terminales activas en los mostradores.

**RF9:** El sistema SDBAP deberá verificar de forma dinámica la matriz de permisos asociados al usuario que se ha autenticado en la terminal de despacho, habilitando la totalidad de las funciones operativas de despacho tanto para el rol de Despachante como para el rol de Supervisor, pero restringiendo el acceso a la funcionalidad de actualización de categorías de bultos con el sistema Cóndor, ocultando o deshabilitando el control en la interfaz si el usuario logueado posee estrictamente el rol de Despachante.

**RF10:** El sistema SDBAP deberá proveer un módulo de reportería accesible para los roles de gestión de la compañía que recopile y procese la información sobre las horas y el esfuerzo invertido en los nuevos desarrollos informáticos registrados en la plataforma, estructurando y emitiendo reportes gerenciales detallados con una periodicidad estrictamente quincenal para dar cumplimiento a los manuales de procedimientos internos y estándares de calidad de la organización.

---

## Requisitos No Funcionales (RNF) — Ontología Sommerville

### Requisitos del Producto — Eficiencia / Rendimiento

**RNF1:** EL SISTEMA SDBAP AL MOMENTO DE DESPLEGAR LA INFORMACIÓN DEL PASAJERO Y SU UBICACIÓN ADQUIRIDA (RF2) DEBERÁ completar todo este proceso con un tiempo de respuesta que no exceda los 4 segundos de demora total.

### Requisitos del Producto — Confiabilidad

**RNF2:** EL SISTEMA SDBAP AL MOMENTO DE EMITIR EL COMPROBANTE DE DESPACHO EN FORMATO PDF (RF5) DEBERÁ garantizar que dicho archivo sea un documento digital inmutable.

### Requisitos de la Organización — Operacionales

**RNF3:** EL SISTEMA SDBAP AL MOMENTO DE REGISTRAR Y PESAR LOS BULTOS (RF3) DEBERÁ realizar la captura de peso de forma automatizada mediante la lectura directa de la balanza electrónica integrada, debido a que la ART de la aerolínea no autoriza que el despachante lo haga manualmente.

### Requisitos de la Organización — Desarrollo

**RNF4:** EL SISTEMA SDBAP DEBE haber sido diseñado utilizando explícitamente a Visual Paradigm como herramienta CASE para su procedimiento de desarrollo de software.

**RNF5:** EL SISTEMA SDBAP AL MOMENTO DE GESTIONAR LAS PRUEBAS DE SOFTWARE DEBERÁ ser ejecutado por medio de la utilización de Selenium y Ruby como herramienta y lenguaje de scripting para la automatización de las pruebas mencionadas.

### Requisitos Externos — Regulatorios

**RNF6:** EL SISTEMA SDBAP DEBE cumplir en todos sus intercambios de información entre sistemas con las especificaciones del estándar JSON (ISO/IEC 21778:2017) en su versión 2.7.2, conforme a lo establecido por la ICAO (International Civil Aviation Organization).

**RNF7:** EL SISTEMA SDBAP AL MOMENTO DE ASIGNAR LAS CATEGORÍAS DE LOS BULTOS (RF3, RF7, RF8) DEBERÁ restringirse a los listados vigentes que periódicamente habilita la Agencia Nacional de Aviación Civil (ANAC) para cada uno de los aeropuertos de su jurisdicción.

### Requisitos Externos — Legales

**RNF8:** EL SISTEMA SDBAP DEBE cumplir con las disposiciones del Código Aeronáutico de la República Argentina (Ley 17.285, Título VI: "Aeronáutica Comercial", Capítulo II "Servicios de Transporte Aéreo Interno", Sección C "Transporte de Equipajes" — Artículos 116 a 118).

**RNF9:** EL SISTEMA SDBAP DEBE cumplir estrictamente con las normas IATA sobre equipaje de pasajeros, específicamente con la IATA Resolution 753 "Baggage Tracking - Implementation Guide".

### Requisitos Externos — Legales / Contables

**RNF10:** EL SISTEMA SDBAP AL MOMENTO DE GENERAR LOS REPORTES GERENCIALES QUINCENALES (RF10) DEBERÁ calcular y mostrar cuantitativamente el esfuerzo invertido en los nuevos desarrollos para dar cumplimiento a los manuales de procedimientos y los estándares ISO 9000 de la empresa.

---

## Historias de Usuario

### HU1 — Registro de despacho de bultos

**Como** despachante de la aerolínea, **quiero** registrar los bultos de un pasajero en el sistema, **para** asegurar su transporte correcto en la bodega del avión y emitir el comprobante correspondiente.

**Criterios de Aceptación:**

1. El sistema debe permitir el inicio del proceso solo si el vuelo asociado al ticket tiene una partida proyectada dentro de las próximas dos horas.
2. El sistema debe verificar la validez del vuelo consultando al sistema Gallius y obtener los datos del pasajero y su ubicación desde el sistema APSale en un tiempo máximo de 4 segundos.
3. Por cada bulto, el sistema debe registrar el peso obtenido de la balanza electrónica integrada e imprimir una etiqueta con un código QR único que contenga todos los datos del despacho.
4. Al finalizar el registro de todos los bultos, el sistema debe enviar automáticamente un archivo PDF con el comprobante a la cuenta de correo electrónico del pasajero.

---

### HU2 — Actualización de categorías de bultos

**Como** supervisor del sector de despacho, **quiero** ejecutar la actualización del listado de categorías de bultos desde el sistema Cóndor, **para** garantizar que los despachos cumplan con las regulaciones vigentes de la ANAC.

**Criterios de Aceptación:**

1. La funcionalidad de actualización debe ser de acceso exclusivo para el rol de Supervisor.
2. El sistema debe conectarse al sistema Cóndor de la ANAC para obtener las categorías habilitadas para el aeropuerto de jurisdicción actual.
3. El intercambio de información entre el SDBAP y el sistema Cóndor debe realizarse estrictamente bajo el estándar JSON versión 2.7.2.
4. Las categorías descargadas deben estar disponibles inmediatamente para que los despachantes puedan asignarlas a los bultos durante el pesaje (Normal, Frágil, Refrigerado, etc.).

---

### HU3 — Gestión de inicio de sesión y seguridad

**Como** personal de la compañía (despachante o supervisor), **quiero** iniciar sesión en la terminal de despacho con mis credenciales, **para** acceder a las funcionalidades del sistema según mi perfil y registrar mi turno laboral.

**Criterios de Aceptación:**

1. El sistema debe solicitar credenciales (usuario y contraseña) al comienzo de cada turno laboral.
2. La validación de las credenciales debe realizarse mediante una consulta externa al sistema AirExploiter de recursos humanos.
3. La comunicación con AirExploiter para la validación de usuarios debe seguir las especificaciones del estándar JSON (ISO/IEC 21778:2017).
4. Una vez validado, el sistema debe habilitar el menú de opciones correspondiente al rol del usuario (el despachante solo ve operaciones de bultos; el supervisor incluye actualización de categorías).
