// Generar 100 donaciones aleatorias y guardarlas en donaciones.dat
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

using namespace std;

struct DONACIONES {
    char ONG[64];        // institución que recibe la donación
    int MONTO;           // cantidad en dólares donados
    char FILANTROPO[32]; // persona o empresa que realizó la donación
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    const char* nombreONG[] = {
        "Caritas",
        "Red Cross",
        "Amigos de los Animales",
        "Fundacion por la Vida",
        "Medicos sin Fronteras",
        "Greenpeace",
        "Save the Children",
        "UNICEF",
        "Cruz Roja Argentina",
        "Banco de Alimentos"
    };

    const int montos[] = {
        10000, 2000, 30000, 4000, 50000, 60000, 70000, 800000, 90000,
        100000000, 568445, 45648, 8452135, 8484845, 5452, 25000
    };

    const char* nombreFILANTROPO[] = {
        "Juan", "Pedro", "Maria", "Luis", "Ana", "Carlos", "Manuel", "Luisa",
        "Isabel", "Sergio", "Juan Carlos", "Juan Manuel", "Agustina", "Valentina",
        "Roberto", "Marta", "Pablo", "Sofia", "Diego", "Camila"
    };

    const size_t nONG = sizeof(nombreONG) / sizeof(nombreONG[0]);
    const size_t nMontos = sizeof(montos) / sizeof(montos[0]);
    const size_t nFilantropos = sizeof(nombreFILANTROPO) / sizeof(nombreFILANTROPO[0]);

    FILE* donaciones = fopen("donaciones.dat", "wb");
    if (!donaciones) {
        cerr << "Error al abrir el archivo para escritura" << endl;
        return 1;
    }

    DONACIONES reg{};
    for (int i = 0; i < 100; ++i) {
        const char* ong = nombreONG[rand() % nONG];
        const char* fil = nombreFILANTROPO[rand() % nFilantropos];

        // Copias seguras a buffers fijos
        strncpy(reg.ONG, ong, sizeof(reg.ONG) - 1);
        reg.ONG[sizeof(reg.ONG) - 1] = '\0';

        reg.MONTO = montos[rand() % nMontos];

        strncpy(reg.FILANTROPO, fil, sizeof(reg.FILANTROPO) - 1);
        reg.FILANTROPO[sizeof(reg.FILANTROPO) - 1] = '\0';

        fwrite(&reg, sizeof(DONACIONES), 1, donaciones);
    }
    fclose(donaciones);

    // Lectura y muestra por consola
    donaciones = fopen("donaciones.dat", "rb");
    if (!donaciones) {
        cerr << "Error al abrir el archivo para lectura" << endl;
        return 1;
    }
    printf("\tONG\t\t\t\t\tMONTO\t\tFILANTROPO\n\n");
    while (fread(&reg, sizeof(DONACIONES), 1, donaciones) == 1) {
        printf("%-30s\t\t%12d\t\t%-20s\n", reg.ONG, reg.MONTO, reg.FILANTROPO);
    }

    fclose(donaciones);
    return 0;
}
