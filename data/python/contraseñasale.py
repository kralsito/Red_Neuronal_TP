import random
import string

def generar_contraseña(longitud):
    caracteres = string.ascii_letters + string.digits + string.punctuation
    contraseña = ''.join(random.choice(caracteres) for i in range(longitud))
    return contraseña

longitud_contraseña = 12  # Longitud deseada para la contraseña
nueva_contraseña = generar_contraseña(longitud_contraseña)
print("Contraseña generada:", nueva_contraseña)
