package com.example.demo.repository;

import com.example.demo.entity.EstatisticaEntity;
import org.springframework.data.jpa.repository.EntityGraph;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.List;

public interface EstatisticaRepository extends JpaRepository<EstatisticaEntity, Long> {

    @EntityGraph(attributePaths = "moda")
    List<EstatisticaEntity> findAllByOrderByIdAsc();
}
