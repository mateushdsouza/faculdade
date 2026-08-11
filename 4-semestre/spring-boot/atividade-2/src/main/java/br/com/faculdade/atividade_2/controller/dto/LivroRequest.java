package br.com.faculdade.atividade_2.controller.dto;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class LivroRequest {
    private String titulo;
    private String autor;
    private String genero;
    private Integer anoPublicado;
    private Integer paginas;
}
