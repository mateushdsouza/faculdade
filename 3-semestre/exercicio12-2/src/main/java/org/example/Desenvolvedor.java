package org.example;

public class Desenvolvedor extends Funcionario {
    private double adicionalProdutividade;

    public Desenvolvedor(String nome, String cpf, double salarioBase, double adicionalProdutividade) {
        super(nome, cpf, salarioBase);
        setAdicionalProdutividade(adicionalProdutividade);
    }

    public void setAdicionalProdutividade(double adicionalProdutividade) {
        if (adicionalProdutividade >= 0) {
            this.adicionalProdutividade = adicionalProdutividade;
        } else {
            System.out.println("Erro: Adicional não pode ser negativo.");
        }
    }

    public double getAdicionalProdutividade() {
        return adicionalProdutividade;
    }

    @Override
    public double calcularSalario() {
        return getSalarioBase() + getAdicionalProdutividade();
    }
}
