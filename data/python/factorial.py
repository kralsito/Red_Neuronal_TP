def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

numero = 5  # Número para calcular su factorial
resultado = factorial(numero)
print("Factorial de", numero, "es", resultado)

#Fibonacci

def fibonacci(n):
    fibonacci_sequence = [0, 1]
    while len(fibonacci_sequence) < n:
        next_number = fibonacci_sequence[-1] + fibonacci_sequence[-2]
        fibonacci_sequence.append(next_number)
    return fibonacci_sequence[:n]

# Ejemplo de uso
n = 10  # Longitud de la secuencia de Fibonacci que se desea obtener
resultado = fibonacci(n)
print("Secuencia de Fibonacci:", resultado)


