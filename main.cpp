#include "procesador.h"
#include <iostream>

int main() {
    // 1: Carga y parseo del documento fuente JSON
    json datos_sensor = leerJSON("tactile_captures_50.json");

    // 2: Procesamiento secuencial del set de capturas
    for (const auto& elemento : datos_sensor["captures"]) {
        int id_captura = elemento["id"];
        std::vector<std::vector<int>> matriz_presion = elemento["matrix"];

        // 3: Pipeline de filtrado, escalado y transmisión
        if (validar(matriz_presion)) {
            auto matriz_escalada = interpolar(matriz_presion);
            enviarHTTP(id_captura, matriz_escalada);
        }
        else {
            std::cerr << "[ERROR] Captura ID " << id_captura << " no cumple las dimensiones 16x16." << std::endl;
        }
    }

    return 0;
}