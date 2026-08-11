package br.com.faculdade.atividade_2.service;

import br.com.faculdade.atividade_2.controller.dto.LivroRequest;
import br.com.faculdade.atividade_2.entity.Livro;
import br.com.faculdade.atividade_2.repository.LivroRepository;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Service;
import org.springframework.web.server.ResponseStatusException;

import java.util.List;

@Service
@RequiredArgsConstructor
public class LivroService {

    private final LivroRepository repository;

    public Livro salvar(LivroRequest livroRequest) {

        Livro livro = new Livro();

        livro.setTitulo(livroRequest.getTitulo());
        livro.setAutor(livroRequest.getAutor());
        livro.setGenero(livroRequest.getGenero());
        livro.setAnoPublicado(livroRequest.getAnoPublicado());
        livro.setPaginas(livroRequest.getPaginas());
        livro.setDisponivel(true);

        return this.repository.save(livro);
    }

    public Livro buscarPorId(Long id) {

        return this.repository.findById(id)
                .orElseThrow(
                        () -> new ResponseStatusException(
                                HttpStatus.NOT_FOUND,
                                "Livro não encontrado com id " + id
                        )
                );
    }

    public List<Livro> listar() {
        return this.repository.findAll();
    }

    public Livro atualizar(Long id, LivroRequest livroRequest) {

        Livro livro = this.buscarPorId(id);

        livro.setTitulo(livroRequest.getTitulo());
        livro.setAutor(livroRequest.getAutor());
        livro.setGenero(livroRequest.getGenero());
        livro.setAnoPublicado(livroRequest.getAnoPublicado());
        livro.setPaginas(livroRequest.getPaginas());

        return this.repository.save(livro);
    }

    public Livro atualizarParcial(Long id, LivroRequest livroRequest) {

        Livro livro = this.buscarPorId(id);

        if (livroRequest.getTitulo() != null) {
            livro.setTitulo(livroRequest.getTitulo());
        }

        if (livroRequest.getAutor() != null) {
            livro.setAutor(livroRequest.getAutor());
        }

        if (livroRequest.getGenero() != null) {
            livro.setGenero(livroRequest.getGenero());
        }

        if (livroRequest.getAnoPublicado() != null) {
            livro.setAnoPublicado(livroRequest.getAnoPublicado());
        }

        if (livroRequest.getPaginas() != null) {
            livro.setPaginas(livroRequest.getPaginas());
        }

        return this.repository.save(livro);
    }

    public void deletarPorId(Long id) {

        Livro livro = this.buscarPorId(id);

        this.repository.delete(livro);
    }

    public List<Livro> buscarPorGenero(String genero) {

        return this.repository.findByGenero(genero);
    }

    public List<Livro> buscarDisponiveis() {

        return this.repository.findByDisponivelTrue();
    }

    public List<Livro> buscar(String autor, Integer anoMin) {

        return this.repository
                .findByAutorAndAnoPublicadoGreaterThanEqual(autor, anoMin);
    }

    public Livro emprestar(Long id) {

        Livro livro = this.buscarPorId(id);

        if (!livro.isDisponivel()) {
            throw new ResponseStatusException(
                    HttpStatus.CONFLICT,
                    "Livro já está emprestado"
            );
        }

        livro.setDisponivel(false);

        return this.repository.save(livro);
    }
}