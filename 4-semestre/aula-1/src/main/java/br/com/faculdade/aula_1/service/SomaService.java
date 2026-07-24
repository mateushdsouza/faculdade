package br.com.faculdade.aula_1.service;

import br.com.faculdade.aula_1.entity.Entrada;
import br.com.faculdade.aula_1.entity.Soma;
import org.springframework.stereotype.Service;

@Service
public class SomaService {
    public Soma soma(Entrada entrada) {
        float somaFinal = 0;
        float media = 0.0f;

        for (Integer numeroAtual : entrada.getLista()) {
            somaFinal += numeroAtual;
        }
        media = (somaFinal / entrada.getLista().size());
        Soma soma1 = new Soma();
        soma1.setResultadoSoma(somaFinal);
        soma1.setResultadoMedia(media);

        return soma1;
    }
}
