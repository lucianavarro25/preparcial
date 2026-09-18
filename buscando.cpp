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