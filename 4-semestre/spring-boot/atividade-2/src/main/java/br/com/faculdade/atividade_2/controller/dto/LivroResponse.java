package br.com.faculdade.atividade_2.controller.dto;

import br.com.faculdade.atividade_2.entity.Livro;

public record LivroResponse(
        Long id,
        String titulo,
        String autor,
        String genero,
        Integer anoPublicado,
        Integer paginas,
        boolean disponivel
) {

    public static LivroResponse de(Livro livro) {
        return new LivroResponse(
                livro.getId(),
                livro.getTitulo(),
                livro.getAutor(),
                livro.getGenero(),
                livro.getAnoPublicado(),
                livro.getPaginas(),
                livro.isDisponivel()
        );
    }
}