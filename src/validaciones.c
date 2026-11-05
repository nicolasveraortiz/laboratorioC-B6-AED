#include <stdio.h>
#include "../include/validaciones.h"

void mostrarMenu()
{
    int opcion;
    do
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
            "---------------------------------------------\n");
        printf(
            "¡Bienvenido al sistema de cálculo físico del Artemis! \n"
            "Ingrese un número para llamar a la función o realizar pruebas \n"
            "1. Resolver frenado aerodinamico \n"
            "2. Resolver desaceleracion de la tripulacion \n"
            "3. Resolver impacto del amerizaje\n"
            "4. Evaluar reingreso a la atmósfera \n"
            "0. Cerrar el programa \n");

        scanf("%d", &opcion);

    } while (opcion != 0);
}