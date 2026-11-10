#include <stdio.h>
#include <string.h>
#include "../include/artemis.h"
#include "../include/validaciones.h"

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
    double velocidadFinal =25.0; 
    printf("FASE 2: Desaceleracion de la Tripulacion");
    printf("Velocidad de ingreso: %.2fm/s\n", nave->velocidad);
    printf("velocidad de despliegue de paracaidas: %.2f m/s\n", velocidadFinal);
    double tiempoFrenado = leerRealPositivo(0.001, 3600.0, "Ingrese el tiempo esperado de la fase de mayor frenado en segundos (ej: 400.0): ");
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
    //segun escenario la capsula toca el agua a 8.0m/s
    double velocidadImpacto = 8.0;
    printf("\n-- FASE 3: AMERIZAJE EN EL OCEANO PACIFICO ---\n");
    printf("Masa de la capsula: %.2f kg\n", nave->masa);
    printf("Velocidad de impacto contra el agua: %.2f m/s\n", velocidadImpacto);
    double distanciaHundimiento = leerRealPositivo(0.001, 50.0, "Ingrese la profundidad de hundimiento en el agua en metros (ej. 1.50): ");
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

// funciones relacionadas con la generacion, carga o manipulacion de un archivo

void mostrarDatosNave(const CapsulaOrion *nave) {
    printf("Masa de la nave: %.2f kg\n", nave->masa);
    printf("Altitud de reingreso: %.2f m\n", nave->altitud);
    printf("Velocidad inicial: %.2f m/s\n", nave->velocidad);
    printf("Angulo de reingreso: %.2f°\n", nave->anguloReingreso);
}


void modificarDatosNave(CapsulaOrion *nave){
    double nuevo;

    printf("\n--- ACTUALIZACION DE PARAMETROS ---\n");
    printf("Datos actuales de la nave:\n");
    mostrarDatosNave(nave);
    printf("\nPara mantener el valor actual, ingrese 0.\n\n");

    nuevo = leerRealPositivo(0, 1000000.0, "Nueva masa (kg): ");
    if (nuevo > 0) { nave->masa = nuevo; }

    nuevo = leerRealPositivo(0, 1000000.0, "Nueva altitud de reingreso (m): ");
    if (nuevo > 0) { nave->altitud = nuevo; }

    nuevo = leerRealPositivo(0, 20000.0, "Nueva velocidad inicial (m/s): ");
    if (nuevo > 0) { nave->velocidad = nuevo; }

    nuevo = leerRealPositivo(0, 90.0, "Nuevo angulo de reingreso (grados): ");
    if (nuevo > 0) { nave->anguloReingreso = nuevo; }

    printf("\nDatos actualizados de la nave:\n");
    mostrarDatosNave(nave);

    if (guardarDatosNave(nave, ARCHIVO_CONFIG)) {
        printf("[SISTEMA] Cambios guardados en '%s'.\n", ARCHIVO_CONFIG);
    } else {
        printf("[ERROR] No se pudo guardar en '%s'. Los cambios valen solo en esta ejecucion.\n", ARCHIVO_CONFIG);
    }
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

//Lectura y Validacion de Datos de JSON cargado 
int guardarDatosNave(const CapsulaOrion *nave, const char *ruta) {
    FILE *archivo = fopen(ruta, "w");
    if (archivo == NULL) {
        return 0;
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
    return 1;
}

// Lee un JSON y carga los datos en la nave. Devuelve 1 si pudo, 0 si fallo.
// Si falla, la nave queda exactamente como estaba.
int cargarDatosNave(CapsulaOrion *nave, const char *ruta) {
    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL) {
        return 0; 
    }

    CapsulaOrion temporal = *nave;   // copia de trabajo
    int encontrados = 0;             // cuantos datos se leyeron bien
    char linea[150];

    while (fgets(linea, sizeof(linea), archivo)) {
        char *dosPuntos = strstr(linea, ":");
        if (dosPuntos != NULL) {
            if (strstr(linea, "\"masa_kg\"")) {
                if (sscanf(dosPuntos + 1, "%lf", &temporal.masa) == 1) { encontrados++; }
            } else if (strstr(linea, "\"altitud_m\"")) {
                if (sscanf(dosPuntos + 1, "%lf", &temporal.altitud) == 1) { encontrados++; }
            } else if (strstr(linea, "\"velocidad_ms\"")) {
                if (sscanf(dosPuntos + 1, "%lf", &temporal.velocidad) == 1) { encontrados++; }
            } else if (strstr(linea, "\"anguloReingreso_grados\"")) {
                if (sscanf(dosPuntos + 1, "%lf", &temporal.anguloReingreso) == 1) { encontrados++; }
            }
        }
    }
    fclose(archivo);

    // Tienen que estar los 4 datos
    if (encontrados != 4) {
        return 0;
    }
    // Los valores tienen que ser fisicamente posibles
    if (temporal.masa <= 0 || temporal.altitud <= 0 ||
        temporal.velocidad <= 0 || temporal.anguloReingreso <= 0) {
        return 0;
    }

    *nave = temporal;   // recien ahora se modifica la nave real
    return 1;
}

void cargarPresetDesdeArchivo(CapsulaOrion *nave) {
    char ruta[256];

    printf("\n--- CARGAR PRESET DESDE ARCHIVO JSON ---\n");
    printf("Ingrese la ruta del archivo (o presione Enter para cancelar): ");
    fgets(ruta, sizeof(ruta), stdin);

    // Sacamos el salto de linea que deja fgets
    if (strlen(ruta) > 0 && ruta[strlen(ruta) - 1] == '\n') {
        ruta[strlen(ruta) - 1] = '\0';
    }

    if (strlen(ruta) == 0) {
        printf("[SISTEMA] Operacion cancelada.\n");
        return;
    }

    if (cargarDatosNave(nave, ruta)) {
        printf("[SISTEMA] Preset cargado con exito:\n");
        mostrarDatosNave(nave);

        // Guardamos tambien en el archivo de configuracion para que quede igual al iniciar
        if (guardarDatosNave(nave, ARCHIVO_CONFIG)) {
            printf("[SISTEMA] Datos guardados tambien en '%s'.\n", ARCHIVO_CONFIG);
        } else {
            printf("[ERROR] No se pudo guardar en '%s'.\n", ARCHIVO_CONFIG);
        }
    } else {
        printf("[ERROR] No se pudo cargar '%s' (no existe, esta corrupto o los valores son imposibles).\n", ruta);
        printf("[SISTEMA] Se mantienen los datos actuales de la nave.\n");
    }
}

void generarInformeJSON(CapsulaOrion *nave) { // AUN NO HACE NADA RELEVANTE, DESARROLLAR
    if (guardarDatosNave(nave, "reporte_artemis.json")) {
        printf("\n[SISTEMA] Informe JSON generado en 'reporte_artemis.json'.\n");
    } else {
        printf("\n[ERROR] No se pudo crear el archivo JSON.\n");
    }
}