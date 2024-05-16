import java.util.ArrayList;
import java.util.Scanner;

class Contacto {
    private String nombre;
    private String telefono;

    public Contacto(String nombre, String telefono) {
        this.nombre = nombre;
        this.telefono = telefono;
    }

    public String getNombre() {
        return nombre;
    }

    public String getTelefono() {
        return telefono;
    }

    @Override
    public String toString() {
        return nombre + ": " + telefono;
    }
}

public class Agenda {
    private static ArrayList<Contacto> contactos = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean salir = false;
        while (!salir) {
            mostrarMenu();
            int opcion = scanner.nextInt();
            switch (opcion) {
                case 1:
                    agregarContacto();
                    break;
                case 2:
                    verContactos();
                    break;
                case 3:
                    buscarContacto();
                    break;
                case 4:
                    salir = true;
                    break;
                default:
                    System.out.println("Opción no válida. Intente de nuevo.");
            }
        }
        scanner.close();
    }

    private static void mostrarMenu() {
        System.out.println("\n=== MENÚ ===");
        System.out.println("1. Agregar contacto");
        System.out.println("2. Ver lista de contactos");
        System.out.println("3. Buscar contacto");
        System.out.println("4. Salir");
        System.out.print("Ingrese su opción: ");
    }

    private static void agregarContacto() {
        scanner.nextLine(); // Consumir el salto de línea pendiente
        System.out.print("Ingrese el nombre del contacto: ");
        String nombre = scanner.nextLine();
        System.out.print("Ingrese el teléfono del contacto: ");
        String telefono = scanner.nextLine();
        contactos.add(new Contacto(nombre, telefono));
        System.out.println("Contacto agregado correctamente.");
    }

    private static void verContactos() {
        if (contactos.isEmpty()) {
            System.out.println("No hay contactos para mostrar.");
        } else {
            System.out.println("\n=== LISTA DE CONTACTOS ===");
            for (Contacto contacto : contactos) {
                System.out.println(contacto);
            }
        }
    }

    private static void buscarContacto() {
        if (contactos.isEmpty()) {
            System.out.println("No hay contactos para buscar.");
            return;
        }
        scanner.nextLine(); // Consumir el salto de línea pendiente
        System.out.print("Ingrese el nombre del contacto a buscar: ");
        String nombreBuscado = scanner.nextLine();
        boolean encontrado = false;
        for (Contacto contacto : contactos) {
            if (contacto.getNombre().equalsIgnoreCase(nombreBuscado)) {
                System.out.println("Contacto encontrado: " + contacto);
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            System.out.println("No se encontró ningún contacto con el nombre especificado.");
        }
    }
}
