using System;
using System.Threading;

public enum EstadoSemaforo
{
    Rojo,
    Amarillo,
    Verde
}

public class Semaforo
{
    public EstadoSemaforo EstadoActual { get; private set; }

    public Semaforo()
    {
        EstadoActual = EstadoSemaforo.Rojo;
    }

    public void CambiarEstado()
    {
        switch (EstadoActual)
        {
            case EstadoSemaforo.Rojo:
                EstadoActual = EstadoSemaforo.Verde;
                break;
            case EstadoSemaforo.Verde:
                EstadoActual = EstadoSemaforo.Amarillo;
                break;
            case EstadoSemaforo.Amarillo:
                EstadoActual = EstadoSemaforo.Rojo;
                break;
        }
    }

    public void MostrarEstado()
    {
        Console.WriteLine($"El semáforo está en: {EstadoActual}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Semaforo semaforo = new Semaforo();
        int intervaloRojo = 5000; // 5 segundos
        int intervaloVerde = 4000; // 4 segundos
        int intervaloAmarillo = 2000; // 2 segundos

        for (int i = 0; i < 10; i++) // Ciclo de 10 cambios
        {
            semaforo.MostrarEstado();

            switch (semaforo.EstadoActual)
            {
                case EstadoSemaforo.Rojo:
                    Thread.Sleep(intervaloRojo);
                    break;
                case EstadoSemaforo.Verde:
                    Thread.Sleep(intervaloVerde);
                    break;
                case EstadoSemaforo.Amarillo:
                    Thread.Sleep(intervaloAmarillo);
                    break;
            }

            semaforo.CambiarEstado();
        }

        Console.WriteLine("Ciclo de semáforo completo.");
    }
}
