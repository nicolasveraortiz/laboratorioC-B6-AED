#pragma once

typedef struct {
    double masa;             // kg
    double altitud;          // metros
    double velocidad;        // m/s
    double anguloReingreso;  // °
} CapsulaOrion;

#define GRAVEDAD 9.8066
#define MASA_CAPSULA 10400.0 // <-- [kg]
#define VELOCIDAD_INICIAL 11000.0 // <-- [m/s]
#define ALTITUD_REINGRESO 120.0 // <-- [km]
#define VELOCIDAD_DE_PARACAIDAS 25.0 // <-- [m/s]
#define ALTITUD_PARACAIDAS 2.5 // <-- [km]
#define VELOCIDAD_IMPACTO 8.0 // <-- [m/s]

void resolverFrenadoAerodinamico(CapsulaOrion *nave);
void resolverDesaceleracionTripulacion(CapsulaOrion *nave);
void resolverAmerizajeImpacto(CapsulaOrion *nave);
void evaluarVentanaReingreso(CapsulaOrion *nave);

double calcularEnergiaCinetica(double masa, double velocidad);
double calcularEnergiaPotencial(double masa, double altitud);
double calcularTrabajoFriccion(double energiaMecanicaFinal, double energiaMecanicaInicial);
double calcularDesaceleracion(double vInicial, double vFinal, double tiempo);
double calcularFuerzaImpacto(double masa, double velocidad, double distanciaHundimiento);

float a_en_g(double a);
double conversor(double valor, double unidad_original, double unidad_buscada);
