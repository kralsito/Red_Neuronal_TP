import java.util.Scanner;

class Ejemplo_4_Switch{
    public static void main(String[] args){
        int opcion, valor1, valor2, resultado;
        Scanner teclado = new Scanner(System.in);

        System.out.println("Ingrese un valor: ");
        valor1 = teclado.nextInt();

        System.out.println("\nIngrese segundo valor: ");
        valor2 = teclado.nextInt();

        System.out.println("\n\nSeleccione una opcion: ");
        System.out.println("Opcion 1: Suma");
        System.out.println("Opcion 2: Resta");
        opcion = teclado.nextInt();
        teclado.close();
        
        switch (opcion) {
            case 1:
                resultado = valor1 + valor2;
                System.out.println("La suma es: " + resultado);
                break;
            case 2:
                resultado = valor1 - valor2;
                System.out.println("La resta es: " + resultado);
                break;

            default:
                System.out.println("default");
                break;
        }
    }
}