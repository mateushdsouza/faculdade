package com.example.demo.controller.estatisticas.dto.mapper;

import com.example.demo.controller.estatisticas.dto.EstatisticaResponseDTO;
import com.example.demo.entity.EstatisticaEntity;
import java.util.List;

public final class EstatisticaMapper {

    private EstatisticaMapper() {
    }

    public static EstatisticaResponseDTO toResponseDTO(EstatisticaEntity entity) {
        return new EstatisticaResponseDTO(
                entity.getId(), entity.getMedia(), entity.getMediana(),
                entity.getMaior(), entity.getMenor(), entity.getTotal(),
                List.copyOf(entity.getModa()), entity.getSoma(), entity.getDesvioPadrao());
    }
}
