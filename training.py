from keras.src.legacy.preprocessing.text import Tokenizer
from keras.src.utils.sequence_utils import pad_sequences
from keras.src.models.sequential import Sequential
from keras._tf_keras.keras.layers import Embedding, LSTM, Dense, Bidirectional
from sklearn.model_selection import train_test_split
import numpy as np
import os
import pickle

# CARGA DE LOS DATOS
# Se define el directorio data donde se almacenan los fragmentos de código organizados por lenguaje de programación
data_dir = "data"
# Crear una lista vacía para almacenar los datos
data = []
# Recorre cada lenguaje de promación y cada archivo de estos subfirectorios
for language in os.listdir(data_dir):
    language_dir = os.path.join(data_dir, language)
    for file_name in os.listdir(language_dir):
        file_path = os.path.join(language_dir, file_name)
        try: # Intentamos abrir el archivo con codificación UTF-8 
            with open(file_path, "r", encoding="utf-8") as file:
                code = file.read()
        except UnicodeDecodeError: # Si falla, intentamos con otra codificación por tildes, $, etc.
            print(f"Error decoding file '{file_path}' as UTF-8, attempting alternative encoding...")
            # Intentamos abrir el archivo con codificación latin-1
            with open(file_path, "r", encoding="latin-1") as file:
                # Leemos el contenido del archivo
                code = file.read()
                # Imprimimos un mensaje de éxito
            print(f"Success! Encoding file '{file_path}' as latin-1")
        # Agregamos el contenido del código y el lenguaje de promación a la lista de datos
        data.append((code, language))

# Ahora `data` contiene una lista de tuplas, donde cada tupla contiene un bloque de código y su lenguaje correspondiente


# PREPARACIÓN DE LOS DATOS PARA EL ENTRENAMIENTO
# Separa el código y el lenguaje en listas separadas
texts, labels = zip(*data)
languages = sorted(set(labels))

# Se crea el mapeo de cada lenguaje a un número y su inverso
label_to_index = {label: idx for idx, label in enumerate(languages)}
index_to_label = {idx: label for label, idx in label_to_index.items()}

# Convertir etiquetas a índices númericos
labels = [label_to_index[label] for label in labels]


# Tokeniza el código usando Keras con un vocabulario máximo de 500 palabras
tokenizer = Tokenizer(num_words=500)

tokenizer.fit_on_texts(texts)
# Convierte los textos tokenizados a secuencias numéricas y ajusta todas las secuencias a la misma longitud
sequences = tokenizer.texts_to_sequences(texts)
max_length = max(len(seq) for seq in sequences)
X = pad_sequences(sequences, maxlen=max_length)

# Convertir las etiquetas a un array numpy
y = np.array(labels)

# DIVISIÓN DE LOS DATOS 
# Se divide los datos en conjuntos de entrenamiento y prueba 
# El 70% de los datos se utiliza para el entrenamiento y el 30% para la prueba
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# DEFINICIÓN Y ENTRENAMIENTO DEL MODELO
model = Sequential([
    # Convierte las secuencias numéricas a vectores densos 
    Embedding(input_dim=500, output_dim=32, input_length=max_length),
    # Se usa una capa LSTM bidireccional para aprender patrones en ambas direcciones de las secuencias
    Bidirectional(LSTM(32)),
    # Es una capa densa de 64 neuronas con función de activación ReLU
    Dense(16, activation='relu'),
    # Es una capa de salida con activación softmax para clasificar los lenguajes de programación
    Dense(len(languages), activation='softmax')
])

# Compilar el modelo
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Entrenar el modelo usando el conjunto de datos de entrenamiento y validando con el conjunto de datos de prueba
model.fit(X_train, y_train, epochs=20, validation_data=(X_test, y_test))


# GUARDAR EL MODELO Y LOS DICCIONARIOS
# Guardar el modelo
model.save("model/language_model.h5")

# Guardar el tokenizer y los diccionarios
with open("model/tokenizer.pickle", "wb") as handle:
    pickle.dump(tokenizer, handle, protocol=pickle.HIGHEST_PROTOCOL)

with open("model/label_to_index.pickle", "wb") as handle:
    pickle.dump(label_to_index, handle, protocol=pickle.HIGHEST_PROTOCOL)

with open("model/index_to_label.pickle", "wb") as handle:
    pickle.dump(index_to_label, handle, protocol=pickle.HIGHEST_PROTOCOL)

# Guardar la longitud máxima de secuencia
with open("model/max_length.pickle", "wb") as handle:
    pickle.dump(max_length, handle, protocol=pickle.HIGHEST_PROTOCOL)