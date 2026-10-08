package com.example.demo.service;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import com.example.demo.entity.EstatisticaEntity;
import com.example.demo.repository.EstatisticaRepository;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Service
public class EstatisticaService {

    private final EstatisticaRepository estatisticaRepository;

    public EstatisticaService(EstatisticaRepository estatisticaRepository) {
        this.estatisticaRepository = estatisticaRepository;
    }

    // Este método executa apenas regras de cálculo, sem acessar o repository.
    public EstatisticaEntity calcular(List<Double> numeros) {
        validar(numeros);
        return new EstatisticaEntity(
                media(numeros), mediana(numeros), maior(numeros), menor(numeros),
                total(numeros), moda(numeros), soma(numeros), desvioPadrao(numeros));
    }

    @Transactional
    public EstatisticaEntity calcularESalvar(List<Double> numeros) {
        EstatisticaEntity estatistica = calcular(numeros);
        return estatisticaRepository.save(estatistica);
    }

    @Transactional(readOnly = true)
    public List<EstatisticaEntity> findAll() {
        return estatisticaRepository.findAllByOrderByIdAsc();
    }


    public double maior(List<Double> numeros) {
        validar(numeros);
        return Collections.max(numeros);
    }

    public double menor(List<Double> numeros) {
        validar(numeros);
        return Collections.min(numeros);
    }

    public int total(List<Double> numeros) {
        validar(numeros);
        return numeros.size();
    }

    public List<Double> moda(List<Double> numeros) {
        validar(numeros);
        Map<Double, Integer> frequencias = new HashMap<>();
        for (Double numero : numeros) {
            frequencias.merge(numero, 1, Integer::sum);
        }

        int maiorFrequencia = Collections.max(frequencias.values());
        if (maiorFrequencia == 1) {
            return List.of();
        }

        List<Double> modas = new ArrayList<>();
        for (Map.Entry<Double, Integer> entrada : frequencias.entrySet()) {
            if (entrada.getValue() == maiorFrequencia) {
                modas.add(entrada.getKey());
            }
        }
        Collections.sort(modas);
        return modas;
    }

    public double soma(List<Double> numeros) {
        validar(numeros);
        double soma = 0;
        for (Double numero : numeros) {
            soma += numero;
        }
        return soma;
    }

    public double media(List<Double> numeros) {
        validar(numeros);
        return soma(numeros) / numeros.size();
    }

    public double mediana(List<Double> numeros) {
        validar(numeros);
        List<Double> ordenados = new ArrayList<>(numeros);
        Collections.sort(ordenados);
        int meio = ordenados.size() / 2;
        if (ordenados.size() % 2 == 0) {
            return (ordenados.get(meio - 1) + ordenados.get(meio)) / 2;
        }
        return ordenados.get(meio);
    }


    public double desvioPadrao(List<Double> numeros) {
        validar(numeros);
        double media = media(numeros);
        double somaQuadrados = 0;
        for (Double numero : numeros) {
            somaQuadrados += Math.pow(numero - media, 2);
        }
        return Math.sqrt(somaQuadrados / numeros.size());
    }
    private void validar(List<Double> numeros) {
        if (numeros == null || numeros.isEmpty()) {
            throw new IllegalArgumentException("Informe uma lista não vazia de números.");
        }
        if (numeros.stream().anyMatch(n -> n == null || !Double.isFinite(n))) {
            throw new IllegalArgumentException("Todos os elementos devem ser números finitos e não nulos.");
        }
    }
}
