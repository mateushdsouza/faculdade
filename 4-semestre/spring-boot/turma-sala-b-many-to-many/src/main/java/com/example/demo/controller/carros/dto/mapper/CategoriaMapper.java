package com.example.demo.controller.carros.dto.mapper;

import com.example.demo.controller.carros.dto.CategoriaResponseDTO;
import com.example.demo.entity.CategoriaEntity;

public class CategoriaMapper {
    public static CategoriaResponseDTO toResponseDTO(CategoriaEntity entity) {
        return new CategoriaResponseDTO(
                entity.getId(),
                entity.getNome()
        );
    }
}
