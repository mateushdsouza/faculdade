package com.example.demo.controller.carros.dto.mapper;

import com.example.demo.controller.carros.dto.CarroResponseDTO;
import com.example.demo.controller.carros.dto.CategoriaResponseDTO;
import com.example.demo.controller.carros.dto.EnderecoResponseDTO;
import com.example.demo.controller.carros.dto.FabricanteResponseDTO;
import com.example.demo.entity.CarrosEntity;

import java.util.Comparator;

public final class CarroMapper {

    private CarroMapper() {
    }

    public static CarroResponseDTO toResponseDTO(CarrosEntity entity) {
        return new CarroResponseDTO(
                entity.getId(),
                entity.getModelo(),
                entity.getAddress() == null
                        ? null
                        : new EnderecoResponseDTO(
                                entity.getAddress().getId(),
                                entity.getAddress().getEnderecoCompleto()
                        ),
                entity.getFabricantes() == null
                        ? null
                        : new FabricanteResponseDTO(
                                entity.getFabricantes().getId(),
                                entity.getFabricantes().getNome()
                        ),
                entity.getCategorias().stream()
                        .map(categoria -> new CategoriaResponseDTO(
                                categoria.getId(),
                                categoria.getNome()
                        ))
                        .sorted(Comparator.comparing(CategoriaResponseDTO::id))
                        .toList()
        );
    }
}
