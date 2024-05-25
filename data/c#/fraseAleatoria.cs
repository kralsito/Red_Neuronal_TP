using System;

class Program
{
    static void Main(string[] args)
    {
        string[] frasesLunes = {
            "¡Feliz comienzo de semana!",
            "¡Que tengas un excelente día!",
            "¡A por todas en este lunes!"
        };

        string[] frasesMartes = {
            "¡Vamos, que ya es martes!",
            "¡No pierdas el ritmo!",
            "¡Excelente día para lograr tus metas!"
        };

        string[] frasesMiercoles = {
            "¡Mitad de semana, ánimo!",
            "¡Ya estás en la cima de la semana!",
            "¡Sigue adelante, estás haciendo un gran trabajo!"
        };

        string[] frasesJueves = {
            "¡Ya casi es viernes, tú puedes!",
            "¡Gran día para avanzar!",
            "¡El fin de semana está cerca!"
        };

        string[] frasesViernes = {
            "¡Por fin es viernes!",
            "¡Disfruta al máximo el día!",
            "¡Que tengas un excelente fin de semana!"
        };

        string[] frasesSabado = {
            "¡Feliz sábado!",
            "¡Disfruta tu día al máximo!",
            "¡Relájate y disfruta del fin de semana!"
        };

        string[] frasesDomingo = {
            "¡Feliz domingo!",
            "¡Descansa y recarga energías!",
            "¡Disfruta de un día de tranquilidad!"
        };

        // Obtener el día de la semana actual
        DayOfWeek diaDeLaSemana = DateTime.Today.DayOfWeek;

        // Seleccionar las frases según el día de la semana
        string fraseSeleccionada = ObtenerFraseAleatoria(diaDeLaSemana);

        // Mostrar la frase seleccionada
        Console.WriteLine(fraseSeleccionada);
    }

    static string ObtenerFraseAleatoria(DayOfWeek dia)
    {
        Random rnd = new Random();
        string[] frases;

        switch (dia)
        {
            case DayOfWeek.Monday:
                frases = new string[] {
                    "¡Feliz comienzo de semana!",
                    "¡Que tengas un excelente día!",
                    "¡A por todas en este lunes!"
                };
                break;
            case DayOfWeek.Tuesday:
                frases = new string[] {
                    "¡Vamos, que ya es martes!",
                    "¡No pierdas el ritmo!",
                    "¡Excelente día para lograr tus metas!"
                };
                break;
            case DayOfWeek.Wednesday:
                frases = new string[] {
                    "¡Mitad de semana, ánimo!",
                    "¡Ya estás en la cima de la semana!",
                    "¡Sigue adelante, estás haciendo un gran trabajo!"
                };
                break;
            case DayOfWeek.Thursday:
                frases = new string[] {
                    "¡Ya casi es viernes, tú puedes!",
                    "¡Gran día para avanzar!",
                    "¡El fin de semana está cerca!"
                };
                break;
            case DayOfWeek.Friday:
                frases = new string[] {
                    "¡Por fin es viernes!",
                    "¡Disfruta al máximo el día!",
                    "¡Que tengas un excelente fin de semana!"
                };
                break;
            case DayOfWeek.Saturday:
                frases = new string[] {
                    "¡Feliz sábado!",
                    "¡Disfruta tu día al máximo!",
                    "¡Relájate y disfruta del fin de semana!"
                };
                break;
            case DayOfWeek.Sunday:
                frases = new string[] {
                    "¡Feliz domingo!",
                    "¡Descansa y recarga energías!",
                    "¡Disfruta de un día de tranquilidad!"
                };
                break;
            default:
                frases = new string[] { "¡Buen día!" };
                break;
        }

        // Seleccionar una frase aleatoria del arreglo
        return frases[rnd.Next(frases.Length)];
    }
}
