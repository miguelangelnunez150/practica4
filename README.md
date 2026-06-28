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
```

## 3. Requisitos de las herramientas
Entorno GNU/Linux (Desarrollado y testeado en Arch Linux)
```
Python 3.x
Compilador Gcc/G++
Administrador python-pip
```
Configuración de dependencias en Arch
```
sudo pacman -Syu base-devel curl nlohmann-json python-flask python-matplotlib python-numpy
```
Proceso de compilación del binario
```
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






# Procesamiento e Interpolación de Imágenes Táctiles para un Gripper Robótico utilizando C++ y Python
## 1.Descripción
Este repositorio contiene la cuarta practica de la asignatura de Sistemas Operativos desarollado en C++ y Python que tiene como objetivo trabajar el procesamiento de matrices táctiles, la interpolación bilineal, la comunicación en red mediante una arquitectura cliente-servidor (HTTP) y la visualización de datos científicos.

---

## 2. Estructura del repositorio

```
├── servidor.py                      # Servidor Python
├── procesador.cpp                   # Lógica en C++
├── main.cpp                         # Función Main
├── procesador.h                     # Header C++
├── cliente                          # Binario
├── imagenes/                        # Directorio imagenes
├── tactile_captures_50.json         # Archivo JSON
├── LICENSE             
└── README.md
```

---

## 3. Requisitos del sistema
- Sistema operativo Linux (probado en Arch)
- Python3
- Gcc/G++
- Python-pip

### Instalacion de las herramientas en Arch
```bash
sudo pacman -Syu base-devel curl nlohmann-json python-flask python-matplotlib python-numpy
```

### Compilacion del programa usando g++
```bash
g++ main.cpp procesador.cpp -o cliente -lcurl
```

---

## 4. Ejecución
```bash
./servidor.py &
./cliente
```

---

## 5. Salida esperada

 * Serving Flask app 'servidor'

 * Debug mode: off

WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.

 * Running on http://127.0.0.1:5000

Press CTRL+C to quit

127.0.0.1 - - [21/May/2026 16:21:59] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:21:59] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:22:00] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:22:00] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:22:00] "POST / HTTP/1.1" 200 -

127.0.0.1 - - [21/May/2026 16:22:00] "POST / HTTP/1.1" 200 -


## 6. Autoría
* Alumno: David

## 7. Licencia
GLP-3.0 license
