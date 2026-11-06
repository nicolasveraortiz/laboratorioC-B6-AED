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

// Funciones de conversion mas utilitarias
float a_en_g(double a){
    // Funcion para expresar aceleracion en multiplos de gravedad
    // La funcion recibe la aceleracion en m/s
    float res = a / GRAVEDAD;

    return res;
}

// Funcion universal de conversion de unidades donde 'unidad_original' y 'unidad_buscadad' deben ser equivalentes
double conversor(double valor, double unidad_original, double unidad_buscada){
    double res = valor * unidad_original / unidad_buscada;
    return res;
}