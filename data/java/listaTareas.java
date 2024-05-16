import java.util.ArrayList;
import java.util.Scanner;

class Tarea {
    private String descripcion;
    private boolean completada;

    public Tarea(String descripcion) {
        this.descripcion = descripcion;
        this.completada = false;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public boolean estaCompletada() {
        return completada;
    }

    public void marcarComoCompletada() {
        completada = true;
    }

    @Override
    public String toString() {
        return (completada ? "[X] " : "[ ] ") + descripcion;
    }
}

public class GestionTareas {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Tarea> tareas = new ArrayList<>();

        boolean salir = false;
        while (!salir) {
            System.out.println("\n=== Menú de Gestión de Tareas ===");
            System.out.println("1. Agregar nueva tarea");
            System.out.println("2. Marcar tarea como completada");
            System.out.println("3. Ver todas las tareas");
            System.out.println("4. Eliminar tarea");
            System.out.println("5. Salir");
            System.out.print("Ingrese su opción: ");
            int opcion = scanner.nextInt();
            scanner.nextLine(); // Consumir el salto de línea pendiente

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese la descripción de la tarea: ");
                    String descripcion = scanner.nextLine();
                    tareas.add(new Tarea(descripcion));
                    System.out.println("Tarea agregada correctamente.");
                    break;
                case 2:
                    System.out.print("Ingrese el índice de la tarea a marcar como completada: ");
                    int indiceCompletada = scanner.nextInt();
                    if (indiceCompletada >= 0 && indiceCompletada < tareas.size()) {
                        tareas.get(indiceCompletada).marcarComoCompletada();
                        System.out.println("Tarea marcada como completada.");
                    } else {
                        System.out.println("Índice de tarea no válido.");
                    }
                    break;
                case 3:
                    System.out.println("\n=== Lista de Tareas ===");
                    for (int i = 0; i < tareas.size(); i++) {
                        System.out.println((i + 1) + ". " + tareas.get(i));
                    }
                    break;
                case 4:
                    System.out.print("Ingrese el índice de la tarea a eliminar: ");
                    int indiceEliminar = scanner.nextInt();
                    if (indiceEliminar >= 0 && indiceEliminar < tareas.size()) {
                        tareas.remove(indiceEliminar);
                        System.out.println("Tarea eliminada correctamente.");
                    } else {
                        System.out.println("Índice de tarea no válido.");
                    }
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
