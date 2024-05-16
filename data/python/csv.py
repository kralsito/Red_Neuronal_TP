import csv

def procesar_csv(archivo_entrada, archivo_salida):
    with open(archivo_entrada, mode='r') as csv_entrada:
        lector_csv = csv.reader(csv_entrada)
        encabezado = next(lector_csv)  # Leer el encabezado

        # Operaciones en los datos
        datos_procesados = []
        for fila in lector_csv:
            nombre, edad = fila[0], int(fila[1])
            edad_doble = edad * 2
            datos_procesados.append([nombre, edad_doble])

    with open(archivo_salida, mode='w', newline='') as csv_salida:
        escritor_csv = csv.writer(csv_salida)
        escritor_csv.writerow(['Nombre', 'Edad x 2'])
        escritor_csv.writerows(datos_procesados)

procesar_csv('datos_entrada.csv', 'datos_salida.csv')
