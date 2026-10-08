package com.example.demo.controller.estatisticas.dto;

import java.util.List;

public record EstatisticaResponseDTO(
        Long id,
        Double media,
        Double mediana,
        Double maior,
        Double menor,
        Integer total,
        List<Double> moda,
        Double soma,
        Double desvioPadrao
) {
}
