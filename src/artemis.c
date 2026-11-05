#include <stdio.h>
#include "../include/artemis.h"

// IMPLEMENTACIÓN DE FUNCIONES FÍSICAS

double calcularEnergiaCinetica(double masa, double velocidad) {
    return 0.5 * masa * velocidad * velocidad;
}

double calcularEnergiaPotencial(double masa, double altitud) {
    // const double g = 9.81;
    return masa * GRAVEDAD * altitud;
}

double calcularTrabajoFriccion(double energiaMecanicaFinal, double energiaMecanicaInicial) {
    return energiaMecanicaFinal - energiaMecanicaInicial; // Negativo porque disipa energía
}

double calcularDesaceleracion(double vInicial, double vFinal, double tiempo) {
    if (tiempo <= 0) return 0.0;
    return (vFinal - vInicial) / tiempo;
}

double calcularFuerzaImpacto(double masa, double velocidad, double distanciaHundimiento) {
    // const double g = 9.81;
    double peso = masa * GRAVEDAD;
    if (distanciaHundimiento <= 0) return peso;
    double fuerzaDinamica = (masa * velocidad * velocidad) / (2.0 * distanciaHundimiento);
    return peso + fuerzaDinamica;
}