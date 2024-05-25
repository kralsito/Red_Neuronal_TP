import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Fechas {
    public static void main(String[] args) {
        LocalDate fechaActual = LocalDate.now();
        System.out.println("Fecha actual: " + fechaActual);

        LocalDateTime fechaHoraActual = LocalDateTime.now();
        System.out.println("Fecha y hora actual: " + fechaHoraActual);

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm:ss");
        String fechaHoraFormateada = fechaHoraActual.format(formatter);
        System.out.println("Fecha y hora formateadas: " + fechaHoraFormateada);
    }
}
