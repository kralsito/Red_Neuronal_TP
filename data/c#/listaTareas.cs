using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        List<Tarea> listaTareas = new List<Tarea>();

        while (true)
        {
            Console.WriteLine("=== Administrador de Tareas ===");
            Console.WriteLine("1. Agregar Tarea");
            Console.WriteLine("2. Marcar Tarea como Completada");
            Console.WriteLine("3. Mostrar Lista de Tareas");
            Console.WriteLine("4. Salir");
            Console.WriteLine("===============================");
            Console.Write("Seleccione una opción: ");

            string opcion = Console.ReadLine();

            switch (opcion)
            {
                case "1":
                    Console.Write("Ingrese la descripción de la tarea: ");
                    string descripcion = Console.ReadLine();
                    Tarea nuevaTarea = new Tarea(descripcion);
                    listaTareas.Add(nuevaTarea);
                    Console.WriteLine("Tarea agregada correctamente.");
                    break;
                case "2":
                    if (listaTareas.Count == 0)
                    {
                        Console.WriteLine("No hay tareas en la lista.");
                        break;
                    }

                    Console.WriteLine("Lista de Tareas:");
                    for (int i = 0; i < listaTareas.Count; i++)
                    {
                        Console.WriteLine($"{i + 1}. {listaTareas[i]}");
                    }

                    Console.Write("Seleccione el número de la tarea a marcar como completada: ");
                    int indiceTareaCompletada;
                    while (!int.TryParse(Console.ReadLine(), out indiceTareaCompletada) || indiceTareaCompletada < 1 || indiceTareaCompletada > listaTareas.Count)
                    {
                        Console.Write("Número inválido. Por favor, ingrese un número válido: ");
                    }

                    listaTareas[indiceTareaCompletada - 1].Completada = true;
                    Console.WriteLine("Tarea marcada como completada correctamente.");
                    break;
                case "3":
                    if (listaTareas.Count == 0)
                    {
                        Console.WriteLine("No hay tareas en la lista.");
                        break;
                    }

                    Console.WriteLine("Lista de Tareas:");
                    for (int i = 0; i < listaTareas.Count; i++)
                    {
                        Console.WriteLine($"{i + 1}. {listaTareas[i]}");
                    }
                    break;
                case "4":
                    Console.WriteLine("¡Hasta luego!");
                    return;
                default:
                    Console.WriteLine("Opción inválida. Por favor, seleccione una opción válida.");
                    break;
            }

            Console.WriteLine();
        }
    }
}

class Tarea
{
    public string Descripcion { get; set; }
    public bool Completada { get; set; }

    public Tarea(string descripcion)
    {
        Descripcion = descripcion;
        Completada = false;
    }

    public override string ToString()
    {
        string estado = Completada ? "[Completada]" : "[Pendiente]";
        return $"{estado} {Descripcion}";
    }
}
