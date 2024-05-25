import numpy as np
import matplotlib.pyplot as plt

def ode_func(t, y):
    return np.array([y[1], t + y[0]])

def solve_ode_euler(func, y0, t_span, num_steps=100):
    t0, tf = t_span
    h = (tf - t0) / num_steps

    t_values = np.linspace(t0, tf, num_steps + 1)
    y_values = np.zeros((len(y0), num_steps + 1))
    y_values[:, 0] = y0

    for i in range(num_steps):
        t_i = t_values[i]
        y_i = y_values[:, i]
        y_prime = func(t_i, y_i)
        y_values[:, i + 1] = y_i + h * y_prime

    return t_values, y_values

t_span = (0, 10)
y0 = np.array([1, 0])  # Initial conditions for y and y'
t, y = solve_ode_euler(ode_func, y0, t_span)

plt.figure(figsize=(8, 6))
plt.plot(t, y[0], label='Solution')
plt.xlabel('Time')
plt.ylabel('y(t)')
plt.title('Solution of ODE: y\' = t + y')
plt.legend()
plt.grid(True)
plt.show()
