#include <stdio.h>
#include <stdbool.h>
#include "../include/artemis.h"
#include "../include/validaciones.h"

int main() {
    bool bandera = true;
    int opcion = 0;
    CapsulaOrion nave = {10400.0, 120000.0, 11000.0, 6.2};
    arteIntro();

    while (bandera) {
        mostrarMenu();
        scanf("%d", &opcion);
        procesoEjecutar(opcion, &nave);
        if (opcion == 5) {bandera = false;}
    }
    return 0;
}