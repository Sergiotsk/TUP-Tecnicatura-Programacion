/*--1)Definir la salida por consola de los bloques anónimos de la sesión.

    SET SERVEROUTPUT ON;

--2)Realizar un bloque anónimo que salude a todos.

BEGIN

    DBMS_OUTPUT.PUT_LINE('Hola a todos');

END;
/

--3)Realizar un bloque anónimo que ingrese dos números y muestre su suma.

    DECLARE
        numero1 NUMBER := 10;
        numero2 NUMBER := 20;
        suma NUMBER;
    BEGIN
        suma := numero1 + numero2;
        DBMS_OUTPUT.PUT_LINE('La suma de ' || numero1 || ' y ' || numero2 || ' es ' || suma);
    END;
    /
--4)Realizar el bloque anónimo anterior con la leyenda adecuada utilizando la conversión a caracteres de la operación.

DECLARE
    numero1 NUMBER := 10;
    numero2 NUMBER := 20;
    suma NUMBER;
begin
    SUMA := numero1 + numero2;
    DBMS_OUTPUT.PUT_LINE('La suma de '|| to_char(numero1)||' y '||to_char(numero2)||' es '|| to_char(suma));
end;    
/
--5)Mediante la declaración de una variable numérica a la que se le asignará el resultado de la operación, mostrar el contenido de la variable junto a la leyenda correspondiente.
--ya lo hice en el punto 4.

--6)Declarar en un bloque anónimo dos variables y controlar cómo y cuándo se realiza la conversión implícita de variables en la salida por consola.

DECLARE
    num1 NUMBER:=100;
    texto2 VARCHAR2(10):= '20';
begin
  DBMS_OUTPUT.PUT_LINE('En esta suma: '|| (num1 + texto2));
end;    
/

--7)Declarar, en un bloque anónimo, dos variables numéricas de tres dígitos y una variable numérica de cuatro; 
--  asignarle el resultado de la suma de dichas variables del mismo tipo a la variable de mayor tamaño. Mostrar por consola el resultado.

DECLARE
    num1 NUMBER(3) := 100;
    num2 NUMBER(3) := 200;
    resultado NUMBER(4);
begin
    resultado := num1 + num2;
    DBMS_OUTPUT.PUT_LINE('La suma de '|| to_char(num1)||' y '||to_char(num2)||' es '|| to_char(resultado));
end;    
/
--8)Declarar una constante en un bloque anónimo y mostrar su contenido por consola con una leyenda adecuada.
--  Comprobar qué pasa si a una constante se le cambia el contenido en la sección ejecutable.

DECLARE
    mensaje constant VARCHAR2(50):= 'Esto es una constante';
begin
  DBMS_OUTPUT.PUT_LINE(mensaje);
  mensaje:='Cambio el valor de la constante';
  DBMS_OUTPUT.PUT_LINE(mensaje);
end;

*/  
--9)Desarrollar un bloque anónimo que tenga declarada una variable numérica y comprobar si ese valor es mayor a 18.

DECLARE
    num1 number(2):=5;
begin
  
end;    