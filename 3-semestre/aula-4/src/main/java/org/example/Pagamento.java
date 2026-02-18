package org.example;

public abstract class Pagamento {

    private double valor;

    public Pagamento(double valor) {
        this.valor = valor;
    }

    public abstract void processarPagamento();

    public double getValor(){
        return this.valor;
    }
}
