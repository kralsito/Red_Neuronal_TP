import pandas as pd

# Cargar datos
data = pd.read_csv('sales_data.csv')

# Describir datos
print(data.describe())
print(data.info())

# Llenar valores nulos con la media
data.fillna(data.mean(), inplace=True)

# Eliminar duplicados
data.drop_duplicates(inplace=True)

import matplotlib.pyplot as plt
import seaborn as sns

# Análisis de la variable 'Ventas'
plt.figure(figsize=(10, 6))
sns.histplot(data['Ventas'], kde=True)
plt.title('Distribución de Ventas')
plt.show()

# Análisis de la variable 'Fecha'
data['Fecha'] = pd.to_datetime(data['Fecha'])
data.set_index('Fecha', inplace=True)
plt.figure(figsize=(12, 6))
data['Ventas'].plot()
plt.title('Ventas a lo Largo del Tiempo')
plt.show()

plt.figure(figsize=(10, 8))
sns.heatmap(data.corr(), annot=True, cmap='coolwarm')
plt.title('Matriz de Correlación')
plt.show()

# Resampleo de datos por mes
data_mensual = data.resample('M').sum()

plt.figure(figsize=(12, 6))
data_mensual['Ventas'].plot()
plt.title('Ventas Mensuales')
plt.show()
