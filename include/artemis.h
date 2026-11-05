#pragma once

typedef struct {
    double masa;             // kg
    double altitud;          // metros
    double velocidad;        // m/s
    double anguloReingreso;  // °
} CapsulaOrion;

void resolverFrenadoAerodinamico(CapsulaOrion *nave);
void resolverDesaceleracionTripulacion(CapsulaOrion *nave);
void resolverAmerizajeImpacto(CapsulaOrion *nave);
void evaluarVentanaReingreso(CapsulaOrion *nave);

double calcularEnergiaCinetica(double masa, double velocidad);
double calcularEnergiaPotencial(double masa, double altitud);
double calcularTrabajoFriccion(double energiaMecanicaFinal, double energiaMecanicaInicial);
double calcularDesaceleracion(double vInicial, double vFinal, double tiempo);
double calcularFuerzaImpacto(double masa, double velocidad, double distanciaHundimiento);