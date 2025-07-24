#include <stdio.h>

#define maxProduto 100

struct produtoES {// Struct usada para o estoque com o maximo de 100 itens.
    int id;
    char nomePd[50];
    int quantidade;
    float preco;
};

float calcularDesconto(float subtotal) { // Função usada para calcular o desconto.
    float desconto = 0, desconto200 = 0;

    if (subtotal <= 50) {
        desconto = subtotal * 0.05;
    } else if (subtotal < 200) {
        desconto = subtotal * 0.10;
    } else {
        printf("\tO total é maior que 200, digite quanto de desconto você deseja aplicar (%%):\n");
        scanf("%f", &desconto200);
        desconto = subtotal * (desconto200 / 100);
    }

    return desconto;
}

int main() {
    int menu, quantidade, id, pagamento;
    float totalL = 0, total = 0, subtotal = 0, totalA = 0, totalP = 0, totalf = 0, desconto = 0, desconto200 = 0, totali=0;
    char entrada;

    struct produtoES produtoEstoque[maxProduto] = {
        {1, "Detergente (unid.)", 50, 1.99},
        {2, "Sabão em Pó (1kg)", 30, 8.99},
        {3, "Esponja", 0, 1.50},
        {4, "Amaciante", 20, 15.00},
        {5, "Bucha de Pia (3 unid.)", 99, 4.99},
        {6, "Desinfetante(1L)", 15, 7.99},
        {7, "Sabão em Barra (unid.)", 60, 1.00},
        {8, "Café (500g)", 10, 24.99},
        {9, "Cerveja Ruim (unid.)", 15, 5.90},
        {10, "Arroz (1kg)", 10, 8.00},
        {11, "Feijão Preto (1kg)", 5, 9.00},
        {12, "Açucar (1kg)", 20, 5.00},
        {13, "Sal (1kg)", 6, 2.00},
        {14, "Picanha Bovina (1kg)", 15, 80.00},
        {15, "Pão de Forma (pct)", 0, 9.50},
        {16, "Pão de Integral (pct)", 0, 12.50},
        {17, "Pão Francês (unid.)", 0, 1.90},
        {18, "Sonho (unid.)", 0, 8.50},
        {19, "Biscoito (g)", 0, 12.50},
        {20, "Pão Doce (unid.)", 0, 2.50},
        {21, "Salgado (unid.)", 0, 17.50}
    };
    printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    printf("\t    Seja Bem-Vindo(a) ao Mercadão do Fabião\n\t           Aqui você não sai no 0x0!\n");
    printf("\t▶ Utilize a tecla [E] para entrar no sistema: ");
    scanf(" %c", &entrada);

    if (entrada == 'E' || entrada == 'e') {
        do {
            printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
            printf("\n\t================ MENU PRINCIPAL ================\n");
            printf("\t1 | 🪣 Materiais de Limpeza\n");
            printf("\t2 | 🍖 Venda de Alimentos\n");
            printf("\t3 | 🥖 Padaria\n");
            printf("\t4 | 💰 Pagamento\n");
            printf("\t5 | 📦 Estoque\n");
            printf("\t6 | 🛒 Caixa\n");
            printf("\t7 | 🔚 Sair\n");
            printf("\t▶ Escolha o setor de acordo com seu número: ");
            scanf("%d", &menu);

            switch (menu) {
                case 1:
                    do {
                        printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
                        printf("\t============= MATERIAIS DE LIMPEZA =============\n");
                        printf("\t🛒 Valor da compra: R$%.2f\n", totalL);
                        printf("\t1 | 🧴 Detergente ------------- R$1,99\n");
                        printf("\t2 | 🫧 Sabão em pó (1kg) ------ R$8,99\n");
                        printf("\t3 | 🧽 Esponja ---------------- R$1,50\n");
                        printf("\t4 | 🫧 Amaciante (1L) --------- R$15,00\n");
                        printf("\t5 | 🧽 Bucha de Pia (3 Unid.) - R$4,99\n");
                        printf("\t6 | 🧴 Desinfetante (1L) ------ R$7,99\n");
                        printf("\t7 | 🧼 Sabão em Barra (Unid.) - R$1,00\n");
                        printf("\t0 | 🔙 Voltar\n");
                        printf("\t▶ Escolha o item desejado: ");
                        scanf("%d", &id);

                        if (id >= 1 && id <= 7) {//se o numero for pressionado conforme o id do produto ele sera selecionado
                            printf("\t▶ Determine a quantidade: ");
                            scanf("%d", &quantidade);
                            if (quantidade > produtoEstoque[id - 1].quantidade) {// ele verifica se a quantidade desejada é maior que a disponivel no estoque
                                printf("\n\t[ Não temos esse produto em estoque! ]\n");
                            } else {
                                total = quantidade * produtoEstoque[id - 1].preco;// faz a quantia vezes o preço do produto que é puxado da struct localizado com o id
                                totalL += total;
                                produtoEstoque[id - 1].quantidade -= quantidade;// localiza na struct e retira o quantidade que foi comprada
                                printf("\t▶ Você adicionou %d unidade(s) do produto %s!\n", quantidade, produtoEstoque[id - 1].nomePd);
                            }
                        } else if (id == 0) {
                            printf("\n\t         ⌛ Voltando ao Menu Principal...\n");
                        } else {
                            printf("\n\t               ❌ Opção inválida!\n");
                        }
                    } while (id != 0);
                    break;

                case 2:
                    do {
                        printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
                        printf("\n\t=================== ALIMENTOS ==================\n");
                        printf("\t🛒 Valor da compra: R$%.2f\n", totalA);
                        printf("\t 8 | ☕ Café (500g) ------------ R$24.99\n");
                        printf("\t 9 | 🍺 Cerveja Kaiser (unid.) - R$5.90\n");
                        printf("\t10 | 🍚 Arroz (1kg) ------------ R$8.00\n");
                        printf("\t11 | 🫘 Feijão Preto (1kg) ----- R$9.00\n");
                        printf("\t12 | 🧂 Açúcar (1kg) ----------- R$5.00\n");
                        printf("\t13 | 🧂 Sal (1kg) -------------- R$2.00\n");
                        printf("\t14 | 🥩 Picanha Bovina (1kg) --- R$80.00\n");
                        printf("\t 0 | 🔙 Voltar\n");
                        printf("\t ▶ Escolha o item desejado: ");
                        scanf("%d", &id);

                        if (id >= 8 && id <= 14) {
                            printf("\t▶ Determine a quantidade: ");
                            scanf("%d", &quantidade);
                            if (quantidade > produtoEstoque[id - 1].quantidade) {
                                printf("\n\t[ Não temos esse produto em estoque! ]\n");
                            } else {
                                total = quantidade * produtoEstoque[id - 1].preco;
                                totalA += total;
                                produtoEstoque[id - 1].quantidade -= quantidade;
                                printf("\t▶ Você adicionou %d unidade(s) do produto %s!\n", quantidade, produtoEstoque[id - 1].nomePd);
                            }
                        } else if (id == 0) {
                            printf("\n\t         ⌛ Voltando ao Menu Principal...\n");
                        } else {
                            printf("\n\t               ❌ Opção inválida!\n");
                        }
                    } while (id != 0);
                    break;

                case 3:
                    do {
                        printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
                        printf("\n\t==================== PADARIA ===================\n");
                        printf("\t🛒 Valor da compra: R$%.2f\n", totalP);
                        printf("\t15 | 🍞 Pão de Forma (pct) ---------- R$9.50\n");
                        printf("\t16 | 🍞 Pão de Forma Integral (pct) - R$12.50\n");
                        printf("\t17 | 🥖 Pão Francês (unid.) ------------ R$1.90\n");
                        printf("\t18 | 🫓 Sonho (unid.) --------------- R$8.50\n");
                        printf("\t19 | 🍪 Biscoito (kg) --------------- R$12.50\n");
                        printf("\t20 | 🥧 Pão Doce (unid.) ------------ R$2.50\n");
                        printf("\t21 | 🥐 Salgado (unid.) ------------- R$17.50\n");
                        printf("\t 0 | 🔙 Voltar\n");
                        printf("\t▶ Escolha o item desejado: ");
                        scanf("%d", &id);

                        if (id >= 15 && id <= 21) {
                            printf("\t▶ Determine a quantidade: ");
                            scanf("%d", &quantidade);
                            if (quantidade > produtoEstoque[id - 1].quantidade) {
                                printf("\n\t[ Não temos esse produto em estoque! ]\n");
                            } else {
                                total = quantidade * produtoEstoque[id - 1].preco;
                                totalP += total;
                                produtoEstoque[id - 1].quantidade -= quantidade;
                                printf("\t▶ Você adicionou %d unidade(s) do produto %s!\n", quantidade, produtoEstoque[id - 1].nomePd);
                            }
                        } else if (id == 0) {
                            printf("\n\t         ⌛ Voltando ao Menu Principal...\n");
                        } else {
                            printf("\n\t               ❌ Opção inválida!\n");
                        }
                    } while (id != 0);
                    break;

                case 4: {
                        char opcao;
                        float troco, vr;
                        int pagamento;
                    
                        subtotal = totalL + totalA + totalP;
                        printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
                        printf("\n\t=================== PAGAMENTO ==================\n");
                        printf("\n\tTotal dos Materiais de limpeza: R$%.2f\n", totalL);
                        printf("\tTotal da Venda de Alimentos: R$%.2f\n", totalA);
                        printf("\tTotal da Padaria: R$%.2f\n", totalP);
                        printf("\tTotal da sua compra: R$%.2f\n", subtotal);
                    
                        printf("\n\t1 | 💵 Dinheiro (com desconto)\n");
                        printf("\t2 | 💳 Cartão\n");
                        printf("\t▶ Escolha a opção de pagamento: ");
                        scanf("%d", &pagamento);
                    
                        if (pagamento == 1) {
                            float desconto = calcularDesconto(subtotal);
                            subtotal -= desconto;
                    
                            printf("\n\tSubtotal com desconto: R$%.2f\n", subtotal);
                            printf("\n\t▶ O cliente pagou quanto em dinheiro?: ");
                            scanf("%f", &vr);
                    
                            if (vr >= subtotal) {
                                troco = vr - subtotal;
                    
                                if (troco <= totali) {
                                    printf("\tTroco a ser devolvido: R$%.2f\n", troco);
                                    totali -= troco;
                                    totalf += subtotal;
                                    totalL = totalA = totalP = subtotal = 0;
                                    printf("\n\t✅ Pagamento finalizado!\n");
                                    
                                } else {
                                    printf("\n\t❌ O caixa não possui troco suficiente!\n");
                                }
                            } else {
                                printf("\n\t❌ Valor entregue menor que o valor da compra!\n");
                            }
                    
                        } else if (pagamento == 2) {
                            printf("\t▶ Pagamento com cartão no valor de: R$%.2f\n", subtotal);
                            totalf += subtotal;
                            totalL = totalA = totalP = subtotal = 0;
                            printf("\n\t▶ Pagamento finalizado!\n");
                        } else {
                            printf("\n\t               ❌ Opção inválida!\n");
                        }
                        break;
                    }

                case 5:
                do{
                        printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
                        printf("\n\t==================== ESTOQUE ===================\n");
                        printf("\t📦 Estoque Atual:\n");
                        for (int i = 0; i < 21; i++) {
                        printf("\tID %d | %s - Qtd: %d\n", produtoEstoque[i].id, produtoEstoque[i].nomePd, produtoEstoque[i].quantidade);//for feito para printar todo o estoque
                    }
                        printf("\n\t▶ Digite o ID do item ou digite 0 para voltar: ");
                        scanf("\t %d", &id);

                    if(id >= 1 && id <= 21){
                            int idProduto, qtdProduto;// variaveis setadas apenas aq dentro onde sao usadas

                            printf("\t▶ Coloque a quantidade de produtos adicionados: ");
                            scanf("%d", &qtdProduto);

                             produtoEstoque[id - 1].quantidade += qtdProduto;// Após colocar o id do produto será localizado e colocar a quantidade em qtdProduto sera adicionada ao quantidade dentro da struct
                    }
                    else if(id == 0){
                        printf("\n\t         ⌛ Voltando ao Menu Principal...\n");
                    }

                }while(id != 0);
                    break;

                case 6:
                int idcaixa;
                    printf("\t━━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
                     printf("\n\t==================== CAIXA =====================\n");
                    printf("\t1 | 🔺 Abertura de caixa\n");
                    printf("\t2 | 🔻 Fechamento de caixa\n");
                    printf("\t0 | 🔙 Voltar ao menu principal\n");
                    printf("\t▶ Escolha a opção desejada: ");
                    scanf("%d", &idcaixa);

                        if(idcaixa == 1){
                            printf("\t📢 Lembre-se de verificar e repor o estoque da Padaria!\n");
                            printf("\t▶ Digite o valor para abrir o caixa: ");
                            scanf("%f", &totali);
                            totalf = totalf + totali;// totali é o Dinheiro inicial do caixa que sera colocado com sendo atribuído a ao totalf que é quanto Dinheiro foi feito no dia.
                        }

                        else if(idcaixa == 2){
                            printf("\n\tFechamento de caixa: Total Bruto R$%.2f Lucro: R$%.2f\n", totalf, (totalf-totali));
                        }
                        else if(idcaixa == 0){
                            printf("\n\t         ⌛ Voltando ao Menu Principal...");
                        }
                    break;

                case 7:
                    printf("\n\t            🔚 Saindo do sistema...\n");
                    break;

                default:
                    printf("\n\t               ❌ Opção inválida!\n");
            }

        } while (menu != 7);
    }

    return 0;
}