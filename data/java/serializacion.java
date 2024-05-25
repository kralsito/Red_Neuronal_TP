import java.io.*;

public class ManejoArchivos {
    public static void main(String[] args) {
        try {
            ObjectOutputStream salida = new ObjectOutputStream(new FileOutputStream("datos.dat"));
            salida.writeObject(new Persona("Juan", 30));
            salida.close();

            ObjectInputStream entrada = new ObjectInputStream(new FileInputStream("datos.dat"));
            Persona personaRecuperada = (Persona) entrada.readObject();
            System.out.println("Nombre: " + personaRecuperada.getNombre() + ", Edad: " + personaRecuperada.getEdad());
            entrada.close();
        } catch (IOException | ClassNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    static class Persona implements Serializable {
        private String nombre;
        private int edad;

        public Persona(String nombre, int edad) {
            this.nombre = nombre;
            this.edad = edad;
        }

        public String getNombre() {
            return nombre;
        }

        public int getEdad() {
            return edad;
        }
    }
}
