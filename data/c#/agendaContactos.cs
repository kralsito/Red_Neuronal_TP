using System;
using System.Collections.Generic;

public class Contacto
{
    public int Id { get; set; }
    public string Nombre { get; set; }
    public string Telefono { get; set; }
    public string Email { get; set; }

    public Contacto(int id, string nombre, string telefono, string email)
    {
        Id = id;
        Nombre = nombre;
        Telefono = telefono;
        Email = email;
    }

    public void ActualizarContacto(string nombre, string telefono, string email)
    {
        Nombre = nombre;
        Telefono = telefono;
        Email = email;
    }

    public override string ToString()
    {
        return $"Id: {Id}, Nombre: {Nombre}, Telefono: {Telefono}, Email: {Email}";
    }
}

public class Agenda
{
    private List<Contacto> contactos;
    private int siguienteId;

    public Agenda()
    {
        contactos = new List<Contacto>();
        siguienteId = 1;
    }

    public void AgregarContacto(string nombre, string telefono, string email)
    {
        Contacto nuevoContacto = new Contacto(siguienteId++, nombre, telefono, email);
        contactos.Add(nuevoContacto);
        Console.WriteLine($"Contacto agregado: {nuevoContacto}");
    }

    public void EliminarContacto(int id)
    {
        Contacto contactoAEliminar = contactos.Find(c => c.Id == id);
        if (contactoAEliminar != null)
        {
            contactos.Remove(contactoAEliminar);
            Console.WriteLine($"Contacto eliminado: {contactoAEliminar}");
        }
        else
        {
            Console.WriteLine($"Contacto con Id {id} no encontrado.");
        }
    }

    public void ActualizarContacto(int id, string nombre, string telefono, string email)
    {
        Contacto contactoAActualizar = contactos.Find(c => c.Id == id);
        if (contactoAActualizar != null)
        {
            contactoAActualizar.ActualizarContacto(nombre, telefono, email);
            Console.WriteLine($"Contacto actualizado: {contactoAActualizar}");
        }
        else
        {
            Console.WriteLine($"Contacto con Id {id} no encontrado.");
        }
    }

    public void MostrarContactos()
    {
        Console.WriteLine("Lista de contactos:");
        foreach (var contacto in contactos)
        {
            Console.WriteLine(contacto);
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        Agenda agenda = new Agenda();

        // Agregar algunos contactos iniciales
        agenda.AgregarContacto("Juan Pérez", "123-4567", "juan.perez@example.com");
        agenda.AgregarContacto("María García", "765-4321", "maria.garcia@example.com");

        // Mostrar contactos iniciales
        agenda.MostrarContactos();

        // Actualizar un contacto
        agenda.ActualizarContacto(1, "Juan Pérez Actualizado", "987-6543", "juan.actualizado@example.com");

        // Eliminar un contacto
        agenda.EliminarContacto(2);

        // Mostrar contactos después de actualizaciones
        agenda.MostrarContactos();
    }
}
