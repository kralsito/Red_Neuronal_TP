using System;

class Program
{
    static void Main(string[] args)
    {
        // Palabra a invertir
        string palabra = "Hola";

        // Invertir la palabra
        string palabraInvertida = InvertirPalabra(palabra);

        // Mostrar el resultado
        Console.WriteLine($"Palabra original: {palabra}");
        Console.WriteLine($"Palabra invertida: {palabraInvertida}");
    }

    static string InvertirPalabra(string palabra)
    {
        // Convertir la palabra en un arreglo de caracteres
        char[] caracteres = palabra.ToCharArray();

        // Invertir el arreglo de caracteres
        Array.Reverse(caracteres);

        // Convertir el arreglo de caracteres invertido nuevamente a una cadena
        return new string(caracteres);
    }
}
