package org.example;

public class Vaga {
    private int numero;
    private String placa;
    private boolean ocupada;

    public Vaga(int numero) {
        this.numero = numero;
        this.placa = "Livre";
        this.ocupada = false;
    }

    public int getNumero() { return numero; }
    public String getPlaca() { return placa; }
    public void setPlaca(String placa) { this.placa = placa; }
    public boolean isOcupada() { return ocupada; }
    public void setOcupada(boolean ocupada) { this.ocupada = ocupada; }

    @Override
    public String toString() {
        return "Vaga " + numero + " [" + (ocupada ? "OCUPADA - " + placa : "LIVRE") + "]";
    }
}
