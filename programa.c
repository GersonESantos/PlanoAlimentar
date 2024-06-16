#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura produto
struct produto {
    char nome[51];
    float quantidade;
    char unidade[6];
    float valor;
    int posicaox;
    int posicaoy;
};

void escreverCSV(struct produto produtos[], int quantidade) {
    // Abrir o arquivo CSV para escrita
    FILE *file = fopen("saida.csv", "w");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo para escrita.\n");
        exit(1);
    }

    // Escrever o cabeçalho do CSV
    fprintf(file, "nome,quantidade,unidade,valor,posicaox,posicaoy\n");

    // Escrever os dados dos produtos no CSV
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%s,%.2f,%s,%.2f,%d,%d\n", produtos[i].nome, produtos[i].quantidade, produtos[i].unidade, produtos[i].valor, produtos[i].posicaox, produtos[i].posicaoy);
    }

    // Fechar o arquivo
    fclose(file);
    printf("Dados gravados com sucesso em saida.csv\n");
}

int main() {
    int quantidadeProdutos;

    // Solicitar o número de produtos ao usuário
    printf("Digite o número de produtos: ");
    scanf("%d", &quantidadeProdutos);

    // Alocar memória para os produtos
    struct produto *produtos = (struct produto *)malloc(quantidadeProdutos * sizeof(struct produto));
    if (produtos == NULL) {
        printf("Não foi possível alocar memória.\n");
        return 1;
    }

    // Ler os dados dos produtos
    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]%*c", produtos[i].nome);  // Lê até nova linha
        printf("Quantidade: ");
        scanf("%f", &produtos[i].quantidade);
        printf("Unidade: ");
        scanf("%s", produtos[i].unidade);
        printf("Valor: ");
        scanf("%f", &produtos[i].valor);
        printf("Posição X: ");
        scanf("%d", &produtos[i].posicaox);
        printf("Posição Y: ");
        scanf("%d", &produtos[i].posicaoy);
    }

    // Escrever os dados no arquivo CSV
    escreverCSV(produtos, quantidadeProdutos);

    // Liberar a memória alocada
    free(produtos);

    return 0;
}
