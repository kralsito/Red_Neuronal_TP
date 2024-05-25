import os
import shutil
import datetime

def respaldo_archivos(origen, destino):
    if not os.path.exists(origen):
        print(f"El directorio de origen '{origen}' no existe.")
        return
    
    if not os.path.isdir(destino):
        print(f"El directorio de destino '{destino}' no es válido.")
        return

    fecha = datetime.datetime.now().strftime('%Y-%m-%d')
    respaldo_destino = os.path.join(destino, f"respaldo_{fecha}")

    if os.path.exists(respaldo_destino):
        print(f"Ya existe un respaldo para hoy en '{respaldo_destino}'.")
        return

    try:
        shutil.copytree(origen, respaldo_destino)
        print(f"Respaldo completado en '{respaldo_destino}'")
    except Exception as e:
        print(f"Error al hacer el respaldo: {e}")

# Ejemplo de uso
respaldo_archivos('/ruta/a/origen', '/ruta/a/destino')
