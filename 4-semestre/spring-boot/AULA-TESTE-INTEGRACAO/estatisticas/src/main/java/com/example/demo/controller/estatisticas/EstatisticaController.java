package com.example.demo.controller.estatisticas;

import com.example.demo.controller.estatisticas.dto.EstatisticaResponseDTO;
import com.example.demo.controller.estatisticas.dto.mapper.EstatisticaMapper;
import com.example.demo.service.EstatisticaService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@RestController
@RequestMapping("/estatisticas")
public class EstatisticaController {

    private final EstatisticaService estatisticaService;

    public EstatisticaController(EstatisticaService estatisticaService) {
        this.estatisticaService = estatisticaService;
    }

    @PostMapping("/calcular")
    public ResponseEntity<EstatisticaResponseDTO> calcularSemSalvar(@RequestBody List<Double> numeros) {
        try {
            return ResponseEntity.ok(
                    EstatisticaMapper.toResponseDTO(estatisticaService.calcular(numeros)));
        } catch (IllegalArgumentException exception) {
            return ResponseEntity.badRequest().build();
        }
    }

    @PostMapping
    public ResponseEntity<EstatisticaResponseDTO> calcular(@RequestBody List<Double> numeros) {
        try {
            return ResponseEntity.ok(
                    EstatisticaMapper.toResponseDTO(estatisticaService.calcularESalvar(numeros)));
        } catch (IllegalArgumentException exception) {
            return ResponseEntity.badRequest().build();
        }
    }

    @GetMapping
    public ResponseEntity<List<EstatisticaResponseDTO>> findAll() {
        try {
            return ResponseEntity.ok(
                    estatisticaService.findAll().stream()
                            .map(EstatisticaMapper::toResponseDTO)
                            .toList());
        } catch (IllegalArgumentException exception) {
            return ResponseEntity.badRequest().build();
        }
    }
}
