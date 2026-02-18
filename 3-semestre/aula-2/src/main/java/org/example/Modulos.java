package org.example;

import java.util.List;

public class Modulos {
    private List<Integer> dados;

    public Modulos(List<Integer> dados) {
        this.dados = dados;
    }

    public void exibeMedia() {
        double soma = 0D;

        for (int dado : dados) {
            soma += dado;
        }
        double media = soma / dados.size();
        System.out.println("Média (via classe): " + media);
    }

    public void exibedesvioPadrao() {
        double soma = 0D;
        double media = soma / dados.size();
        for (int dado : dados) {
            soma = soma + Math.pow(dado - media, 2);
        }
        System.out.println("Valor do desvio padrão (via classe): " + Math.sqrt(soma / dados.size()));
    }
}
