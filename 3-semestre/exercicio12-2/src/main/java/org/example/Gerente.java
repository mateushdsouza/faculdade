package org.example;

public class Gerente extends Funcionario {
    public Gerente(String nome, String cpf, double salarioBase) {
        super(nome, cpf, salarioBase);
    }

    @Override
    public double calcularSalario() {
        return getSalarioBase() + (getSalarioBase() * 0.20);
    }
}
