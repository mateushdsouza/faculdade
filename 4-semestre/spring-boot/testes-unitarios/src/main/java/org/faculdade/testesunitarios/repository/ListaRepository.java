package org.faculdade.testesunitarios.repository;

import lombok.Getter;
import org.springframework.stereotype.Repository;


import java.util.ArrayList;
import java.util.List;

@Repository
@Getter
public class ListaRepository {
    private ArrayList<Integer> numeros = new List();

    private void adicionarNumero(Integer numero) {
        if (numeros.size() < 3) {
            numeros.add(numero);
        } else {
            throw new IllegalStateException("A lista ja possui 3 numeros")
        }
    }


}
