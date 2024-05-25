import random

def estimate_pi(num_points):
    inside_circle = 0
    for _ in range(num_points):
        x = random.uniform(-1, 1)
        y = random.uniform(-1, 1)
        if x**2 + y**2 <= 1:
            inside_circle += 1
    return 4 * inside_circle / num_points

num_points = 1000000
pi_estimate = estimate_pi(num_points)
print(f"Estimation of Pi with {num_points} points: {pi_estimate}")
