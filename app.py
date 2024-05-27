from keras._tf_keras.keras.models import load_model
from keras.src.legacy.preprocessing.text import Tokenizer
from keras.src.utils.sequence_utils import pad_sequences
import numpy as np
import pickle

# Cargar el modelo y el tokenizer
model = load_model("model/language_model.h5")

# Cargar los diccionarios y la longitud máxima de secuencia
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

# Predicción del lenguaje de programación de un archivo de texto
# Función para leer el contenido del archivo con múltiples intentos de codificación
def read_file_with_fallback(file_path):
    try:
        with open(file_path, "r", encoding="utf-8") as file:
            return file.read()
    except UnicodeDecodeError:
        try:
            with open(file_path, "r", encoding="latin-1") as file:
                return file.read()
        except UnicodeDecodeError:
            raise Exception("Error decodificando archivo en UTF-8 y Latin-1")
# Ruta al archivo de texto
file_path = "input.txt"

# Leer el contenido del archivo
with open(file_path, "r") as file:
    code_example = read_file_with_fallback(file_path)

predicted_language = predict_language(code_example)
print(f"El lenguaje de programacion es: {predicted_language}")


# Función para predecir las probabilidades de cada lenguaje de programación para un fragmento de código dado
def predict_language_probabilities(code):
    # Tokenizar el código
    sequence = tokenizer.texts_to_sequences([code])
    padded_sequence = pad_sequences(sequence, maxlen=max_length)
    # Realizar la predicción
    prediction = model.predict(padded_sequence)[0]
    # Obtener las probabilidades de cada lenguaje
    probabilities = {index_to_label[i]: prob for i, prob in enumerate(prediction)}
    return probabilities    

probabilities = predict_language_probabilities(code_example)
for language, probability in probabilities.items():
    print(f"{language}: {probability:.2f}%")
