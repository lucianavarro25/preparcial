#include <iostream>

using namespace std;

struct Vehiculo {
    char placa[10];
    char tipo[20];
    int horaEntrada;
    bool activo;
};

// REGISTRAR VEHICULO
void registrarVehiculo(Vehiculo estacionamiento[], int capacidad,
                       char placa[], char tipo[], int hora) {

    // Verificar si la placa ya existe
    for (int i = 0; i < capacidad; i++) {

        if (estacionamiento[i].activo) {

            bool iguales = true;

            for (int j = 0; placa[j] != '\0' ||
                 estacionamiento[i].placa[j] != '\0'; j++) {

                if (placa[j] != estacionamiento[i].placa[j]) {
                    iguales = false;
                    break;
                }
            }

            if (iguales) {
                cout << "Ya existe un vehiculo con esa placa." << endl;
                return;
            }
        }
    }

    // Buscar un espacio libre
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

            cout << "Vehiculo registrado correctamente." << endl;
            return;
        }
    }

    cout << "ERROR: Estacionamiento lleno." << endl;

}


// BUSCAR VEHICULO
int buscarVehiculo(Vehiculo estacionamiento[], int capacidad,
                   char placa[]) {

    for (int i = 0; i < capacidad; i++) {

        if (estacionamiento[i].activo) {

            bool iguales = true;

            for (int j = 0; placa[j] != '\0' ||
                 estacionamiento[i].placa[j] != '\0'; j++) {

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


// REGISTRAR SALIDA
void registrarSalida(Vehiculo estacionamiento[], int capacidad,
                     char placa[]) {

    int posicion = buscarVehiculo(estacionamiento, capacidad, placa);

    if (posicion == -1) {
        cout << "Vehiculo no encontrado." << endl;
        return;
    }

    estacionamiento[posicion].activo = false;

    cout << "Salida registrada correctamente." << endl;
}
// MOSTRAR ESTADISTICAS
void mostrarEstadisticas(Vehiculo estacionamiento[], int capacidad) {

    int ocupados = 0;

    // Contar espacios ocupados
    for (int i = 0; i < capacidad; i++) {

        if (estacionamiento[i].activo) {
            ocupados++;
        }
    }

    int libres = capacidad - ocupados;

    double porcentaje = (ocupados * 100.0) / capacidad;

    cout << "Espacios ocupados: " << ocupados << endl;
    cout << "Espacios libres: " << libres << endl;
    cout << "Porcentaje de ocupacion: " << porcentaje << "%" << endl;
}

// MAIN
int main() {

     Vehiculo estacionamiento[3];

    for (int i = 0; i < 3; i++) {
        estacionamiento[i].activo = false;
    }

    char placa1[] = "ABC123";
    char tipo1[] = "Carro";

    char placa2[] = "XYZ789";
    char tipo2[] = "Moto";

    registrarVehiculo(estacionamiento, 3, placa1, tipo1, 8);
    registrarVehiculo(estacionamiento, 3, placa2, tipo2, 9);

    mostrarEstadisticas(estacionamiento, 3);
    return 0;
}