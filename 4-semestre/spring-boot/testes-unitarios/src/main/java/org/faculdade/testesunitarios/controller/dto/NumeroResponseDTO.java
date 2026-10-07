package org.faculdade.testesunitarios.controller.dto;

public record NumeroResponseDTO(
        Integer maior,
        Integer menor,
        Integer quantidade,
        Integer moda,
        Double media,
        Integer multiplicacao
) {
}