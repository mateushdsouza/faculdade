package br.com.faculdade.aula_3.controller.carro.dto;

import br.com.faculdade.aula_3.entity.Carro;

public record CarroResponse(
        long id,
        String marca,
        String modelo,
        String cor,
        Double preco,
        Integer ano
        ) {
    public static CarroResponse de (Carro carro) {
        return new CarroResponse(
                carro.getId(),
                carro.getMarca(),
                carro.getCor(),
                carro.getModelo(),
                carro.getPreco(),
                carro.getAno()
        );
    }
}
