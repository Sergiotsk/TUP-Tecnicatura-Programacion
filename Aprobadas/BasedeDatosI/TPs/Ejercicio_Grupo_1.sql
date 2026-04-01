/*1. Realizar un listado que muestre por cada detective cuántos son los
crímenes que investigan en los que aún no tiene ningún sospechoso.*/

select 
    d.apellido || ',' || d.nombre as DETECTIVE,
    count(c.detective) AS CRIMENES_SIN_SOSPECHOSO
    from  detectives d
    left join crimenes c on c.detective = d.id
    left join sospechosos_crimen s on s.crimen = c.id
    where s.crimen is null
    group by 
        d.apellido,d.nombre;
        
/*
2. Se han cargado mal las fechas de egreso de todos los criminales que han
salido de la prisión, en una semana menos de la fecha debida. Ten en
cuenta que deberás realizar dicha modificación, pero sólo de los presos
que han salido de prisión.
*/

update criminales_prision    
set fecha_egreso= fecha_egreso-7
where fecha_egreso is not null;
commit;

/*3. Eliminar los registros de aquellos criminales que no han cometido delito
alguno ni son sospechosos de ningún crimen.
*/

delete
from criminales c
where NOT EXISTS (
    SELECT 1
    FROM criminales_prision cp
    WHERE cp.criminal = c.id -- Comprueba si el criminal existe en la tabla de prisión
)and
NOT EXISTS (
    SELECT 1
    FROM sospechosos_crimen s
    WHERE s.sospechoso = c.id -- Comprueba si el criminal existe en la tabla de prisión
);ROLLBACK;
commit;
/*4. Armar un listado de los criminales que no se encuentran en prisión que
tengan tatuaje, sean altos, sexo masculino y rubios.
*/

select 
     c.nombre as criminal 
     from criminales c
     where c.tatuajes='S'and c.altura='alto' and c.sexo='Masculino' and c.color_pelo='Rubio'
    and NOT EXISTS (
    SELECT 1
    FROM criminales_prision cp
    WHERE cp.criminal = c.id -- Comprueba si el criminal existe en la tabla de prisión
);

/*5. Realizar un listado de los sospechosos a crímenes que se han cometido
indicando el nombre del criminal, el nombre y apellido del damnificado, el
crimen cometido y el nombre del detective a cargo de la investigación.
*/
select 
    c.nombre as nom_criminal,
    cs.d_nombre || ',' || cs.d_apellido  as damnificado,
    cs.tipo_crimen as crimen_cometido,
    d.apellido || '.' || d.nombre as detective_a_cargo
    from sospechosos_crimen s
    join criminales c on c.id = s.sospechoso
    join crimenes cs on  cs.id = s.crimen
    join detectives d on d.id = cs.detective
    order by 
        s.sospechoso;
    

/*6. Realizar un listado de criminales que están presos en los que se mostrará
su nombre, sexo, características físicas, años que llevan preso y una
leyenda en función de ese tiempo:
• Si lleva menos de 5 años corresponde que diga 'Sin categorización'.
• Si lleva entre 5 y 15 años 'Peligrosidad considerable'
• Si lleva más de más de 15 años corresponde que diga 'Muy peligroso'.
*/

select 
    c.nombre as NOMBRE,
    c.sexo as SEXO,
    c.color_pelo as COLOR_PELO,
    c.color_ojos as COLOR_OJOS,
    c.tatuajes as TATUAJES,
    c.anteojos as ANTEOJOS,
    c.cicatrices as CICATRICES,
    c.barba as BARBA,
    c.calzado as CALZADO,
    trunc((sysdate-FECHA_INGRESO)/365) as AÑOS_EN_PRISION,
     case
        when trunc((sysdate-FECHA_INGRESO)/365) < 5 then 'Sin categorizacion'
        when trunc((sysdate-FECHA_INGRESO)/365) >5 and trunc((sysdate-FECHA_INGRESO)/365) <15  then 'Peligrosidad Considerable'
        when trunc((sysdate-FECHA_INGRESO)/365) >15  then 'Muy Preligroso'
        end
    FROM criminales c
    join criminales_prision cp on cp.criminal = c.id
    order by
    c.nombre;       


/*7. Confeccionar una vista que permita tener un informe de los criminales que
no se encuentran en prisión y son sospechosos de más de un delito.*/

 CREATE OR REPLACE VIEW informe_sospechosos
 AS SELECT c.nombre,c.id
 FROM criminales c
 JOIN sospechosos_crimen s ON s.sospechoso = c.id
 where NOT EXISTS (
    SELECT 1
    FROM criminales_prision cp
    WHERE cp.criminal = c.id 
)
group by 
    c.nombre,c.id
having 
    count(s.crimen) > 1;

select * from informe_sospechosos;






