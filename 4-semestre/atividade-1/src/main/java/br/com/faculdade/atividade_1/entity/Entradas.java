package br.com.faculdade.atividade_1.entity;

import lombok.Getter;
import lombok.Setter;

public class Entradas {
    @Getter
    @Setter
    private String nome;

    @Getter
    @Setter
    private Integer idade;

    @Getter
    @Setter
    private boolean gestante;

    @Getter
    @Setter
    private boolean pessoaComDeficiencia;
}
