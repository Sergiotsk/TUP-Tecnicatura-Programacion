#include <iostream>
#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    int edad;
    string nacionalidad;
    string posicion;
    int numero;

public:
    // Constructor que inicializa los atributos
    Jugador(string n, int e, string nac, string pos, int num) : nombre(n), edad(e), nacionalidad(nac), posicion(pos), numero(num) {}

    // Método para mostrar la info del jugador
    void mostrarInfo() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", Nacionalidad: " << nacionalidad << ", Posicion: " << posicion << ", Numero: " << numero << endl;
    }
};
    
int main() {
    // Creás un objeto Jugador llamado "Messi           
    Jugador messi("Messi", 36, "Argentina", "Delantero", 10  );
    
    Jugador maradona("Maradona", 60, "Argentina", "Delantero", 10);

    Jugador Cristiano("Ronaldo", 40, "Portugal", "Delantero", 10);

    // Ahora usás un objeto específico, por ejemplo, mostrar la info de Messi
    cout << "Info de Messi: ";
    messi.mostrarInfo();

    cout << "Info de Maradona: ";
    maradona.mostrarInfo();

    cout << "Info de  Cristiano: ";
    Cristiano.mostrarInfo();

    return 0;
}
