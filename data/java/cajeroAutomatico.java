import java.util.Scanner;

public class CajeroAutomatico {
    private static double saldo = 1000; // Saldo inicial

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean salir = false;

        System.out.println("¡Bienvenido al Cajero Automático!");
        while (!salir) {
            mostrarMenu();
            int opcion = scanner.nextInt();
            switch (opcion) {
                case 1:
                    consultarSaldo();
                    break;
                case 2:
                    depositar();
                    break;
                case 3:
                    retirar();
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
        System.out.println("1. Consultar saldo");
        System.out.println("2. Depositar dinero");
        System.out.println("3. Retirar dinero");
        System.out.println("4. Salir");
        System.out.print("Ingrese su opción: ");
    }

    private static void consultarSaldo() {
        System.out.println("Su saldo actual es: $" + saldo);
    }

    private static void depositar() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese la cantidad a depositar: $");
        double cantidad = scanner.nextDouble();
        if (cantidad > 0) {
            saldo += cantidad;
            System.out.println("Depósito exitoso. Su saldo actual es: $" + saldo);
        } else {
            System.out.println("Cantidad no válida. El depósito no se realizó.");
        }
    }

    private static void retirar() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Ingrese la cantidad a retirar: $");
        double cantidad = scanner.nextDouble();
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            System.out.println("Retiro exitoso. Su saldo actual es: $" + saldo);
        } else {
            System.out.println("Cantidad no válida o saldo insuficiente. El retiro no se realizó.");
        }
    }
}
