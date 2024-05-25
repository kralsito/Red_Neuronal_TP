public class ContadorThread extends Thread {
    private int inicio;
    private int fin;

    public ContadorThread(int inicio, int fin) {
        this.inicio = inicio;
        this.fin = fin;
    }

    @Override
    public void run() {
        for (int i = inicio; i <= fin; i++) {
            System.out.println("Contador: " + i);
            try {
                Thread.sleep(1000); // Esperar 1 segundo
            } catch (InterruptedException e) {
                System.out.println("Hilo interrumpido");
            }
        }
    }

    public static void main(String[] args) {
        ContadorThread thread1 = new ContadorThread(1, 5);
        ContadorThread thread2 = new ContadorThread(6, 10);
        thread1.start();
        thread2.start();
    }
}
