import pandas as pd

# Cargar datos
productos = pd.read_csv('products.csv')

# Describir datos
print(productos.describe())
print(productos.info())

import matplotlib.pyplot as plt
import seaborn as sns

# Distribución de precios
plt.figure(figsize=(10, 6))
sns.histplot(productos['Precio'], kde=True)
plt.title('Distribución de Precios')
plt.show()

# Precio por categoría
plt.figure(figsize=(12, 6))
sns.boxplot(x='Categoría', y='Precio', data=productos)
plt.title('Precio por Categoría')
plt.xticks(rotation=45)
plt.show()

# Productos más vendidos
plt.figure(figsize=(12, 6))
top_10_productos = productos.nlargest(10, 'Ventas')
sns.barplot(x='Producto', y='Ventas', data=top_10_productos)
plt.title('Top 10 Productos Más Vendidos')
plt.xticks(rotation=45)
plt.show()

# Popularidad por categoría
plt.figure(figsize=(12, 6))
sns.boxplot(x='Categoría', y='Ventas', data=productos)
plt.title('Popularidad por Categoría')
plt.xticks(rotation=45)
plt.show()

# Distribución de reseñas
plt.figure(figsize=(10, 6))
sns.histplot(productos['Reseñas'], kde=True)
plt.title('Distribución de Reseñas')
plt.show()

# Reseñas por categoría
plt.figure(figsize=(12, 6))
sns.boxplot(x='Categoría', y='Reseñas', data=productos)
plt.title('Reseñas por Categoría')
plt.xticks(rotation=45)
plt.show()

plt.figure(figsize=(10, 8))
sns.heatmap(productos.corr(), annot=True, cmap='coolwarm')
plt.title('Matriz de Correlación')
plt.show()
