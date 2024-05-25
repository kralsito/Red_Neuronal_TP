import java.util.ArrayList;
import java.util.List;

public class Colecciones {
    public static void main(String[] args) {
        List<String> nombres = new ArrayList<>();
        nombres.add("Juan");
        nombres.add("María");
        nombres.add("Pedro");

        for (String nombre : nombres) {
            System.out.println(nombre);
        }

        if (nombres.contains("María")) {
            System.out.println("María está en la lista.");
        }
    }
}
