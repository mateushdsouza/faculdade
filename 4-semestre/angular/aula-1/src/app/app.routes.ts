import { Routes } from '@angular/router';
import { CarrosListComponent } from './components/carros-list/carros-list.component';
import { DashboardComponent } from './components/dashboard/dashboard.component';

export const routes: Routes = [
  { path: '', redirectTo:'carros', pathMatch:'full'},
  { path: 'carros', component:CarrosListComponent},
  { path: 'dashboard', component:DashboardComponent}
];