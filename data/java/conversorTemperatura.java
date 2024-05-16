import java.util.Scanner;

public class ConversorTemperatura {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Mostrar el menú de opciones
        System.out.println("Bienvenido al conversor de temperatura");
        System.out.println("1. Convertir de Celsius a Fahrenheit");
        System.out.println("2. Convertir de Fahrenheit a Celsius");
        System.out.print("Seleccione la opción deseada (1 o 2): ");

        // Leer la opción del usuario
        int opcion = scanner.nextInt();

        // Variables para almacenar la temperatura
        double temperatura;
        double resultado;

        // Realizar la conversión según la opción seleccionada
        if (opcion == 1) {
            // Conversión de Celsius a Fahrenheit
            System.out.print("Ingrese la temperatura en Celsius: ");
            temperatura = scanner.nextDouble();
            resultado = celsiusAFahrenheit(temperatura);
            System.out.println("La temperatura en Fahrenheit es: " + resultado + " °F");
        } else if (opcion == 2) {
            // Conversión de Fahrenheit a Celsius
            System.out.print("Ingrese la temperatura en Fahrenheit: ");
            temperatura = scanner.nextDouble();
            resultado = fahrenheitACelsius(temperatura);
            System.out.println("La temperatura en Celsius es: " + resultado + " °C");
        } else {
            System.out.println("Opción no válida. Por favor, seleccione 1 o 2.");
        }

        scanner.close();
    }

    // Función para convertir Celsius a Fahrenheit
    public static double celsiusAFahrenheit(double celsius) {
        return (celsius * 9 / 5) + 32;
    }

    // Función para convertir Fahrenheit a Celsius
    public static double fahrenheitACelsius(double fahrenheit) {
        return (fahrenheit - 32) * 5 / 9;
    }
}
