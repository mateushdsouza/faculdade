package com.example.demo.entity;

import jakarta.persistence.*;

import java.util.HashSet;
import java.util.Set;

@Entity
@Table(name = "carros")
public class CarrosEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    private Long id;

    @Column(name = "modelo")
    private String modelo;

    @OneToOne(cascade = CascadeType.ALL)
    @JoinColumn(name = "endereco_id", referencedColumnName = "id")
    private EnderecoEntity address;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "fabricante_id", nullable = false)
    private FabricantesEntity fabricantes;

    @ManyToMany
    @JoinTable(
            name = "carro_categoria",
            joinColumns = @JoinColumn(name = "carro_id"),
            inverseJoinColumns = @JoinColumn(name = "categoria_id")
    )
    private Set<CategoriaEntity> categorias = new HashSet<>();



    public CarrosEntity() {
    }

    public CarrosEntity(Long id, String modelo, EnderecoEntity address, FabricantesEntity fabricantes, Set<CategoriaEntity> categorias) {
        this.id = id;
        this.modelo = modelo;
        this.address = address;
        this.fabricantes = fabricantes;
        this.categorias = categorias;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public EnderecoEntity getAddress() {
        return address;
    }

    public void setAddress(EnderecoEntity address) {
        this.address = address;
    }

    public FabricantesEntity getFabricantes() {
        return fabricantes;
    }

    public void setFabricantes(FabricantesEntity fabricantes) {
        this.fabricantes = fabricantes;
    }

    public Set<CategoriaEntity> getCategorias() {
        return categorias;
    }

    public void setCategorias(Set<CategoriaEntity> categorias) {
        this.categorias = categorias;
    }
}
