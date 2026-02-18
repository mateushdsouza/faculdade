package org.example;

public class Pix extends Pagamento{
    private String chavePix;

    Pix(double valor, String chavePix) {
        super(valor);
        this.chavePix = chavePix;
    }

    @Override
    public void processarPagamento() {
        System.out.println("Pix com chave pix:" + " " + this.chavePix + "no valor de " + getValor() );
    }
}
