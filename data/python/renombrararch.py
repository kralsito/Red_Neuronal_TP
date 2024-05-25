import os

def renombrar_archivos(directorio, prefijo):
    for count, filename in enumerate(os.listdir(directorio)):
        extension = filename.split('.')[-1]
        nuevo_nombre = f"{prefijo}_{count}.{extension}"
        os.rename(os.path.join(directorio, filename), os.path.join(directorio, nuevo_nombre))

renombrar_archivos('/ruta/a/directorio', 'archivo')
