using System;
using System.Collections.Generic;


public class TiendaOnline
{
    private List<Medicamento> inventario;

    public void MostrarInventario()
    {
        Console.WriteLine("Inventario de la Tienda Online:");
        foreach (var medicamento in inventario)
        {
            Console.WriteLine(medicamento);
        }
    }

    public bool VenderMedicamento(string nombre, int cantidad)
    {
        Medicamento medicamento = inventario.Find(m => m.Nombre == nombre);
        if (medicamento != null && medicamento.Stock >= cantidad)
        {
            medicamento.Stock -= cantidad;
            Console.WriteLine($"Venta realizada: {cantidad} unidades de {nombre}");
            return true;
        }
        else if (medicamento != null && medicamento.Stock < cantidad)
        {
            Console.WriteLine($"No hay suficiente stock de {nombre}");
            return false;
        }
        else
        {
            Console.WriteLine($"El medicamento {nombre} no está disponible en la tienda");
            return false;
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        TiendaOnline tienda = new TiendaOnline();

        // Mostrar inventario inicial
        tienda.MostrarInventario();

        // Realizar algunas ventas
        tienda.VenderMedicamento("Paracetamol", 20);
        tienda.VenderMedicamento("Ibuprofeno", 15);
        tienda.VenderMedicamento("Amoxicilina", 30);

        // Mostrar inventario después de las ventas
        tienda.MostrarInventario();
    }
}
