package br.com.faculdade.aula_3.controller.carro;

import br.com.faculdade.aula_3.controller.carro.dto.CarroRequest;
import br.com.faculdade.aula_3.controller.carro.dto.CarroResponse;
import br.com.faculdade.aula_3.entity.Carro;
import br.com.faculdade.aula_3.service.CarroService;
import lombok.AllArgsConstructor;
import lombok.RequiredArgsConstructor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.server.ResponseStatusException;

@RestController
@RequestMapping("/api/carros")
@RequiredArgsConstructor
public class CarroController {
    private final CarroService carroService;

    @PostMapping("/salvar")
    public ResponseEntity<CarroResponse> salvar (@RequestBody CarroRequest carroRequest) {
        try {
            Carro carro = this.carroService.salvar(carroRequest);
            return ResponseEntity.ok().body(CarroResponse.de(carro));
        } catch (Exception e) {
            return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
        }
    }

    @GetMapping("/{id}")
    public ResponseEntity<CarroResponse> buscarPorId (@PathVariable Long id){
        try {
            Carro carro = this.carroService.buscarPorId(id);
            return ResponseEntity.ok().body(CarroResponse.de(carro));
        } catch (ResponseStatusException responseStatusException) {
            throw responseStatusException;
        }

    }
}
