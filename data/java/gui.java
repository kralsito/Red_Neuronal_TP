import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class CalculadoraFX extends Application {
    @Override
    public void start(Stage primaryStage) {
        TextField display = new TextField();
        display.setEditable(false);

        VBox root = new VBox();
        root.getChildren().add(display);

        String[] buttonLabels = {"7", "8", "9", "+", "4", "5", "6", "-", "1", "2", "3", "*", "0", "=", "C", "/"};
        for (String label : buttonLabels) {
            Button button = new Button(label);
            button.setOnAction(e -> {
                if (label.equals("=")) {
                    String expression = display.getText();
                    String result = evaluarExpresion(expression);
                    display.setText(result);
                } else if (label.equals("C")) {
                    display.clear();
                } else {
                    display.appendText(label);
                }
            });
            root.getChildren().add(button);
        }

        Scene scene = new Scene(root, 200, 250);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Calculadora");
        primaryStage.show();
    }

    private String evaluarExpresion(String expression) {
        // Implementar lógica de evaluación de expresión matemática
        return "Resultado";
    }

    public static void main(String[] args) {
        launch(args);
    }
}
