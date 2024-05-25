// Clase principal Persona
public class Persona {
    private String nombre;
    private int edad;

    public Persona(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }

    public void saludar() {
        System.out.println("Hola, soy " + nombre + " y tengo " + edad + " años.");
    }
}

// Clase Empleado que hereda de Persona
public class Empleado extends Persona {
    private double salario;

    public Empleado(String nombre, int edad, double salario) {
        super(nombre, edad);
        this.salario = salario;
    }

    public void trabajar() {
        System.out.println("Soy " + getNombre() + " y estoy trabajando.");
    }

    public static void main(String[] args) {
        Empleado empleado = new Empleado("Juan", 30, 3000.0);
        empleado.saludar();
        empleado.trabajar();
    }
}
