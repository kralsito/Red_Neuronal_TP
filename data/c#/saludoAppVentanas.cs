using System;
using System.Windows.Forms;

namespace VentanasApp
{
    public class FormInicio : Form
    {
        private TextBox textBoxNombre;
        private Button buttonSaludar;
        private Button buttonSalir;

        public FormInicio()
        {
            InitializeComponents();
        }

        private void InitializeComponents()
        {
            textBoxNombre = new TextBox();
            buttonSaludar = new Button();
            buttonSalir = new Button();

            textBoxNombre.Location = new System.Drawing.Point(30, 30);
            textBoxNombre.Size = new System.Drawing.Size(200, 20);

            buttonSaludar.Location = new System.Drawing.Point(30, 70);
            buttonSaludar.Size = new System.Drawing.Size(90, 30);
            buttonSaludar.Text = "Saludar";
            buttonSaludar.Click += new EventHandler(buttonSaludar_Click);

            buttonSalir.Location = new System.Drawing.Point(140, 70);
            buttonSalir.Size = new System.Drawing.Size(90, 30);
            buttonSalir.Text = "Salir";
            buttonSalir.Click += new EventHandler(buttonSalir_Click);

            this.Controls.Add(textBoxNombre);
            this.Controls.Add(buttonSaludar);
            this.Controls.Add(buttonSalir);

            this.Text = "Inicio";
            this.StartPosition = FormStartPosition.CenterScreen;
        }

        private void buttonSaludar_Click(object sender, EventArgs e)
        {
            string nombre = textBoxNombre.Text;
            FormSaludo formSaludo = new FormSaludo(nombre);
            formSaludo.ShowDialog();
        }

        private void buttonSalir_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new FormInicio());
        }
    }

    public class FormSaludo : Form
    {
        private Label labelSaludo;

        public FormSaludo(string nombre)
        {
            InitializeComponents(nombre);
        }

        private void InitializeComponents(string nombre)
        {
            labelSaludo = new Label();

            labelSaludo.Text = $"¡Hola, {nombre}!";
            labelSaludo.Location = new System.Drawing.Point(30, 30);
            labelSaludo.AutoSize = true;

            this.Controls.Add(labelSaludo);

            this.Text = "Saludo";
            this.StartPosition = FormStartPosition.CenterScreen;
            this.FormClosed += new FormClosedEventHandler(FormSaludo_FormClosed);
        }

        private void FormSaludo_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}
