class OOP_1_Constructor_3{
    //Constructor Ovearloading: Se define como tener multiples constructores con parametros diferentes de esta forma
    //cada constructor realiza una tarea diferente

    String Saludo = "";
    int Contador = 0;

    //Constructor por defecto sin parametros
    OOP_1_Constructor_3(){
        System.out.print("Hola desde el constructor default");
    }

    OOP_1_Constructor_3(String _Saludo){
        this.Saludo = _Saludo;
    }

    OOP_1_Constructor_3(int _Contador){
        this.Contador = _Contador;
    }

    public static void main(String[] args) {
        //constructor default
        OOP_1_Constructor_3 ConstructorDefault = new OOP_1_Constructor_3();
        System.out.println(ConstructorDefault.Saludo);

        //Constructor con string como parametro
        OOP_1_Constructor_3 ConstructorString = new OOP_1_Constructor_3("Hola mundo desde el constructor con string");
        System.out.println(ConstructorString.Saludo);

        //Constructor con int como parametro
        OOP_1_Constructor_3 ConstructorInt = new OOP_1_Constructor_3(10);
        System.out.println("El valor del contador es: " + ConstructorInt.Contador);
    }
}