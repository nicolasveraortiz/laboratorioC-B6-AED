@echo off
cd /d "%~dp0"

where gcc >nul 2>&1
if errorlevel 1 (
    echo Error: no se encontro 'gcc' en el PATH. 1>&2
    echo Instale MinGW-w64 o MSYS2 y agregue su carpeta bin al PATH. 1>&2
    exit /b 1
)

gcc ./src/main.c ./src/artemis.c ./src/validaciones.c -o artemis
if errorlevel 1 (
    echo Error: la compilacion fallo. 1>&2
    exit /b 1
)

chcp 65001

echo Compilacion exitosa: artemis.exe