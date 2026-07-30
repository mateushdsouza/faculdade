import { Component } from '@angular/core';
import { Carro } from '../../models/carro';

@Component({
  selector: 'app-carros-list',
  imports: [],
  templateUrl: './carros-list.component.html',
  styleUrl: './carros-list.component.scss'
})
export class CarrosListComponent {
  lista: Carro[] = [];

  constructor() {
    let carro1 = new Carro();
    carro1.id = 1;
    carro1.marca = 'Ford';
    carro1.nome = 'Fiesta';

    let carro2 = new Carro();
    carro2.id = 2;
    carro2.marca = 'Honda';
    carro2.nome = 'Civic';

    let carro3 = new Carro();
    carro3.id = 3;
    carro3.marca = 'Chevrolet';
    carro3.nome = 'Onix';

    this.lista.push(carro1);
    this.lista.push(carro2);
    this.lista.push(carro3);
  }
}