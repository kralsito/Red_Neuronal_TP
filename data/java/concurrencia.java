public class ContadorHilos implements Runnable {
    private int inicio;
    private int fin;

    public ContadorHilos(int inicio, int fin) {
        this.inicio = inicio;
        this.fin = fin;
    }

    @Override
    public void run() {
        for (int i = inicio; i <= fin; i++) {
            System.out.println(Thread.currentThread().getName() + ": " + i);
        }
    }

    public static void main(String[] args) {
        Thread hilo1 = new Thread(new ContadorHilos(1, 5));
        Thread hilo2 = new Thread(new ContadorHilos(6, 10));

        hilo1.start();
        hilo2.start();
    }
}
