public class BucleFor {
    public static void main(String[] args) {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Número: " + i);
        }
    }
}

public class Arreglo {
    public static void main(String[] args) {
        String[] nombres = {"Juan", "María", "Pedro"};

        for (String nombre : nombres) {
            System.out.println("Nombre: " + nombre);
        }
    }
}
