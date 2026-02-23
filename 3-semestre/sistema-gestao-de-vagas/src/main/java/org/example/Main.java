package org.example;

import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<Vaga> estacionamento = new ArrayList<>();

        for (int i = 1; i <= 5; i++) {
            estacionamento.add(new Vaga(i));
        }

        int opcao = 0;
        while (opcao != 4) {
            System.out.println("\n--- GESTÃO DE ESTACIONAMENTO ---");
            System.out.println("1. Listar Vagas");
            System.out.println("2. Entrada de Veículo");
            System.out.println("3. Saída de Veículo");
            System.out.println("4. Sair");
            System.out.print("Escolha: ");
            opcao = scanner.nextInt();
            scanner.nextLine();

            if (opcao == 1) {
                System.out.println("\n--- STATUS ATUAL ---");
                for (Vaga v : estacionamento) {
                    System.out.println(v.toString());
                }
            } else if (opcao == 2) {
                System.out.println("Informe o número da vaga (1-5): ");
                int numVaga = scanner.nextInt();
                scanner.nextLine();

                if (numVaga < 1 || numVaga > 5) {
                    System.out.println("ERRO: Vaga inexistente.");
                } else {
                    Vaga selecionada = estacionamento.get(numVaga - 1);

                    if (selecionada.isOcupada()) {
                        System.out.println("ERRO: Esta vaga já está ocupada!");
                    } else {
                        System.out.print("Informe a placa do veículo: ");
                        String placa = scanner.nextLine();

                        selecionada.setPlaca(placa);
                        selecionada.setOcupada(true);
                        System.out.println("Sucesso: Veículo registrado!");
                    }
                }
            } else if (opcao == 3) {
                System.out.print("Informe o número da vaga para liberar (1-5): ");
                int numVaga = scanner.nextInt();

                if (numVaga < 1 || numVaga > 5) {
                    System.out.println("ERRO: Vaga inexistente.");
                } else{
                    Vaga selecionada = estacionamento.get(numVaga - 1);

                    if (!selecionada.isOcupada()) {
                        System.out.println("ERRO: Esta vaga já está vazia.");
                    } else {
                        selecionada.setPlaca("");
                        selecionada.setOcupada(false);
                        System.out.println("Sucesso: Vaga liberada!");
                    }
                }
            }
        }
        System.out.println("Sistema encerrado.");
        scanner.close();
    }
}