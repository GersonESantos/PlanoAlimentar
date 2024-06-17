#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

// Definição da estrutura produto
struct produto {
    char nome[51];
    float quantidade;
    char unidquant[6];
    float peso;
    char unidpeso[6];
};

// Função para carregar produtos do arquivo CSV
int carregarProdutos(struct produto produtos[], const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        return 0; // Se o arquivo não existe, retorna 0
    }

    char linha[256];
    int contador = 0;

    // Ignorar a linha de cabeçalho
    fgets(linha, sizeof(linha), file);

    while (fgets(linha, sizeof(linha), file) && contador < MAX_PRODUTOS) {
        sscanf(linha, "%50[^,],%f,%5[^,],%f,%5[^,\n]",
               produtos[contador].nome,
               &produtos[contador].quantidade,
               produtos[contador].unidquant,
               &produtos[contador].peso,
               produtos[contador].unidpeso);
        contador++;
    }

    fclose(file);
    return contador;
}

// Função para salvar produtos no arquivo CSV
void salvarProdutos(struct produto produtos[], int quantidade, const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", nomeArquivo);
        return;
    }

    // Escrever cabeçalho
    fprintf(file, "nome,quantidade,unidquant,peso,unidpeso\n");

    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%s,%.2f,%s,%.2f,%s\n",
                produtos[i].nome, produtos[i].quantidade,
                produtos[i].unidquant, produtos[i].peso,
                produtos[i].unidpeso);
    }

    fclose(file);
    printf("Dados gravados com sucesso em %s.\n", nomeArquivo);
}

// Função para inserir novos produtos manualmente
void inserirProdutos(struct produto produtos[], int *quantidade) {
    while (*quantidade < MAX_PRODUTOS) {
        printf("Digite os detalhes do produto %d:\n", *quantidade + 1);

        printf("Nome (digite '!' para parar): ");
        scanf(" %50[^\n]", produtos[*quantidade].nome);
        if (strcmp(produtos[*quantidade].nome, "!") == 0) {
            break;
        }

        printf("Quantidade: ");
        scanf("%f", &produtos[*quantidade].quantidade);

        printf("Unidade de Quantidade: ");
        scanf(" %5s", produtos[*quantidade].unidquant);

        printf("Peso: ");
        scanf("%f", &produtos[*quantidade].peso);

        printf("Unidade de Peso: ");
        scanf(" %5s", produtos[*quantidade].unidpeso);

        (*quantidade)++;
    }
}

int main() {
    struct produto produtos[MAX_PRODUTOS];
    int quantidadeProdutos = 0;

    // Carregar produtos existentes, se houver
    quantidadeProdutos = carregarProdutos(produtos, "saida.csv");

    // Inserir novos produtos
    inserirProdutos(produtos, &quantidadeProdutos);

    // Salvar todos os produtos no arquivo CSV
    salvarProdutos(produtos, quantidadeProdutos, "saida.csv");

    return 0;
}
