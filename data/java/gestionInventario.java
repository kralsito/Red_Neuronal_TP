import java.util.ArrayList;
import java.util.Scanner;

class Producto {
    private String nombre;
    private double precio;
    private int cantidad;

    public Producto(String nombre, double precio, int cantidad) {
        this.nombre = nombre;
        this.precio = precio;
        this.cantidad = cantidad;
    }

    public String getNombre() {
        return nombre;
    }

    public double getPrecio() {
        return precio;
    }

    public int getCantidad() {
        return cantidad;
    }

    public void setPrecio(double precio) {
        this.precio = precio;
    }

    public void setCantidad(int cantidad) {
        this.cantidad = cantidad;
    }
}

public class GestionInventario {
    private static ArrayList<Producto> inventario = new ArrayList<>();
    private static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        boolean salir = false;
        while (!salir) {
            mostrarMenu();
            int opcion = scanner.nextInt();
            switch (opcion) {
                case 1:
                    agregarProducto();
                    break;
                case 2:
                    mostrarInventario();
                    break;
                case 3:
                    venderProducto();
                    break;
                case 4:
                    generarInforme();
                    break;
                case 5:
                    salir = true;
                    break;
                default:
                    System.out.println("Opción no válida. Intente de nuevo.");
            }
        }
        scanner.close();
    }

    private static void mostrarMenu() {
        System.out.println("\n=== MENÚ ===");
        System.out.println("1. Agregar producto");
        System.out.println("2. Mostrar inventario");
        System.out.println("3. Vender producto");
        System.out.println("4. Generar informe");
        System.out.println("5. Salir");
        System.out.print("Ingrese su opción: ");
    }

    private static void agregarProducto() {
        scanner.nextLine(); // Consumir el salto de línea pendiente
        System.out.print("Ingrese el nombre del producto: ");
        String nombre = scanner.nextLine();
        System.out.print("Ingrese el precio del producto: ");
        double precio = scanner.nextDouble();
        System.out.print("Ingrese la cantidad en inventario: ");
        int cantidad = scanner.nextInt();
        inventario.add(new Producto(nombre, precio, cantidad));
        System.out.println("Producto agregado al inventario.");
    }

    private static void mostrarInventario() {
        if (inventario.isEmpty()) {
            System.out.println("El inventario está vacío.");
        } else {
            System.out.println("\n=== INVENTARIO ===");
            for (Producto producto : inventario) {
                System.out.println("Nombre: " + producto.getNombre() + ", Precio: $" + producto.getPrecio() +
                        ", Cantidad: " + producto.getCantidad());
            }
        }
    }

    private static void venderProducto() {
        if (inventario.isEmpty()) {
            System.out.println("No hay productos en el inventario para vender.");
            return;
        }
        System.out.println("Seleccione el producto a vender:");
        for (int i = 0; i < inventario.size(); i++) {
            Producto producto = inventario.get(i);
            System.out.println((i + 1) + ". " + producto.getNombre() + " - $" + producto.getPrecio() +
                    " - Disponibles: " + producto.getCantidad());
        }
        System.out.print("Ingrese el número del producto a vender: ");
        int indice = scanner.nextInt() - 1;
        if (indice < 0 || indice >= inventario.size()) {
            System.out.println("Índice de producto no válido.");
            return;
        }
        Producto productoSeleccionado = inventario.get(indice);
        System.out.print("Ingrese la cantidad a vender: ");
        int cantidadAVender = scanner.nextInt();
        if (cantidadAVender <= 0 || cantidadAVender > productoSeleccionado.getCantidad()) {
            System.out.println("Cantidad no válida.");
            return;
        }
        productoSeleccionado.setCantidad(productoSeleccionado.getCantidad() - cantidadAVender);
        System.out.println("Venta realizada correctamente.");
    }

    private static void generarInforme() {
        if (inventario.isEmpty()) {
            System.out.println("No hay productos en el inventario para generar un informe.");
            return;
        }
        double valorTotalInventario = 0;
        System.out.println("\n=== INFORME DE INVENTARIO ===");
        for (Producto producto : inventario) {
            double valorProducto = producto.getPrecio() * producto.getCantidad();
            valorTotalInventario += valorProducto;
            System.out.println("Nombre: " + producto.getNombre() + ", Precio: $" + producto.getPrecio() +
                    ", Cantidad: " + producto.getCantidad() + ", Valor Total: $" + valorProducto);
        }
        System.out.println("Valor Total del Inventario: $" + valorTotalInventario);
    }
}
