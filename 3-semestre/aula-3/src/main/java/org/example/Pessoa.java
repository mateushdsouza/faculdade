package org.example;

public class Pessoa {
    private String nome;
    private int idade;
    private String genero;
    private float altura;

    public void setNome(String nome){
        this.nome = nome;
    }

    String getNome(){
        return this.nome;
    }

    void andar(){
        System.out.println("Estou andando!");
    }

    void comer(){
        System.out.println("Estou comendo!");
    }

    void falar(){
        System.out.println("Estou falando!");
    }

    void IncrementarIdade(){
        this.idade += 1;
    }
}