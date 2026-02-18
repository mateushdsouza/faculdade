package org.example;

public class CartaoDeCredito extends Pagamento{

    private int parcelas;

    CartaoDeCredito(double valor, int parcelas) {
        super(valor);
        this.parcelas = parcelas;
    }

    @Override
    public void processarPagamento() {
        System.out.println("Valor do pagamento: " + this.getValor() + " Quantidade " + "de parcelas: " + this.parcelas);
    }

}
