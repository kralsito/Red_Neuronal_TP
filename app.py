from keras._tf_keras.keras.models import load_model
from keras.src.legacy.preprocessing.text import Tokenizer
from keras.src.utils.sequence_utils import pad_sequences
import numpy as np
import pickle

# Cargar el modelo y el tokenizer
model = load_model("model/language_model.h5")

with open("model/tokenizer.pickle", "rb") as handle:
    tokenizer = pickle.load(handle)
with open("model/label_to_index.pickle", "rb") as handle:
    label_to_index = pickle.load(handle)
with open("model/index_to_label.pickle", "rb") as handle:
    index_to_label = pickle.load(handle)
with open("model/max_length.pickle", "rb") as handle:
    max_length = pickle.load(handle)

# Función para predecir el lenguaje de programación
def predict_language(code):
    sequence = tokenizer.texts_to_sequences([code])
    padded_sequence = pad_sequences(sequence, maxlen=max_length)
    prediction = model.predict(padded_sequence)
    language_index = np.argmax(prediction)
    return index_to_label[language_index]

# Ruta al archivo de texto
file_path = "input.txt"

# Leer el contenido del archivo
with open(file_path, "r") as file:
    code_example = file.read()

predicted_language = predict_language(code_example)
print(f"El lenguaje de programacion es: {predicted_language}")
