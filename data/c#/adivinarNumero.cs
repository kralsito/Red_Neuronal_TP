using System;

class AdivinaElNumero
{
    static void Main(string[] args)
    {
        Random random = new Random();

        const int MINIMO = 1;
        const int MAXIMO = 100;
        int numeroSecreto = random.Next(MINIMO, MAXIMO + 1);
        int intentos = 0;
        bool acertado = false;

        Console.WriteLine("¡Bienvenido al juego Adivina el Número!");
        Console.WriteLine($"Tienes que adivinar un número entre {MINIMO} y {MAXIMO}.");

        while (!acertado)
        {
            Console.Write("Ingresa tu intento: ");
            int intento;
            if (!int.TryParse(Console.ReadLine(), out intento))
            {
                Console.WriteLine("Por favor, ingresa un número válido.");
                continue;
            }

            intentos++;

            if (intento < numeroSecreto)
            {
                Console.WriteLine("El número secreto es mayor.");
            }
            else if (intento > numeroSecreto)
            {
                Console.WriteLine("El número secreto es menor.");
            }
            else
            {
                acertado = true;
                Console.WriteLine($"¡Felicidades! ¡Has adivinado el número secreto {numeroSecreto} en {intentos} intentos!");
            }
        }
    }
}
