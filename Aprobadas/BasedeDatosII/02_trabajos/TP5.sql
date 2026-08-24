--1. Crear una función que permita calcular de un número su factorial. Tener en cuenta que el 
--   número debe ser entero y positivo. Gestionar los errores

create or replace function factorial (p_numero in number)
return NUMBER is 
v_factorial number;
v_cont := p_numero;
begin
while v_cont != 0 Loop




end loop;



end;
/











--2. Crear un bloque anónimo que mediante una variable numérica muestre su tabla de 
--   multiplicar. En caso de que se ingrese una letra indicar el error mediante una leyenda. 