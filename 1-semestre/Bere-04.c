#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO_PADRAO 100
#define MAX_CARRINHO 100
#define MAX_NOME 50
#define MAX_PRODUTO 100
#define NOME_ARQUIVO_ESTOQUE "estoque.txt"
#define NOME_ARQUIVO_CLIENTES "ListaDeClientes.txt"
#define NOME_ARQUIVO_USUARIOS "usuarios.txt"
#define NOME_ARQUIVO_VENDAS "vendas.txt"
#define NOME_ARQUIVO_PAGAMENTO "pagamento.txt"
#define MAX_USUARIOS 20
#define MAX_LOGIN 13
#define MAX_SENHA 9

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
    char tipoTipo[MAX_NOME];
    float preco;
};

struct ItemCarrinho {
    int idProduto;
    char nome[MAX_NOME];
    int quantidade;
    float precoUnitario;
    float subtotal;
};

typedef enum {
    USUARIO_NORMAL = 2,
    ADMINISTRADOR = 1
} TipoUsuario;

typedef struct {
    char login[MAX_LOGIN];
    char senha[MAX_SENHA];
    TipoUsuario tipo;
} Usuario;

// Protótipos das funções
void visualizarClientes();
void cadastrarCliente();
void realizarFechamento(int *vd, float *totalf, float *totali, float *totalD, float *totalC);
void realizarAberturacaixa(float *subtotal, float *totali, float *totalf);
void realizarPagamento(float *subtotal, float *totalf, float *totalD, float *totalC, float *totali);
float calcularDesconto(float subtotal);
void salvarProdutos(struct produtoES estoque[], int numProdutos);
int carregarProdutos(struct produtoES estoque[]);
void CadastrarItens(struct produtoES estoque[], int *numProdutos);
void excluirProduto(struct produtoES estoque[], int *numProdutos);
void listarProdutos(struct produtoES estoque[], int numProdutos);
void realizarVenda(struct produtoES estoque[], int *numProdutos, int *vd, float *subtotal, float *totalf);
int validarLogin(const char *login);
int validarSenha(const char *senha);
void cadastrarUsuario(Usuario usuarios[], int *numUsuarios);
TipoUsuario verificarUsuario(const char *login, const char *senha, Usuario usuarios[], int numUsuarios);
void controleAcesso(struct produtoES estoque[], int *numProdutosCadastrados, Usuario usuarios[], int *numUsuariosCadastrados, float *subtotal, float *totalf, float *totalD, float *totalC, float *totali, int *vd);
int carregarUsuarios(Usuario usuarios[]);
void salvarUsuarios(Usuario usuarios[], int numUsuarios);
void gerenciarCadastros(struct produtoES estoque[], int *numProdutosCadastrados, Usuario usuarios[], int *numUsuariosCadastrados);
void gerenciarVendas(struct produtoES estoque[], int *numProdutosCadastrados, int *vd, float *subtotal, float *totalf, float *totalD, float *totalC, float *totali);
void ordem_alfabetica(struct produtoES estoque[], int numProdutos);
void ordenarPorTipo(struct produtoES estoque[], int numProdutos);
void ordenarPorQuantidade(struct produtoES estoque[], int numProdutos);


int main() {
    struct produtoES estoque[MAX_PRODUTO];
    int numProdutosCadastrados = carregarProdutos(estoque);
    Usuario usuarios[MAX_USUARIOS];
    int numUsuariosCadastrados = carregarUsuarios(usuarios);
    float subtotal = 0, totali = 0, totalf = 0, totalD = 0, totalC = 0;
    int menu, vd = 0;



    if (numUsuariosCadastrados == 0) {
        printf("\n\tVoce deve cadastrar primeiro 1 usuarios para comeaar");
        cadastrarUsuario(usuarios, &numUsuariosCadastrados);
    }

    do {
        printf("\n\t============ MERCADAO DO FABIAO ============\n");
        printf("\t1 | Cadastro\n");
        printf("\t2 | Venda\n");
        printf("\t3 | Abertura de caixa\n");
        printf("\t4 | Fechamento de caixa\n");
        printf("\t0 | Sair\n");
        printf("\t Escolha a opcao: ");
        scanf("%d", &menu);
        while (getchar() != '\n');

        switch (menu) {
            case 1:
                gerenciarCadastros(estoque, &numProdutosCadastrados, usuarios, &numUsuariosCadastrados);
                break;
            case 2:
                gerenciarVendas(estoque, &numProdutosCadastrados, &vd, &subtotal, &totalf, &totalD, &totalC, &totali);
                break;
            case 3:
            {
                char loginInputAbertura[MAX_LOGIN];
                char senhaInputAbertura[MAX_SENHA];
                TipoUsuario tipoUsuarioLogadoAbertura;

                printf("\n\t[ Para abrir o caixa, e necessario login ]\n");
                printf("\tDigite seu login: ");
                scanf("%s", loginInputAbertura);
                while (getchar() != '\n');

                printf("\tDigite sua senha: ");
                scanf("%s", senhaInputAbertura);
                while (getchar() != '\n');

                tipoUsuarioLogadoAbertura = verificarUsuario(loginInputAbertura, senhaInputAbertura, usuarios, numUsuariosCadastrados);

                if (tipoUsuarioLogadoAbertura == ADMINISTRADOR) {
                    realizarAberturacaixa(&subtotal, &totali, &totalf);
                } else {
                    printf("\t[ Acesso negado! Credenciais invalidas. ]\n");
                }
                break;
            }
            case 4:
            {
                char loginInputFechamento[MAX_LOGIN];
                char senhaInputFechamento[MAX_SENHA];
                TipoUsuario tipoUsuarioLogadoFechamento;

                printf("\n\t[ Para fechar o caixa, e necessario login de Administrador ]\n");
                printf("\tDigite seu login: ");
                scanf("%s", loginInputFechamento);
                while (getchar() != '\n');

                printf("\tDigite sua senha: ");
                scanf("%s", senhaInputFechamento);
                while (getchar() != '\n');

                tipoUsuarioLogadoFechamento = verificarUsuario(loginInputFechamento, senhaInputFechamento, usuarios, numUsuariosCadastrados);

                if (tipoUsuarioLogadoFechamento == ADMINISTRADOR) {
                    realizarFechamento(&vd, &totalf, &totali, &totalD, &totalC);
                } else {
                    printf("\t[ Acesso negado! Credenciais invalidas ou usuario nao eh um administrador. ]\n");
                }
                break;
            }
            case 0:
                printf("\n\tSaindo do sistema...\n");
                break;
            default:
                printf("\n\tOpcao invalida!\n");
        }
    } while (menu != 0);

    return 0;
}

void ordenarPorQuantidade(struct produtoES estoque[], int numProdutos) {
    int i, j;
    struct produtoES temp;

    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - 1 - i; j++) {
            if (estoque[j].quantidade > estoque[j + 1].quantidade) {
                temp = estoque[j];
                estoque[j] = estoque[j + 1];
                estoque[j + 1] = temp;
            }
        }
    }
    printf("\t[ Produtos ordenados por quantidade em estoque (Crescente). ]\n"); //
}

void ordenarPorTipo(struct produtoES estoque[], int numProdutos) {
    int i, j;
    struct produtoES temp;

    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - 1 - i; j++) {
            if (strcmp(estoque[j].tipoTipo, estoque[j + 1].tipoTipo) > 0) {
                temp = estoque[j];
                estoque[j] = estoque[j + 1];
                estoque[j + 1] = temp;
            }
        }
    }
    printf("\t[ Produtos ordenados por categoria (Tipo de Produto). ]\n");
}

void ordem_alfabetica(struct produtoES estoque[], int numProdutos) {
    int i, j;
    struct produtoES temp;


    for (i = 0; i < numProdutos - 1; i++) {
        for (j = 0; j < numProdutos - 1 - i; j++) {
            if (strcmp(estoque[j].nomePd, estoque[j + 1].nomePd) > 0) {
                temp = estoque[j];
                estoque[j] = estoque[j + 1];
                estoque[j + 1] = temp;
            }
        }
    }
    printf("\t[ Produtos ordenados por nome (A-Z). ]\n");
}

void listarProdutos(struct produtoES estoque[], int numProdutos) {
    int op;
    if (numProdutos == 0) {
        printf("\t[ Nenhum produto cadastrado ainda. ]\n");
        return;
    }

    printf("\n\tVoce deseja que a lista seja mostrada em qual ordem?\n");
    printf("\t1 - Ordem alfabetica de produtos (A-Z)\n");
    printf("\t2 - Ordem por categoria (Tipo de Produto)\n");
    printf("\t3 - Ordem de quantidade em estoque (Crescente)\n");
    printf("\t4 - Ordem normal (Cadastro)\n");
    printf("\tOpcao: ");
    scanf("%d", &op);
    while (getchar() != '\n');

    // Cria uma copia do estoque para ordenar
    struct produtoES estoqueCopia[MAX_PRODUTO];
    for(int i = 0; i < numProdutos; i++) {
        estoqueCopia[i] = estoque[i];
    }

    switch (op) {
        case 1:
            ordem_alfabetica(estoqueCopia, numProdutos);
            break;

        case 2:
            ordenarPorTipo(estoqueCopia, numProdutos);
            break;

        case 3:
            ordenarPorQuantidade(estoqueCopia, numProdutos);
            break;

        case 4:
            break;

        default:
            printf("\t[ Opcao invalida de ordenacao. Mostrando em ordem normal. ]\n");
            break;
    }

    printf("\t========= LISTA DE PRODUTOS =========\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("\tID: %d | Nome: %-30s | Tipo: %-15s | Qtd: %d | Preco: R$%.2f\n",
               estoqueCopia[i].id, estoqueCopia[i].nomePd, estoqueCopia[i].tipoTipo, estoqueCopia[i].quantidade, estoqueCopia[i].preco);
    }
    printf("\t=======================================\n");
}

void excluirProduto(struct produtoES estoque[], int *numProdutos) {
    int idExcluir;
    listarProdutos(estoque, *numProdutos);

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
        for (int i = indiceExcluir; i < *numProdutos - 1; i++) {
            estoque[i] = estoque[i + 1];
            estoque[i].id = i + 1;
        }
        (*numProdutos)--;
        salvarProdutos(estoque, *numProdutos);
        printf("\t[ Produto com ID %d excluido com sucesso! ]\n", idExcluir);
    } else {
        printf("\t[ ID de produto invalido. ]\n");
    }
}

void salvarProdutos(struct produtoES estoque[], int numProdutos) {
    FILE *arquivo = fopen(NOME_ARQUIVO_ESTOQUE, "w");
    if (arquivo == NULL) {
        perror("\tErro ao abrir o arquivo de estoque para salvar!");
        return;
    }

    for (int i = 0; i < numProdutos; i++) {
        fprintf(arquivo, "%d;%s;%d;%s;%.2f\n",
                estoque[i].id,
                estoque[i].nomePd,
                estoque[i].quantidade,
                estoque[i].tipoTipo,
                estoque[i].preco);
    }

    fclose(arquivo);
    printf("\t[ Estoque atualizado e salvo no arquivo '%s'! ]\n", NOME_ARQUIVO_ESTOQUE);
}

int carregarProdutos(struct produtoES estoque[]) {
    FILE *arquivo = fopen(NOME_ARQUIVO_ESTOQUE, "r");
    if (arquivo == NULL) {
        printf("\t[ Aviso: Arquivo de estoque nao encontrado. Um novo sera criado. ]\n");
        return 0;
    }

    int numProdutos = 0;
    while (fscanf(arquivo, "%d;%49[^;];%d;%49[^;];%f\n",
                  &estoque[numProdutos].id,
                  estoque[numProdutos].nomePd,
                  &estoque[numProdutos].quantidade,
                  estoque[numProdutos].tipoTipo,
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
            printf("\n\t======== CADASTRAR NOVO PRODUTO ========\n\t");
            estoque[*numProdutos].id = *numProdutos + 1;

            printf("\n\tNome do Produto: ");
            fgets(estoque[*numProdutos].nomePd, MAX_NOME, stdin);
            estoque[*numProdutos].nomePd[strcspn(estoque[*numProdutos].nomePd, "\n")] = '\0';

            printf("\tTipo do Produto: ");
            fgets(estoque[*numProdutos].tipoTipo, MAX_NOME, stdin);
            estoque[*numProdutos].tipoTipo[strcspn(estoque[*numProdutos].tipoTipo, "\n")] = '\0';

            printf("\tValor do Produto: ");
            scanf("%f", &estoque[*numProdutos].preco);
            while (getchar() != '\n');

            printf("\tQuantidade em Estoque: ");
            scanf("%d", &estoque[*numProdutos].quantidade);
            while (getchar() != '\n');

            (*numProdutos)++;
            printf("\t\nProduto cadastrado com sucesso!\n");
        } else {
            printf("\t\nLimite maximo de produtos atingido!\n");
            break;
        }

        printf("\t\n1 - Continuar Cadastrando | 0 - Sair\n");
        printf("\tOpcao: ");
        scanf("%d", &opc);
        while (getchar() != '\n');
    } while (opc != 0);

    salvarProdutos(estoque, *numProdutos);
}

void cadastrarCliente() {
    Cliente novoCliente;
    FILE *arquivo;

    printf("\t Digite o codigo do cliente: ");
    scanf(" %[^\n]", novoCliente.codigo);

    printf("\t Digite o nome completo: ");
    scanf(" %[^\n]", novoCliente.nomeCompleto);

    printf("\t Digite o nome social: ");
    scanf(" %[^\n]", novoCliente.nomeSocial);

    printf("\t Digite o CPF: ");
    scanf(" %[^\n]", novoCliente.cpf);

    printf("\t Digite a rua e numero: ");
    scanf(" %[^\n]", novoCliente.ruaNumero);

    printf("\t Digite o bairro: ");
    scanf(" %[^\n]", novoCliente.bairro);

    printf("\t Digite o celular/WhatsApp: ");
    scanf(" %[^\n]", novoCliente.celularWhats);
    while (getchar() != '\n');

    arquivo = fopen(NOME_ARQUIVO_CLIENTES, "a");

    if (arquivo == NULL) {
        printf(" Erro ao abrir o arquivo %s para o cliente %s.\n", NOME_ARQUIVO_CLIENTES, novoCliente.codigo);
        return;
    }

    fprintf(arquivo, "Codigo: %s\n", novoCliente.codigo);
    fprintf(arquivo, "Nome Completo: %s\n", novoCliente.nomeCompleto);
    fprintf(arquivo, "Nome Social: %s\n", novoCliente.nomeSocial);
    fprintf(arquivo, "CPF: %s\n", novoCliente.cpf);
    fprintf(arquivo, "Endereco: %s\n", novoCliente.ruaNumero);
    fprintf(arquivo, "Bairro: %s\n", novoCliente.bairro);
    fprintf(arquivo, "Celular/Whats: %s\n\n", novoCliente.celularWhats);

    fclose(arquivo);

    printf("Cliente %s cadastrado com sucesso no arquivo %s!\n", novoCliente.codigo, NOME_ARQUIVO_CLIENTES);
}

void visualizarClientes() {
    FILE *arquivo;
    char linha[200];

    arquivo = fopen(NOME_ARQUIVO_CLIENTES, "r");

    if (arquivo == NULL) {
        printf("\tErro ao abrir o arquivo %s para leitura. Pode nao haver clientes cadastrados.\n", NOME_ARQUIVO_CLIENTES);
        return;
    }

    printf("\n\t=========== LISTA DE CLIENTES ===========\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("\t%s", linha);
    }

    printf("\t=========================================\n");

    fclose(arquivo);
}

void realizarVenda(struct produtoES estoque[], int *numProdutos, int *vd, float *subtotal, float *totalf) {
    struct ItemCarrinho carrinho[MAX_CARRINHO];
    int totalItensCarrinho = 0;
    int idProduto, quantidadeDesejada;
    char continuar;

    *subtotal = 0;

    do {
        listarProdutos(estoque, *numProdutos);

        printf("\n\tDigite o ID do produto que deseja comprar (ou 0 para finalizar a venda): ");
        scanf("%d", &idProduto);
        while (getchar() != '\n');

        if (idProduto == 0) {
            break;
        }

        int encontrado = 0;
        for (int i = 0; i < *numProdutos; i++) {
            if (estoque[i].id == idProduto) {
                encontrado = 1;

                printf("\tQuantidade desejada: ");
                scanf("%d", &quantidadeDesejada);
                while (getchar() != '\n');

                if (quantidadeDesejada <= estoque[i].quantidade) {

                    carrinho[totalItensCarrinho].idProduto = estoque[i].id;
                    strcpy(carrinho[totalItensCarrinho].nome, estoque[i].nomePd);
                    carrinho[totalItensCarrinho].quantidade = quantidadeDesejada;
                    carrinho[totalItensCarrinho].precoUnitario = estoque[i].preco;
                    carrinho[totalItensCarrinho].subtotal = (float)quantidadeDesejada * estoque[i].preco;

                    *subtotal += carrinho[totalItensCarrinho].subtotal;
                    totalItensCarrinho++;

                    estoque[i].quantidade -= quantidadeDesejada;
                    printf("\tProduto '%s' adicionado ao carrinho.\n", estoque[i].nomePd);

                } else {
                    printf("\tEstoque insuficiente! Temos apenas %d unidades.\n", estoque[i].quantidade);
                }
                break;
            }
        }

        if (!encontrado && idProduto != 0) {
            printf("\tProduto com ID %d nao encontrado.\n", idProduto);
        }

        printf("\n\tDeseja adicionar outro produto? (s/n): ");
        scanf(" %c", &continuar);
        while (getchar() != '\n');

    } while (continuar == 's' || continuar == 'S');

    if (totalItensCarrinho > 0) {
        printf("\n\t=========== RESUMO DO CARRINHO ===========\n");
        for (int i = 0; i < totalItensCarrinho; i++) {
            printf("\t%d x %s - R$%.2f cada | Subtotal: R$%.2f\n",
                   carrinho[i].quantidade,
                   carrinho[i].nome,
                   carrinho[i].precoUnitario,
                   carrinho[i].subtotal);
        }
        printf("\tTOTAL DA VENDA: R$%.2f\n", *subtotal);
        printf("\t==========================================\n");

        salvarProdutos(estoque, *numProdutos);
        (*vd)++;


        FILE *arquivoVendas = fopen(NOME_ARQUIVO_VENDAS, "a");
        if (arquivoVendas == NULL) {
            perror("\tErro ao abrir o arquivo de vendas para salvar!");
            return;
        }


        fprintf(arquivoVendas, "--- Venda #%d - Total: R$%.2f ---\n", *vd, *subtotal);
        for (int i = 0; i < totalItensCarrinho; i++) {
            fprintf(arquivoVendas, "\t%d x %s - R$%.2f cada | Subtotal: R$%.2f\n",
                   carrinho[i].quantidade,
                   carrinho[i].nome,
                   carrinho[i].precoUnitario,
                   carrinho[i].subtotal);
        }
        fprintf(arquivoVendas, "-------------------------------------\n\n");

        fclose(arquivoVendas);
        printf("\t Detalhes da venda salvos no arquivo '%s'! ]\n", NOME_ARQUIVO_VENDAS);


    } else {
        printf("\tNenhum item adicionado ao carrinho. Venda cancelada.\n");
    }
}

float calcularDesconto(float subtotal) {
    float desconto = 0, descontoPercentual = 0;

    if (subtotal <= 50) {
        desconto = subtotal * 0.05;
    } else if (subtotal < 200) {
        desconto = subtotal * 0.10;
    } else {
        printf("\tO total eh maior que 200, digite quanto de desconto voce deseja aplicar (%%):\n");
        scanf("%f", &descontoPercentual);
        while (getchar() != '\n');
        desconto = subtotal * (descontoPercentual / 100);
    }
    return desconto;
}

void realizarPagamento(float *subtotal, float *totalf, float *totalD, float *totalC, float *totali) {
    if (*subtotal <= 0) {
        printf("\tNao ha vendas pendentes para pagamento.\n");
        return;
    }

    int pagamento;
    float troco = 0, valorRecebido = 0;
    float valorRestante = *subtotal;

    do {
        printf("\n\t=================== PAGAMENTO ==================\n");
        printf("\tTotal da compra: R$%.2f\n", valorRestante);
        printf("\t1 | Dinheiro (com desconto)\n");
        printf("\t2 | Cartao\n");
        printf("\t3 | Pagamento em conjunto (Dinheiro + Cartao)\n");
        printf("\t0 | Sair (cancelar pagamento e retornar ao menu anterior)\n");
        printf("\tEscolha a opcao de pagamento: ");
        scanf("%d", &pagamento);
        while (getchar() != '\n');

        switch (pagamento) {
            case 1: {
                float desconto = calcularDesconto(valorRestante);
                float totalComDesconto = valorRestante - desconto;

                printf("\tSubtotal com desconto: R$%.2f\n", totalComDesconto);

                do {
                    printf("\tValor recebido em dinheiro: ");
                    scanf("%f", &valorRecebido);
                    while (getchar() != '\n');

                    if (valorRecebido >= totalComDesconto) {
                        troco = valorRecebido - totalComDesconto;
                        printf("\tTroco a devolver: R$%.2f\n", troco);
                        *totalD += totalComDesconto;
                        *totalf += totalComDesconto;
                        valorRestante = 0;
                        printf("\tPagamento em dinheiro concluido com sucesso!\n");
                    } else if (valorRecebido == 0) {
                        printf("\tVoltando para a escolha de pagamento.\n");
                        break;
                    } else {
                        printf("\tValor insuficiente! Informe um valor igual ou maior que R$%.2f\n ou digite 0 para voltar para pagar com outro metodo\n", totalComDesconto);
                    }
                } while (valorRecebido < totalComDesconto && valorRecebido != 0);
                break;
            }
            case 2: {
                printf("\tPagamento no cartao confirmado para R$%.2f.\n", valorRestante);
                *totalC += valorRestante;
                *totalf += valorRestante;
                valorRestante = 0;
                printf("\tPagamento em cartao concluido com sucesso!\n");
                break;
            }
            case 3: {
                float valorDinheiro, valorCartao;
                printf("\tInforme o valor pago em dinheiro: ");
                scanf("%f", &valorDinheiro);
                while (getchar() != '\n');

                if (valorDinheiro >= valorRestante) {
                    troco = valorDinheiro - valorRestante;
                    printf("\tTroco a devolver: R$%.2f\n", troco);
                    *totalD += valorRestante;
                    *totalf += valorRestante;
                    valorRestante = 0;
                    printf("\tPagamento em dinheiro concluido com sucesso!\n");
                } else {
                    valorCartao = valorRestante - valorDinheiro;
                    printf("\tValor restante a ser pago no cartao: R$%.2f\n", valorCartao);
                    *totalD += valorDinheiro;
                    *totalC += valorCartao;
                    *totalf += valorDinheiro + valorCartao;
                    valorRestante = 0;
                    printf("\tPagamento em conjunto concluido com sucesso!\n");
                }
                break;
            }
            case 0:
                printf("\tSaindo do pagamento. Valor restante: R$%.2f\n", valorRestante);
                break;
            default:
                printf("\tOpcao de pagamento invalida.\n");
                break;
        }

        if (valorRestante <= 0 || pagamento == 0) {
            *subtotal = 0;
        }
    } while (valorRestante > 0 && pagamento != 0);
}

void realizarAberturacaixa(float *subtotal, float *totali, float *totalf) {
    printf("\n\t=== Abertura de Caixa ===\n");

    if (*totali > 0) {
        printf("\n\tCaixa ja iniciado com R$ %.2f\n", *totali);
    } else {
        printf("\n\tInforme o valor inicial no caixa: R$ ");
        scanf("%f", totali);
        while (getchar() != '\n');
        *totalf = *totali;
        *subtotal = 0;

        printf("\n\tCaixa iniciado com R$ %.2f\n", *totali);
    }
}

void realizarFechamento(int *vd, float *totalf, float *totali, float *totalD, float *totalC) {
    printf("\n\t===== FECHAMENTO DO CAIXA =====\n");
    printf("\tDinheiro no comeco do dia: R$%.2f\n", *totali);
    printf("\tVendas realizadas: %d\n", *vd);
    printf("\tTotal vendido (Dinheiro + Cartao): R$%.2f\n", *totalD + *totalC);
    printf("\tTotal vendido no dinheiro: R$%.2f\n", *totalD);
    printf("\tTotal vendido no cartao: R$%.2f\n", *totalC);
    printf("\tSaldo final em caixa (Dinheiro): R$%.2f\n", *totali + *totalD);
    printf("\t===============================\n");

    *vd = 0;
    *totalf = 0;
    *totali = 0;
    *totalD = 0;
    *totalC = 0;
}

int validarLogin(const char *login) {
    int len = strlen(login);
    return (len >= 8 && len <= 12);
}

int validarSenha(const char *senha) {
    int len = strlen(senha);
    return (len >= 6 && len <= 8);
}

void cadastrarUsuario(Usuario usuarios[], int *numUsuarios) {
    char inputLogin[MAX_LOGIN];
    char inputSenha[MAX_SENHA];
    int tipoInput;

    if (*numUsuarios >= MAX_USUARIOS) {
        printf("\tLimite maximo de usuarios atingido! Nao eh possivel cadastrar mais.\n");
        return;
    }

    printf("\n\t======== CADASTRAR NOVO USUARIO ========\n");
    do {
        printf("\tDigite o login (8 a 12 caracteres): ");
        scanf("%s", inputLogin);
        while (getchar() != '\n');
        if (!validarLogin(inputLogin)) {
            printf("\tO login deve conter entre 8 a 12 caracteres!\n");
        }
    } while (!validarLogin(inputLogin));
    strcpy(usuarios[*numUsuarios].login, inputLogin);

    do {
        printf("\tDigite a senha (6 a 8 caracteres): ");
        scanf("%s", inputSenha);
        while (getchar() != '\n');
        if (!validarSenha(inputSenha)) {
            printf("\tA senha deve conter entre 6 a 8 caracteres!\n");
        }
    } while (!validarSenha(inputSenha));
    strcpy(usuarios[*numUsuarios].senha, inputSenha);

    do {
        printf("\tDigite o tipo do usuario (1 - Administrador 2 - Usuario Normal): ");
        scanf("%d", &tipoInput);
        while (getchar() != '\n');
        if (tipoInput != ADMINISTRADOR && tipoInput != USUARIO_NORMAL) {
            printf("\tTipo invalido, digite 1 (Administrador) ou 2 (Usuario Normal)!\n");
        }
    } while (tipoInput != ADMINISTRADOR && tipoInput != USUARIO_NORMAL);
    usuarios[*numUsuarios].tipo = (TipoUsuario)tipoInput;

    (*numUsuarios)++;
    salvarUsuarios(usuarios, *numUsuarios);
    printf("\tUsuario cadastrado com sucesso!\n");
}

TipoUsuario verificarUsuario(const char *login, const char *senha, Usuario usuarios[], int numUsuarios) {
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(login, usuarios[i].login) == 0 && strcmp(senha, usuarios[i].senha) == 0) {
            printf("\tLogin realizado com sucesso!\n");
            return usuarios[i].tipo;
        }
    }
    printf("\tLogin ou senha incorretos.\n");
    return (TipoUsuario)0;
}

void controleAcesso(struct produtoES estoque[], int *numProdutosCadastrados, Usuario usuarios[], int *numUsuariosCadastrados, float *subtotal, float *totalf, float *totalD, float *totalC, float *totali, int *vd) {
    char loginInput[MAX_LOGIN];
    char senhaInput[MAX_SENHA];
    TipoUsuario usuarioVerificado;

    printf("\n\t[ Para acessar o menu de Cadastros, e necessario login de Administrador ]\n");
    printf("\tDigite seu login: ");
    scanf("%s", loginInput);
    while (getchar() != '\n');

    printf("\tDigite sua senha: ");
    scanf("%s", senhaInput);
    while (getchar() != '\n');

    usuarioVerificado = verificarUsuario(loginInput, senhaInput, usuarios, *numUsuariosCadastrados);

    if (usuarioVerificado == ADMINISTRADOR) {
        printf("\tLogin de Administrador bem-sucedido! Acessando menu de Cadastros.\n");
        gerenciarCadastros(estoque, numProdutosCadastrados, usuarios, numUsuariosCadastrados);
    } else {
        printf("\t[ Acesso negado! Credenciais invalidas ou usuario nao eh um administrador. ]\n");
    }
}

void salvarUsuarios(Usuario usuarios[], int numUsuarios) {
    FILE *arquivo = fopen(NOME_ARQUIVO_USUARIOS, "w");
    if (arquivo == NULL) {
        perror("\tErro ao abrir o arquivo de usuarios para salvar!");
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        fprintf(arquivo, "%s;%s;%d\n",
                usuarios[i].login,
                usuarios[i].senha,
                usuarios[i].tipo);
    }

    fclose(arquivo);
    printf("\t[ Usuarios atualizados e salvos no arquivo '%s'! ]\n", NOME_ARQUIVO_USUARIOS);
}

int carregarUsuarios(Usuario usuarios[]) {
    FILE *arquivo = fopen(NOME_ARQUIVO_USUARIOS, "r");
    if (arquivo == NULL) {
        printf("\t[ Aviso: Arquivo de usuarios nao encontrado. Um novo sera criado. ]\n");
        return 0;
    }

    int numUsuarios = 0;

    while (fscanf(arquivo, "%[^;];%[^;];%d\n",
                  usuarios[numUsuarios].login,
                  usuarios[numUsuarios].senha,
                  (int *)&usuarios[numUsuarios].tipo) == 3 && numUsuarios < MAX_USUARIOS) {
        numUsuarios++;
    }

    fclose(arquivo);
    return numUsuarios;
}

void gerenciarCadastros(struct produtoES estoque[], int *numProdutosCadastrados, Usuario usuarios[], int *numUsuariosCadastrados) {
    int menuCadastro;

    do {
        printf("\n\t=============== Cadastros ===============\n");
        printf("\t1 | Cadastro de clientes\n");
        printf("\t2 | Cadastro de produtos\n");
        printf("\t3 | Cadastro de usuarios\n");
        printf("\t0 | Voltar ao menu anterior\n");
        printf("\t Escolha a opcao: ");
        scanf("%d", &menuCadastro);
        while (getchar() != '\n');

        switch (menuCadastro) {
            case 1: {
                char opcao;
                do {
                    printf("\n\t============== Cadastro de Cliente ===============\n");
                    printf("\t1 | Cadastrar novo cliente\n");
                    printf("\t2 | Listar clientes\n");
                    printf("\t0 | Sair\n");
                    printf("\tEscolha uma opcao: ");
                    scanf(" %c", &opcao);
                    while (getchar() != '\n');

                    switch (opcao) {
                        case '1':
                            cadastrarCliente();
                            break;
                        case '2':
                            visualizarClientes();
                            break;
                        case '0':
                            printf("\tVoltando ao menu de Cadastros...\n");
                            break;
                        default:
                            printf("\tOpcao invalida. Tente novamente.\n");
                    }
                } while (opcao != '0');
                break;
            }
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
                            CadastrarItens(estoque, numProdutosCadastrados);
                            break;
                        case 2:
                            listarProdutos(estoque, *numProdutosCadastrados);
                            break;
                        case 3:
                            excluirProduto(estoque, numProdutosCadastrados);
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
            case 3: {
                cadastrarUsuario(usuarios, numUsuariosCadastrados);
                break;
            }
            case 0:
                printf("\n\tVoltando ao menu principal...\n");
                break;
            default:
                printf("\n\tOpcao invalida!\n");
        }
    } while (menuCadastro != 0);
}

void gerenciarVendas(struct produtoES estoque[], int *numProdutosCadastrados, int *vd, float *subtotal, float *totalf, float *totalD, float *totalC, float *totali) {
    int menuVenda;
    do {
        printf("\n\t=============== Menu de Vendas ===============\n");
        printf("\t1 | Realizar nova venda\n");
        printf("\t0 | Voltar ao menu principal\n");
        printf("\t Escolha a opcao: ");
        scanf("%d", &menuVenda);
        while (getchar() != '\n');

        switch (menuVenda) {
            case 1:
                realizarVenda(estoque, numProdutosCadastrados, vd, subtotal, totalf);
                if (*subtotal > 0) {
                    realizarPagamento(subtotal, totalf, totalD, totalC, totali);
                }
                break;
            case 0:
                printf("\n\tVoltando ao menu principal...\n");
                break;
            default:
                printf("\n\tOpcao invalida!\n");
        }
    } while (menuVenda != 0);
}