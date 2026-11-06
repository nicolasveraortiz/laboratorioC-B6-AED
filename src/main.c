#include <stdio.h>
#include "../include/validaciones.h"

int main() {
    int opcion = mostrarMenu();
    pocesoEjecutar(opcion, NILL);
    return 0;
}
