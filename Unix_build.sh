#!/bin/sh
set -e

# Se posiciona en la raiz del proyecto para que las rutas relativas funcionen.
cd "$(dirname "$0")"

if ! command -v gcc >/dev/null 2>&1; then
    echo "Error: no se encontró 'gcc' en el PATH." >&2
    echo "macOS: instalar con 'xcode-select --install'. Linux: instalar el paquete 'gcc' o 'build-essential'." >&2
    exit 1
fi

gcc ./src/main.c ./src/artemis.c ./src/validaciones.c -o artemis

echo "Compilación exitosa: ./artemis"