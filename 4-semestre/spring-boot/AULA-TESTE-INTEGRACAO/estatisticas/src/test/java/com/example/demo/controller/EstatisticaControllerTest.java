package com.example.demo.controller;

import com.example.demo.controller.estatisticas.EstatisticaController;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.http.HttpStatus;


import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

@SpringBootTest
public class EstatisticaControllerTest {

    @Autowired
    EstatisticaController estatisticaController;

    List<Double> numeros;

    @BeforeEach
    void setup() {
        numeros = List.of(1.0, 2.0, 3.0);
    }

    @Test
    void cenario_01_calcular_media(){
        var resposta = estatisticaController.calcularSemSalvar(numeros);

        assertEquals(HttpStatus.OK, resposta.getStatusCode());
        assertNotNull(resposta.getBody());
        assertEquals(2.0, resposta.getBody().media(), 0.001);
    }

//    EXERCÍCIO 1 — Média
    @Test
    void exercicio_01_calcular_media(){
        numeros = List.of(2.0, 4.0, 6.0);

        var resposta = estatisticaController.calcularSemSalvar(numeros);

        assertEquals(HttpStatus.OK, resposta.getStatusCode());
        assertNotNull(resposta.getBody());
        assertEquals(4.0, resposta.getBody().media(), 0.001);
    }

//    EXERCÍCIO 2 — Mediana com quantidade ímpar
    @Test
    void exercicio_02_mediana_impar() {
        numeros = List.of(9.0, 1.0, 3.0);

        var resposta = estatisticaController.calcularSemSalvar(numeros);

        assertEquals(HttpStatus.OK, resposta.getStatusCode());
        assertNotNull(resposta.getBody());
        assertEquals(3.0, resposta.getBody().mediana(), 0.001);
    }

//    EXERCÍCIO 3 — Mediana com quantidade par
    @Test
    void exercicio_03_mediana_par() {
        numeros = List.of(8.0, 2.0, 4.0, 6.0);

        var resposta = estatisticaController.calcularSemSalvar(numeros);

        assertEquals(HttpStatus.OK, resposta.getStatusCode());
        assertNotNull(resposta.getBody());
        assertEquals(5.0, resposta.getBody().mediana(), 0.001);
    }


//    EXERCÍCIO 4 — Maior, menor e total
    void exercicio_04_maior_menor_total() {
        numeros = List.of(-5.0, 10.0, 3.0);

        var resposta = estatisticaController.calcularSemSalvar(numeros);

        assertEquals(HttpStatus.OK, resposta.getStatusCode());
        assertNotNull(resposta.getBody());

        assertEquals(10.0, resposta.getBody().maior(), 0.001);
        assertEquals(-5.0, resposta.getBody().menor(), 0.001);
        assertEquals(3.0, resposta.getBody().total(), 0.001);
    }

//    EXERCÍCIO 5 — Moda
    void exercicio_05_moda() {
        numeros = List.of(1.0, 2.0, 2.0, 3.0);

        var resposta = estatisticaController.calcularSemSalvar(numeros);

        assertEquals(HttpStatus.OK, resposta.getStatusCode());
        assertNotNull(resposta.getBody());

        assertEquals(List.of(2.0), resposta.getBody().moda());
    }

//    EXERCÍCIO 6 — Lista vazia
    void exercicio_06_lista_vazia() {
        numeros = List.of();

        var resposta = estatisticaController.calcularSemSalvar(numeros);

        assertNull(resposta.getBody());
        assertEquals(HttpStatus.BAD_REQUEST, resposta.getStatusCode());
    }

}
`