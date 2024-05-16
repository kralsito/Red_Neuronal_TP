import time
import random

def calcular_tiempo_ejecucion(func):
    def wrapper(*args, **kwargs):
        inicio = time.time()
        resultado = func(*args, **kwargs)
        fin = time.time()
        tiempo_ejecucion = fin - inicio
        print(f"Tiempo de ejecución de {func.__name__}: {tiempo_ejecucion:.4f} segundos")
        return resultado
    return wrapper

@calcular_tiempo_ejecucion
def proceso_de_datos(n):
    print(f"Iniciando proceso de datos para {n} elementos...")
    datos = [random.randint(1, 100) for _ in range(n)]
    procesados = [dato * 2 for dato in datos if dato % 2 == 0]
    print("Proceso completado.")
    return procesados

# Ejemplo de uso
n = 1000000  # Cantidad de datos a procesar
resultado_proceso = proceso_de_datos(n)
print("Resultado del proceso (primeros 10 elementos):", resultado_proceso[:10])
