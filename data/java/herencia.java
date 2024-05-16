public class OOP_2_Herencia_Padre{
    protected int id;
    protected String Nombre;
    protected String Apellido;
    protected int Edad;

    public OOP_2_Herencia_Padre(){

    }

    /**
     * @return the apellido
     */
    public String getApellido() {
        return Apellido;
    }

    /**
     * @return the edad
     */
    public int getEdad() {
        return Edad;
    }

    /**
     * @return the id
     */
    public int getId() {
        return id;
    }

    /**
     * @return the nombre
     */
    public String getNombre() {
        return Nombre;
    }

    /**
     * @param apellido the apellido to set
     */
    public void setApellido(String apellido) {
        Apellido = apellido;
    }

    /**
     * @param edad the edad to set
     */
    public void setEdad(int edad) {
        Edad = edad;
    }

    /**
     * @param id the id to set
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * @param nombre the nombre to set
     */
    public void setNombre(String nombre) {
        Nombre = nombre;
    }


    public OOP_2_Herencia_Padre(int id, String nombre, String apellido, int edad){
        this.id = id;
        this.Nombre = nombre;
        this.Apellido = apellido;
        this.Edad = edad;
    }

    public  void Concentrarse(){
        System.out.println("Concentrando");
    }
    public void Viajar(){
        System.out.println("Viajando");
    }
}