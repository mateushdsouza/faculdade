package com.example.demo.repository;

import com.example.demo.entity.FabricantesEntity;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.Optional;

public interface FabricanteRepository extends JpaRepository<FabricantesEntity, Long> {

    boolean existsByNomeIgnoreCase(String nome);

    Optional<FabricantesEntity> findByNomeIgnoreCase(String nome);
}
