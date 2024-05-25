public class CalculoAreaRectangulo {
    public static void main(String[] args) {
        int base = 5;
        int altura = 3;
        int area = calcularAreaRectangulo(base, altura);
        System.out.println("Área del rectángulo: " + area);
    }

    public static int calcularAreaRectangulo(int base, int altura) {
        return base * altura;
    }
}
