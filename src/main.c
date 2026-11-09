#include <stdio.h>
#include <stdbool.h>
#include "../include/artemis.h"
#include "../include/validaciones.h"

int main() {
    bool bandera = true;
    int opcion = 0;
    CapsulaOrion nave = {10400.0, 120000.0, 11000.0, 6.2};
    cargarDatosDeJSON(&nave); 
    arteIntro();

    while (bandera) {
        mostrarMenu();
        opcion = leerEntero(0, 6);
        procesoEjecutar(opcion, &nave);
        if (opcion == 0) {bandera = false;}
    }
    return 0;
}