package br.com.faculdade.atividade_2.repository;

import br.com.faculdade.atividade_2.entity.Livro;
import org.springframework.data.jpa.repository.JpaRepository;

import java.util.List;

public interface LivroRepository extends JpaRepository<Livro, Long> {

    List<Livro> findByGenero(String genero);

    List<Livro> findByDisponivelTrue();

    List<Livro> findByAutorAndAnoPublicadoGreaterThanEqual(
            String autor,
            Integer anoMin
    );
}