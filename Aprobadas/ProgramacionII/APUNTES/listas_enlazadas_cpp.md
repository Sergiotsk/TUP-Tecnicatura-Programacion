# Listas simplemente enlazadas en C++

Este apunte resume los conceptos básicos que necesitas para comenzar a trabajar con listas simplemente enlazadas en C++ si vienes de programar en C. Incluye una comparación rápida entre ambos lenguajes, la estructura clásica de un nodo, las operaciones más frecuentes y ejemplos de código idiomático en C++ moderno.

## De C a C++: ¿qué cambia?

- **`struct` con funciones miembro**: en C++ puedes definir métodos dentro de una estructura para encapsular comportamiento.
- **Constructores y destructores**: permiten inicializar y limpiar recursos automáticamente.
- **`new`/`delete` vs. `malloc`/`free`**: en C++ se usan `new` y `delete` (o mejor, smart pointers) para gestionar memoria.
- **`nullptr`** reemplaza a `NULL` para punteros nulos.
- **`std::cout`/`std::cin`**: flujos de entrada/salida en lugar de `printf`/`scanf`.
- **Plantillas y STL**: C++ ofrece librerías genéricas como `std::forward_list`, aunque aprender la implementación manual ayuda a comprender su funcionamiento.

> Consejo: si bien `new` y `delete` son válidos, se recomienda utilizar contenedores y punteros inteligentes (`std::unique_ptr`) para evitar fugas de memoria. En listas enlazadas educativas podemos empezar con punteros crudos para entender el mecanismo y luego evolucionar a smart pointers.

## Estructura básica de un nodo

```cpp
struct Nodo {
    int dato;          // información almacenada
    Nodo* siguiente;   // puntero al próximo nodo

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};
```

- El constructor inicializa el dato y el puntero `siguiente`.
- `nullptr` indica que no hay más nodos.

## Clase ListaSimple

Definimos una clase ligera para administrar la cabeza de la lista y las operaciones.

```cpp
class ListaSimple {
private:
    Nodo* cabeza;  // primer nodo de la lista

public:
    ListaSimple() : cabeza(nullptr) {}

    ~ListaSimple() {
        limpiar();
    }

    bool estaVacia() const {
        return cabeza == nullptr;
    }

    void insertarAlInicio(int valor) {
        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    void insertarAlFinal(int valor) {
        Nodo* nuevo = new Nodo(valor);
        if (estaVacia()) {
            cabeza = nuevo;
            return;
        }
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }

    bool eliminar(int valor) {
        if (estaVacia()) {
            return false;
        }
        // Caso especial: el primer nodo
        if (cabeza->dato == valor) {
            Nodo* nodoAEliminar = cabeza;
            cabeza = cabeza->siguiente;
            delete nodoAEliminar;
            return true;
        }
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->dato != valor) {
            actual = actual->siguiente;
        }
        if (actual->siguiente == nullptr) {
            return false; // no se encontró el valor
        }
        Nodo* nodoAEliminar = actual->siguiente;
        actual->siguiente = nodoAEliminar->siguiente;
        delete nodoAEliminar;
        return true;
    }

    Nodo* buscar(int valor) const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->dato == valor) {
                return actual;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }

    void limpiar() {
        while (!estaVacia()) {
            Nodo* nodoAEliminar = cabeza;
            cabeza = cabeza->siguiente;
            delete nodoAEliminar;
        }
    }

    void imprimir() const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->dato << " -> ";
            actual = actual->siguiente;
        }
        std::cout << "nullptr\n";
    }
};
```

### Puntos claves

1. **Encapsulación**: la clase administra la cabeza y las operaciones, evitando manipular punteros desde `main`.
2. **Destructor**: llama a `limpiar()` para liberar memoria cuando la lista se destruye.
3. **Funciones miembro `const`**: marcan métodos que no modifican el estado interno.

## Uso en `main`

```cpp
#include <iostream>
#include <memory> // para std::unique_ptr en ejemplos más avanzados

int main() {
    ListaSimple lista;

    lista.insertarAlInicio(3);
    lista.insertarAlInicio(1);
    lista.insertarAlFinal(5);

    lista.imprimir(); // 1 -> 3 -> 5 -> nullptr

    if (lista.eliminar(3)) {
        std::cout << "Se eliminó el 3\n";
    }

    Nodo* encontrado = lista.buscar(5);
    if (encontrado != nullptr) {
        std::cout << "Encontrado: " << encontrado->dato << '\n';
    }

    // El destructor de ListaSimple libera la memoria automáticamente
    return 0;
}
```

## Buenas prácticas y próximos pasos

- **Inicialización uniforme** (`Nodo* nuevo = new Nodo{valor};`) para mayor claridad.
- **`std::unique_ptr`**: permite gestionar memoria automáticamente sin `delete`.
- **Uso de `struct` anidados**: puedes declarar `struct Nodo` dentro de `ListaSimple` para ocultarlo.
- **Excepciones**: maneja posibles fallos de `new` o utiliza `std::nothrow`.
- **Iteradores personalizados**: facilitan recorrer la lista con `for` basados en rango.

### Ejemplo con `std::unique_ptr`

```cpp
#include <memory>

struct NodoSmart {
    int dato;
    std::unique_ptr<NodoSmart> siguiente;

    explicit NodoSmart(int valor) : dato(valor), siguiente(nullptr) {}
};

class ListaSmart {
private:
    std::unique_ptr<NodoSmart> cabeza;

public:
    void insertarAlInicio(int valor) {
        auto nuevo = std::make_unique<NodoSmart>(valor);
        nuevo->siguiente = std::move(cabeza);
        cabeza = std::move(nuevo);
    }
};
```

Este patrón elimina la necesidad de `delete`, pues los `unique_ptr` liberan la memoria automáticamente.

## Recursos recomendados

- Documentación oficial de C++: [https://en.cppreference.com](https://en.cppreference.com)
- "Programming Principles and Practice Using C++" de Bjarne Stroustrup
- Tutorial sobre listas enlazadas de cppreference: busca "forward_list" para ver la versión estándar.

Con estos conceptos ya puedes comenzar a implementar y experimentar con tus propias listas simplemente enlazadas en C++. ¡Practica agregando operaciones como insertar en posición específica, invertir la lista o contar nodos!
