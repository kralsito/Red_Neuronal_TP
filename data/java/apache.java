import org.apache.commons.lang3.StringUtils;

public class EjemploApacheCommonsLang {
    public static void main(String[] args) {
        String texto = "ejemplo de texto";
        System.out.println("Texto en mayúsculas: " + StringUtils.upperCase(texto));
        System.out.println("Texto invertido: " + StringUtils.reverse(texto));
    }
}
