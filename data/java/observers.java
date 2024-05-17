import java.util.Observable;
import java.util.Observer;

class EventPublisher extends Observable {
    void publishEvent(String message) {
        setChanged();
        notifyObservers(message);
    }
}

class EventSubscriber implements Observer {
    @Override
    public void update(Observable o, Object arg) {
        System.out.println("Event received: " + arg);
    }
}

public class Main {
    public static void main(String[] args) {
        EventPublisher publisher = new EventPublisher();
        EventSubscriber subscriber = new EventSubscriber();

        publisher.addObserver(subscriber);
        publisher.publishEvent("Hello, World!");  // Output: Event received: Hello, World!
    }
}
