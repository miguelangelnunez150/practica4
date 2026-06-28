#include "procesador.h"
#include <fstream>
#include <iostream>
#include <curl/curl.h>

// 1. Cargar archivo JSON
json cargarDatosJSON(const std::string& path) {
    std::ifstream archivo(path);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir " << path << std::endl;
        exit(1);
    }
    return json::parse(archivo);
}

// 2. Validar que la matriz sea 16x16
bool verificarDimensiones(const std::vector<std::vector<int>>& mat) {
    if (mat.size() != 16) return false;
    for (size_t i = 0; i < mat.size(); ++i) {
        if (mat[i].size() != 16) return false;
    }
    return true;
}

// 3. Interpolación bilineal manual (Escalar a 128x128)
std::vector<std::vector<double>> procesarEscaladoBilineal(const std::vector<std::vector<int>>& mat) {
    std::vector<std::vector<double>> nueva(128, std::vector<double>(128, 0.0));

    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 128; ++j) {
            // Calcular posiciones flotantes
            float x = j * 15.0f / 127.0f;
            float y = i * 15.0f / 127.0f;

            // Obtener índices vecinos
            int x1 = (int)x, y1 = (int)y;
            int x2 = std::min(x1 + 1, 15);
            int y2 = std::min(y1 + 1, 15);

            float dx = x - x1, dy = y - y1;

            // Fórmulas de interpolación
            float sup = mat[y1][x1] * (1.0f - dx) + mat[y1][x2] * dx;
            float inf = mat[y2][x1] * (1.0f - dx) + mat[y2][x2] * dx;

            nueva[i][j] = sup * (1.0f - dy) + inf * dy;
        }
    }
    return nueva;
}

// 4. Enviar matriz al servidor Python con libcurl
void transmitirDatosServidor(int id, const std::vector<std::vector<double>>& mat) {
    CURL* curl = curl_easy_init();
    if (curl) {
        // Crear estructura JSON de envío
        json payload = { {"capture_id", id}, {"width", 128}, {"height", 128}, {"data", mat} };
        std::string json_str = payload.dump();

        // Configurar cabeceras HTTP
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        // Configurar opciones de libcurl
        curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:5000/");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_str.c_str());

        // Realizar la petición POST
        curl_easy_perform(curl);

        // Limpiar recursos
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
}