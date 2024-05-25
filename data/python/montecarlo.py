import random

def generador_punto():
    x = random.uniform(-1, 1)
    y = random.uniform(-1, 1)
    return x, y

def generador_punto_normal():
    x = random.gauss(0, 1)  # Genera una muestra de una distribución normal (media 0, desviación estándar 1)
    y = random.gauss(0, 1)
    while x < -1 or x > 1 or y < -1 or y > 1:
        x = random.gauss(0, 1)
        y = random.gauss(0, 1)
    return x, y

def generador_punto_exponencial():
    x = random.expovariate(1)  # Genera una muestra de una distribución exponencial (media 1)
    y = random.expovariate(1)
    while x < -1 or x > 1 or y < -1 or y > 1:
        x = random.expovariate(1)
        y = random.expovariate(1)
    return x, y

def estimate_pi(num_points, generador_func):
    inside_circle = 0
    for _ in range(num_points):
        x, y = generador_func()
        if x**2 + y**2 <= 1:
            inside_circle += 1
    return 4 * inside_circle / num_points

num_points = 1000000

pi_estimate_uniform = estimate_pi(num_points, generador_punto)
print(f"Estimation of Pi with {num_points} points using uniform random numbers: {pi_estimate_uniform}")

pi_estimate_normal = estimate_pi(num_points, generador_punto_normal)
print(f"Estimation of Pi with {num_points} points using normal random numbers: {pi_estimate_normal}")

pi_estimate_exponential = estimate_pi(num_points, generador_punto_exponencial)
print(f"Estimation of Pi with {num_points} points using exponential random numbers: {pi_estimate_exponential}")
