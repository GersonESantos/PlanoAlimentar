#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura produto
struct produto {
    int codigo;
    char nome[51];
    float quantidade;
    char unidade[6];
    float valor;
    int posicaox;
    int posicaoy;
};

void escreverTXT(struct produto produtos[], int quantidade) {
    // Abrir o arquivo TXT para escrita
    FILE *file = fopen("saida.txt", "w");
    if (file == NULL) {
        printf("Nao foi possivel abrir o arquivo para escrita.\n");
        exit(1);
    }

    // Escrever os dados dos produtos no TXT
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "Codigo: %d\n", produtos[i].codigo);
        fprintf(file, "Nome: %s\n", produtos[i].nome);
        fprintf(file, "Quantidade: %.2f\n", produtos[i].quantidade);
        fprintf(file, "Unidade: %s\n", produtos[i].unidade);
        fprintf(file, "Valor: %.2f\n", produtos[i].valor);
        fprintf(file, "Posicao X: %d\n", produtos[i].posicaox);
        fprintf(file, "Posicao Y: %d\n", produtos[i].posicaoy);
        fprintf(file, "------------------------------\n");
    }

    // Fechar o arquivo
    fclose(file);
    printf("Dados gravados com sucesso em saida.txt\n");
}

int main() {
    int quantidadeProdutos;

    // Solicitar o numero de produtos ao usuario
    printf("Digite o numero de produtos: ");
    scanf("%d", &quantidadeProdutos);

    // Alocar memoria para os produtos
    struct produto *produtos = (struct produto *)malloc(quantidadeProdutos * sizeof(struct produto));
    if (produtos == NULL) {
        printf("Nao foi possivel alocar memoria.\n");
        return 1;
    }

    // Ler os dados dos produtos
    for (int i = 0; i < quantidadeProdutos; i++) {
        printf("Produto %d:\n", i + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[i].codigo);
        printf("Nome: ");
        scanf(" %[^\n]%*c", produtos[i].nome);  // Le ate nova linha
        printf("Quantidade: ");
        scanf("%f", &produtos[i].quantidade);
        printf("Unidade: ");
        scanf("%s", produtos[i].unidade);
        printf("Valor: ");
        scanf("%f", &produtos[i].valor);
        printf("Posicao X: ");
        scanf("%d", &produtos[i].posicaox);
        printf("Posicao Y: ");
        scanf("%d", &produtos[i].posicaoy);
    }

    // Escrever os dados no arquivo TXT
    escreverTXT(produtos, quantidadeProdutos);

    // Liberar a memoria alocada
    free(produtos);

    return 0;
}
