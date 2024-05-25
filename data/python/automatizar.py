import shutil
import datetime

def respaldo_archivos(origen, destino):
    fecha = datetime.datetime.now().strftime('%Y-%m-%d')
    respaldo_destino = os.path.join(destino, f"respaldo_{fecha}")
    shutil.copytree(origen, respaldo_destino)
    print(f"Respaldo completado en {respaldo_destino}")

respaldo_archivos('/ruta/a/origen', '/ruta/a/destino')