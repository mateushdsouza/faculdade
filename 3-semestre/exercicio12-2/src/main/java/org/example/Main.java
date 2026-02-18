package org.example;

import java.util.ArrayList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        ArrayList<Funcionario> funcionarios = new ArrayList<>();
        funcionarios.add(new FuncionarioCLT("Pedro", "135.558.223-25", 1500));
        funcionarios.add(new Gerente("Carlos", "524.235.254-78", 2000));
        funcionarios.add(new Desenvolvedor("Mateus", "235.254.255-14", 3000, 250));

        for (Funcionario f : funcionarios)  {
            qqqqq

            f.exibirDados();
            System.out.println("--------------------");
        }
    }
}