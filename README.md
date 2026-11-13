# Simulador de Misiones Artemis: Reingreso, Frenado Aerodinámico y Amerizaje

**Universidad Tecnológica Nacional, Facultad Regional Resistencia**
**Cátedra:** Algoritmos y Estructuras de Datos, Ingeniería en Sistemas de Información.
**Trabajo Práctico Integrador Final**
**Grupo:** B6.

## a) Integrantes y comisión

### Integrante 

| Integrantes |
| --- |
| Santiago Solari |
| Santiago Emmanuel Enriquez |
| Santiago Mac Donald |
| Luciano Gabriel Pereyra Brest |
| Clivio Nicolás Vera Ortiz |

**Comisión:** K1.2
**Video de presentación:** https://drive.google.com/file/d/1suVy8tuOP27-lO_H0Oq32eTJWqctcWX7/view?usp=sharing

---

## b) Descripción del escenario asignado y reglas

**Escenario asignado: Situación-Problema 4. Reingreso atmosférico, frenado aerodinámico y amerizaje (Trabajo, Energía e Impacto).**

Tras el sobrevuelo lunar, el módulo de tripulación Orion se separa del módulo de servicio y reingresa a la atmósfera terrestre. El programa simula las tres fases del retorno y permite analizar cada una a partir de un menú interactivo.

### Datos predeterminados de la misión

| Magnitud | Valor |
|---|---|
| Masa de la cápsula | 10.400,0 kg |
| Altitud de reingreso | 120.000,0 m (120 km) |
| Velocidad de reingreso | 11.000,0 m/s (≈ 39.600 km/h) |
| Ángulo de reingreso (γ) | 6,2° |
| Velocidad de despliegue de paracaídas | 25,0 m/s |
| Altitud de despliegue de paracaídas | 2.500,0 m (2,5 km) |
| Velocidad de impacto con el agua | 8,0 m/s |
| Gravedad | g = 9,8066 m/s² |

### Funciones

1. **Frenado aerodinámico.** El escudo térmico disipa la energía de la cápsula mediante la fuerza de rozamiento del aire. El programa calcula la energía mecánica inicial (reingreso) y final (apertura de paracaídas) de la configuración actual, y obtiene el trabajo de la fuerza de rozamiento como la variación de energía mecánica: `Wroz = Efinal − Einicial`. 
2. **Desaceleración de la tripulación.** El usuario ingresa la duración de la fase de mayor frenado (por ejemplo, 400 s). El programa calcula la desaceleración media `a = (vf − vi) / Δt` y la expresa en múltiplos de g. Si la carga supera **9 G**, informa una **alerta crítica** por riesgo de pérdida de conocimiento inducida por fuerzas G. En caso contrario, informa que las fuerzas G están dentro de los parámetros de supervivencia.
3. **Amerizaje.** La cápsula toca el agua a una velocidad configurable en m/s (8.0 m/s por predeterminado). El usuario ingresa la profundidad de hundimiento y el programa calcula la fuerza promedio sobre la estructura: `F = m·g + m·v² / (2·d)`. También informa cuántas veces el peso de la nave equivale esa fuerza.
4. **Evaluación del ángulo de reingreso.** El programa compara el ángulo γ de la nave con la ventana de seguridad **5,5° ≤ γ ≤ 7,0°**:
   - γ < 5,5°: la nave rebota hacia el espacio (rebote atmosférico).
   - γ > 7,0°: desaceleración excesiva, la nave se desintegra.
   - Dentro del rango: trayectoria segura.
5. **Modificar datos nave.** El programa ofrece al usuario cambiar los valores actuales del registro de la nave, esto permite explorar otras posibilidades. La configuración se cambia en sobre el registro de los datos actuales, tiene su respectivo sistema de manejo de errores típicos y guarda la configuracion nueva en un archivo .json.
6. **Cargar preset de archivo JSON.** Permite al usuario modificar los datos de la nave indicando la ruta a un archivo .json que contenga esa configuracion de nave con el formato correcto, verifica el formato de los datos y coherencia de los mismos. 
7. **Restablecer valores predeterminados**. Si el usuario luego de modificar los valores de la nave quisiera volver a los datos originales sin escribirlos manualmente, esta funcion lo hace de forma automatica.

### Reglas de uso

- El programa corre por consola y se maneja con un menú numérico del 0 al 7.
- Cada opción ejecuta una fase de forma independiente sobre los datos de la cápsula.
- Las fases 2 y 3 piden un dato al usuario, que debe ser un número real positivo.
- La opción 5 solicita al usuario valores nuevos para la nave dentro de un rango especificado en la misma funcion.
- La opcion 6 solicita al usuario un ruta valida, de no serlo o de contener el .json valores no validos no se utiliza.

---

## c) Funcionamiento

### Menú principal

```
1. Resolver frenado aerodinamico
2. Resolver desaceleracion de la tripulacion
3. Resolver impacto del amerizaje
4. Evaluar reingreso a la atmósfera
5. Modificar datos de la nave
6. Cargar preset desde archivo JSON
7. Restablecer valores predeterminados
0. Cerrar el programa
```

Al iniciar, el programa muestra un banner de bienvenida y el menú. Tras ejecutar una opción vuelve al menú, hasta que el usuario elige la opción 0.

### Ejemplo de ejecución (valores iniciales de la misión)

| Opción | Dato ingresado | Resultado aproximado |
|---|---|---|
| 1. Frenado aerodinámico | (ninguno) | E. mecánica inicial ≈ 6,414·10¹¹ J, final ≈ 2,582·10⁸ J, **W_roz ≈ −6,412·10¹¹ J** |
| 2. Desaceleración | Δt = 400 s | a ≈ −27,44 m/s² ≈ **2,80 G**, dentro de parámetros de supervivencia |
| 3. Amerizaje | d = 1,50 m | F ≈ 3,24·10⁵ N ≈ **3,18 veces el peso** de la cápsula |
| 4. Ventana de reingreso | (ninguno) | γ = 6,2°, **trayectoria segura** |

### Arquitectura del código

```
proyecto/
├── include/
│   ├── artemis.h          # struct, constantes y prototipos de la lógica física
│   └── validaciones.h     # prototipos de interfaz, menú y entrada de datos
├── src/
│   ├── main.c             # función main y ciclo del menú principal
│   ├── artemis.c          # cálculos físicos y fases de la simulación
│   └── validaciones.c     # interfaz de consola, despacho del menú y entrada segura
└── README.md
```

| Módulo | Responsabilidad |
|---|---|
| `main.c` | Contiene únicamente `main()`. Inicializa la cápsula, muestra la intro y ejecuta el ciclo del menú hasta que se elige salir. |
| `artemis.h` | Define el tipo estructurado `CapsulaOrion` (masa, altitud, velocidad, ángulo de reingreso) y las constantes de la misión (`#define`). |
| `artemis.c` | Implementa las funciones físicas puras (`calcularEnergiaCinetica`, `calcularEnergiaPotencial`, `calcularTrabajoFriccion`, `calcularDesaceleracion`, `calcularFuerzaImpacto`), las funciones de cada fase del menú (`resolverFrenadoAerodinamico`, `resolverDesaceleracionTripulacion`, `resolverAmerizajeImpacto`, `evaluarVentanaReingreso`) y utilidades de conversión (`a_en_g`). |
| `validaciones.c/.h` | Interfaz de consola (`arteIntro`, `mostrarMenu`), despacho de opciones (`procesoEjecutar`), entrada de enteros positivos (`leerEntero`) y entrada de reales positivos (`leerRealPositivo`). |

### Decisiones de diseño

- **Estructura `CapsulaOrion` por puntero.** El estado de la nave se declara una vez en `main` y se pasa por puntero (`CapsulaOrion *nave`) a cada fase. Así todas las funciones comparten los mismos datos sin copiarlos ni usar variables globales.
- **Separación entre cálculo y presentación.** Las funciones `calcular...` reciben valores y devuelven un resultado, sin imprimir nada. Las funciones `resolver...` leen datos, llaman a las de cálculo y muestran el reporte. Esto evita código duplicado y facilita probar cada fórmula por separado.
- **Constantes con nombre.** Los datos de la misión y la gravedad están definidos con `#define` en `artemis.h`, para no repetir números en el código.
- **Cálculo energético del frenado.** El trabajo de rozamiento se obtiene por el principio de conservación de la energía mecánica (`Em = K + U`), tomando como estado inicial el reingreso y como estado final la apertura de paracaídas.

---

## d) Compilación y ejecución

### Requisitos

- Compilador `gcc` (o compatible con C99 o superior).
- Terminal con soporte UTF-8 para ver correctamente el banner y los caracteres especiales.

### Compilación

En una terminal, desde la raiz del proyecto, ejecutar de los siguiente el script correspondiente al sistema operativo utilizado:
- macOS / Linux:  sh ./Unix_build.sh
- Windows:        ./Windows_build.bat

En caso de generar un error de compilacion, ejecutar el siguiente comando para compilar el proyecto manualmente. Desde la raíz del repositorio, basta con copiar y pegar el siguiente comando:

```bash
gcc ./src/main.c ./src/artemis.c ./src/validaciones.c -o artemis
```

> Si, en Windows, en lugar de utilizar el script se ejecutó el ultimo comando, se recomienda ejecutar el siguiente comando posteriormente al anterior para el correcto muestreo del diseño o banners en la consola:
```bash
chcp 65001
```

### Ejecución

Una vez ejecutado el script anterior se generará un archivo ejecutable desde la terminal, con el se da inicio al programa.
```bash
./artemis        # generado localmente no depende de que S.O. se utilice.
```

---

## e) Registro de uso de Inteligencia Artificial

Conforme a lo exigido por la cátedra, se registra el uso de herramientas de IA generativa. Los integrantes validaron el código propuesto compilándolo, probándolo con entradas normales y erróneas, y adaptándolo al estilo del proyecto. Las consultas realizadas corresponden en su gran mayoria a preguntas sobre sintaxis, manejo de punteros, y errores de compilación

| Herramienta | Tarea | Consulta realizada | Cómo se validó / adaptó |
|---|---|---|---|
| Claude (Anthropic) | Depuración de entrada de datos | Se consultó por qué, al ingresar una letra en el menú, el programa entraba en un bucle infinito mostrando "Opción inválida". | Se comprendió que `scanf("%d")` no consume el carácter inválido y deja basura en el buffer. Se probó con `a`, `abc` y `3abc`, y se adaptó la solución para aplicarla a todos los puntos de ingreso de datos. |
| Claude (Anthropic) | Revisión de `solicitar_double_positivo` | Se consultaron los errores de la función de ingreso seguro (tamaño del buffer en `fgets`, memoria dinámica sin liberar, precedencia de operadores en la condición). | Se corrigió el uso de `sizeof`, se evaluó reemplazar el `malloc` por un arreglo local y se agregaron paréntesis a la condición. | 
| Claude (Anthropic) | Generacion de script `.sh` y `.bat` | En orden de que el usuario no necesite ejecutar el comando de compilacion del proyecto manualmente, se solicitó la generacion de un script para la creacion del ejecutable del proyecto | Se implementó el script tanto para sistemas basado en Unix (MacOS/Linux -> .sh) como para sistemas Windows (.bat). Al contar con un script ejecutable para estos sistemas operativos, nos aseguramos de que cualquiera puede compilar el programa de forma sencilla.|
| Gemini (Google) | Ayuda para comprender y manipular archivos JSON| Se solicitaron ejemplos de códigos sencillos para manipular JSON y una lista de errores cómunes | Se generaron multiples funciones para manipular el JSON de datos.|