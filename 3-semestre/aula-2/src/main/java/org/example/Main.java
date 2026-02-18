package org.example;


import java.util.ArrayList;
import java.util.List;


public class Main {
    public static void main(String[] args) {


        /*
        Para um conjunto de dados, obtenha-se;
            * Média
            * Valor máximo
            * Valor mínimo
            * Desvio padrão
                ** mínimo de 10 numeros
         */


        List<Integer> dados = new ArrayList<>(List.of(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
        Double media = 0D;
        int maximo = 0;
        int minimo;


        //maximo
        for( int i = 0; i<dados.size(); i++ ) {
            if(dados.get(i) > maximo) {
                maximo = dados.get(i);
            }
        }
        System.out.println("Maximo é: " + maximo);


        //Minimo
        minimo = dados.get(0);
        for( int i = 1; i<dados.size(); i++ ) {
            if(dados.get(i) < minimo) {
                minimo = dados.get(i);
            }
        }
        System.out.println("Minimo é: " + minimo);

        Modulos dadosEstatisticos = new Modulos(dados);
        dadosEstatisticos.exibeMedia();
        dadosEstatisticos.exibedesvioPadrao();
    }
}