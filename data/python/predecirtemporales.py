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
