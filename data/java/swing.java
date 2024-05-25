import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CalculadoraSwing extends JFrame implements ActionListener {
    private JTextField display;

    public CalculadoraSwing() {
        super("Calculadora");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 400);

        display = new JTextField();
        display.setEditable(false);
        display.setHorizontalAlignment(JTextField.RIGHT);
        add(display, BorderLayout.NORTH);

        JPanel panelBotones = new JPanel(new GridLayout(4, 4));
        String[] botones = {"7", "8", "9", "/", "4", "5", "6", "*", "1", "2", "3", "-", "0", ".", "=", "+"};
        for (String boton : botones) {
            JButton btn = new JButton(boton);
            btn.addActionListener(this);
            panelBotones.add(btn);
        }
        add(panelBotones, BorderLayout.CENTER);

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String textoBoton = ((JButton) e.getSource()).getText();
        display.setText(display.getText() + textoBoton);
    }

    public static void main(String[] args) {
        new CalculadoraSwing();
    }
}
