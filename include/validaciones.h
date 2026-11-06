#pragma once
#include "artemis.h"

void mostrarMenu();
void arteIntro();
void procesoEjecutar(int opcion, CapsulaOrion *nave);

double solicitar_double();
// float solicitar_float();
double solicitar_double_positivo(char *msg);
int solicitar_entero();
