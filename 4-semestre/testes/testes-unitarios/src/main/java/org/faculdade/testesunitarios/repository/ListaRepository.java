package org.faculdade.testesunitarios.repository;

import lombok.Getter;
import org.springframework.stereotype.Repository;


import java.util.ArrayList;
import java.util.List;

@Repository
@Getter
public class ListaRepository {
    private final List<Integer> numeros = new ArrayList<>();

    public void adicionarNumero(Integer numero) {
        if (numeros.size() < 3) {
            numeros.add(numero);
        } else {
            throw new IllegalStateException("A lista ja possui 3 numeros");
        }
    }


}
