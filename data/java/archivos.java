import java.io.FileWriter;
import java.io.IOException;

public class FileWriterExample {
    public static void writeToFile(String text, String filePath) {
        try {
            FileWriter writer = new FileWriter(filePath);
            writer.write(text);
            writer.close();
            System.out.println("File written successfully.");
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        writeToFile("Hello, Java!", "output.txt");
    }
}
