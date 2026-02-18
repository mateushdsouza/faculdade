package org.example;

import java.util.Scanner;
import java.util.Random;

public class Atividade {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int geradorInt = random.nextInt(100);
        int chute;

        do {
            System.out.println("Chute um numero de um a 100!");
            chute = sc.nextInt();

            if (chute > geradorInt) {
                System.out.println("O valor que voce digitou e maior");
            } else if(chute < geradorInt) {
                System.out.println("O valor que voce digitou e menor");
            } else {
                System.out.println("VOCE ACERTOU!");
            }
        } while(chute != geradorInt);
    }
}
