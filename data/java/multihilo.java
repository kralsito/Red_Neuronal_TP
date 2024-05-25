import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;

public class EjemploConcurrencia {
    private static final int NUM_HILOS = 3;

    public static void main(String[] args) {
        CyclicBarrier barrera = new CyclicBarrier(NUM_HILOS, () -> System.out.println("Todos los hilos han llegado"));

        for (int i = 0; i < NUM_HILOS; i++) {
            Thread hilo = new Thread(new Tarea(barrera));
            hilo.start();
        }
    }

    static class Tarea implements Runnable {
        private CyclicBarrier barrera;

        public Tarea(CyclicBarrier barrera) {
            this.barrera = barrera;
        }

        @Override
        public void run() {
            try {
                System.out.println("Hilo " + Thread.currentThread().getId() + " iniciando tarea.");
                Thread.sleep(2000); // Simular procesamiento
                System.out.println("Hilo " + Thread.currentThread().getId() + " finalizó tarea.");
                barrera.await();
            } catch (InterruptedException | BrokenBarrierException e) {
                e.printStackTrace();
            }
        }
    }
}
