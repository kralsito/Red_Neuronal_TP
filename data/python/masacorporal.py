def calcular_imc(peso, altura):
    imc = peso / (altura ** 2)
    return imc

def determinar_categoria_imc(imc):
    if imc < 18.5:
        return 'Bajo peso'
    elif 18.5 <= imc < 24.9:
        return 'Peso normal'
    elif 24.9 <= imc < 29.9:
        return 'Sobrepeso'
    else:
        return 'Obesidad'

peso_usuario = float(input("Ingrese su peso en kilogramos: "))
altura_usuario = float(input("Ingrese su altura en metros: "))
imc_usuario = calcular_imc(peso_usuario, altura_usuario)
categoria_imc = determinar_categoria_imc(imc_usuario)

print(f"Su IMC es: {imc_usuario}")
print(f"Categoría de IMC: {categoria_imc}")
