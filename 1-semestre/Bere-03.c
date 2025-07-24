#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_PADRAO 100
#define MAX_CARRINHO 100



#define MAX_NOME 50
#define MAX_PRODUTO 100
#define NOME_ARQUIVO_ESTOQUE "estoque.txt"


typedef struct {
    char codigo[TAMANHO_PADRAO];
    char nomeCompleto[TAMANHO_PADRAO];
    char nomeSocial[TAMANHO_PADRAO];
    char cpf[TAMANHO_PADRAO];
    char ruaNumero[TAMANHO_PADRAO];
    char bairro[TAMANHO_PADRAO];
    char celularWhats[TAMANHO_PADRAO];
} Cliente;

struct produtoES {
    int id;
    char nomePd[MAX_NOME];
    int quantidade;
    char tipoProd; // Armazena apenas um caractere para o tipo do produto
    float preco;
};

struct ItemCarrinho {
    int idProduto;
    char nome[MAX_NOME];
    int quantidade;
    float precoUnitario;
    float subtotal;
};

// Protótipos das funções
void salvarProdutos(struct produtoES estoque[], int numProdutos);

int carregarProdutos(struct produtoES estoque[]);

void CadastrarItens(struct produtoES estoque[], int *numProdutos);

void excluirProduto(struct produtoES estoque[], int *numProdutos);

void listarProdutos(struct produtoES estoque[], int numProdutos);

void realizarVenda(struct produtoES estoque[], int *numProdutos);

void cadastrarCliente();

void realizarPagamento(float *subtotal, float *totali, float *totalf);





int main() {

    struct produtoES estoque[MAX_PRODUTO];
    int numProdutosCadastrados = carregarProdutos(estoque); // Carrega os produtos do arquivo
    float subtotal = 0, totalf = 0, desconto = 0;

    int menu;
    do {
        printf("\n\t=============== BERE ===============\n");
        printf("\t1 | Cadastro\n");
        printf("\t2 | Venda\n");
        printf("\t3 | Abertura de caixa\n");
        printf("\t4 | Fechamento de caixa\n");
        printf("\t5 | Relatorio\n");
        printf("\t0 | Sair\n");
        printf("\t Escolha a opcao: ");
        scanf("%d", &menu);
        while (getchar() != '\n');

        switch (menu) {
            case 1: {
                int menuCadastro;
                do {
                    printf("\n\t=============== Cadastros ===============\n");
                    printf("\t1 | Cadastro de clientes\n");
                    printf("\t2 | Cadastro de produtos\n");
                    printf("\t0 | Voltar ao menu anterior\n");
                    printf("\t Escolha a opcao: ");
                    scanf("%d", &menuCadastro);
                    while (getchar() != '\n');

                    switch (menuCadastro) {
                        case 1:
                            char opcao;

                            do {
                                printf("\n\t============== Cadastro de Cliente ===============\n");
                                printf("\t1 | Cadastrar novo cliente\n");
                                printf("\t0 | Sair\n");
                                printf("\tEscolha uma opcao: ");
                                scanf(" %c", &opcao);

                                while (getchar() != '\n');

                                switch (opcao) {
                                    case '1':
                                        cadastrarCliente();
                                        break;
                                    case '0':
                                        printf("Voltando ao menu de Cadastros...\n");
                                        break;
                                    default:
                                        printf("Opcao invalida. Tente novamente.\n");
                                }
                            } while (opcao != '0');
                            break;
                        case 2: {
                            int menuCadastroPD;
                            do {
                                printf("\n\t=============== Cadastros de produtos ===============\n");
                                printf("\t1 | Cadastrar produto\n");
                                printf("\t2 | Listar Produtos\n");
                                printf("\t3 | Excluir produto\n");
                                printf("\t0 | Voltar ao menu anterior\n");
                                printf("\t Escolha a opcao: ");
                                scanf("%d", &menuCadastroPD);
                                while (getchar() != '\n');
                                switch (menuCadastroPD) {
                                    case 1:
                                        CadastrarItens(estoque, &numProdutosCadastrados);
                                        break;
                                    case 2:
                                        listarProdutos(estoque, numProdutosCadastrados);
                                        break;
                                    case 3:
                                        excluirProduto(estoque, &numProdutosCadastrados);
                                        break;
                                    case 0:
                                        printf("\n\tVoltando ao menu de Cadastros...\n");
                                        break;
                                    default:
                                        printf("\n\tOpcao invalida!\n");
                                }
                            } while (menuCadastroPD != 0);
                            break;
                        }
                        case 0:
                            printf("\n\tVoltando ao menu anterior...\n");
                            break;
                        default:
                            printf("\n\tOpcao invalida!\n");
                    }
                } while (menuCadastro != 0);
                break;
            }
            case 2:
                int opcao;
                printf("\n\t=============== Venda ===============\n");
                printf("\t1 | Nova venda\n");
                printf("\t2 | Retirada de caixa\n");
                printf("\t3 | Pagamento\n");
                printf("\t0 | Voltar ao menu anterior\n");
                printf("\t Escolha a opcao: ");
                scanf("%d", &opcao);
                while (getchar() != '\n');

                switch (opcao) {
                    case 1:
                        realizarVenda(estoque, &numProdutosCadastrados);
                        break;
                    case 2:

                        break;
                    case 3:
                        break;
                    case 0:
                        printf("\n\tVoltando ao menu anterior...\n");
                        break;
                }

                break;
            case 3:
                printf("\n\t[Funcionalidade de abertura de caixa]\n");
                // Aqui você chamaria as funções relacionadas à abertura de caixa
                break;
            case 4:
                printf("\n\t[Funcionalidade de fechamento de caixa]\n");
                // Aqui você chamaria as funções relacionadas ao fechamento de caixa
                break;
            case 5:
                printf("\n\t[Funcionalidade de relatório]\n");
                // Aqui você chamaria as funções relacionadas a relatórios
                break;
            case 0:
                printf("\n\tSaindo do sistema...\n");
                break;
            default:
                printf("\n\tOpcao invalida!\n");
        }
    } while (menu != 0);

    return 0;
}

void listarProdutos(struct produtoES estoque[], int numProdutos) {
    if (numProdutos > 0) {
        printf("\t========= LISTA DE PRODUTOS =========\n");
        for (int i = 0; i < numProdutos; i++) {
            printf("\tID: %d | Nome: %-30s | Tipo: %c | Qtd: %d | Preço: R$%.2f\n",
                   estoque[i].id, estoque[i].nomePd, estoque[i].tipoProd, estoque[i].quantidade, estoque[i].preco);
        }
        printf("\t=======================================\n");
    } else {
        printf("\t[ Nenhum produto cadastrado ainda. ]\n");
    }
}

void excluirProduto(struct produtoES estoque[], int *numProdutos) {
    int idExcluir;
    listarProdutos(estoque, *numProdutos); // Primeiro, listamos os produtos para o usuário ver os IDs

    if (*numProdutos == 0) {
        printf("\t[ Nao ha produtos cadastrados para excluir. ]\n");
        return;
    }

    printf("\n\tDigite o ID do produto que deseja excluir (ou 0 para voltar): ");
    scanf("%d", &idExcluir);
    while (getchar() != '\n');

    if (idExcluir == 0) {
        printf("\t[ Voltando ao menu de cadastros. ]\n");
        return;
    }

    int indiceExcluir = -1;
    for (int i = 0; i < *numProdutos; i++) {
        if (estoque[i].id == idExcluir) {
            indiceExcluir = i;
            break;
        }
    }

    if (indiceExcluir != -1) {
        // Desloca os elementos subsequentes para preencher o espaço do produto excluído
        for (int i = indiceExcluir; i < *numProdutos - 1; i++) {
            estoque[i] = estoque[i + 1];
            estoque[i].id = i + 1; // Reajusta os IDs
        }
        (*numProdutos)--; // Decrementa o número de produtos
        salvarProdutos(estoque, *numProdutos); // Salva a lista atualizada no arquivo
        printf("\t[ Produto com ID %d excluído com sucesso! ]\n", idExcluir);
    } else {
        printf("\t[ ID de produto inválido. ]\n");
    }
}

void salvarProdutos(struct produtoES estoque[], int numProdutos) {
    FILE *arquivo = fopen(NOME_ARQUIVO_ESTOQUE, "w"); // Abre o arquivo para escrita (sobrescreve)
    if (arquivo == NULL) {
        perror("\tErro ao abrir o arquivo de estoque para salvar!");
        return;
    }

    for (int i = 0; i < numProdutos; i++) {
        fprintf(arquivo, "%d;%s;%d;%c;%.2f\n", // Usar %c para escrever um char
                estoque[i].id,
                estoque[i].nomePd,
                estoque[i].quantidade,
                estoque[i].tipoProd,
                estoque[i].preco);
    }

    fclose(arquivo);
    printf("\t[ Estoque atualizado e salvo no arquivo '%s'! ]\n", NOME_ARQUIVO_ESTOQUE);
}

int carregarProdutos(struct produtoES estoque[]) {
    FILE *arquivo = fopen(NOME_ARQUIVO_ESTOQUE, "r");
    if (arquivo == NULL) {
        printf("\t[ Aviso: Arquivo de estoque nao encontrado. Um novo sera criado. ]\n");
        return 0; // Retorna 0 produtos carregados
    }

    int numProdutos = 0;
    while (fscanf(arquivo, "%d;%49[^;];%d;%c;%f\n", // Usar %c para ler um char
                  &estoque[numProdutos].id,
                  estoque[numProdutos].nomePd,
                  &estoque[numProdutos].quantidade,
                  &estoque[numProdutos].tipoProd,
                  &estoque[numProdutos].preco) == 5 && numProdutos < MAX_PRODUTO) {
        numProdutos++;
    }

    fclose(arquivo);
    return numProdutos;
}

void CadastrarItens(struct produtoES estoque[], int *numProdutos) {
    int opc;
    do {
        if (*numProdutos < MAX_PRODUTO) {
            printf(
                "\n\t======== CADASTRAR NOVO PRODUTO ========\n\tAtencao o tipo de produto deve ser A=alimento L=limpeza P=padaria");
            estoque[*numProdutos].id = *numProdutos + 1; // Atribui um ID automático

            printf("\n\tNome do Produto: ");
            fgets(estoque[*numProdutos].nomePd, MAX_NOME, stdin);
            estoque[*numProdutos].nomePd[strcspn(estoque[*numProdutos].nomePd, "\n")] = '\0';

            printf("\tTipo do Produto: ");
            scanf(" %c", &estoque[*numProdutos].tipoProd); // Usar %c para ler um char (atenção ao espaço antes de %c)
            while (getchar() != '\n');
            printf("\tValor do Produto: ");
            scanf("%f", &estoque[*numProdutos].preco);
            while (getchar() != '\n');

            printf("\tQuantidade em Estoque: ");
            scanf("%d", &estoque[*numProdutos].quantidade);
            while (getchar() != '\n');

            (*numProdutos)++; // Incrementa o contador de produtos cadastrados
            printf("\t\nProduto cadastrado com sucesso!\n");
        } else {
            printf("\t\nLimite máximo de produtos atingido!\n");
            break; // Sai do loop se o limite for atingido
        }

        printf("\t\n1 - Continuar Cadastrando | 0 - Sair\n");
        printf("\tOpca+o: ");
        scanf("%d", &opc);
        while (getchar() != '\n');
    } while (opc != 0);

    // Salvar os produtos após o cadastro ser finalizado
    salvarProdutos(estoque, *numProdutos);
}

void cadastrarCliente() {
    Cliente novoCliente;
    FILE *arquivo;

    printf("\t Digite o codigo do cliente: ");
    scanf(" %[^\n]", novoCliente.codigo);

    printf("\t Digite o nome completo: ");
    scanf(" %[^\n]", novoCliente.nomeCompleto);;

    printf("\t Digite o nome social (opcional, deixe em branco se não houver): ");
    scanf(" %[^\n]", novoCliente.nomeSocial);

    printf("\t Digite o CPF: ");
    scanf(" %[^\n]", novoCliente.cpf);

    printf("\t Digite a rua e número: ");
    scanf(" %[^\n]", novoCliente.ruaNumero);

    printf("\t Digite o bairro: ");
    scanf(" %[^\n]", novoCliente.bairro);

    printf("\t Digite o celular/WhatsApp: ");
    scanf(" %[^\n]", novoCliente.celularWhats);


    arquivo = fopen("ListaDeClientes.txt", "a");

    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo %s para o cliente %s.\n", "ListaDeClientes.txt", novoCliente.codigo);
        return;
    }

    fprintf(arquivo, "Código: %s\n", novoCliente.codigo);
    fprintf(arquivo, "Nome Completo: %s\n", novoCliente.nomeCompleto);
    fprintf(arquivo, "Nome Social: %s\n", novoCliente.nomeSocial);
    fprintf(arquivo, "CPF: %s\n", novoCliente.cpf);
    fprintf(arquivo, "Endereço: %s\n", novoCliente.ruaNumero);
    fprintf(arquivo, "Bairro: %s\n", novoCliente.bairro);
    fprintf(arquivo, "Celular/Whats: %s\n\n", novoCliente.celularWhats);
    // Adicionando uma linha em branco para separar os clientes

    fclose(arquivo);

    printf("Cliente %s cadastrado com sucesso no arquivo %s!\n", novoCliente.codigo, "ListaDeClientes.txt");
}

void realizarVenda(struct produtoES estoque[], int *numProdutos) {
    struct ItemCarrinho carrinho[MAX_CARRINHO];
    int totalItensCarrinho = 0;
    int idProduto, quantidadeDesejada;
    char continuar;

    do {
        listarProdutos(estoque, *numProdutos);

        printf("\n\tDigite o ID do produto que deseja comprar: ");
        scanf("%d", &idProduto);

        int encontrado = 0;
        for (int i = 0; i < *numProdutos; i++) {
            if (estoque[i].id == idProduto) {
                encontrado = 1;

                printf("\tQuantidade desejada: ");
                scanf("%d", &quantidadeDesejada);

                if (quantidadeDesejada <= estoque[i].quantidade) {
                    // Adiciona ao carrinho
                    carrinho[totalItensCarrinho].idProduto = estoque[i].id;
                    strcpy(carrinho[totalItensCarrinho].nome, estoque[i].nomePd);
                    carrinho[totalItensCarrinho].quantidade = quantidadeDesejada;
                    carrinho[totalItensCarrinho].precoUnitario = estoque[i].preco;
                    carrinho[totalItensCarrinho].subtotal = quantidadeDesejada * estoque[i].preco;

                    totalItensCarrinho++;

                    // Atualiza estoque
                    estoque[i].quantidade -= quantidadeDesejada;
                    printf("\tProduto '%s' adicionado ao carrinho.\n", estoque[i].nomePd);

                } else {
                    printf("\tEstoque insuficiente! Temos apenas %d unidades.\n", estoque[i].quantidade);
                }

                break;
            }
        }

        if (!encontrado) {
            printf("\tProduto com ID %d não encontrado.\n", idProduto);
        }

        printf("\n\tDeseja adicionar outro produto? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    // Exibir resumo do carrinho
    float totalCompra = 0.0;
    printf("\n\t=========== RESUMO DO CARRINHO ===========\n");
    for (int i = 0; i < totalItensCarrinho; i++) {
        printf("\t%d x %s - R$%.2f cada | Subtotal: R$%.2f\n",
               carrinho[i].quantidade,
               carrinho[i].nome,
               carrinho[i].precoUnitario,
               carrinho[i].subtotal);

        totalCompra += carrinho[i].subtotal;
    }
    printf("\tTOTAL A PAGAR: R$%.2f\n", totalCompra);
    printf("\t==========================================\n");

    salvarProdutos(estoque, *numProdutos);


}

float calcularDesconto(float subtotal) {
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

void realizarPagamento(float *subtotal, float *totali, float *totalf) {
    float troco, valorRecebido;
    int pagamento;

    printf("\n=================== PAGAMENTO ==================\n");
    printf("Total da compra: R$%.2f\n", *subtotal);

    printf("\n1 | Dinheiro (com desconto)\n");
    printf("2 | Cartao\n");
    printf("Escolha a opcao de pagamento: ");
    scanf("%d", &pagamento);

    if (pagamento == 1) {
        float desconto = calcularDesconto(*subtotal);
        *subtotal -= desconto;

        printf("\nSubtotal com desconto: R$%.2f\n", *subtotal);
        printf("Valor recebido em dinheiro: ");
        scanf("%f", &valorRecebido);

        if (valorRecebido >= *subtotal) {
            troco = valorRecebido - *subtotal;

            if (troco <= *totali) {
                printf("Troco a ser devolvido: R$%.2f\n", troco);
                *totali -= troco;
                *totalf += *subtotal;
                *subtotal = 0;
                printf("Pagamento finalizado com sucesso.\n");

            } else {
                printf("Erro: Caixa nao possui troco suficiente.\n");
            }
        } else {
            printf("Erro: Valor recebido menor que o valor da compra.\n");
        }

    } else if (pagamento == 2) {
        printf("Pagamento com cartao no valor de: R$%.2f\n", *subtotal);
        *totalf += *subtotal;
        *subtotal = 0;
        printf("Pagamento finalizado com sucesso.\n");
    } else {
        printf("Opcao invalida.\n");
    }
}



