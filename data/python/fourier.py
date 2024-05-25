import numpy as np
import matplotlib.pyplot as plt

# Crear una señal de ejemplo
t = np.linspace(0, 2*np.pi, 1000)
signal = np.sin(2*np.pi*5*t) + 0.5*np.sin(2*np.pi*10*t)

# Calcular la Transformada de Fourier
fourier_transform = np.fft.fft(signal)
freq = np.fft.fftfreq(len(signal), d=t[1]-t[0])

# Graficar la señal y su espectro de frecuencia
plt.figure(figsize=(12, 6))

plt.subplot(1, 2, 1)
plt.plot(t, signal)
plt.xlabel('Time')
plt.ylabel('Amplitude')
plt.title('Original Signal')

plt.subplot(1, 2, 2)
plt.plot(freq, np.abs(fourier_transform))
plt.xlabel('Frequency')
plt.ylabel('Amplitude')
plt.title('Fourier Transform')
plt.xlim(-15, 15)

plt.tight_layout()
plt.show()
