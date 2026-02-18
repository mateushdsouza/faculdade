package org.example;

public abstract class Funcionario {
    private String nome;
    private String cpf;
    private double salarioBase;

    public Funcionario(String nome, String cpf, double salarioBase) {
        this.nome = nome;
        this.cpf = cpf;
        setSalarioBase(salarioBase);
        ;
    }


    public void setSalarioBase(double salarioBase) {
        if (salarioBase >= 0) {
            this.salarioBase = salarioBase;
        } else {
            System.out.println("Erro: O salário não pode ser negativo.");
        }
    }

    public double getSalarioBase() {
        return this.salarioBase;
    }

    public abstract double calcularSalario();

    public void exibirDados() {
        System.out.println("Nome: " + this.nome);
        System.out.println("CPF: " + this.cpf);
        System.out.println("Salario base: " + getSalarioBase());
        System.out.println("Salario final: " + calcularSalario());
    }

    public double aumentarSalario(double percentual) {
        this.salarioBase += (this.salarioBase * (percentual / 100));
        return this.salarioBase;
    }
}
