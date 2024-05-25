import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ImplementacionServicioRemoto extends UnicastRemoteObject implements ServicioRemoto {
    public ImplementacionServicioRemoto() throws RemoteException {
        super();
    }

    @Override
    public String saludar(String nombre) throws RemoteException {
        return "Hola, " + nombre + "!";
    }
}
