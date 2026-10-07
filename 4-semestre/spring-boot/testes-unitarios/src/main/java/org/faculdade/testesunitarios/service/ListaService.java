package org.faculdade.testesunitarios.service;

import lombok.AllArgsConstructor;
import org.faculdade.testesunitarios.repository.ListaRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
@AllArgsConstructor
public class ListaService {
    private final ListaRepository listaRepository;

    public void adicionarNumeros(Integer numero) {
        listaRepository.adicionarNumero(numero);
    }

    public Integer maiorNumero() {
        if (listaRepository.getNumeros().isEmpty()) {
            throw new IllegalStateException("A lista esta vazia");
        }

        Integer maior = listaRepository.getNumeros().get(0);

        for (Integer numero : listaRepository.getNumeros()) {
            if (numero > maior) {
                maior = numero;
            }
        }

        return maior;
    }

    public Integer menorNumero() {
        if (listaRepository.getNumeros().isEmpty()) {
            throw new IllegalStateException("A lista esta vazia");
        }

        Integer menor = listaRepository.getNumeros().get(0);

        for (Integer numero : listaRepository.getNumeros()) {
            if (numero < menor) {
                menor = numero;
            }
        }

        return menor;
    }

    public Integer qtdNumeros() {
        return listaRepository.getNumeros().size();
    }

    public Integer moda() {
        if (listaRepository.getNumeros().isEmpty()) {
            throw new IllegalStateException("A lista esta vazia");
        }

        Integer moda = null;
        int maiorFrequencia = 1;

        for (Integer numero : listaRepository.getNumeros()) {
            int frequencia = 0;

            for (Integer outroNumero : listaRepository.getNumeros()) {
                if (numero.equals(outroNumero)) {
                    frequencia++;
                }
            }

            if (frequencia > maiorFrequencia) {
                maiorFrequencia = frequencia;
                moda = numero;
            }
        }

        return moda;
    }

    public Double media() {
        if (listaRepository.getNumeros().isEmpty()) {
            throw new IllegalStateException("A lista esta vazia");
        }

        Integer soma = 0;

        for (Integer numero : listaRepository.getNumeros()) {
            soma += numero;
        }

        return (double) soma / listaRepository.getNumeros().size();
    }

    public Integer multiplicacao() {
        if (listaRepository.getNumeros().size() != 3) {
            throw new IllegalStateException("A lista deve possuir 3 numeros");
        }

        Integer resultado = 1;

        for (Integer numero : listaRepository.getNumeros()) {
            resultado *= numero;
        }

        return resultado;
    }
}
