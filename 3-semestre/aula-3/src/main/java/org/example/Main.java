package org.example;

public class Main {
    public static void main(String[] args) {
        Pessoa pessoa1 = new Pessoa();
        Pessoa pessoa2 = new Pessoa();

        pessoa2.setNome("Mateus");
        System.out.println(pessoa2.getNome());
    }
}