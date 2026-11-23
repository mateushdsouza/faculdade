package org.faculdade.testesunitarios.controller;

import lombok.AllArgsConstructor;
import org.faculdade.testesunitarios.controller.dto.NumeroRequestDTO;
import org.faculdade.testesunitarios.controller.dto.NumeroResponseDTO;
import org.faculdade.testesunitarios.service.ListaService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/lista")
@AllArgsConstructor
public class ListaController {

    private final ListaService listaService;

    @PostMapping("/numeros")
    public ResponseEntity<Void> adicionarNumeros(@RequestBody NumeroRequestDTO dto) {
        listaService.adicionarNumeros(dto.numeros());

        return ResponseEntity.ok().build();
    }

    @GetMapping("/resultados")
    public ResponseEntity<NumeroResponseDTO> resultados() {

        NumeroResponseDTO response = new NumeroResponseDTO(
                listaService.maiorNumero(),
                listaService.menorNumero(),
                listaService.qtdNumeros(),
                listaService.moda(),
                listaService.media(),
                listaService.multiplicacao()
        );

        return ResponseEntity.ok(response);
    }
}