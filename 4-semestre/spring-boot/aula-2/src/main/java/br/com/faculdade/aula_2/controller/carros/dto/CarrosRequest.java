package br.com.faculdade.aula_2.controller.carros.dto;

import lombok.*;


import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;


@Data
public class CarrosRequest {
    @NotNull
    @NotEmpty
    @NotBlank(message = "Nao pode ser uma informacao em branco!")
    private String marca;
}
