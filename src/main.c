#include <stdio.h>
#include <stdbool.h>
#include "../include/artemis.h"
#include "../include/validaciones.h"

int main() {
    bool bandera = true;
    int opcion = 0;
    CapsulaOrion nave = {10400.0, 120000.0, 11000.0, 6.2};
    arteIntro();
    iniciarDatosNave(&nave);

    while (bandera) {
        mostrarMenu();
        opcion = leerEntero(0, 7);
        int c;
        while ((c = getchar()) != '\n' && c != EOF); 
        procesoEjecutar(opcion, &nave);
        if (opcion == 0) {bandera = false;}
    }
    return 0;
}
