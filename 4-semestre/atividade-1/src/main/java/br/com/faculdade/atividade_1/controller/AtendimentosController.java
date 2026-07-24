package br.com.faculdade.atividade_1.controller;

import br.com.faculdade.atividade_1.entity.Entradas;
import br.com.faculdade.atividade_1.entity.Saidas;
import br.com.faculdade.atividade_1.service.AtendimentosService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@RequestMapping("api/atendimentos")
public class AtendimentosController {
    @Autowired
    private AtendimentosService atendimentosService;

    @PostMapping("classificar")
    public ResponseEntity<Saidas> classificar(@RequestBody Entradas entradas) {
        try {
            Saidas saidas = this.atendimentosService.classificar(entradas);

            return new ResponseEntity<Saidas>(saidas, HttpStatus.OK);
        } catch (Exception e) {
            return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
        }
    }
}
