using System;
using Xamarin.Forms;

namespace NotasApp
{
    public class Nota
    {
        public string Titulo { get; set; }
        public string Contenido { get; set; }
    }

    public partial class MainPage : ContentPage
    {
        ObservableCollection<Nota> listaNotas = new ObservableCollection<Nota>();

        public MainPage()
        {
            InitializeComponent();

            ListView listaView = new ListView();
            listaView.ItemsSource = listaNotas;
            listaView.ItemTemplate = new DataTemplate(typeof(TextCell));
            listaView.ItemTemplate.SetBinding(TextCell.TextProperty, "Titulo");
            listaView.ItemSelected += ListaView_ItemSelected;

            Entry entryTitulo = new Entry();
            entryTitulo.Placeholder = "Título";

            Editor editorContenido = new Editor();
            editorContenido.Placeholder = "Contenido";

            Button botonGuardar = new Button();
            botonGuardar.Text = "Guardar Nota";
            botonGuardar.Clicked += BotonGuardar_Clicked;

            StackLayout stackLayout = new StackLayout();
            stackLayout.Children.Add(entryTitulo);
            stackLayout.Children.Add(editorContenido);
            stackLayout.Children.Add(botonGuardar);
            stackLayout.Children.Add(listaView);

            Content = stackLayout;
        }

        private void BotonGuardar_Clicked(object sender, EventArgs e)
        {
            Entry entryTitulo = Content.Children[0] as Entry;
            Editor editorContenido = Content.Children[1] as Editor;

            if (!string.IsNullOrEmpty(entryTitulo.Text) && !string.IsNullOrEmpty(editorContenido.Text))
            {
                listaNotas.Add(new Nota { Titulo = entryTitulo.Text, Contenido = editorContenido.Text });
                entryTitulo.Text = string.Empty;
                editorContenido.Text = string.Empty;
            }
            else
            {
                DisplayAlert("Error", "Por favor, ingrese tanto el título como el contenido de la nota.", "Aceptar");
            }
        }

        private void ListaView_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            if (e.SelectedItem != null)
            {
                Nota notaSeleccionada = (Nota)e.SelectedItem;
                listaNotas.Remove(notaSeleccionada);
            }
        }
    }
}
