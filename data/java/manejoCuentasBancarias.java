import java.util.Scanner;

class CuentaBancaria {
    protected String titular;
    protected double saldo;

    public CuentaBancaria(String titular) {
        this.titular = titular;
        this.saldo = 0;
    }

    public void depositar(double cantidad) {
        saldo += cantidad;
        System.out.println("Se ha depositado $" + cantidad + " en la cuenta de " + titular);
    }

    public void retirar(double cantidad) {
        if (saldo >= cantidad) {
            saldo -= cantidad;
            System.out.println("Se ha retirado $" + cantidad + " de la cuenta de " + titular);
        } else {
            System.out.println("Saldo insuficiente para retirar $" + cantidad);
        }
    }

    public void mostrarSaldo() {
        System.out.println("Saldo disponible en la cuenta de " + titular + ": $" + saldo);
    }
}

class CuentaCorriente extends CuentaBancaria {
    private double sobregiro;

    public CuentaCorriente(String titular, double sobregiro) {
        super(titular);
        this.sobregiro = sobregiro;
    }

    @Override
    public void retirar(double cantidad) {
        if (saldo + sobregiro >= cantidad) {
            saldo -= cantidad;
            System.out.println("Se ha retirado $" + cantidad + " de la cuenta de " + titular);
        } else {
            System.out.println("No se puede retirar $" + cantidad + ". Saldo insuficiente y sobregiro excedido.");
        }
    }
}

class CuentaAhorro extends CuentaBancaria {
    private double interesAnual;

    public CuentaAhorro(String titular, double interesAnual) {
        super(titular);
        this.interesAnual = interesAnual;
    }

    public void calcularInteresMensual() {
        double interesMensual = saldo * (interesAnual / 12) / 100;
        saldo += interesMensual;
        System.out.println("Se ha calculado el interés mensual en la cuenta de " + titular + ": $" + interesMensual);
    }
}

public class ManejoCuentas {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        CuentaCorriente cuentaCorriente = new CuentaCorriente("Juan Pérez", 100);
        CuentaAhorro cuentaAhorro = new CuentaAhorro("María González", 2.5);

        cuentaCorriente.depositar(500);
        cuentaCorriente.mostrarSaldo();
        cuentaCorriente.retirar(200);
        cuentaCorriente.mostrarSaldo();

        System.out.println();

        cuentaAhorro.depositar(1000);
        cuentaAhorro.mostrarSaldo();
        cuentaAhorro.calcularInteresMensual();
        cuentaAhorro.mostrarSaldo();

        scanner.close();
    }
}
