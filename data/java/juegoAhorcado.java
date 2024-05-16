import java.util.Scanner;
import java.util.Random;

public class Ahorcado {
    private static final String[] PALABRAS = {"ordenador", "java", "programacion", "codigo", "inteligencia", "aplicacion", "algoritmo"};
    private static final int MAX_INTENTOS = 6;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        String palabraSecreta = PALABRAS[random.nextInt(PALABRAS.length)];
        char[] palabraAdivinada = new char[palabraSecreta.length()];
        for (int i = 0; i < palabraAdivinada.length; i++) {
            palabraAdivinada[i] = '_';
        }

        int intentosRestantes = MAX_INTENTOS;
        boolean juegoTerminado = false;

        System.out.println("¡Bienvenido al juego de Ahorcado!");
        System.out.println("Intenta adivinar la palabra secreta.");

        while (!juegoTerminado) {
            System.out.println("\nPalabra: " + String.valueOf(palabraAdivinada));
            System.out.println("Intentos restantes: " + intentosRestantes);
            System.out.print("Ingresa una letra: ");
            char letra = scanner.next().charAt(0);

            boolean letraEncontrada = false;
            for (int i = 0; i < palabraSecreta.length(); i++) {
                if (palabraSecreta.charAt(i) == letra) {
                    palabraAdivinada[i] = letra;
                    letraEncontrada = true;
                }
            }

            if (!letraEncontrada) {
                intentosRestantes--;
                System.out.println("La letra no está en la palabra.");
            }

            if (intentosRestantes == 0 || String.valueOf(palabraAdivinada).equals(palabraSecreta)) {
                juegoTerminado = true;
            }
        }

        if (intentosRestantes == 0) {
            System.out.println("\n¡Has perdido! La palabra secreta era: " + palabraSecreta);
        } else {
            System.out.println("\n¡Felicidades! ¡Has adivinado la palabra secreta!");
        }

        scanner.close();
    }
}
