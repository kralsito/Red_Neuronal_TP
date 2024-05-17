using System;

delegate void EventHandler(string message);

class Publisher {
    public event EventHandler Notify;

    public void DoSomething() {
        Notify?.Invoke("Something happened.");
    }
}

class Subscriber {
    public void HandleEvent(string message) {
        Console.WriteLine("Event handled: " + message);
    }
}

class Program {
    static void Main(string[] args) {
        Publisher publisher = new Publisher();
        Subscriber subscriber = new Subscriber();

        publisher.Notify += subscriber.HandleEvent;
        publisher.DoSomething();  // Output: Event handled: Something happened.
    }
}
