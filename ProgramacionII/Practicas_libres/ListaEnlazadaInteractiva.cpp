#include <iostream>
#include <limits>
#include <string>

/**
 * Programa interactivo para practicar operaciones básicas sobre una lista
 * simplemente enlazada en C++. Permite insertar, buscar, eliminar y limpiar
 * la lista mostrando el estado después de cada operación.
 */
class ListaEnlazada {
private:
    struct Nodo {
        int valor;
        Nodo* siguiente;

        explicit Nodo(int v) : valor(v), siguiente(nullptr) {}
    };

    Nodo* cabeza = nullptr;

public:
    ListaEnlazada() = default;

    ~ListaEnlazada() {
        limpiar();
    }

    bool estaVacia() const {
        return cabeza == nullptr;
    }

    std::size_t tamanio() const {
        std::size_t contador = 0;
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            ++contador;
            actual = actual->siguiente;
        }
        return contador;
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

    bool insertarEnPosicion(std::size_t posicion, int valor) {
        if (posicion == 0) {
            insertarAlInicio(valor);
            return true;
        }

        Nodo* actual = cabeza;
        std::size_t indice = 0;
        while (actual != nullptr && indice + 1 < posicion) {
            actual = actual->siguiente;
            ++indice;
        }

        if (actual == nullptr) {
            return false;
        }

        Nodo* nuevo = new Nodo(valor);
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
        return true;
    }

    bool eliminar(int valor) {
        if (estaVacia()) {
            return false;
        }

        if (cabeza->valor == valor) {
            Nodo* nodoAEliminar = cabeza;
            cabeza = cabeza->siguiente;
            delete nodoAEliminar;
            return true;
        }

        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr && actual->siguiente->valor != valor) {
            actual = actual->siguiente;
        }

        if (actual->siguiente == nullptr) {
            return false;
        }

        Nodo* nodoAEliminar = actual->siguiente;
        actual->siguiente = nodoAEliminar->siguiente;
        delete nodoAEliminar;
        return true;
    }

    bool buscar(int valor) const {
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            if (actual->valor == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void limpiar() {
        while (cabeza != nullptr) {
            Nodo* nodoAEliminar = cabeza;
            cabeza = cabeza->siguiente;
            delete nodoAEliminar;
        }
    }

    void imprimir() const {
        if (estaVacia()) {
            std::cout << "Lista vacía\n";
            return;
        }

        std::cout << "[ ";
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            std::cout << actual->valor;
            if (actual->siguiente != nullptr) {
                std::cout << " -> ";
            }
            actual = actual->siguiente;
        }
        std::cout << " ]\n";
    }
};

void mostrarMenu() {
    std::cout << "\n===== Laboratorio de listas enlazadas =====\n";
    std::cout << "1. Insertar al inicio\n";
    std::cout << "2. Insertar al final\n";
    std::cout << "3. Insertar en posición\n";
    std::cout << "4. Eliminar un valor\n";
    std::cout << "5. Buscar un valor\n";
    std::cout << "6. Mostrar la lista\n";
    std::cout << "7. Limpiar lista\n";
    std::cout << "0. Salir\n";
    std::cout << "Selecciona una opción: ";
}

int leerEntero(const std::string& mensaje) {
    int valor;
    while (true) {
        std::cout << mensaje;
        if (std::cin >> valor) {
            return valor;
        }
        std::cout << "Entrada inválida. Intenta nuevamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

std::size_t leerPosicion(const ListaEnlazada& lista) {
    std::size_t posicion;
    while (true) {
        std::cout << "Ingresa la posición (0 a " << lista.tamanio() << "): ";
        if (std::cin >> posicion) {
            return posicion;
        }
        std::cout << "Entrada inválida. Intenta nuevamente.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    ListaEnlazada lista;
    bool salir = false;

    while (!salir) {
        mostrarMenu();

        int opcion;
        if (!(std::cin >> opcion)) {
            std::cout << "Entrada inválida. Debes ingresar un número.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                int valor = leerEntero("Valor a insertar al inicio: ");
                lista.insertarAlInicio(valor);
                std::cout << "Se insertó " << valor << " al inicio.\n";
                lista.imprimir();
                break;
            }
            case 2: {
                int valor = leerEntero("Valor a insertar al final: ");
                lista.insertarAlFinal(valor);
                std::cout << "Se insertó " << valor << " al final.\n";
                lista.imprimir();
                break;
            }
            case 3: {
                int valor = leerEntero("Valor a insertar: ");
                std::size_t posicion = leerPosicion(lista);
                if (lista.insertarEnPosicion(posicion, valor)) {
                    std::cout << "Se insertó " << valor << " en la posición " << posicion << ".\n";
                } else {
                    std::cout << "No se pudo insertar en la posición " << posicion
                              << ". (Recuerda que la lista tiene " << lista.tamanio() << " nodos.)\n";
                }
                lista.imprimir();
                break;
            }
            case 4: {
                int valor = leerEntero("Valor a eliminar: ");
                if (lista.eliminar(valor)) {
                    std::cout << "Se eliminó " << valor << " de la lista.\n";
                } else {
                    std::cout << "El valor " << valor << " no está presente en la lista.\n";
                }
                lista.imprimir();
                break;
            }
            case 5: {
                int valor = leerEntero("Valor a buscar: ");
                if (lista.buscar(valor)) {
                    std::cout << "Encontrado. El valor " << valor << " está en la lista.\n";
                } else {
                    std::cout << "El valor " << valor << " no se encuentra en la lista.\n";
                }
                break;
            }
            case 6:
                lista.imprimir();
                break;
            case 7:
                lista.limpiar();
                std::cout << "La lista fue vaciada.\n";
                lista.imprimir();
                break;
            case 0:
                salir = true;
                break;
            default:
                std::cout << "Opción no válida. Intenta nuevamente.\n";
        }
    }

    std::cout << "¡Gracias por practicar listas enlazadas!\n";
    return 0;
}
