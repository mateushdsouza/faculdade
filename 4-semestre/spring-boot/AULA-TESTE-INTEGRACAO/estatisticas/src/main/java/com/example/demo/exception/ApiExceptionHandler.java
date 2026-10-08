package com.example.demo.exception;

import com.example.demo.controller.estatisticas.dto.ErroResponseDTO;
import org.springframework.http.ResponseEntity;
import org.springframework.http.converter.HttpMessageNotReadableException;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.RestControllerAdvice;

@RestControllerAdvice
public class ApiExceptionHandler {

    // JSON inválido é rejeitado antes da execução do método do controller.
    @ExceptionHandler(HttpMessageNotReadableException.class)
    public ResponseEntity<ErroResponseDTO> tratarJsonInvalido() {
        return ResponseEntity.badRequest().body(new ErroResponseDTO("Envie um array JSON de números."));
    }
}
