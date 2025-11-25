# PREGUNTAS CONCEPTUALES Y EJERCICIOS AVANZADOS
## Preparación para el Parcial - Listas Simplemente Enlazadas

---

## PREGUNTAS CONCEPTUALES

### 1. ¿Qué es una lista simplemente enlazada?
**Respuesta esperada:**
- Es una estructura de datos dinámica donde cada nodo contiene:
  - Datos (información)
  - Un puntero al siguiente nodo
- El último nodo apunta a NULL
- Solo se puede recorrer en una dirección (hacia adelante)

---

### 2. ¿Cuál es la diferencia entre una lista simplemente enlazada y una lista doblemente enlazada?
**Respuesta esperada:**
- **Simplemente enlazada:** Cada nodo tiene un puntero al siguiente
- **Doblemente enlazada:** Cada nodo tiene puntero al siguiente Y al anterior
- En doblemente enlazada puedes recorrer en ambas direcciones

---

### 3. ¿Qué es una estructura tipo "guirnalda"?
**Respuesta esperada:**
- Es una lista de listas
- La lista principal contiene nodos que a su vez tienen punteros a otras listas
- En este programa: COUNTRY es una guirnalda (lista de INVERSOR, cada uno con lista de LOTE)

---

### 4. ¿Por qué es importante verificar si un puntero es NULL antes de usarlo?
**Respuesta esperada:**
- Para evitar errores de ejecución (segmentation fault)
- NULL indica que no hay más nodos o que la lista está vacía
- Acceder a un puntero NULL causa un crash del programa

---

### 5. ¿Cuál es la complejidad temporal de buscar un elemento en una lista simplemente enlazada?
**Respuesta esperada:**
- O(n) en el peor caso, donde n es el número de nodos
- Debes recorrer desde el inicio hasta encontrar el elemento o llegar al final

---

### 6. ¿Qué pasa si pierdes la referencia al primer nodo (INICIO) de una lista?
**Respuesta esperada:**
- Pierdes acceso a toda la lista
- No puedes recuperar los nodos (pérdida de memoria - memory leak)
- Por eso siempre usamos punteros auxiliares para recorrer

---

## EJERCICIOS DE TRAZADO (Dibujar la estructura)

### Ejercicio A: Dibujar la estructura después de estas operaciones

```
LOTEO L;
L tiene 3 lotes:
  - Lote1: "A123B", precio 25000
  - Lote2: "C456D", precio 30000  
  - Lote3: "E789F", precio 22000

COUNTRY C;
C tiene 2 inversores:
  - "JUAN" compró: "A123B", "C456D"
  - "MARIA" compró: "E789F"
```

**Dibuja:**
1. La estructura de LOTEO con punteros
2. La estructura de COUNTRY (guirnalda) con punteros
3. Indica dónde están los NULL

---

### Ejercicio B: Trazar la ejecución

Dado este código:
```cpp
TERRENO * P = L.INICIO;
int suma = 0;
while (P) {
    suma += P->PRECIO;
    P = P->SIG;
}
```

Si L tiene 3 nodos con precios 100, 200, 300:
- ¿Cuál es el valor de `suma` al final?
- ¿Cuántas iteraciones del while se ejecutan?
- ¿Qué valor tiene `P` al final?

---

## EJERCICIOS DE CÓDIGO (Completar el código)

### Ejercicio C: Insertar al inicio

Completa esta función para insertar un nuevo terreno al INICIO de la lista:

```cpp
void LOTEO::INSERTAR_INICIO(char * codigo, int precio) {
    TERRENO * nuevo = new TERRENO;
    strcpy(nuevo->CODIGOLOTE, codigo);
    nuevo->PRECIO = precio;
    
    nuevo->SIG=INICIO;
    
    
}
```

---

### Ejercicio D: Contar nodos

Completa esta función para contar cuántos nodos tiene la lista:

```cpp
int LOTEO::CONTAR_NODOS() {
    TERRENO * P = INICIO;
    int contador = 0;
    
    // COMPLETA AQUÍ
    
    return contador;
}
```

---

### Ejercicio E: Buscar y eliminar terrenio, buscando por codigo

Completa esta función para eliminar el primer nodo que tenga ese código:

```cpp
bool LOTEO::ELIMINAR_POR_CODIGO(char * codigo) {
    if (INICIO == NULL) return false;
    
    // Caso 1: Está al inicio
    if (strcmp(INICIO->CODIGOLOTE, codigo) == 0) {
        // COMPLETA AQUÍ
        return true;
    }
    
    // Caso 2: Está en el medio o al final
    TERRENO * P = INICIO;
    while (P->SIG != NULL) {
        if (strcmp(P->SIG->CODIGOLOTE, codigo) == 0) {
            // COMPLETA AQUÍ
            return true;
        }
        P = P->SIG;
    }
    
    return false;
}
```

---

## PREGUNTAS DE ANÁLISIS DE CÓDIGO

### Pregunta 1: ¿Qué hace este código?

```cpp
TERRENO * P = INICIO;
while (P && P->SIG) {
    P = P->SIG;
}
```

**Opciones:**
a) Recorre toda la lista
b) Llega al último nodo (no NULL)
c) Llega al penúltimo nodo
d) Causa un error

**Respuesta correcta:** b) Llega al último nodo

---

### Pregunta 2: ¿Cuál es el error en este código?

```cpp
TERRENO * P = INICIO;
while (P) {
    delete P;
    P = P->SIG;
}
```

**Respuesta:** 
Después de `delete P`, el puntero P ya no es válido. No puedes acceder a `P->SIG` después de eliminar el nodo. Debes guardar la referencia al siguiente antes de eliminar:

```cpp
TERRENO * P = INICIO;
while (P) {
    TERRENO * siguiente = P->SIG;
    delete P;
    P = siguiente;
}
```

---

### Pregunta 3: ¿Qué imprime este código si la lista tiene 3 nodos?

```cpp
TERRENO * P = INICIO;
int i = 0;
while (P && i < 2) {
    printf("%s\n", P->CODIGOLOTE);
    P = P->SIG;
    i++;
}
```

**Respuesta:** Imprime los códigos de los primeros 2 nodos.

---

## EJERCICIOS AVANZADOS

### Ejercicio F: Invertir lista (sin crear nueva)

Implementar `void LOTEO::INVERTIR()` que invierta el orden de los nodos **modificando los punteros**, sin crear nuevos nodos.

**Pista:** Necesitas 3 punteros: anterior, actual, siguiente.

---

### Ejercicio G: Detectar ciclo

Implementar `bool LOTEO::TIENE_CICLO()` que detecte si hay un ciclo en la lista (un nodo apunta a uno anterior).

**Pista:** Usa el algoritmo de la "tortuga y la liebre" (Floyd).

---

### Ejercicio H: Obtener nodo en posición N

Implementar `TERRENO * LOTEO::OBTENER_NODO(int posicion)` que retorne un puntero al nodo en la posición dada (0 = primero, 1 = segundo, etc.).

**Retornar NULL si la posición no existe.**

---

### Ejercicio I: Insertar en posición específica

Implementar `bool LOTEO::INSERTAR_EN_POSICION(int pos, char * codigo, int precio)` que inserte un nuevo nodo en la posición `pos`.

---

### Ejercicio J: Concatenar dos listas

Implementar `void LOTEO::CONCATENAR(LOTEO * otra)` que agregue todos los nodos de `otra` al final de la lista actual.

**Cuidado:** No debes crear nuevos nodos, solo modificar punteros.

---

## CONCEPTOS CLAVE A RECORDAR

### ✅ Punteros
- `*` declara un puntero
- `->` accede a miembros de un objeto a través de puntero
- `NULL` indica que no apunta a nada
- `new` crea memoria dinámica
- `delete` libera memoria dinámica

### ✅ Recorrer lista
```cpp
P = INICIO;
while (P) {
    // hacer algo con P
    P = P->SIG;
}
```

### ✅ Insertar al inicio
```cpp
nuevo->SIG = INICIO;
INICIO = nuevo;
```

### ✅ Eliminar del inicio
```cpp
TERRENO * temp = INICIO;
INICIO = INICIO->SIG;
delete temp;
```

### ✅ Buscar elemento
```cpp
P = INICIO;
while (P && !condicion) {
    P = P->SIG;
}
if (P) {
    // encontrado
}
```

---

## TIPS PARA EL EXAMEN

1. **Lee cuidadosamente** el enunciado
2. **Dibuja la estructura** antes de programar
3. **Verifica casos límite:** lista vacía, un solo nodo, etc.
4. **Usa nombres de variables claros**
5. **Comenta tu código** si tienes tiempo
6. **Prueba mentalmente** tu código con ejemplos pequeños
7. **No olvides liberar memoria** si eliminas nodos
8. **Verifica punteros NULL** siempre

---

¡Éxitos en el parcial! 🎓

