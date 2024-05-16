import java.util.Random;
import java.util.Scanner;

public class LanzamientoDado {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        // Solicitar al usuario el número de lanzamientos
        System.out.print("Ingrese el número de lanzamientos del dado: ");
        int numLanzamientos = scanner.nextInt();

        // Arreglo para almacenar la frecuencia de cada cara del dado (de 1 a 6)
        int[] frecuencia = new int[6];

        // Realizar los lanzamientos del dado y contar la frecuencia de cada cara
        for (int i = 0; i < numLanzamientos; i++) {
            // Generar un número aleatorio entre 1 y 6 (inclusive) para simular el lanzamiento del dado
            int resultado = random.nextInt(6) + 1;
            // Incrementar la frecuencia correspondiente al resultado del lanzamiento
            frecuencia[resultado - 1]++;
            // Mostrar el resultado del lanzamiento
            System.out.println("Lanzamiento " + (i + 1) + ": " + resultado);
        }

        // Mostrar la frecuencia de cada cara del dado
        System.out.println("\nFrecuencia de cada cara del dado:");
        for (int i = 0; i < frecuencia.length; i++) {
            System.out.println("Cara " + (i + 1) + ": " + frecuencia[i]);
        }

        // Cerrar el scanner
        scanner.close();
    }
}
