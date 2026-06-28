from flask import Flask, request
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np
import os

app = Flask(__name__)

# Verificación y apertura del directorio de salida para los gráficos
carpeta_destino = "imagenes"
os.makedirs(carpeta_destino, exist_ok=True)

@app.route('/', methods=['POST'])
def recibir():
    datos = request.json
    
    # Procesamiento de la matriz numérica y configuración del mapa de calor
    plt.imshow(np.array(datos['data']), cmap="plasma") # <--- Cambiado a plasma (tonos morados/rosas)
    plt.colorbar(label="Presion")                       
    plt.title("Matriz de Presion Tactil - Captura")    # <--- Título personalizado
    plt.grid(True, color="white", alpha=0.3, linestyle="--") # <--- Añade una rejilla elegante
    
    # Almacenamiento local del archivo de imagen con su respectivo identificador
    ruta_guardado = os.path.join(carpeta_destino, f"capture_{datos['capture_id']}.png")
    plt.savefig(ruta_guardado)
    plt.close()
    
    return "OK"

if __name__ == '__main__': 
    app.run(port=5000)
