package br.com.faculdade.aula_3.repository;

import br.com.faculdade.aula_3.entity.Carro;
import org.springframework.data.jpa.repository.JpaRepository;

public interface CarroRepository extends JpaRepository<Carro, Long> {

}
