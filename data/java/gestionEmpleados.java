import java.util.ArrayList;
import java.util.Scanner;

// Clase para representar a un empleado
class Empleado {
    private int id;
    private String nombre;
    private double salario;

    // Constructor
    public Empleado(int id, String nombre, double salario) {
        this.id = id;
        this.nombre = nombre;
        this.salario = salario;
    }

    // Métodos getters y setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    // Método para imprimir los detalles del empleado
    public void imprimirDetalles() {
        System.out.println("ID: " + id + ", Nombre: " + nombre + ", Salario: $" + salario);
    }
}

public class GestionEmpleados {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Empleado> empleados = new ArrayList<>();

        boolean salir = false;
        while (!salir) {
            System.out.println("\n=== Menú de Gestión de Empleados ===");
            System.out.println("1. Agregar nuevo empleado");
            System.out.println("2. Listar todos los empleados");
            System.out.println("3. Buscar empleado por ID");
            System.out.println("4. Calcular salario total de todos los empleados");
            System.out.println("5. Salir");
            System.out.print("Ingrese su opción: ");
            int opcion = scanner.nextInt();

            switch (opcion) {
                case 1:
                    System.out.println("\n=== Agregar Nuevo Empleado ===");
                    System.out.print("Ingrese el ID del empleado: ");
                    int id = scanner.nextInt();
                    scanner.nextLine(); // Consumir el salto de línea pendiente
                    System.out.print("Ingrese el nombre del empleado: ");
                    String nombre = scanner.nextLine();
                    System.out.print("Ingrese el salario del empleado: $");
                    double salario = scanner.nextDouble();
                    empleados.add(new Empleado(id, nombre, salario));
                    System.out.println("¡Empleado agregado correctamente!");
                    break;
                case 2:
                    System.out.println("\n=== Listado de Empleados ===");
                    for (Empleado empleado : empleados) {
                        empleado.imprimirDetalles();
                    }
                    break;
                case 3:
                    System.out.println("\n=== Buscar Empleado por ID ===");
                    System.out.print("Ingrese el ID del empleado a buscar: ");
                    int idBusqueda = scanner.nextInt();
                    boolean encontrado = false;
                    for (Empleado empleado : empleados) {
                        if (empleado.getId() == idBusqueda) {
                            empleado.imprimirDetalles();
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) {
                        System.out.println("No se encontró ningún empleado con el ID especificado.");
                    }
                    break;
                case 4:
                    System.out.println("\n=== Salario Total de Todos los Empleados ===");
                    double salarioTotal = 0;
                    for (Empleado empleado : empleados) {
                        salarioTotal += empleado.getSalario();
                    }
                    System.out.println("El salario total de todos los empleados es: $" + salarioTotal);
                    break;
                case 5:
                    salir = true;
                    break;
                default:
                    System.out.println("Opción no válida. Por favor, ingrese una opción válida.");
            }
        }

        scanner.close();
    }
}
