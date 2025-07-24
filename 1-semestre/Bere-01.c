#include <stdio.h>
#include <math.h> 

int main() {
int menu, quantidade, produto, pagamento, faturamento; 
char entrada;
float precoL[] = {1.99, 8.99, 1.50, 15.00}; 
float precoA[] = {19.30, 4.90, 6.70, 69.99, 8.00};
float precoP[] = {7.50, 8.99, 1.50, 13.00};
float total = 0, totalL = 0, totalA = 0, totalP = 0, totalf = 0, subtotal = 0, desconto = 0;

printf("Bem-vindo ao mercadão do Fabião: Aqui você não sai no 0x0!\n");
printf("Utilize a tecla [E] para entrar no sistema: ");
scanf(" %c", &entrada);
    
    if (entrada == 'E' || entrada == 'e') { 
    do {
     subtotal = totalA + totalL + totalP; 
     printf("\nMenu principal:\n");
     printf("1- Material de Limpeza\n");
     printf("2- Venda de Alimentos\n");
     printf("3- Padaria\n");
     printf("4- Pagamento\n");
     printf("5- Faturamento diario\n");
     printf("6- Sair\n");
     printf("Escolha a opção de acordo com seu número: ");
     scanf("%d", &menu);
     
     switch (menu) {
     case 1:
     do {
         printf("\nMateriais de limpeza:\n");
         printf("Valor da compra: R$%.2f\n", totalL);
         printf("1- Detergente - R$1,99\n");
         printf("2- Sabão em pó (1kg) - R$8,99\n");
         printf("3- Esponja - R$1,50\n");
         printf("4- Amaciante (1L) - R$15,00\n");
         printf("5- Voltar ao menu principal\n");
         printf("Escolha a opção: ");
         scanf("%d", &produto);
         if (produto >= 1 && produto <= 4) {
         printf("Determine a quantidade: ");
         scanf("%d", &quantidade);
         total = quantidade * precoL[produto - 1];
         totalL += total;  // Acumula o total
         printf("Você adicionou %d unidade(s) do produto %d!\n", quantidade, produto);
         } 
         else if (produto == 5) {
         printf("Voltando ao Menu...\n\n");
         } 
         else {
         printf("Opção inválida!\n");
         }
     } while (produto != 5);
     break;
     
     case 2:
     do {
         printf("\nAlimentos:\n");
         printf("Valor da compra: R$%.2f\n", totalA);
         printf("1- Café - R$19,30\n");
         printf("2- Leite - R$4,90\n");
         printf("3- Arroz - R$6,70\n");
         printf("4- Picanha Bovina - R$69,99\n");
         printf("5- Feijão carioca - R$8,00\n");
         printf("6- Voltar ao menu principal\n");
         printf("Escolha a opção: ");
         scanf("%d", &produto);
         if (produto >= 1 && produto <= 5) {
         printf("Determine a quantidade: ");
         scanf("%d", &quantidade);
         total = quantidade * precoA[produto - 1];
         totalA += total;  
         printf("Você adicionou %d unidade(s) do produto %d!\n", quantidade, produto);
         } 
         else if (produto == 6) {
         printf("Voltando ao Menu...\n\n");
         } 
         else {
         printf("Opção inválida!\n");
         }
     } while (produto != 6);
     break;
     
     case 3:
     do {
         printf("\nPadaria:\n");
         printf("Total da Padaria: %.2f\n", totalP);
         printf("1- Pão de forma - R$7,50\n");
         printf("2- Pão de ló - R$8,99\n");
         printf("3- Pão francês - R$1,50\n");
         printf("4- Pão integral - R$13,00\n");
         printf("5- Voltar ao menu principal\n");
         printf("Escolha a opção: ");
         scanf("%d", &produto);
         if (produto >= 1 && produto <= 4) {
         printf("Determine a quantidade: ");
         scanf("%d", &quantidade);
         total = quantidade * precoP[produto - 1];
         totalP += total;  
         printf("Você adicionou %d unidade(s) do produto %d!\n", quantidade, produto);
         } 
         else if (produto == 5) {
         printf("Voltando ao Menu...\n");
         } 
         else {
         printf("Opção inválida!\n");
         }
     } while (produto != 5);
     break;
     
     case 4:
         printf("\nTotal da sua compra: R$%.2f\n", subtotal);
         printf("1- Dinheiro (até 18%% de Cashback);\n");
         printf("2- Cartão.\n");
         printf("Escolha a opção de pagamento: ");
         scanf("%d", &pagamento);
         if (pagamento == 1) {
         if (subtotal <= 50) desconto = subtotal * 0.05;
         else if (subtotal < 100) desconto = subtotal * 0.10;
         else desconto = subtotal * 0.18;
         subtotal -= desconto;
         }
         printf("Valor final: R$%.2f\n", subtotal);
         totalf += subtotal;  
         totalL = totalA = totalP = subtotal = 0;  
         printf("Pagamento finalizado!\n");
     break;
     
     case 5:
         printf("\nO faturamento diário é de: R$%.2f\n", totalf);
     break;
     
     case 6:
         printf("Saindo...\n");
     break;

     default:
         printf("Opção inválida!\n");
         }
     } while (menu != 6); //feche do
    } //feche if
     else {
         printf("Tecla incorreta!\n");
    }
return 0;
}