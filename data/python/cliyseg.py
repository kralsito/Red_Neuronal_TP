import pandas as pd

# Cargar datos
clientes = pd.read_csv('customers.csv')

# Describir datos
print(clientes.describe())
print(clientes.info())

import matplotlib.pyplot as plt
import seaborn as sns

# Distribución de edades
plt.figure(figsize=(10, 6))
sns.histplot(clientes['Edad'], kde=True)
plt.title('Distribución de Edad de los Clientes')
plt.show()

# Distribución de género
plt.figure(figsize=(6, 6))
clientes['Género'].value_counts().plot.pie(autopct='%1.1f%%')
plt.title('Distribución de Género')
plt.show()

# Distribución de gastos
plt.figure(figsize=(10, 6))
sns.histplot(clientes['Gasto_Anual'], kde=True)
plt.title('Distribución de Gasto Anual')
plt.show()

# Gasto por género
plt.figure(figsize=(10, 6))
sns.boxplot(x='Género', y='Gasto_Anual', data=clientes)
plt.title('Gasto Anual por Género')
plt.show()

from sklearn.cluster import KMeans

# Seleccionar características para segmentación
X = clientes[['Edad', 'Gasto_Anual']]

# Encontrar el número óptimo de clusters
wcss = []
for i in range(1, 11):
    kmeans = KMeans(n_clusters=i, init='k-means++', max_iter=300, n_init=10, random_state=0)
    kmeans.fit(X)
    wcss.append(kmeans.inertia_)

plt.figure(figsize=(10, 6))
plt.plot(range(1, 11), wcss)
plt.title('Elbow Method')
plt.xlabel('Número de Clusters')
plt.ylabel('WCSS')
plt.show()

# Aplicar K-means
kmeans = KMeans(n_clusters=3, init='k-means++', max_iter=300, n_init=10, random_state=0)
clientes['Cluster'] = kmeans.fit_predict(X)

# Visualización de clusters
plt.figure(figsize=(10, 6))
sns.scatterplot(x='Edad', y='Gasto_Anual', hue='Cluster', data=clientes, palette='viridis')
plt.title('Segmentación de Clientes')
plt.show()
