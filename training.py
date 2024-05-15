from keras.src.legacy.preprocessing.text import Tokenizer
from keras.src.utils.sequence_utils import pad_sequences
from keras.src.models.sequential import Sequential
from keras._tf_keras.keras.layers import Embedding, LSTM, Dense, Bidirectional
from sklearn.model_selection import train_test_split
import numpy as np
import os
import pickle


data_dir = "data"
data = []

for language in os.listdir(data_dir):
    language_dir = os.path.join(data_dir, language)
    for file_name in os.listdir(language_dir):
        file_path = os.path.join(language_dir, file_name)
        with open(file_path, "r") as file:
            code = file.read()
            data.append((code, language))
# Ahora `data` contiene una lista de tuplas, donde cada tupla contiene un bloque de código y su lenguaje correspondiente


# Preparación de los datos
texts, labels = zip(*data)
languages = sorted(set(labels))

# Mapear cada lenguaje a un número
label_to_index = {label: idx for idx, label in enumerate(languages)}
index_to_label = {idx: label for label, idx in label_to_index.items()}

# Convertir etiquetas a índices
labels = [label_to_index[label] for label in labels]

# Tokenización de los textos
tokenizer = Tokenizer(num_words=1000)
tokenizer.fit_on_texts(texts)
sequences = tokenizer.texts_to_sequences(texts)
max_length = max(len(seq) for seq in sequences)
X = pad_sequences(sequences, maxlen=max_length)

# Convertir las etiquetas a un array numpy
y = np.array(labels)

# Dividir los datos en conjuntos de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Definir el modelo
model = Sequential([
    Embedding(input_dim=1000, output_dim=64, input_length=max_length),
    Bidirectional(LSTM(64)),
    Dense(64, activation='relu'),
    Dense(len(languages), activation='softmax')
])

# Compilar el modelo
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['accuracy'])

# Entrenar el modelo
model.fit(X_train, y_train, epochs=100, validation_data=(X_test, y_test))

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