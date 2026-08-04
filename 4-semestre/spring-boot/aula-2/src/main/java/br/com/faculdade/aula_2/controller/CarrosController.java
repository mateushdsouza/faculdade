package br.com.faculdade.aula_2.controller;

import br.com.faculdade.aula_2.controller.carros.dto.CarrosRequest;
import br.com.faculdade.aula_2.controller.carros.dto.CarrosResponse;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("/carros")
public class CarrosController {

    @PostMapping("/salvar")
    public ResponseEntity<CarrosResponse> saveNewCar(@RequestBody CarrosRequest carrosRequest){
        System.out.println(carrosRequest.getMarca());
        return ResponseEntity.ok(new CarrosResponse());
    }
}
