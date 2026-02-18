package org.example;

import java.util.Scanner;

public class Aula {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite seu peso (kg): ");
        float peso = scanner.nextFloat();

        System.out.print("Digite sua altura (metros, ex: 1,75): ");
        float altura = scanner.nextFloat();

        float imc = peso / (altura * altura);
        System.out.printf("Seu IMC é: %.2f%n", imc);
    }
}