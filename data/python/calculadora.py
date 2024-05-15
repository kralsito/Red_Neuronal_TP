#Declaramos variables para el calculo de una calculadora

def funcion_suma(a,b):
    resultado = a+b
    return resultado

def funcion_resta(a,b):
    resultado = a-b
    return resultado

def funcion_multiplicacion(a,b):
    resultado = a*b
    return resultado

def funcion_division(a,b):
    resultado = a/b
    return resultado

print ("1.- Operacion Suma")
print ("2.- Operacion Resta")
print ("3.- Operacion Multiplicacion")
print ("4.- Operacion Division")

opcion_elegida = input ("Selecciona una opcion de las siguientes: ")

op = int (opcion_elegida)
print (op)

if op == 1:
    print("\nOperacion Suma elegida. Introduzca los dos numeros\n")
    numero1 = input ("Numero 1: ")
    numero2 = input ("\nNumero 2: ")
    numero11 = int(numero1)
    numero22 = int(numero2)
    int(numero2)
    resultado_op = funcion_suma (numero11,numero22)
    print ("El resultado es: ",resultado_op)
    
elif op == 2 :
    print("Operacion Resta elegida. Introduzca los dos numeros")
    numero1 = input ("Numero 1: ")
    numero2 = input ("Numero 2: ")
    numero11 = int(numero1)
    numero22 = int(numero2)
    resultado_op = funcion_resta (numero11,numero22)
    print ("El resultado es: ",resultado_op)
    
elif op == 3 :
    print("Operacion Multiplicacion elegida. Introduzca los dos numeros")
    numero1 = input ("Numero 1: ")
    numero2 = input ("Numero 2: ")
    numero11 = int(numero1)
    numero22 = int(numero2)
    resultado_op = funcion_multiplicacion (numero11,numero22)
    print ("El resultado es: ",resultado_op)
    
elif op == 4 :
    print("Operacion Division elegida. Introduzca los dos numeros")
    numero1 = input ("Numero 1: ")
    numero2 = input ("Numero 2: ")
    numero11 = int(numero1)
    numero22 = int(numero2)
    resultado_op = funcion_division (numero11,numero22)
    print ("El resultado es: ",resultado_op)