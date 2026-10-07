package org.faculdade.testesunitarios;

import org.faculdade.testesunitarios.repository.ListaRepository;
import org.faculdade.testesunitarios.service.ListaService;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;
import static org.junit.jupiter.api.Assertions.*;

@DisplayName("Testes do ListaService")
class ListaServiceTest {

    private ListaRepository listaRepository;
    private ListaService listaService;

    @BeforeEach
    void setUp() {
        listaRepository = new ListaRepository();
        listaService = new ListaService(listaRepository);
    }


    // ==================== MAIOR NÚMERO ====================

    @Test
    @DisplayName("Deve retornar o maior número da lista")
    void deveRetornarMaiorNumero() {
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(30);
        listaRepository.adicionarNumero(20);

        assertEquals(30, listaService.maiorNumero());
    }

    @Test
    @DisplayName("Deve retornar o maior número quando todos forem negativos")
    void deveRetornarMaiorNumeroNegativo() {
        listaRepository.adicionarNumero(-10);
        listaRepository.adicionarNumero(-5);
        listaRepository.adicionarNumero(-20);

        assertEquals(-5, listaService.maiorNumero());
    }

    @Test
    @DisplayName("Deve lançar exceção ao buscar o maior número em uma lista vazia")
    void deveLancarExcecaoNoMaiorComListaVazia() {
        assertThrows(
                IllegalStateException.class,
                () -> listaService.maiorNumero()
        );
    }


    // ==================== MENOR NÚMERO ====================

    @Test
    @DisplayName("Deve retornar o menor número da lista")
    void deveRetornarMenorNumero() {
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(30);
        listaRepository.adicionarNumero(20);

        assertEquals(10, listaService.menorNumero());
    }

    @Test
    @DisplayName("Deve retornar o menor número quando houver números negativos")
    void deveRetornarMenorNumeroNegativo() {
        listaRepository.adicionarNumero(-10);
        listaRepository.adicionarNumero(5);
        listaRepository.adicionarNumero(-20);

        assertEquals(-20, listaService.menorNumero());
    }

    @Test
    @DisplayName("Deve lançar exceção ao buscar o menor número em uma lista vazia")
    void deveLancarExcecaoNoMenorComListaVazia() {
        assertThrows(
                IllegalStateException.class,
                () -> listaService.menorNumero()
        );
    }


    // ==================== QUANTIDADE ====================

    @Test
    @DisplayName("Deve retornar 3 quando a lista possuir três números")
    void deveRetornarQuantidadeTres() {
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(20);
        listaRepository.adicionarNumero(30);

        assertEquals(3, listaService.qtdNumeros());
    }

    @Test
    @DisplayName("Deve retornar 1 quando a lista possuir um número")
    void deveRetornarQuantidadeUm() {
        listaRepository.adicionarNumero(10);

        assertEquals(1, listaService.qtdNumeros());
    }

    @Test
    @DisplayName("Deve retornar 0 quando a lista estiver vazia")
    void deveRetornarQuantidadeZero() {
        assertEquals(0, listaService.qtdNumeros());
    }


    // ==================== MODA ====================

    @Test
    @DisplayName("Deve retornar o número que mais se repete")
    void deveRetornarModa() {
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(20);

        assertEquals(10, listaService.moda());
    }

    @Test
    @DisplayName("Deve retornar a moda quando todos os números forem iguais")
    void deveRetornarModaComTresNumerosIguais() {
        listaRepository.adicionarNumero(5);
        listaRepository.adicionarNumero(5);
        listaRepository.adicionarNumero(5);

        assertEquals(5, listaService.moda());
    }

    @Test
    @DisplayName("Deve retornar null quando não existir moda")
    void deveRetornarNullQuandoNaoExisteModa() {
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(20);
        listaRepository.adicionarNumero(30);

        assertThat(listaService.moda()).isNull();
    }


    // ==================== MÉDIA ====================

    @Test
    @DisplayName("Deve calcular a média dos números")
    void deveCalcularMedia() {
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(20);
        listaRepository.adicionarNumero(30);

        assertEquals(20.0, listaService.media());
    }

    @Test
    @DisplayName("Deve calcular a média de números negativos")
    void deveCalcularMediaComNumerosNegativos() {
        listaRepository.adicionarNumero(-10);
        listaRepository.adicionarNumero(-20);
        listaRepository.adicionarNumero(-30);

        assertEquals(-20.0, listaService.media());
    }

    @Test
    @DisplayName("Deve lançar exceção ao calcular média de uma lista vazia")
    void deveLancarExcecaoNaMediaComListaVazia() {
        assertThrows(
                IllegalStateException.class,
                () -> listaService.media()
        );
    }


    // ==================== MULTIPLICAÇÃO ====================

    @Test
    @DisplayName("Deve multiplicar os três números")
    void deveMultiplicarTresNumeros() {
        listaRepository.adicionarNumero(2);
        listaRepository.adicionarNumero(3);
        listaRepository.adicionarNumero(4);

        assertEquals(24, listaService.multiplicacao());
    }

    @Test
    @DisplayName("Deve retornar 0 quando um dos números for zero")
    void deveRetornarZeroNaMultiplicacaoComZero() {
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(0);
        listaRepository.adicionarNumero(5);

        assertEquals(0, listaService.multiplicacao());
    }

    @Test
    @DisplayName("Deve lançar exceção quando não houver três números para multiplicar")
    void deveLancarExcecaoNaMultiplicacaoSemTresNumeros() {
        listaRepository.adicionarNumero(10);
        listaRepository.adicionarNumero(20);

        assertThrows(
                IllegalStateException.class,
                () -> listaService.multiplicacao()
        );
    }
}