import java.util.Scanner;

public class Factorial {
    // Función para calcular el factorial de un número
    public static long calcularFactorial(int n) {
        if (n < 0) {
            return -1; // Retornar -1 si n es negativo
        }
        long factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }
        return factorial;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Solicitar al usuario el número para calcular su factorial
        System.out.print("Ingrese un número para calcular su factorial: ");
        int numero = scanner.nextInt();

        // Calcular el factorial del número ingresado por el usuario
        long factorial = calcularFactorial(numero);

        // Mostrar el resultado del factorial
        if (factorial == -1) {
            System.out.println("Error: El número ingresado debe ser positivo.");
        } else {
            System.out.println("El factorial de " + numero + " es: " + factorial);
        }

        // Cerrar el scanner
        scanner.close();
    }
}
