import requests

def descargar_archivo(url, destino):
    response = requests.get(url)
    with open(destino, 'wb') as file:
        file.write(response.content)
    print(f"Archivo descargado: {destino}")

descargar_archivo('https://example.com/archivo.zip', '/ruta/a/archivo.zip')
