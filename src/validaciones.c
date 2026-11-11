#include <stdio.h>
#include "../include/validaciones.h"
#include "../include/artemis.h"

void arteIntro()
{
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

void mostrarMenu()
{
    printf(
        "\nIngrese un número para llamar a la función o realizar pruebas \n"
        "1. Resolver frenado aerodinamico \n"
        "2. Resolver desaceleracion de la tripulacion \n"
        "3. Resolver impacto del amerizaje\n"
        "4. Evaluar reingreso a la atmósfera \n"        
        "5. Modificar datos de la nave \n"
        "6. Cargar preset desde archivo JSON \n"
        "7. Restablecer valores predeterminados \n"
        "0. Cerrar el programa \n");
        
}

void procesoEjecutar(int opcion, CapsulaOrion *nave)
{
    switch (opcion)
    {
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
    case 5:
        modificarDatosNave(nave);
        break;
    case 6:
        cargarPresetDesdeArchivo(nave);
        break;
    case 7:
        valoresPredeterminadoDeNave(nave);
        guardarDatosNave(nave, ARCHIVO_CONFIG);
        break;
    case 0:
        printf("Cerrando el programa...");
        break;
    default:
        printf("Opción inválida. Por favor ingrese un número válido para ejecutar el programa.");
        break;
    }
}

int leerEntero(int min, int max) {
    int numero;
    
    while (1) {
        printf("Ingrese una opción (%d al %d): ", min, max);
        
        if (scanf("%d", &numero) != 1) {
            printf("Tipo de dato invalido. Ingrese un numero.\n");
            
            while (getchar() != '\n'); 
            
            continue;
        }
        
        if (numero >= min && numero <= max) {
            return numero;
        }
        
        printf("Opcion fuera de rango. Ingrese un numero entre %d y %d.\n", min, max);
    }
}

double leerRealPositivo(double min, double max, char *msg) {
    double numero;
    
    while (1) {
        printf("%s", msg);
        
        if (scanf("%lf", &numero) != 1) {
            printf("Tipo de dato invalido. Ingrese un numero real.\n");
            while (getchar() != '\n'); 
            continue;
        }
        
        if (numero >= min && numero <= max) {
            return numero;
        }
        
        printf("Valor fuera del rango aceptado. Ingrese un numero entre %g y %g.\n" , min, max);
    }
}