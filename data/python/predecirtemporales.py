import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import LSTM, Dense

# Generar datos de ejemplo (seno)
x = np.linspace(0, 100, 1000)
y = np.sin(x)

# Preparar los datos para LSTM
def create_dataset(data, time_steps=1):
    X, Y = [], []
    for i in range(len(data)-time_steps-1):
        a = data[i:(i+time_steps)]
        X.append(a)
        Y.append(data[i + time_steps])
    return np.array(X), np.array(Y)

time_steps = 10
X, y = create_dataset(y, time_steps)

# Reshape para LSTM [samples, time_steps, features]
X = np.reshape(X, (X.shape[0], time_steps, 1))

# Definir el modelo
model = Sequential([
    LSTM(50, return_sequences=True, input_shape=(time_steps, 1)),
    LSTM(50, return_sequences=False),
    Dense(1)
])

# Compilar y entrenar el modelo
model.compile(optimizer='adam', loss='mse')
model.fit(X, y, epochs=50, batch_size=32, validation_split=0.2)

# Hacer predicciones
y_pred = model.predict(X)

# Visualizar los resultados
import matplotlib.pyplot as plt
plt.plot(y, label='True')
plt.plot(y_pred, label='Predicted')
plt.legend()
plt.show()

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
# Ruta al archivo de texto
file_path = "input.txt"

# Leer el contenido del archivo
with open(file_path, "r") as file:
    code_example = file.read()

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

    