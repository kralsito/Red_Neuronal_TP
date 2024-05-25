using System;

class Persona
{
    // Propiedades de la clase Persona
    public string Nombre { get; set; }
    public int Edad { get; set; }

    // Constructor de la clase Persona
    public Persona(string nombre, int edad)
    {
        Nombre = nombre;
        Edad = edad;
    }

    // Método de la clase Persona para saludar
    public void Saludar()
    {
        Console.WriteLine($"Hola, mi nombre es {Nombre} y tengo {Edad} años.");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Creamos una instancia de la clase Persona
        Persona persona1 = new Persona("Juan", 30);

        // Llamamos al método Saludar de la instancia persona1
        persona1.Saludar();
    }
}
