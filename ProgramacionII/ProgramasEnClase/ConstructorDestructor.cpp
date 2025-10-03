#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
#include <windows.h>//esto es por que me imprimia caracteres extraños en la consola

using namespace std;//para no escribir std::cout, std::cin, std::string todo el tiempo

class PROFESOR {

private:
    int contadorDeCuentos=0;
    int maxCuentos=0;   

public:
    

    // Constructor: se ejecuta al CREAR el objeto.
    // Inicializa el estado y deja listo el objeto para usarse.
    PROFESOR(int limite) : contadorDeCuentos(0), maxCuentos(limite) {
        cout<<"Constructor llamado: crear profesor con limite de "<<maxCuentos<<" anécdotas."<<endl;
    }

    void contarAnecdota() {
        while (contadorDeCuentos < maxCuentos) {

            cout << "Profe contando anécdota #" << contadorDeCuentos+1 << endl;
            cout << "mi cerebro disociando...." << endl;
            contadorDeCuentos++;
            cout<<"presiona una tecla si sigue divagando...\n";
            getch();
            
         
            if (contadorDeCuentos == maxCuentos) {
                cout << "Demasiadas anécdotas... destructor en camino." << endl;
               
                return;
            }
        }
    }

    // Destructor: se ejecuta al DESTRUIR el objeto.
    // Libera recursos y realiza limpieza.
    ~PROFESOR() {
        cout << "Destructor llamado: liberar memoria y recibo de sueldo." << endl;
        if (reciboDeSueldo) {
            cout << "delete reciboDeSueldo; // chau sueldo, hola jubilación" << endl;
            delete reciboDeSueldo; //Libera la memoria asignada al recibo de sueldo.
            reciboDeSueldo = NULL; //Evita doble liberación.
        }
    }
    string* reciboDeSueldo = new string("Recibo de sueldo");
   
};

int main() {
    SetConsoleOutputCP(CP_UTF8);//esto es por que me imprimia caracteres extraños en la consola
    SetConsoleCP(CP_UTF8);//esto es por que me imprimia caracteres extraños en la consola


    int AnecdotaMax;
    cout<<"Ingrese limite de anecdotas:";
    cin>>AnecdotaMax;
    PROFESOR profe(AnecdotaMax);//Instancia de la clase PROFESOR 
    profe.contarAnecdota();//Llama al metodo contarAnecdota
    getch();
    return 0;
}
