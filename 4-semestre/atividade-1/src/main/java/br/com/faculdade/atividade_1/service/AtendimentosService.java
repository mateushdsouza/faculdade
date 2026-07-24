package br.com.faculdade.atividade_1.service;

import br.com.faculdade.atividade_1.entity.Entradas;
import br.com.faculdade.atividade_1.entity.Saidas;
import org.springframework.stereotype.Service;

@Service
public class AtendimentosService {
    public Saidas classificar(Entradas entradas) {
        Saidas saidas = new Saidas();
        if (entradas.getIdade() >= 60 || entradas.isGestante() || entradas.isPessoaComDeficiencia()) {
            saidas.setNome(entradas.getNome());
            saidas.setTipoAtendimento("PRIORITARIO");
            saidas.setMensagem("Pessoa com direito a atendimento prioritário.");
        }else {
            saidas.setNome(entradas.getNome());
            saidas.setTipoAtendimento("COMUM");
            saidas.setMensagem("Pessoa com direito a atendimento comum.");
        }
        return saidas;
    }
}
