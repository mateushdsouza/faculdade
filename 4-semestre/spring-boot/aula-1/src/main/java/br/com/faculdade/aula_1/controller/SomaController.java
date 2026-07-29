package br.com.faculdade.aula_1.controller;

import br.com.faculdade.aula_1.entity.Entrada;
import br.com.faculdade.aula_1.entity.Soma;
import br.com.faculdade.aula_1.service.SomaService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@Slf4j
@RestController()
@RequestMapping("api/soma")
public class SomaController {
    @Autowired
    private SomaService somaService;

    @GetMapping()
    private ResponseEntity<Soma> soma(@RequestBody Entrada entrada){
        try {
            Soma soma = this.somaService.soma(entrada);

            return new ResponseEntity<Soma>(soma, HttpStatus.OK);
        } catch (Exception e) {
            log.info(e.getMessage());
            return new ResponseEntity(HttpStatus.BAD_REQUEST);
        }
    }
}
