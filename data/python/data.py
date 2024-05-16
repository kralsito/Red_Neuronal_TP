from pip import pandas as pd

# Cargar datos desde un archivo CSV
df = pd.read_csv('datos.csv')

# Mostrar las primeras filas del DataFrame
print("Primeras filas de datos:")
print(df.head())

# Verificar tipos de datos y resumen estadístico
print("\nInformación del DataFrame:")
print(df.info())
print("\nResumen estadístico:")
print(df.describe())

# Calcular el promedio de una columna
promedio_edad = df['edad'].mean()
print("\nPromedio de edad:", promedio_edad)

# Filtrar datos por condiciones
mujeres_mayores = df[(df['sexo'] == 'Femenino') & (df['edad'] > 30)]
print("\nMujeres mayores de 30 años:")
print(mujeres_mayores)

# Guardar datos filtrados en un nuevo archivo CSV
mujeres_mayores.to_csv('mujeres_mayores.csv', index=False)
