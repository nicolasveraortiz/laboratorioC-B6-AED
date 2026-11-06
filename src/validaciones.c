#include <stdio.h>
#include "../include/validaciones.h"
#include "../include/artemis.h"

void arteIntro() {
    printf(
            "---------------------------------------------\n"
            " ███  ████  █████ █████ █   █ ███  ████ \n"   
            "█ ░░█ █░░░█  ░█░░░█░░░░░██ ██░ █░░█ ░░░░ \n"  
            "█████░████░░  █░░░████░░█░█ █░░█░░░███░░░ \n"
            "█░░░█░█░░█░ ░ █░░ █░░░░ █░░░█░░█░░  ░░█ \n"  
            "█░░░█░█░░░█░  █░░ █████░█░░ █░███░████░░ \n" 
            " ░░  ░░░░  ░   ░░  ░░░░░ ░░  ░░░░░ ░░░░ ░ \n"
            "  ░   ░ ░   ░   ░   ░░░░░ ░   ░ ░░░ ░░░░ \n"
            "---------------------------------------------\n\n"
            "¡Bienvenido al sistema de cálculo físico del Artemis! \n");
}

void mostrarMenu() {
    printf(
        "Ingrese un número para llamar a la función o realizar pruebas \n"
        "1. Resolver frenado aerodinamico \n"
        "2. Resolver desaceleracion de la tripulacion \n"
        "3. Resolver impacto del amerizaje\n"
        "4. Evaluar reingreso a la atmósfera \n" 
        "0. Cerrar el programa \n"
    );
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
            evaluarVentanaReingreso(nave);
            break;
        case 0:
            printf("Cerrando el programa...");
            break;
        default:
            printf("Opción inválida. Por favor ingrese un número válido para ejecutar el programa.");
    }
}
