from flask import Flask, render_template, request, jsonify
from keras._tf_keras.keras.models import load_model
from keras.src.legacy.preprocessing.text import Tokenizer
from keras.src.utils.sequence_utils import pad_sequences
import numpy as np
import pickle
import os

app = Flask(__name__)

# Cargar el modelo y los diccionarios al iniciar la aplicación
MODEL_PATH = "model/language_model.h5"
TOKENIZER_PATH = "model/tokenizer.pickle"
LABEL_TO_INDEX_PATH = "model/label_to_index.pickle"
INDEX_TO_LABEL_PATH = "model/index_to_label.pickle"
MAX_LENGTH_PATH = "model/max_length.pickle"

# Verificar que los archivos existen
if not all(os.path.exists(p) for p in [MODEL_PATH, TOKENIZER_PATH, LABEL_TO_INDEX_PATH, INDEX_TO_LABEL_PATH, MAX_LENGTH_PATH]):
    raise Exception("El modelo no ha sido entrenado. Por favor, ejecuta training.py primero.")

model = load_model(MODEL_PATH)
with open(TOKENIZER_PATH, "rb") as h:
    tokenizer = pickle.load(h)
with open(INDEX_TO_LABEL_PATH, "rb") as h:
    index_to_label = pickle.load(h)
with open(MAX_LENGTH_PATH, "rb") as h:
    max_length = pickle.load(h)

def get_predictions(code):
    sequence = tokenizer.texts_to_sequences([code])
    padded_sequence = pad_sequences(sequence, maxlen=max_length)
    prediction = model.predict(padded_sequence)[0]
    
    # Obtener todas las probabilidades
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
    
    predictions = get_predictions(code)
    return jsonify({
        "predictions": predictions
    })

if __name__ == "__main__":
    # Hugging Face Spaces usa el puerto 7860 por defecto
    port = int(os.environ.get("PORT", 7860))
    app.run(host="0.0.0.0", port=port)
