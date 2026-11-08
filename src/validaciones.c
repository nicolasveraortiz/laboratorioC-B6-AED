#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include "../include/validaciones.h"
#include "../include/artemis.h"

void depurador(CapsulaOrion *nave);

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
        "6. Generar informe de la nave \n"
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
    case 6010:
        depurador(nave);
        break;
    case 5:
        modificarDatosNave(nave);
        break;
    case 6:
        generarInformeJSON(nave);
        break;
    case 0:
        printf("Cerrando el programa...");
        break;
    default:
        printf("Opción inválida. Por favor ingrese un número válido para ejecutar el programa.");
        break;
    }
}

void depurador(CapsulaOrion *nave){
    bool depurando = true;
    int opcion;
    while (depurando)
    {
        printf("Ingrese la opcion correspondiente a la funcion a depurar\n");
        scanf("%d", &opcion);
        switch (opcion){
        case 1:
            solicitar_double_positivo("Depurando 'solicitar_double_positivo'\n");
            break;
        case 0:
            depurando = false;
            printf("Saliendo de depurador...\n");
            break;
        default:
            printf("No se hizo referencia a ninguna funcion existente...\n");
            break;
        }
        printf("\n");
    }    
}

// No da error de compilación, pero aún no está correctamente inplementado
double solicitar_double_positivo(char *msg)
{
    char *entrada = malloc(65 * sizeof(char));
    char *endptr; // <-- puntero a final de linea
    if (entrada == NULL){
        printf("Error de asignacion de memoria en funcion 'solicitar_double_positivo'");
        return -1; // Evaluar NULL o valor establecido como mensaje de error entre funciones internas
    }

    printf("%s", msg);
    fgets(entrada, sizeof(*entrada), stdin);

    errno = 0;
    double valor = strtod(entrada, &endptr);

    if (entrada == endptr || *endptr != '\n' && *endptr != '\0' || errno == ERANGE){ // <-- ERANGE verifica que el valor ingresado se encuentre entro los parametros que el tipo de dato permite
        printf("Error en el valor ingresado: Debe ingresar un valor NUMERICO real.\n");
        return -1;
    } else {
        // strtod guarda en 'endprt' el texto que no se transforma a double por ser caracter, evaluar la posibilidad de permitir al usuario ingresar valores + unidad de medida
        // strtod y esta condicion permite que el usuario ingrese algo como '123.321 texto' -> en 'valor' queda '123.321'
        if (valor >= 0){
            return valor;
        }else{
            printf("Error en el valor ingresado: Se esperada un numero real positivo.\n");
            return -1;
        }
    }
}