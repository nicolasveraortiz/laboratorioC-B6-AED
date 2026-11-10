#pragma once
#include "artemis.h"

void mostrarMenu();
void arteIntro();
void procesoEjecutar(int opcion, CapsulaOrion *nave);

int leerEntero(int min, int max);
double leerRealPositivo(double min, double max, char *msg);
