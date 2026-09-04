package com.example.demo.config;

import com.example.demo.entity.CarrosEntity;
import com.example.demo.entity.FabricantesEntity;
import com.example.demo.repository.CarroRepository;
import com.example.demo.repository.FabricanteRepository;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.stereotype.Component;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Component
public class DataSeeder implements ApplicationRunner {

    private final CarroRepository carroRepository;
    private final FabricanteRepository fabricanteRepository;

    public DataSeeder(
            CarroRepository carroRepository,
            FabricanteRepository fabricanteRepository
    ) {
        this.carroRepository = carroRepository;
        this.fabricanteRepository = fabricanteRepository;
    }

    @Override
    @Transactional
    public void run(ApplicationArguments args) {
        cadastrarFabricantes();
        cadastrarCarrosComFabricante();
    }

    private void cadastrarFabricantes() {
        List<String> nomes = List.of(
                "Toyota",
                "Honda",
                "Volkswagen",
                "Chevrolet",
                "Ford"
        );

        nomes.stream()
                .filter(nome -> !fabricanteRepository.existsByNomeIgnoreCase(nome))
                .map(this::novoFabricante)
                .forEach(fabricanteRepository::save);
    }

    private void cadastrarCarrosComFabricante() {
        List<CarroSeed> carros = List.of(
                new CarroSeed("Corolla", "Toyota"),
                new CarroSeed("Civic", "Honda"),
                new CarroSeed("Golf", "Volkswagen"),
                new CarroSeed("Onix", "Chevrolet"),
                new CarroSeed("Ka", "Ford")
        );

        carros.stream()
                .filter(carro -> !carroRepository.existsByModeloIgnoreCase(carro.modelo()))
                .map(this::novoCarroComFabricante)
                .forEach(carroRepository::save);
    }

    private FabricantesEntity novoFabricante(String nome) {
        FabricantesEntity fabricante = new FabricantesEntity();
        fabricante.setNome(nome);
        return fabricante;
    }

    private CarrosEntity novoCarroComFabricante(CarroSeed seed) {
        FabricantesEntity fabricante = fabricanteRepository
                .findByNomeIgnoreCase(seed.fabricante())
                .orElseThrow();

        CarrosEntity carro = new CarrosEntity();
        carro.setModelo(seed.modelo());
        carro.setFabricantes(fabricante);
        return carro;
    }

    private record CarroSeed(String modelo, String fabricante) {
    }
}
