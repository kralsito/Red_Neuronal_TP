class MiExcepcion extends Exception {
    public MiExcepcion(String mensaje) {
        super(mensaje);
    }
}

public class ManejoExcepcionesPersonalizadas {
    public static void main(String[] args) {
        try {
            validarEdad(-5);
        } catch (MiExcepcion e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public static void validarEdad(int edad) throws MiExcepcion {
        if (edad < 0) {
            throw new MiExcepcion("La edad no puede ser negativa.");
        }
        System.out.println("Edad válida: " + edad);
    }
}
