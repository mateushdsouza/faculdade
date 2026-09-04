package com.example.demo.repository;

import com.example.demo.entity.CarrosEntity;
import org.springframework.data.jpa.repository.EntityGraph;
import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Query;

import java.util.List;

public interface CarroRepository extends JpaRepository<CarrosEntity, Long> {

    boolean existsByModeloIgnoreCase(String modelo);

    @EntityGraph(attributePaths = {"address", "fabricantes", "categorias"})
    @Query("select distinct carro from CarrosEntity carro")
    List<CarrosEntity> findAllWithRelationships();
}
