package com.example.demo.controller.carros.dto;

import java.util.List;

public record CarroResponseDTO(
        Long idCarro,
        String modelo,
        EnderecoResponseDTO endereco,
        FabricanteResponseDTO fabricante,
        List<CategoriaResponseDTO> categorias
) {
}
