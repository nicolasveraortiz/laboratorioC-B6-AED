#include <stdio.h>
#include "../include/artemis.h"

// IMPLEMENTACIÓN DE FUNCIONES FÍSICAS

double calcularEnergiaCinetica(double masa, double velocidad) {
    return 0.5 * masa * velocidad * velocidad;
}

double calcularEnergiaPotencial(double masa, double altitud) {
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
    double peso = masa * GRAVEDAD;
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

void resolverDesaceleracionTripulacion(CapsulaOrion *nave) {
    double tiempoFrenado;
    double velocidadFinal =25.0; 
    printf("FASE 2: Desaceleracion de la Tripulacion");
    printf("Velocidad de ingreso: %.2fm/s\n", nave->velocidad);
    printf("velocidad de despliegue de paracaidas: %.2f m/s\n", velocidadFinal);
    printf("Ingrese el tiempo esperado de la fase de mayor frenado en segundos (ej: 400.0): ");
    scanf("%lf", &tiempoFrenado);
    //funcion matematica: 
    double aceleracion = calcularDesaceleracion(nave->velocidad, velocidadFinal, tiempoFrenado);
    double fuerzaG = a_en_g(aceleracion);
    printf("\n[REPORTE DE DESACELERACION]\n");
    printf("> Desaceleracion media: %.2f m/s^2\n", aceleracion);
    // Uso -fuerzag porque la aceleracion es negativa por frenado, asi mostramos Gs positivos
    printf("> Fuerza G soportada por los astronautas: %.2f G\n", -fuerzaG);
    
    if (-fuerzaG > 9.0) {
        //Advertencia creada:
        printf("[ALERTA CRITICA] Riesgo de perdida de conocimiento inducida por fuerzas G (G-LOC).\n");
    }   else {
        printf("[ESTADO] Fuerzas G dentro de los parametros de supervivencia.\n");
    }
}

void resolverAmerizajeImpacto(CapsulaOrion *nave) {
    double distanciaHundimiento;
    //segun escenario la capsula toca el agua a 8.0m/s
    double velocidadImpacto = 8.0;
    printf("\n-- FASE 3: AMERIZAJE EN EL OCEANO PACIFICO ---\n");
    printf("Masa de la capsula: %.2f kg\n", nave->masa);
    printf("Velocidad de impacto contra el agua: %.2f m/s\n", velocidadImpacto);

    printf("Ingrese la profundidad de hundimiento en el agua en metros (ej. 1.50): ");
    scanf("%lf", &distanciaHundimiento);
    //funcion matematica:
    double fuerzaTotal = calcularFuerzaImpacto(nave->masa, velocidadImpacto, distanciaHundimiento);
    //comparo la fuerza del impacto contra el peso normal de la nave 
    double pesoNave = nave->masa * GRAVEDAD;
    double multiplicadorPeso = fuerzaTotal / pesoNave; 

    printf("\n[REPORTE DE IMPACTO ESTRUCTURAL]\n");
    printf("> Fuerza total absorbida por el escudo: %.2f N\n", fuerzaTotal);
    printf("> El impacto equivale a %.2f veces el propio peso de la capsula.\n", multiplicadorPeso);
}

void evaluarVentanaReingreso (CapsulaOrion *nave) {
    float angulo;
    
    printf("\n=============================================\n");
    printf("          EVALUACION DE ANGULO DE REINGRESO           \n");
    printf("=============================================\n");

    // printf("Ingrese un angulo de reingreso: ");
    // angulo = solicitar_float_positivo();

    printf(" > Angulo de reingreso (gamma) actual: %.2f°\n" , nave->anguloReingreso);

    if (nave->anguloReingreso < 5.5) {
        printf(" [ALERTA] Ángulo por debajo del rango (< 5,5°). La nave rebotará hacia el espacio.\n");
    } else if (nave->anguloReingreso > 7.0) {
        printf(" [ALERTA] Ángulo por encima del rango (> 7.0°). La nave se desintegrará.\n");
    } else {
        printf(" [TRAYECTORIA SEGURA] Ángulo de reingreso dentro del rango esperado (5,5° - 7.0°).\n");
    }
}

void modificarDatosNave(CapsulaOrion *nave){
    printf("\n--- ACTUALIZACION DE PARAMETROS ---\n");
    printf("Actuales datos de la nave:\n");
    printf("masa de la nave: %.2lf kg\n", nave->masa);
    printf("altitud de reingreso de nave: %.2lf m\n", nave->altitud);
    printf("velocdad inicial de la nave: %.2lf m/s\n", nave->velocidad);
    printf("angulo de reingreso de la nave: %.2lf°\n", nave->anguloReingreso);

    double nmasa = nave->masa;                        // kg
    double naltitud = nave->altitud;                  // metros
    double nvelocidad = nave->velocidad;              // m/s
    double nanguloReingreso = nave->anguloReingreso;  // °
    
    printf("\nSi desea mantener el valor actual, ingrese -1.\n");
    
    printf("\nIngrese la nueva masa para la nave: ");
    scanf("%lf", &nmasa);
    if (nmasa >= 0) { nave->masa = nmasa; }
    printf("\nIngrese la nueva altitud de reingreso para la nave: ");
    scanf("%lf", &naltitud);
    if (naltitud >= 0) { nave->altitud = naltitud; }
    printf("\nIngrese la nueva velocidad inicial para la nave: ");
    scanf("%lf", &nvelocidad);
    if (nvelocidad >= 0) { nave->velocidad = nvelocidad; }
    printf("\nIngrese el nuevo angulo de reingreso para la nave: ");
    scanf("%lf", &nanguloReingreso);
    if (nanguloReingreso >= 0) { nave->anguloReingreso = nanguloReingreso; }

    printf("Actuales datos de la nave:\n");
    printf("Masa de la nave: %.2lf kg\n", nave->masa);
    printf("Altitud de reingreso de nave: %.2lf m\n", nave->altitud);
    printf("Velocdad inicial de la nave: %.2lf m/s\n", nave->velocidad);
    printf("Angulo de reingreso de la nave: %.2lf°\n", nave->anguloReingreso);
}

void valoresPredeterminadoDeNave(CapsulaOrion *nave){
    nave->masa = MASA_CAPSULA;
    nave->altitud = ALTITUD_REINGRESO;
    nave->velocidad = VELOCIDAD_INICIAL;
    nave->anguloReingreso = 6.2;

    printf("Insertando valores predeterminados de la nave:\n");
    printf("masa de la nave: %lfkg\n", nave->masa);
    printf("altitud de reingreso de nave: %lfm\n", nave->altitud);
    printf("velocdad inicial de la nave: %lfm/s\n", nave->velocidad);
    printf("angulo de reingreso de la nave: %lf°\n", nave->anguloReingreso);
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

// Implementacion de persistencia de datos (en json)
void generarInformeJSON(CapsulaOrion *nave) {
    // Abrir o crear el archivo en modo escritura ("w" de write)
    FILE *archivo = fopen("reporte_artemis.json", "w");
    
    if (archivo == NULL) {
        printf("\n[ERROR] No se pudo crear el archivo JSON.\n");
        return;
    }

    fprintf(archivo, "{\n");
    fprintf(archivo, "  \"CapsulaOrion\": {\n");
    fprintf(archivo, "    \"masa_kg\": %.2f,\n", nave->masa);
    fprintf(archivo, "    \"altitud_m\": %.2f,\n", nave->altitud);
    fprintf(archivo, "    \"velocidad_ms\": %.2f,\n", nave->velocidad);
    fprintf(archivo, "    \"anguloReingreso_grados\": %.2f\n", nave->anguloReingreso);
    fprintf(archivo, "  }\n");
    fprintf(archivo, "}\n");

    fclose(archivo);
    
    printf("\n[SISTEMA] Informe JSON generado exitosamente en 'reporte_artemis.json'.\n");
}