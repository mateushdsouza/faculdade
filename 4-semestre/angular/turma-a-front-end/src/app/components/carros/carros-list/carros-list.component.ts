import { Component, inject } from '@angular/core';
import { RouterLink } from "@angular/router";
import { Carro } from '../../../models/carro';
import { CarrosService } from '../../../services/carros.service';

@Component({
  selector: 'app-carros-list',
  imports: [RouterLink],
  templateUrl: './carros-list.component.html',
  styleUrl: './carros-list.component.scss'
})
export class CarrosListComponent {
  carroService = inject(CarrosService);

  ngOnInit() {
    this.findAll();
  }
  findAll() {
    this.carroService.listAll().subscribe({
      next: (retorno) => {
        this.lista = retorno;
      }
      error:(erro) => {
        console.log(erro);
        Swal.fire({
          icon: "error",
          title: "Falha de carregamento",
          text: "Ocorreu um erro ao tentar carregar a lista",
        });
      }
    })
  }


  lista: Carro[] = []

  constructor() {
    
    this.lista.push(new Carro(1, 'Ford', 'Fiesta'));
    this.lista.push(new Carro(2, 'Fiat', 'Uno'));
    this.lista.push(new Carro(3, 'Honda', 'Civic'));


    let carroNovo = history.state.carroNovo;

    let carroEditado = history.state.carroEditado;

    if(carroNovo) {
      carroNovo.id = 123;
      this.lista.push(carroNovo);
    }

    if(carroEditado) {
      console.log(carroEditado)
      for(let i = 0; i < this.lista.length; i++) {
        console.log(carroEditado.id, this.lista[i].id)
        if(carroEditado.id == this.lista[i].id) {
          console.log("achou")
          this.lista[i] = carroEditado
          break;
        }
      }
    }
  }

  deletar(carro: Carro) {
    Swal.fire({
      t
    })
  }
}
