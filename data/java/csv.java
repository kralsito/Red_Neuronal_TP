import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ManejoArchivosCSV {
    public static void main(String[] args) {
        List<String[]> registros = new ArrayList<>();
        registros.add(new String[]{"Nombre", "Edad", "Correo"});
        registros.add(new String[]{"Juan", "30", "juan@example.com"});
        registros.add(new String[]{"María", "25", "maria@example.com"});

        escribirCSV(registros, "datos.csv");

        List<String[]> datosLeidos = leerCSV("datos.csv");
        for (String[] registro : datosLeidos) {
            for (String campo : registro) {
                System.out.print(campo + "\t");
            }
            System.out.println();
        }
    }

    public static void escribirCSV(List<String[]> registros, String archivo) {
        try (FileWriter writer = new FileWriter(archivo)) {
            for (String[] registro : registros) {
                StringBuilder linea = new StringBuilder();
                for (String campo : registro) {
                    linea.append(campo).append(",");
                }
                linea.deleteCharAt(linea.length() - 1); // Eliminar última coma
                linea.append("\n");
                writer.write(linea.toString());
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static List<String[]> leerCSV(String archivo) {
        List<String[]> registros = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(archivo))) {
            String linea;
            while ((linea = reader.readLine()) != null) {
                String[] campos = linea.split(",");
                registros.add(campos);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return registros;
    }
}
