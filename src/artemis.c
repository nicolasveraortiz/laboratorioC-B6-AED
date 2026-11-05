#include <stdio.h>
#include "../include/artemis.h"

// IMPLEMENTACIÓN DE FUNCIONES FÍSICAS

double calcularEnergiaCinetica(double masa, double velocidad) {
    return 0.5 * masa * velocidad * velocidad;
}

double calcularEnergiaPotencial(double masa, double altitud) {
    const double g = 9.8;
    return masa * g * altitud;
}

double calcularTrabajoFriccion(double energiaMecanicaFinal, double energiaMecanicaInicial) {
    return energiaMecanicaFinal - energiaMecanicaInicial; // Negativo porque disipa energía
}

double calcularDesaceleracion(double vInicial, double vFinal, double tiempo) {
    if (tiempo <= 0) return 0.0;
    return (vFinal - vInicial) / tiempo;
}

double calcularFuerzaImpacto(double masa, double velocidad, double distanciaHundimiento) {
    const double g = 9.8;
    double peso = masa * g;
    if (distanciaHundimiento <= 0) return peso;
    double fuerzaDinamica = (masa * velocidad * velocidad) / (2.0 * distanciaHundimiento);
    return peso + fuerzaDinamica;
}

// IMPLEMENTACIÓN DE FUNCIONES PARA EL MENU

void resolverFrenadoAerodinamico(CapsulaOrion *nave) {
    const double velocidadFinal = 25.0;
    const double altitudFinal = 2500.0;

    printf("\n=============================================\n");
    printf("         FRENADO AERODINAMICO ORION          \n");
    printf("=============================================\n");
    
    double ei = calcularEnergiaCinetica(nave->masa, nave->velocidad) + calcularEnergiaPotencial(nave->masa, nave->altitud);
    double ef = calcularEnergiaCinetica(nave->masa, velocidadFinal) + calcularEnergiaPotencial(nave->masa, altitudFinal);
    
    double trabajo = calcularTrabajoFriccion(ef, ei);

    // Mostrar los resultados de forma ordenada y profesional
    printf(" > Masa de la nave:            %.2f kg\n", nave->masa);
    printf(" > Altitud inicial / final:    %.2f m / %.2f m\n", nave->altitud, altitudFinal);
    printf(" > Velocidad inicial / final:  %.2f m/s / %.2f m/s\n", nave->velocidad, velocidadFinal);
    printf(" > Energía Mecánica Inicial:   %.3e J\n", ei);
    printf(" > Energía Mecánica Final:     %.3e J\n", ef);
    printf(" > Trabajo de Fricción (W_roz):  %.3e J\n", trabajo);
    printf("---------------------------------------------\n");
}