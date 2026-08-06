package br.com.faculdade.aula_3.service;

import br.com.faculdade.aula_3.controller.carro.dto.CarroRequest;
import br.com.faculdade.aula_3.entity.Carro;
import br.com.faculdade.aula_3.repository.CarroRepository;
import lombok.AllArgsConstructor;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.stereotype.Service;
import org.springframework.web.server.ResponseStatusException;

import java.util.ArrayList;

@Service
@RequiredArgsConstructor
public class CarroService {
    private final CarroRepository carroRepository;

    public Carro salvar(CarroRequest carroRequest){
        Carro carro = new Carro();
        carro.setMarca(carroRequest.getMarca());
        carro.setAno(carroRequest.getAno());
        carro.setPreco(carroRequest.getPreco());
        carro.setModelo(carroRequest.getModelo());
        carro.setCor(carroRequest.getCor());

        return this.carroRepository.save(carro);
    }

    public Carro atualizar(){

        return null;
    }

    public Carro buscarPorId(Long id){
        return this.carroRepository.findById(id)
                .orElseThrow(
                        () -> new ResponseStatusException(
                        HttpStatus.NOT_FOUND,
                        "Carro não encontrado com id "+ id));
    }

    public ArrayList<Carro> listar(){

        return null;
    }

    public Carro deletarPorId(){

        return null;
    }
}
