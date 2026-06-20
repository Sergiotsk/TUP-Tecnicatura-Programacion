SET SERVEROUTPUT ON;
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



--7) Realizar un bloque anónimo que declare dos variables numéricas con sus valores iniciales en la declaración. 
--En la sección ejecutable se deberán comparar las variables indicando si la primera es mayor, menor o igual a la segunda mediante una leyenda adecuada.

DECLARE
    numero1 number(3):= &5;
    numero2 number(3):= &8;
begin
    if numero1>numero2 then
      DBMS_OUTPUT.put_line('El primer numero es MAYOR');
    elsif num1=numero2 then
      DBMS_OUTPUT.put_line('El primer numero es igual al segundo');
    else
      DBMS_OUTPUT.put_line('El primer numero es MENOR');
              
    end if;
end;
/



--8)Crear un bloque PL que, dado un nombre y un apellido, devuelva las iniciales de la persona.

DECLARE 
    nombre varchar(50):= 'Sergio';
    apellido varchar(60):='Tschernitschek';
begin
     DBMS_OUTPUT.PUT_LINE('Primer letra de nombre: '||substr(nombre,1,1));
     DBMS_OUTPUT.PUT_LINE('Primer letra del apellido: '||substr(apellido,1,2));
end;    
/



--9)Escribir un bloque con dos variables numéricas que muestre la división del mayor con el menor de los valores. 
--Si el divisor es cero, el programa debe mostrar un error.

DECLARE
    num1 number(3):= &NUMERO1;
    num2 number(3):= &NUMERO2;
begin
    if num2 = 0 then
        DBMS_OUTPUT.PUT_LINE('Error, no se puede dividir por 0');
    elsif num1>=num2 then
        DBMS_OUTPUT.PUT_LINE('Resultado: '||(num1/num2));  
    elsif num1 = 0 then
        DBMS_OUTPUT.PUT_LINE('Error, no se puede dividir por 0');
    elsif num2>=num1 then
        DBMS_OUTPUT.PUT_LINE('Resultado: '||(num2/num1));              
    end if;
end;    
/


--10)Para tributar un determinado impuesto se debe ser mayor de 18 años y tener ingresos iguales o superiores a $800.000 mensuales.
-- Escribir un bloque que controle edad e ingresos mensuales y muestre por pantalla si se tiene que tributar impuestos o no.

DECLARE
    l_edad number(3):= &edad;
    l_ingresos number (7):= &sueldo;
begin
    case 
      when l_edad>=18 and l_ingresos>=800000 then 
        DBMS_OUTPUT.PUT_LINE('Tenes que pagar impuestos');
      else 
        DBMS_OUTPUT.PUT_LINE('No tenes que pagar impuestos');
    end case;
end;
/



--11)Crear un bloque PL/SQL que muestre un comentario acorde a la nota que ha sacado un alumno:
-- `10` Sobresaliente, `9` Excelente, `8` Muy Bueno, `7` Bueno, `6` Aprobado, debajo de `6` Reprobado. *(Resolverlo con `CASE`.)

DECLARE
    l_nota number(2) := &NOTA;
begin
    case 
      when l_nota = 10 then
      DBMS_OUTPUT.PUT_LINE('SOBRESALIENTE');
      when l_nota = 9 then        
      DBMS_OUTPUT.PUT_LINE('EXCELENTE');
      when l_nota = 8 then       
      DBMS_OUTPUT.PUT_LINE('MUY BUENO');
      when l_nota =7 then 
      DBMS_OUTPUT.PUT_LINE('BUENO');
      when l_nota =6 then 
      DBMS_OUTPUT.PUT_LINE('Aprobado');
      else
      DBMS_OUTPUT.PUT_LINE('REPROBADO'); 
    end case;
end;    
/



--12)Escribir los 10 primeros números pares de menor a mayor.


begin
     for i in 1..10 loop
       DBMS_OUTPUT.PUT_LINE('Numero par '|| i || ': '||i*2);
     end loop;   
end;               
/



--13)Escribir los 10 primeros números impares de mayor a menor.
begin
     for i in reverse 1..10 loop
       DBMS_OUTPUT.PUT_LINE('Numero par '|| i || ': '||i*2);
     end loop;   
end;               



--14)Escribir un procedimiento que muestre la tabla de multiplicar deseada (del 1 al 12). 
--Crear el bloque anónimo para probarlo.

CREATE OR REPLACE PROCEDURE multiplicar(p_numero IN NUMBER(3)) AS
 begin
    for i in 1..12 loop
      DBMS_OUTPUT.PUT_LINE(p_numero || ' X ' || i || (p_numero*i));
    end loop;
 end multiplicar;
 /

 --bloque de prueba

 begin
   multiplicar(&numero);
 end;
 /



--15)Armar un bloque que escriba en pantalla la cadena:
-- `'BASE DE DATOS II'` de atrás para adelante (`'II SOTAD ED ESAB'`).

DECLARE
    v_string VARCHAR2(50) := 'BASE DE DATOS II';
    v_string_reves VARCHAR2(50);
begin
   select reverse(v_string) into v_string_reves from dual; 
   DBMS_OUTPUT.PUT_LINE(v_string_reves);
end;    
/
 


--16)Armar un procedimiento que escriba los 10 primeros números pares ya sea de menor a mayor (ascendente) o de mayor a menor (descendente). 
--   Crear el bloque anónimo para probarlo.

CREATE or REPLACE PROCEDURE p_numeros(l_orden VARCHAR2) AS

begin
   if l_orden = 'a' then
    for i in 1..10 loop
    DBMS_OUTPUT.PUT_LINE('Par N°'||i||' :'||i*2);
  end loop;
    elsif l_orden ='d' then
       for i in REVERSE 1..10 loop
     DBMS_OUTPUT.PUT_LINE('Par N°'||i||' :'||i*2);
  end loop;
    else 
    DBMS_OUTPUT.PUT_LINE('Orden incorrecto use a(ascendente o d (desendente))');
    
  end if;
  
end;
/

--prueba

begin
  p_numeros('d');
end;
/ 


--17)Crear una función PL/SQL que:
-- al ingresar una fecha, devuelva cuál es el trimestre del año al cual pertenece.
-- Crear el bloque anónimo para probarla.

CREATE or REPLACE function num_trimestre(p_fecha date) 
RETURN number AS
    l_trimestre number;
    l_mes number;
begin
    l_mes:=extract(month from p_fecha);
case 
  when l_mes < 4 then
    l_trimestre:=1;    
  when l_mes < 7 then 
    l_trimestre:=2;
  when l_mes < 10 then 
    l_trimestre:=3;  
  else 
    l_trimestre:=4; 
end case;

return l_trimestre;  
end num_trimestre;
/
DECLARE
 V_FECHA date;
begin
 V_FECHA := TO_DATE(10-10-2024, dd-mm-yyyy);
 DBMS_OUTPUT.PUT_LINE('La fecha corresponde al trimestre: '||num_trimestre(V_FECHA));
end;
/



--18)Crear una función que, dada una frase, indique cuántas palabras la forman.
-- Considerar que las palabras se separan por espacio; no considerar los espacios finales de la frase dada.

CREATE or REPLACE function n_palabras(l_frase VARCHAR2)
RETURN number AS
    l_space number(3);
    l_word number(3);
begin
    l_space:= length(trim(l_frase))-length(REPLACE(trim(l_frase),' ',''));
    l_word:=l_space+1;
RETURN l_word;
end n_palabras;    
/

DECLARE
    v_frase VARCHAR2(100):='&Ingrese_frase';
begin
    DBMS_OUTPUT.PUT_LINE(v_frase);
    DBMS_OUTPUT.PUT_LINE('La frase tiene '||n_palabras(v_frase)||' palabras.');    
end;
/



--19)Armar un bloque que, al pedir una palabra, le dé vuelta solo si es una palabra. En caso de que sea una frase 
----(contenga uno o más espacios, pero no al final), indicar que no se cumple con la consigna.

DECLARE
  v_palabras VARCHAR2(100):='&Ingrese_su_palabra_o_frase';
  l_space number(3);
  l_words number(3);
  v_string_reves varchar2(100);
begin
   l_space:= length(trim(v_palabras))-length(REPLACE(trim(v_palabras),' ',''));
   l_words:=l_space+1;   
   case 
     when l_space = 0 then
      DBMS_OUTPUT.PUT_LINE('palabra: '||v_palabras);
      select reverse(v_palabras) into v_string_reves from dual; 
      DBMS_OUTPUT.PUT_LINE('Palabra al reves: '||v_string_reves);
     else 
      DBMS_OUTPUT.PUT_LINE('Error debe ingresar solo una palabra');
   end case;
end;  
/

*/

--20)Armar una función que, dada la fecha de nacimiento de una persona, indique cuál es su edad.
---- Crear el bloque anónimo para probarla.

CREATE OR REPLACE FUNCTION calc_edad(p_fnacimiento date)
RETURN number AS
  l_edad number(3);
  l_meses number(4);
begin
  l_meses:=months_between(current_date,p_fnacimiento);
  l_edad:=trunc(l_meses/12);
  
  RETURN l_edad;
  end calc_edad;  
 / 

DECLARE
  v_edad number (3);
  v_fnacimiento date := TO_DATE('&Calcular_edad','DD-MM-YYYY');
begin
  v_edad:= calc_edad(v_fnacimiento);
  DBMS_OUTPUT.PUT_LINE('Su edad es de: '|| v_edad ||' años');

end;
/

-- =============================================================================
-- REFERENCIA: FUNCIONES BUILT-IN USADAS EN ESTE TP
-- =============================================================================

/*
------------------------------------------------------------------------
NUMÉRICAS
------------------------------------------------------------------------
MOD(numero, divisor)
  Devuelve el resto de la división.
  MOD(10, 3) → 1

TRUNC(numero)
  Elimina los decimales sin redondear.
  TRUNC(3.9) → 3

------------------------------------------------------------------------
DE STRING
------------------------------------------------------------------------
SUBSTR(string, posicion_inicio, longitud)
  Extrae una porción del string. La posición empieza en 1.
  SUBSTR('HOLA MUNDO', 1, 4) → 'HOLA'

LENGTH(string)
  Devuelve la cantidad de caracteres.
  LENGTH('HOLA') → 4

REPLACE(string, buscar, reemplazar)
  Reemplaza todas las ocurrencias de un substring.
  REPLACE('HOLA MUNDO', ' ', '') → 'HOLAMUNDO'

TRIM(string)
  Elimina espacios al inicio y al final.
  TRIM('  HOLA  ') → 'HOLA'

LTRIM(string)
  Elimina espacios solo al inicio (Left).
  LTRIM('  HOLA  ') → 'HOLA  '

RTRIM(string)
  Elimina espacios solo al final (Right).
  RTRIM('  HOLA  ') → '  HOLA'

REVERSE(string)
  Invierte el string.
  REVERSE('HOLA') → 'ALOH'

UPPER(string)
  Convierte a mayúsculas.
  UPPER('hola') → 'HOLA'

LOWER(string)
  Convierte a minúsculas.
  LOWER('HOLA') → 'hola'

INITCAP(string)
  Primera letra de cada palabra en mayúscula.
  INITCAP('hola mundo') → 'Hola Mundo'

LPAD(string, longitud, caracter_relleno)
  Rellena por la izquierda hasta alcanzar la longitud indicada.
  LPAD('42', 5, '0') → '00042'

RPAD(string, longitud, caracter_relleno)
  Rellena por la derecha.
  RPAD('HOLA', 8, '.') → 'HOLA....'

INSTR(string, substring)
  Devuelve la posición donde aparece el substring. 0 si no existe.
  INSTR('HOLA MUNDO', 'MUNDO') → 6

CONCAT(string1, string2)
  Une dos strings. Equivalente al operador ||.
  CONCAT('HOLA', ' MUNDO') → 'HOLA MUNDO'

------------------------------------------------------------------------
DE FECHA
------------------------------------------------------------------------
SYSDATE
  Fecha y hora actual del servidor (no es función, es pseudocolumna).

CURRENT_DATE
  Fecha actual en la zona horaria de la sesión.

EXTRACT(parte FROM fecha)
  Extrae año, mes o día de una fecha.
  EXTRACT(MONTH FROM SYSDATE) → 5
  EXTRACT(YEAR FROM SYSDATE)  → 2026
  EXTRACT(DAY FROM SYSDATE)   → 9

MONTHS_BETWEEN(fecha1, fecha2)
  Devuelve la diferencia en meses entre dos fechas (fecha1 - fecha2).
  MONTHS_BETWEEN(SYSDATE, TO_DATE('2000-01-01','YYYY-MM-DD')) → ~315

TO_DATE(string, formato)
  Convierte un string a tipo DATE.
  TO_DATE('15/05/2026', 'DD/MM/YYYY')

ADD_MONTHS(fecha, n)
  Suma n meses a una fecha.
  ADD_MONTHS(SYSDATE, 3) → fecha dentro de 3 meses

LAST_DAY(fecha)
  Devuelve el último día del mes de la fecha dada.
  LAST_DAY(SYSDATE) → 31/05/2026

NEXT_DAY(fecha, dia_semana)
  Devuelve la fecha del próximo día de la semana indicado.
  NEXT_DAY(SYSDATE, 'MONDAY')

TO_CHAR(fecha, formato)
  Convierte una fecha a string con el formato dado.
  TO_CHAR(SYSDATE, 'DD/MM/YYYY') → '09/05/2026'
  TO_CHAR(SYSDATE, 'DAY')        → 'SATURDAY'
*/