import csv
from statistics import mean, median, stdev

def procesar_csv(archivo_entrada, archivo_salida):
    # Leer datos del archivo de entrada
    with open(archivo_entrada, mode='r') as csv_entrada:
        lector_csv = csv.reader(csv_entrada)
        encabezado = next(lector_csv)  # Leer el encabezado

        # Operaciones en los datos
        datos_procesados = []
        edades = []
        nombres = []
        for fila in lector_csv:
            nombre, edad = fila[0], int(fila[1])
            edad_doble = edad * 2
            datos_procesados.append([nombre, edad_doble])
            edades.append(edad)
            nombres.append(nombre)

    # Escribir datos procesados en el archivo de salida
    with open(archivo_salida, mode='w', newline='') as csv_salida:
        escritor_csv = csv.writer(csv_salida)
        escritor_csv.writerow(['Nombre', 'Edad x 2'])
        escritor_csv.writerows(datos_procesados)

    # Calcular estadísticas sobre las edades
    if edades:
        edad_promedio = mean(edades)
        edad_mediana = median(edades)
        edad_stdev = stdev(edades)
        edad_max = max(edades)
        edad_min = min(edades)

        print(f"Estadísticas de edades:")
        print(f"  Edad promedio: {edad_promedio:.2f}")
        print(f"  Edad mediana: {edad_mediana:.2f}")
        print(f"  Desviación estándar de las edades: {edad_stdev:.2f}")
        print(f"  Edad máxima: {edad_max}")
        print(f"  Edad mínima: {edad_min}")

        # Guardar estadísticas en un archivo de reporte
        with open('reporte_estadisticas.csv', mode='w', newline='') as reporte_csv:
            escritor_reporte = csv.writer(reporte_csv)
            escritor_reporte.writerow(['Estadística', 'Valor'])
            escritor_reporte.writerow(['Promedio', edad_promedio])
            escritor_reporte.writerow(['Mediana', edad_mediana])
            escritor_reporte.writerow(['Desviación Estándar', edad_stdev])
            escritor_reporte.writerow(['Máxima', edad_max])
            escritor_reporte.writerow(['Mínima', edad_min])

    # Guardar un resumen de los nombres en otro archivo
    with open('resumen_nombres.txt', mode='w') as resumen_nombres:
        resumen_nombres.write("Resumen de nombres:\n")
        for nombre in nombres:
            resumen_nombres.write(f"{nombre}\n")

# Ejemplo de uso
procesar_csv('datos_entrada.csv', 'datos_salida.csv')
