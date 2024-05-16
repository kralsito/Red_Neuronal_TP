import java.util.Scanner;

public class Primos {
    // Función para verificar si un número es primo
    public static boolean esPrimo(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    // Función para mostrar los primeros n números primos
    public static void mostrarPrimos(int n) {
        int count = 0;
        int num = 2;
        System.out.println("Los primeros " + n + " números primos son:");
        while (count < n) {
            if (esPrimo(num)) {
                System.out.print(num + " ");
                count++;
            }
            num++;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Solicitar al usuario el número de primos a mostrar
        System.out.print("Ingrese el número de primos a mostrar: ");
        int n = scanner.nextInt();

        // Mostrar los primeros n números primos
        mostrarPrimos(n);

        // Cerrar el scanner
        scanner.close();
    }
}
