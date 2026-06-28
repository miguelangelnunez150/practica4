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
