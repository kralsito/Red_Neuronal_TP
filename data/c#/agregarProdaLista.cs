using System;
using System.Collections.Generic;

class Program
{
    static void Main(string[] args)
    {
        // Crear una lista de productos
        List<Producto> listaDeProductos = new List<Producto>();

        // Agregar algunos productos iniciales
        listaDeProductos.Add(new Producto(1, "Producto A", 10.99));
        listaDeProductos.Add(new Producto(2, "Producto B", 23.50));

        // Mostrar la lista de productos
        Console.WriteLine("Lista de productos inicial:");
        MostrarProductos(listaDeProductos);

        // Agregar un nuevo producto
        Producto nuevoProducto = new Producto(3, "Producto C", 15.75);
        AgregarProducto(listaDeProductos, nuevoProducto);

        // Mostrar la lista de productos actualizada
        Console.WriteLine("\nLista de productos después de agregar uno nuevo:");
        MostrarProductos(listaDeProductos);
    }

    static void AgregarProducto(List<Producto> lista, Producto producto)
    {
        lista.Add(producto);
        Console.WriteLine($"\nProducto agregado: {producto}");
    }

    static void MostrarProductos(List<Producto> lista)
    {
        foreach (var producto in lista)
        {
            Console.WriteLine(producto);
        }
    }
}
