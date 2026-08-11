package br.com.faculdade.atividade_2.controller;

import br.com.faculdade.atividade_2.controller.dto.LivroRequest;
import br.com.faculdade.atividade_2.controller.dto.LivroResponse;
import br.com.faculdade.atividade_2.entity.Livro;
import br.com.faculdade.atividade_2.service.LivroService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.server.ResponseStatusException;

import java.util.List;

@RestController
@RequestMapping("/api/livros")
@RequiredArgsConstructor
public class LivroController {

    private final LivroService livroService;


    @PostMapping()
    public ResponseEntity<LivroResponse> salvar(
            @RequestBody LivroRequest livroRequest
    ) {
        try {

            Livro livro = this.livroService.salvar(livroRequest);

            return new ResponseEntity<>(
                    LivroResponse.de(livro),
                    HttpStatus.CREATED
            );

        } catch (Exception e) {

            return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
        }
    }


    @GetMapping("/{id}")
    public ResponseEntity<LivroResponse> buscarPorId(
            @PathVariable Long id
    ) {

        try {

            Livro livro = this.livroService.buscarPorId(id);

            return new ResponseEntity<>(
                    LivroResponse.de(livro),
                    HttpStatus.OK
            );

        } catch (ResponseStatusException responseStatusException) {

            throw responseStatusException;

        } catch (Exception e) {

            return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
        }
    }


    @GetMapping()
    public ResponseEntity<List<LivroResponse>> listar() {

        try {

            List<LivroResponse> livros = this.livroService.listar()
                    .stream()
                    .map(LivroResponse::de)
                    .toList();

            return new ResponseEntity<>(
                    livros,
                    HttpStatus.OK
            );

        } catch (Exception e) {

            return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
        }
    }



    @PutMapping("/{id}")
    public ResponseEntity<LivroResponse> atualizar(
            @PathVariable Long id,
            @RequestBody LivroRequest livroRequest
    ) {

        try {

            Livro livro = this.livroService.atualizar(
                    id,
                    livroRequest
            );

            return new ResponseEntity<>(
                    LivroResponse.de(livro),
                    HttpStatus.OK
            );

        } catch (ResponseStatusException responseStatusException) {

            throw responseStatusException;

        } catch (Exception e) {

            return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
        }
    }


    @PatchMapping("/{id}")
    public ResponseEntity<LivroResponse> atualizarParcial(
            @PathVariable Long id,
            @RequestBody LivroRequest livroRequest
    ) {

        try {

            Livro livro = this.livroService.atualizarParcial(
                    id,
                    livroRequest
            );

            return new ResponseEntity<>(
                    LivroResponse.de(livro),
                    HttpStatus.OK
            );

        } catch (ResponseStatusException responseStatusException) {

            throw responseStatusException;

        } catch (Exception e) {

            return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
        }
    }


    @DeleteMapping("/{id}")
    public ResponseEntity<?> deletarPorId(
            @PathVariable Long id
    ) {

        try {

            this.livroService.deletarPorId(id);

            return new ResponseEntity<>(
                    HttpStatus.OK
            );

        } catch (ResponseStatusException responseStatusException) {

            throw responseStatusException;

        } catch (Exception e) {

            return new ResponseEntity<>(
                    HttpStatus.BAD_REQUEST
            );
        }
    }


    @GetMapping("/genero/{genero}")
    public ResponseEntity<List<LivroResponse>> buscarPorGenero(
            @PathVariable String genero
    ) {

        try {

            List<LivroResponse> livros = this.livroService
                    .buscarPorGenero(genero)
                    .stream()
                    .map(LivroResponse::de)
                    .toList();

            return new ResponseEntity<>(
                    livros,
                    HttpStatus.OK
            );

        } catch (Exception e) {

            return new ResponseEntity<>(
                    HttpStatus.BAD_REQUEST
            );
        }
    }


    @GetMapping("/disponiveis")
    public ResponseEntity<List<LivroResponse>> buscarDisponiveis() {

        try {

            List<LivroResponse> livros = this.livroService
                    .buscarDisponiveis()
                    .stream()
                    .map(LivroResponse::de)
                    .toList();

            return new ResponseEntity<>(
                    livros,
                    HttpStatus.OK
            );

        } catch (Exception e) {

            return new ResponseEntity<>(
                    HttpStatus.BAD_REQUEST
            );
        }
    }


    @GetMapping("/buscar")
    public ResponseEntity<List<LivroResponse>> buscar(
            @RequestParam String autor,
            @RequestParam Integer anoMin
    ) {

        try {

            List<LivroResponse> livros = this.livroService
                    .buscar(autor, anoMin)
                    .stream()
                    .map(LivroResponse::de)
                    .toList();

            return new ResponseEntity<>(
                    livros,
                    HttpStatus.OK
            );

        } catch (Exception e) {

            return new ResponseEntity<>(
                    HttpStatus.BAD_REQUEST
            );
        }
    }


    // PATCH /api/livros/{id}/emprestar
    @PatchMapping("/{id}/emprestar")
    public ResponseEntity<LivroResponse> emprestar(
            @PathVariable Long id
    ) {

        try {

            Livro livro = this.livroService.emprestar(id);

            return new ResponseEntity<>(
                    LivroResponse.de(livro),
                    HttpStatus.OK
            );

        } catch (ResponseStatusException responseStatusException) {

            throw responseStatusException;

        } catch (Exception e) {

            return new ResponseEntity<>(
                    HttpStatus.BAD_REQUEST
            );
        }
    }
}