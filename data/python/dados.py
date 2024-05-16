import random

def lanzar_dados():
    dado1 = random.randint(1, 6)
    dado2 = random.randint(1, 6)
    suma = dado1 + dado2
    return dado1, dado2, suma

dado1, dado2, suma = lanzar_dados()
print("Dado 1:", dado1)
print("Dado 2:", dado2)
print("Suma de los dados:", suma)
