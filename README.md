# Simulador de Misiones Artemis: Reingreso, Frenado Aerodinámico y Amerizaje

**Universidad Tecnológica Nacional, Facultad Regional Resistencia**
**Cátedra:** Algoritmos y Estructuras de Datos, Ingeniería en Sistemas de Información.
**Trabajo Práctico Integrador Final**
**Grupo:** B6.

## a) Integrantes y comisión

| Integrante | Rol / módulos principales |
|---|---|
| Santiago Solari| - |
| Santiago Emmanuel Enriquez | - |
| Santiago Mac Donald| - |
| Luciano Gabriel Pereyra Brest| - |
| Clivio Nicolás Vera Ortiz | - |

**Comisión:** K1.2
**Video de presentación:** -

---

## b) Descripción del escenario asignado y reglas

**Escenario asignado: Situación-Problema 4. Reingreso atmosférico, frenado aerodinámico y amerizaje (Trabajo, Energía e Impacto).**

Tras el sobrevuelo lunar, el módulo de tripulación Orion se separa del módulo de servicio y reingresa a la atmósfera terrestre. El programa simula las tres fases del retorno y permite analizar cada una a partir de un menú interactivo.

### Datos predeterminados de la misión

| Magnitud | Valor |
|---|---|
| Masa de la cápsula | 10.400,0 kg |
| Altitud de reingreso | 120.000,0 m (120 km) |
| Velocidad de reingreso | 11.000,0 m/s (≈ 39.600 km/h, Mach 32) |
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
5. **Modificar datos nave.** El programa ofrece al usuario cambiar los valores actuales del registro de la nave, esto permite explorar otras posibilidades. La configuración se cambia en .cfg y tiene su respectivo sistema de manejo de errores típicos.

### Reglas de uso

- El programa corre por consola y se maneja con un menú numérico.
- Cada opción ejecuta una fase de forma independiente sobre los datos de la cápsula.
- Las fases 2 y 3 piden un dato al usuario, que debe ser un número real positivo.
- La opción 5 cierra el programa.

---

## c) Funcionamiento

### Menú principal

```
1. Resolver frenado aerodinamico
2. Resolver desaceleracion de la tripulacion
3. Resolver impacto del amerizaje
4. Evaluar reingreso a la atmósfera
5. Modificar datos nave
0. Cerrar el programa
```

Al iniciar, el programa muestra un banner de bienvenida y el menú. Tras ejecutar una opción vuelve al menú, hasta que el usuario elige la opción 5. Existe además un **modo de depuración** (código oculto `6010`) pensado para el equipo de desarrollo, que permite probar funciones auxiliares, como la de ingreso seguro de números, de forma aislada.

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
| `artemis.h` | Define el tipo estructurado `CapsulaOrion` (masa, altitud, velocidad, ángulo de reingreso), las constantes de la misión (`#define`) y los prototipos públicos. |
| `artemis.c` | Implementa las funciones físicas puras (`calcularEnergiaCinetica`, `calcularEnergiaPotencial`, `calcularTrabajoFriccion`, `calcularDesaceleracion`, `calcularFuerzaImpacto`), las funciones de cada fase del menú (`resolverFrenadoAerodinamico`, `resolverDesaceleracionTripulacion`, `resolverAmerizajeImpacto`, `evaluarVentanaReingreso`) y utilidades de conversión (`a_en_g`, `conversor`). |
| `validaciones.c/.h` | Interfaz de consola (`arteIntro`, `mostrarMenu`), despacho de opciones (`procesoEjecutar`), modo depuración y la función de ingreso seguro `solicitar_double_positivo`. |

### Decisiones de diseño

- **Estructura `CapsulaOrion` por puntero.** El estado de la nave se declara una vez en `main` y se pasa por puntero (`CapsulaOrion *nave`) a cada fase. Así todas las funciones comparten los mismos datos sin copiarlos ni usar variables globales.
- **Separación entre cálculo y presentación.** Las funciones `calcular...` reciben valores y devuelven un resultado, sin imprimir nada. Las funciones `resolver...` leen datos, llaman a las de cálculo y muestran el reporte. Esto evita código duplicado y facilita probar cada fórmula por separado.
- **Constantes con nombre.** Los datos de la misión y la gravedad están definidos con `#define` en `artemis.h`, para no repetir números en el código.
- **Cálculo energético del frenado.** El trabajo de rozamiento se obtiene por el principio de conservación de la energía mecánica (`Em = K + U`), tomando como estado inicial el reingreso y como estado final la apertura de paracaídas.
- **Ingreso seguro con `fgets` y `strtod`.** La función `solicitar_double_positivo` lee una línea completa y la convierte con `strtod`, verificando que se haya leído un número, que no haya caracteres sobrantes, que el valor no se salga del rango de `double` y que sea positivo. De este modo una entrada inválida no deja basura en el buffer de entrada.

---

## d) Compilación y ejecución

### Requisitos

- Compilador `gcc` (o compatible con C99 o superior).
- Terminal con soporte UTF-8 para ver correctamente el banner y los caracteres especiales.

### Compilación

Desde la raíz del repositorio:

```bash
gcc -Wall -Wextra -o artemis src/main.c src/artemis.c src/validaciones.c
```

### Ejecución

```bash
./artemis        # Linux / macOS
artemis.exe      # Windows
```

---

## e) Registro de uso de Inteligencia Artificial

Conforme a lo exigido por la cátedra, se registra el uso de herramientas de IA generativa. Los integrantes validaron el código propuesto compilándolo, probándolo con entradas normales y erróneas, y adaptándolo al estilo del proyecto. Las consultas realizadas corresponden en su gran mayoria a preguntas sobre sintaxis, manejo de punteros, y errores de compilación

| Herramienta | Tarea | Consulta realizada | Cómo se validó / adaptó |
|---|---|---|---|
| Claude (Anthropic) | Depuración de entrada de datos | Se consultó por qué, al ingresar una letra en el menú, el programa entraba en un bucle infinito mostrando "Opción inválida". | Se comprendió que `scanf("%d")` no consume el carácter inválido y deja basura en el buffer. Se probó con `a`, `abc` y `3abc`, y se adaptó la solución para aplicarla a todos los puntos de ingreso de datos. |
| Claude (Anthropic) | Revisión de `solicitar_double_positivo` | Se consultaron los errores de la función de ingreso seguro (tamaño del buffer en `fgets`, memoria dinámica sin liberar, precedencia de operadores en la condición). | Se corrigió el uso de `sizeof`, se evaluó reemplazar el `malloc` por un arreglo local y se agregaron paréntesis a la condición. |
