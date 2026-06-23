Desarrollar todas las consignas pedidas y con cada una de las sentencias que responden a ellas armar un archivo que lleve el siguiente formato BII_Apellido_Legajo.sql, por ejemplo BII_TN_GARCIA_12345.sql

Una clínica veterinaria necesita automatizar el control de sus operaciones diarias mediante un paquete PL/SQL (PKG_VETERINARIA) que centralice la lógica de negocio sobre su base de datos. La base ya cuenta con las tablas CLIENTE, MASCOTA, VETERINARIO, ESPECIALIDAD, CONSULTA, VACUNA, VACUNA_APLICADA, PRODUCTO y DETALLE_CONSULTA, las tablas que encontrará en el script adjunto. 

Se le solicita el desarrollo de un paquete que cubra dos de las cuatro áreas funcionales: gestión de consultas y gestión de stock de productos.

Consideraciones

El paquete debe definir excepciones propias para los escenarios de error más relevantes (mascota inexistente, veterinario inactivo o inexistente, consulta en estado inválido para la operación solicitada, stock insuficiente, vacuna inexistente),

Nota: todas las consignas deben llevar los bloques anónimos de prueba.


Requerimientos

1. Gestión de consultas

Implementar una función que registre el alta de una nueva consulta (turno) para una mascota con un veterinario determinado, dejándola en estado PENDIENTE. Deberá devolver el identificador de la consulta generada.