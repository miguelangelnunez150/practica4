# Procesamiento de Matrices Táctiles en Gripper Robótico mediante C++ y Python

## 1. Descripción

Este proyecto implementa el pipeline de captura, validación y escalado de datos de presión para un sensor táctil robótico. El sistema cliente en C++ se encarga de la carga del dataset JSON, el filtrado por dimensiones y la interpolación bilineal manual, transmitiendo los resultados mediante peticiones HTTP POST hacia un servidor web en Python para su posterior representación gráfica.

---

## 2. Estructura del proyecto

```text
├── servidor.py              # Script del servidor Python
├── procesador.cpp           # Funciones de filtrado e interpolación
├── main.cpp                 # Flujo de ejecución principal
├── procesador.h             # Prototipos y cabeceras
├── cliente                  # Ejecutable compilado
├── imagenes/                # Directorio de volcado de mapas de presión
├── tactile_captures_50.json # Dataset de origen (50 capturas)
├── LICENSE                  # Archivo de licencia pública
└── README.md                # Documentación del repositorio
3. Requisitos de las herramientas
Entorno GNU/Linux (Desarrollado y testeado en Arch Linux)

Python 3.x

Compilador Gcc/G++

Administrador python-pip
Configuración de dependencias en Arch
sudo pacman -Syu base-devel curl nlohmann-json python-flask python-matplotlib python-numpy
Proceso de compilación del binario
g++ main.cpp procesador.cpp -o cliente -lcurl

4. Lanzamiento del sistema

./servidor.py &
./cliente

5. Trazas de salida esperadas
Serving Flask app 'servidor'

Debug mode: off

WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.

* Running on [http://127.0.0.1:5000](http://127.0.0.1:5000)

Press CTRL+C to quit

127.0.0.1 - - [21/May/2026 16:21:59] "POST /HTTP/1.1" 200 -
127.0.0.1 - - [21/May/2026 16:21:59] "POST /HTTP/1.1" 200 -
127.0.0.1 - - [21/May/2026 16:22:00] "POST /HTTP/1.1" 200 -

6. Créditos y Autoría
Estudiante: Miguel Ángel Núñez Cózar

7. Licencia
GPL-3.0 license
