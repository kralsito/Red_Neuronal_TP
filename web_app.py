from flask import Flask, render_template, request, jsonify
import os
import pickle
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing.sequence import pad_sequences
from huggingface_hub import hf_hub_download

app = Flask(__name__)

# --- CONFIGURACIÓN DEL REPOSITORIO ---
REPO_ID = "mmorullo/CodeAI-Detector" 

# Inicializamos las variables globales
model = None
tokenizer = None
index_to_label = None
max_length = None

def load_resources():
    global model, tokenizer, index_to_label, max_length
    try:
        print(f"--- INFO: Iniciando descarga de recursos desde Hugging Face Hub ---")
        
        # 1. Descarga oficial del modelo
        # hf_hub_download descarga el archivo real y devuelve la ruta local segura
        model_path = hf_hub_download(repo_id=REPO_ID, filename="model/language_model.keras", repo_type="space")
        model = load_model(model_path)
        print(f"--- Modelo cargado desde: {model_path} ---")

        # 2. Descarga del Tokenizer
        tok_path = hf_hub_download(repo_id=REPO_ID, filename="model/tokenizer.pickle", repo_type="space")
        with open(tok_path, "rb") as h:
            tokenizer = pickle.load(h)

        # 3. Descarga de Index to Label
        label_path = hf_hub_download(repo_id=REPO_ID, filename="model/index_to_label.pickle", repo_type="space")
        with open(label_path, "rb") as h:
            index_to_label = pickle.load(h)

        # 4. Descarga de Max Length
        len_path = hf_hub_download(repo_id=REPO_ID, filename="model/max_length.pickle", repo_type="space")
        with open(len_path, "rb") as h:
            max_length = pickle.load(h)

        print("--- Todos los recursos (Modelo y Pickles) cargados exitosamente ---")
        return True
    except Exception as e:
        print(f"--- ERROR CRÍTICO EN CARGA DE RECURSOS ---")
        print(str(e))
        return False

# Intentar cargar al arrancar
load_resources()

def get_predictions(code):
    # Verificación de seguridad por si la carga falló
    if model is None or tokenizer is None:
        return [{"language": "Error de Sistema", "probability": 0, "message": "Los recursos del modelo no están disponibles."}]
        
    # Preprocesamiento
    sequence = tokenizer.texts_to_sequences([code])
    padded_sequence = pad_sequences(sequence, maxlen=max_length)
    
    # Inferencia
    prediction = model.predict(padded_sequence)[0]
    
    results = []
    for i, prob in enumerate(prediction):
        results.append({
            "language": index_to_label[i],
            "probability": float(prob) * 100
        })
    
    # Ordenar por probabilidad descendente
    results = sorted(results, key=lambda x: x["probability"], reverse=True)
    return results

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/api/analyze", methods=["POST"])
def analyze():
    data = request.json
    code = data.get("code", "")
    
    if not code:
        return jsonify({"error": "No hay código para analizar"}), 400
    
    try:
        predictions = get_predictions(code)
        return jsonify({"predictions": predictions})
    except Exception as e:
        print(f"Error en predicción: {e}")
        return jsonify({"error": "Error interno al procesar el código"}), 500

if __name__ == "__main__":
    # Puerto dinámico para Hugging Face
    port = int(os.environ.get("PORT", 7860))
    app.run(host="0.0.0.0", port=port)