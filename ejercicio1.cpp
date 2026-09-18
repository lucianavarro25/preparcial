#include <iostream>
using namespace std;


struct vehiculo{
    char placa[10];
    char tipo[20];
    int horaEntrada;
    bool activo;
};
void registrarVehiculo(Vehiculo estacionamiento[], int capacidad,
                       char placa[], char tipo[], int hora) {

    // Primero verificamos si la placa ya existe

    for (int i = 0; i < capacidad; i++) {

        if (estacionamiento[i].activo) {

            bool iguales = true;

            for (int j = 0; placa[j] != '\0' || estacionamiento[i].placa[j] != '\0'; j++) {

                if (placa[j] != estacionamiento[i].placa[j]) {
                    iguales = false;
                    break;
                }
            }

            if (iguales) {
                cout << "Ya existe un vehiculo con esa placa.\n";
                return;
            }
        }
    }
int buscarVehiculo(Vehiculo estacionamiento[], int capacidad, char placa[]) {

    for (int i = 0; i < capacidad; i++) {

        if (estacionamiento[i].activo) {

            bool iguales = true;

            for (int j = 0; placa[j] != '\0' || estacionamiento[i].placa[j] != '\0'; j++) {

                if (estacionamiento[i].placa[j] != placa[j]) {
                    iguales = false;
                    break;
                }
            }

            if (iguales) {
                return i;
            }
        }
    }

    return -1;
}
    // Buscamos un espacio libre

    for (int i = 0; i < capacidad; i++) {

        if (!estacionamiento[i].activo) {

            int j = 0;

            while (placa[j] != '\0') {
                estacionamiento[i].placa[j] = placa[j];
                j++;
            }
            estacionamiento[i].placa[j] = '\0';

            j = 0;

            while (tipo[j] != '\0') {
                estacionamiento[i].tipo[j] = tipo[j];
                j++;
            }
            estacionamiento[i].tipo[j] = '\0';

            estacionamiento[i].horaEntrada = hora;
            estacionamiento[i].activo = true;

            cout << "Vehiculo registrado correctamente.\n";
            return;
        }
    }

    cout << "Estacionamiento lleno.\n";
}
int main(){
    return 0;
}

