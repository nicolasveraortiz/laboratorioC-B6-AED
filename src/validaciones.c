#include <stdio.h>
#include "artemis.h"
#include "validaciones.h"

int mostrarMenu() {
    int opcion;
    printf(
            "---------------------------------------------\n"
            " ███  ████  █████ █████ █   █ ███  ████ \n"   
            "█ ░░█ █░░░█  ░█░░░█░░░░░██ ██░ █░░█ ░░░░ \n"  
            "█████░████░░  █░░░████░░█░█ █░░█░░░███░░░ \n"
            "█░░░█░█░░█░ ░ █░░ █░░░░ █░░░█░░█░░  ░░█ \n"  
            "█░░░█░█░░░█░  █░░ █████░█░░ █░███░████░░ \n" 
            " ░░  ░░░░  ░   ░░  ░░░░░ ░░  ░░░░░ ░░░░ ░ \n"
            "  ░   ░ ░   ░   ░   ░░░░░ ░   ░ ░░░ ░░░░ \n"
            "---------------------------------------------\n");
    printf(
        "¡Bienvenido al sistema de cálculo físico del Artemis! \n"
        "Ingrese un número para llamar a la función o realizar pruebas \n"
        "1. Resolver frenado aerodinamico \n"
        "2. Resolver desaceleracion de la tripulacion \n"
        "3. Resolver impacto del amerizaje\n"
        "4. Evaluar reingreso a la atmósfera \n" 
        "0. Cerrar el programa \n"
    );
    
    scanf("%d", &opcion);
    return opcion;
}

void procesoEjecutar(int opcion, CapsulaOrion *nave) {
    switch (opcion) {
        case 1:
            resolverFrenadoAerodinamico(nave);
            break;
        case 2:
            resolverDesaceleracionTripulacion(nave);
            break;
        case 3: 
            resolverAmerizajeImpacto(nave);
            break;
        case 4:
            resolverVentanaReingreso(nave);
            break;
        case 0:
            printf("Cerrando el programa");
            break;
        default:
            printf("Opción inválida. Por favor ingrese un número válido para ejecutar el programa.");
            break;
    }
}
