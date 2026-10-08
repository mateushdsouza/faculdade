package com.example.demo.entity;

import jakarta.persistence.*;
import java.util.ArrayList;
import java.util.List;

@Entity
@Table(name = "estatisticas")
public class EstatisticaEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Column(nullable = false)
    private Double media;

    @Column(nullable = false)
    private Double mediana;

    @Column(nullable = false)
    private Double maior;

    @Column(nullable = false)
    private Double menor;

    @Column(nullable = false)
    private Integer total;

    @ElementCollection
    @CollectionTable(name = "estatistica_modas", joinColumns = @JoinColumn(name = "estatistica_id"))
    @OrderColumn(name = "posicao")
    @Column(name = "valor", nullable = false)
    private List<Double> moda = new ArrayList<>();

    @Column(nullable = false)
    private Double soma;

    @Column(nullable = false)
    private Double desvioPadrao;

    public EstatisticaEntity() {
    }

    public EstatisticaEntity(Double media, Double mediana, Double maior, Double menor, Integer total, List<Double> moda, Double soma, Double desvioPadrao) {
        this.media = media;
        this.mediana = mediana;
        this.maior = maior;
        this.menor = menor;
        this.total = total;
        this.moda = new ArrayList<>(moda);
        this.soma = soma;
        this.desvioPadrao = desvioPadrao;
    }

    public Long getId() {
        return id;
    }

    public Double getMedia() {
        return media;
    }

    public Double getMediana() {
        return mediana;
    }

    public Double getMaior() {
        return maior;
    }

    public Double getMenor() {
        return menor;
    }

    public Integer getTotal() {
        return total;
    }

    public List<Double> getModa() {
        return moda;
    }

    public Double getSoma() {
        return soma;
    }

    public Double getDesvioPadrao() {
        return desvioPadrao;
    }
}
