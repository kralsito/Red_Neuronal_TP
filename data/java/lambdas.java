import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

        numbers.stream()
               .filter(n -> n % 2 == 0)
               .forEach(System.out::println);  // Output: 2 4 6 8 10
    }
}

@FunctionalInterface
interface OperacionMatematica {
    int operar(int a, int b);
}

public class Lambda {
    public static void main(String[] args) {
        OperacionMatematica suma = (a, b) -> a + b;
        OperacionMatematica resta = (a, b) -> a - b;

        System.out.println("Suma: " + suma.operar(5, 3));
        System.out.println("Resta: " + resta.operar(5, 3));
    }
}