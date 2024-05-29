import numpy as np
import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split, GridSearchCV, cross_val_score
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import classification_report, confusion_matrix
import matplotlib.pyplot as plt
import seaborn as sns

# Cargar el conjunto de datos Iris
iris = load_iris()
X, y = iris.data, iris.target

# Crear un DataFrame para facilitar el análisis y visualización
df = pd.DataFrame(data=np.c_[X, y], columns=iris.feature_names + ['target'])

# Mostrar las primeras filas del DataFrame
print("Primeras filas del DataFrame:")
print(df.head())

# Descripción estadística del conjunto de datos
print("\nDescripción estadística del conjunto de datos:")
print(df.describe())

# Dividir el conjunto de datos en entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Búsqueda de hiperparámetros óptimos usando GridSearchCV
param_grid = {'n_neighbors': np.arange(1, 25)}
knn = KNeighborsClassifier()
knn_cv = GridSearchCV(knn, param_grid, cv=5)
knn_cv.fit(X_train, y_train)

print(f"\nMejor número de vecinos (n_neighbors): {knn_cv.best_params_['n_neighbors']}")

# Inicializar y entrenar el modelo KNN con el mejor número de vecinos
knn = KNeighborsClassifier(n_neighbors=knn_cv.best_params_['n_neighbors'])
knn.fit(X_train, y_train)

# Evaluar el modelo
accuracy = knn.score(X_test, y_test)
print(f"\nAccuracy: {accuracy:.2f}")

# Predicciones
y_pred = knn.predict(X_test)

# Reporte de clasificación
print("\nReporte de clasificación:")
print(classification_report(y_test, y_pred, target_names=iris.target_names))

# Matriz de confusión
conf_matrix = confusion_matrix(y_test, y_pred)
print("\nMatriz de confusión:")
print(conf_matrix)

# Visualización de la matriz de confusión
plt.figure(figsize=(8, 6))
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues', xticklabels=iris.target_names, yticklabels=iris.target_names)
plt.xlabel('Predicción')
plt.ylabel('Real')
plt.title('Matriz de Confusión')
plt.show()

# Visualización de la distribución de las características
sns.pairplot(df, hue='target', palette='Set2', markers=["o", "s", "D"])
plt.suptitle('Distribución de las Características del Conjunto de Datos Iris', y=1.02)
plt.show()

# Validación cruzada
cv_scores = cross_val_score(knn, X, y, cv=5)
print(f"\nPuntuaciones de validación cruzada: {cv_scores}")
print(f"Media de puntuaciones de validación cruzada: {cv_scores.mean():.2f}")

# Gráfico de precisión vs. número de vecinos
neighbors = np.arange(1, 25)
train_accuracy = np.empty(len(neighbors))
test_accuracy = np.empty(len(neighbors))

for i, k in enumerate(neighbors):
    knn = KNeighborsClassifier(n_neighbors=k)
    knn.fit(X_train, y_train)
    train_accuracy[i] = knn.score(X_train, y_train)
    test_accuracy[i] = knn.score(X_test, y_test)

plt.figure(figsize=(10, 6))
plt.plot(neighbors, train_accuracy, label='Precisión en el conjunto de entrenamiento')
plt.plot(neighbors, test_accuracy, label='Precisión en el conjunto de prueba')
plt.xlabel('Número de vecinos')
plt.ylabel('Precisión')
plt.title('Precisión en función del número de vecinos')
plt.legend()
plt.show()
