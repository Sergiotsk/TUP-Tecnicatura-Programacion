--1)Desarrollar un bloque que dado un valor numérico indique si el mismo es positivo.
/*
DECLARE
    num1 number(3):= 8;
begin
    if num1>0 then
      DBMS_OUTPUT.PUT_LINE('El numero es positivo');
    else
      DBMS_OUTPUT.PUT_LINE('El numero es negativo');
    end if;    
end;    
/


--2)Desarrollar un bloque que dado un valor numérico indique si el mismo es positivo, negativo o cero.

DECLARE
    num1 number (3):=0;
begin
    if num1<0 then
      DBMS_OUTPUT.PUT_LINE('El numero es NEGATIVO');
    elsif num1=0 then
      DBMS_OUTPUT.PUT_LINE('El numero es CERO');
    else
      DBMS_OUTPUT.PUT_LINE('El numero es POSITIVO');
    end if;
end;  
/     

      
--3)Escribir un programa que declare un número entero y muestre por pantalla si es par o impar.

DECLARE
    num1 number(3):= 166;
begin
    if MOD(num1,2)=0 then
        DBMS_OUTPUT.PUT_LINE('Es PAR');+         
    else
        DBMS_OUTPUT.PUT_LINE('ES IMPAR');  
    end if;
end;
/


--4)Escribir un bloque que declare un número entero y muestre por pantalla si es múltiplo de 3 o no.


DECLARE
    num1 number(3):= 10;
begin
    if MOD(num1,3)=0 then
        DBMS_OUTPUT.PUT_LINE('ES MULTIPLO DE 3');        
    else
        DBMS_OUTPUT.PUT_LINE('NO ES MULTIPLO DE 3');  
    end if;
end;
/


--5) Escribir un bloque que declare un número entero y muestre por pantalla si es múltiplo de 3; caso contrario, mostrar el número múltiplo de tres anterior al dado.

DECLARE
    l_num1 number(5):= 25446;
    l_anterior number(5);
begin
    if MOD(l_num1,3)=0 then
        DBMS_OUTPUT.PUT_LINE('ES MULTIPLO DE 3');        
    else
       l_anterior:=l_num1-1;

         WHILE MOD(l_anterior,3)!=0 LOOP
            l_anterior := l_anterior - 1;                       
         END LOOP;

        DBMS_OUTPUT.put_line('Multiplo anterior: '||l_anterior);
    end if;
    
end;
/

--6)Realizar un bloque anónimo que declare dos variables numéricas cuyo valor inicial sea cero, se le asigne su valor en el procedimiento y muestre el resultado de la suma.

DECLARE
    num1 number(3):=0;
    num2 number(3):=0;
begin
    num1:=45;
    num2:=565;
    DBMS_OUTPUT.PUT_LINE(num1+num2);
end;
/

*/

--7) Realizar un bloque anónimo que declare dos variables numéricas con sus valores iniciales en la declaración. 
--En la sección ejecutable se deberán comparar las variables indicando si la primera es mayor, menor o igual a la segunda mediante una leyenda adecuada.

DECLARE
    num1 number(3):= 5;
    num2 number(3):= 8;
begin
    if num1>num2 then
      DBMS_OUTPUT.put_line('El primer numero es MAYOR');
    elsif num1 then
        
    end if;
end;