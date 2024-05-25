from scipy.integrate import solve_ivp
import matplotlib.pyplot as plt

def ode_func(t, y):
    return t + y

t_span = (0, 10)
y0 = 1
sol = solve_ivp(ode_func, t_span, [y0], dense_output=True)

t = np.linspace(0, 10, 100)
y = sol.sol(t)

plt.figure(figsize=(8, 6))
plt.plot(t, y[0], label='Solution')
plt.xlabel('Time')
plt.ylabel('y(t)')
plt.title('Solution of ODE: y\' = t + y')
plt.legend()
plt.grid(True)
plt.show()
