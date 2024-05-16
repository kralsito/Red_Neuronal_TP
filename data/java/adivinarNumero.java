import java.util.Scanner;
import java.util.Random;

public class AdivinaElNumero {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        final int MINIMO = 1;
        final int MAXIMO = 100;
        int numeroSecreto = random.nextInt(MAXIMO - MINIMO + 1) + MINIMO;
        int intentos = 0;
        boolean acertado = false;

        System.out.println("¡Bienvenido al juego Adivina el Número!");
        System.out.println("Tienes que adivinar un número entre " + MINIMO + " y " + MAXIMO + ".");

        while (!acertado) {
            System.out.print("Ingresa tu intento: ");
            int intento = scanner.nextInt();
            intentos++;

            if (intento < numeroSecreto) {
                System.out.println("El número secreto es mayor.");
            } else if (intento > numeroSecreto) {
                System.out.println("El número secreto es menor.");
            } else {
                acertado = true;
                System.out.println("¡Felicidades! ¡Has adivinado el número secreto " + numeroSecreto + " en " + intentos + " intentos!");
            }
        }

        scanner.close();
    }
}
