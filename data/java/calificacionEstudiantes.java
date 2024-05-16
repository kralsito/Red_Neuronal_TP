import java.util.Scanner;

// Clase para representar a un estudiante
class Estudiante {
    private String nombre;
    private int edad;
    private double[] calificaciones;

    // Constructor
    public Estudiante(String nombre, int edad, int numAsignaturas) {
        this.nombre = nombre;
        this.edad = edad;
        this.calificaciones = new double[numAsignaturas];
    }

    // Método para ingresar las calificaciones del estudiante
    public void ingresarCalificaciones(Scanner scanner) {
        System.out.println("Ingrese las calificaciones para el estudiante " + nombre + ":");
        for (int i = 0; i < calificaciones.length; i++) {
            System.out.print("Calificación en la asignatura #" + (i + 1) + ": ");
            calificaciones[i] = scanner.nextDouble();
        }
    }

    // Método para calcular el promedio de calificaciones del estudiante
    public double calcularPromedio() {
        double suma = 0;
        for (double calificacion : calificaciones) {
            suma += calificacion;
        }
        return suma / calificaciones.length;
    }

    // Método para mostrar la información del estudiante
    public void mostrarInformacion() {
        System.out.println("\nInformación del estudiante:");
        System.out.println("Nombre: " + nombre);
        System.out.println("Edad: " + edad);
        System.out.println("Calificaciones:");
        for (int i = 0; i < calificaciones.length; i++) {
            System.out.println("Asignatura #" + (i + 1) + ": " + calificaciones[i]);
        }
        System.out.println("Promedio: " + calcularPromedio());
    }
}

// Clase principal del programa
public class GestionEstudiantes {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Solicitar al usuario el número de estudiantes y el número de asignaturas
        System.out.print("Ingrese el número de estudiantes: ");
        int numEstudiantes = scanner.nextInt();
        System.out.print("Ingrese el número de asignaturas: ");
        int numAsignaturas = scanner.nextInt();

        // Crear un arreglo de objetos Estudiante
        Estudiante[] estudiantes = new Estudiante[numEstudiantes];

        // Crear y llenar los datos de cada estudiante
        for (int i = 0; i < numEstudiantes; i++) {
            System.out.println("\nIngrese los datos del estudiante #" + (i + 1) + ":");
            scanner.nextLine(); // Consumir el salto de línea pendiente
            System.out.print("Nombre: ");
            String nombre = scanner.nextLine();
            System.out.print("Edad: ");
            int edad = scanner.nextInt();
            estudiantes[i] = new Estudiante(nombre, edad, numAsignaturas);
            estudiantes[i].ingresarCalificaciones(scanner);
        }

        // Mostrar la información de cada estudiante
        System.out.println("\nInformación de los estudiantes:");
        for (int i = 0; i < numEstudiantes; i++) {
            estudiantes[i].mostrarInformacion();
        }

        // Cerrar el scanner
        scanner.close();
    }
}
