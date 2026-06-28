#ifndef PROCESADOR_MUTADO_H
#define PROCESADOR_MUTADO_H

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Declaración de las funciones del pipeline de procesamiento
json cargarDatosJSON(const std::string& path);
bool verificarDimensiones(const std::vector<std::vector<int>>& mat);
std::vector<std::vector<double>> procesarEscaladoBilineal(const std::vector<std::vector<int>>& mat);
void transmitirDatosServidor(int id, const std::vector<std::vector<double>>& mat);

#endif // PROCESADOR_MUTADO_H