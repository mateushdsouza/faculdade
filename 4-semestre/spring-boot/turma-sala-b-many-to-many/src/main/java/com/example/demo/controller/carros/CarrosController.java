package com.example.demo.controller.carros;

import com.example.demo.controller.carros.dto.CarroResponseDTO;
import com.example.demo.controller.carros.dto.CategoriaResponseDTO;
import com.example.demo.controller.carros.dto.mapper.CarroMapper;
import com.example.demo.controller.carros.dto.mapper.CategoriaMapper;
import com.example.demo.entity.CarrosEntity;
import com.example.demo.entity.CategoriaEntity;
import com.example.demo.entity.FabricantesEntity;
import com.example.demo.service.CarrosService;
import lombok.AllArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@AllArgsConstructor
@RestController
@RequestMapping("/carros")
public class CarrosController {

    private final CarrosService carrosService;

    @GetMapping
    public ResponseEntity<List<CarroResponseDTO>> findAll() {
        return ResponseEntity.ok(
                carrosService.findAll().stream()
                        .map(CarroMapper::toResponseDTO)
                        .toList()
        );
    }

    @PostMapping
    public ResponseEntity<CarroResponseDTO> salvarCarro(@RequestBody CarrosEntity carrosEntity) {
        CarrosEntity carroSalvo = carrosService.salvarCarro(carrosEntity);
        return ResponseEntity.status(HttpStatus.CREATED)
                .body(CarroMapper.toResponseDTO(carroSalvo));
    }

    // LOCALHOST:8080/carros/fabricantes
    @PostMapping("/fabricantes")
    public ResponseEntity salvarFabricante(
            @RequestBody FabricantesEntity fabricante
            ) {
    this.carrosService.salvarFabricante(fabricante);
    return ResponseEntity.ok("Adicionado");
    }

    // PATCH LOCALHOST:8080/carros/32/fabricantes/2
    @PatchMapping("/{carroId}/fabricantes/{fabricanteId}")
    public ResponseEntity associarFabricante(
            @PathVariable Long carroId,
            @PathVariable Long fabricanteId
    ){
        this.carrosService.associarFabricante(carroId, fabricanteId);
        return ResponseEntity.ok("Adicionado");
    }

    @PostMapping("/categorias")
    public ResponseEntity<CategoriaResponseDTO> salvarCategoria(@RequestBody CategoriaEntity categoriaEntity) {
        CategoriaEntity categoriaSalva = carrosService.salvarCategoria(categoriaEntity);
        return ResponseEntity.ok().body(CategoriaMapper.toResponseDTO(categoriaSalva));
    }

    @PatchMapping("/{carroId}/categorias/{categoriaId}")
    public ResponseEntity associarCategoria(
            @PathVariable Long carroId,
            @PathVariable Long categoriaId
    ) {
        this.carrosService.associarCategoria(carroId, categoriaId);
        return ResponseEntity.ok("Categoria Adicionada");
    }
}