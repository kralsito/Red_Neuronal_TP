import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class AgendaContactos extends Application {
    private TextField txtNombre;
    private TextField txtTelefono;
    private Label lblMensaje;

    @Override
    public void start(Stage primaryStage) {
        txtNombre = new TextField();
        txtTelefono = new TextField();
        lblMensaje = new Label();

        Button btnGuardar = new Button("Guardar");
        btnGuardar.setOnAction(e -> guardarContacto());

        GridPane grid = new GridPane();
        grid.add(new Label("Nombre:"), 0, 0);
        grid.add(txtNombre, 1, 0);
        grid.add(new Label("Teléfono:"), 0, 1);
        grid.add(txtTelefono, 1, 1);
        grid.add(btnGuardar, 0, 2);
        grid.add(lblMensaje, 1, 2);

        Scene scene = new Scene(grid, 300, 200);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Agenda de Contactos");
        primaryStage.show();
    }

    private void guardarContacto() {
        String nombre = txtNombre.getText();
        String telefono = txtTelefono.getText();
        // Lógica para guardar el contacto en una base de datos, archivo, etc.
        lblMensaje.setText("Contacto guardado: " + nombre + ", Teléfono: " + telefono);
    }

    public static void main(String[] args) {
        launch(args);
    }
}
