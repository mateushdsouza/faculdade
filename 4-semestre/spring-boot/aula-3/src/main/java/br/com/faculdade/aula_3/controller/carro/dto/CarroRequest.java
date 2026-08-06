package br.com.faculdade.aula_3.controller.carro.dto;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class CarroRequest {
    private long id;
    private String marca;
    private String modelo;
    private String cor;
    private Double preco;
    private Integer ano;
}
