package com.example.demo.service;

import com.example.demo.entity.CarrosEntity;
import com.example.demo.entity.CategoriaEntity;
import com.example.demo.entity.FabricantesEntity;
import com.example.demo.repository.CarroRepository;
import com.example.demo.repository.CategoriaRepository;
import com.example.demo.repository.FabricanteRepository;
import jakarta.transaction.Transactional;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@RequiredArgsConstructor
@Service
public class CarrosService {

    private final CarroRepository carroRepository;
    private final FabricanteRepository fabricanteRepository;
    private final CategoriaRepository categoriaRepository;

    public List<CarrosEntity> findAll() {
        return carroRepository.findAllWithRelationships();
    }

    public Optional<CarrosEntity> findById(Long id) {
        return carroRepository.findById(id);
    }

    public CarrosEntity salvarCarro(CarrosEntity carrosEntity) {
        if (carrosEntity.getAddress() != null) {
            carrosEntity.getAddress().setCarros(carrosEntity);
        }
        return carroRepository.save(carrosEntity);
    }

    public FabricantesEntity salvarFabricante(FabricantesEntity fabricantesEntity){
        return this.fabricanteRepository.save(fabricantesEntity);
    }


    @Transactional
    public void associarFabricante(Long carroId, Long fabricanteId){
        var carro = this.carroRepository.findById(carroId).orElseThrow();
        var fabricante = this.fabricanteRepository.findById(fabricanteId).orElseThrow();

        carro.setFabricantes(fabricante);

    }

    public CategoriaEntity salvarCategoria(CategoriaEntity categoriaEntity) {
        return categoriaRepository.save(categoriaEntity);
    }

    @Transactional
    public void associarCategoria(Long carroId, Long categoriaId){
        var carro = this.carroRepository.findById(carroId).orElseThrow();
        var categoria = this.categoriaRepository.findById(categoriaId).orElseThrow();

        carro.getCategorias().add(categoria);
    }

}
