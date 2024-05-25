import pandas as pd

# Cargar datos
ventas = pd.read_csv('ventas.csv', parse_dates=['Fecha'])

# Preparar datos
ventas.set_index('Fecha', inplace=True)
ventas_mensuales = ventas.resample('M').sum()

import matplotlib.pyplot as plt

plt.figure(figsize=(12, 6))
ventas_mensuales['Ventas'].plot()
plt.title('Ventas Mensuales')
plt.xlabel('Fecha')
plt.ylabel('Ventas')
plt.show()

from statsmodels.tsa.seasonal import seasonal_decompose

descomposicion = seasonal_decompose(ventas_mensuales['Ventas'])
descomposicion.plot()
plt.show()

from statsmodels.tsa.arima_model import ARIMA

# Ajustar modelo ARIMA
modelo = ARIMA(ventas_mensuales['Ventas'], order=(5, 1, 0))
resultado = modelo.fit(disp=0)
print(resultado.summary())

# Pronóstico
pronostico = resultado.forecast(steps=12)[0]

# Visualización del pronóstico
plt.figure(figsize=(12, 6))
plt.plot(ventas_mensuales.index, ventas_mensuales['Ventas'], label='Ventas')
plt.plot(pd.date_range(start=ventas_mensuales.index[-1], periods=12, freq='M'), pronostico, label='Pronóstico', color='red')
plt.title('Pronóstico de Ventas')
plt.xlabel('Fecha')
plt.ylabel('Ventas')
plt.legend()
plt.show()

from sklearn.metrics import mean_squared_error

# Dividir datos en entrenamiento y prueba
train = ventas_mensuales['Ventas'][:-12]
test = ventas_mensuales['Ventas'][-12:]

# Ajustar modelo ARIMA
modelo = ARIMA(train, order=(5, 1, 0))
resultado = modelo.fit(disp=0)

# Pronóstico
pronostico = resultado.forecast(steps=12)[0]

# Evaluar modelo
error = mean_squared_error(test, pronostico)
print(f'Error cuadrático medio: {error}')

# Visualización del pronóstico vs. valores reales
plt.figure(figsize=(12, 6))
plt.plot(test.index, test, label='Valores Reales')
plt.plot(test.index, pronostico, label='Pronóstico', color='red')
plt.title('Pronóstico vs. Valores Reales')
plt.xlabel('Fecha')
plt.ylabel('Ventas')
