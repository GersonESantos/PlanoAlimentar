#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura produto
struct produto {
    char nome[51];
    float quantidade;
    char unidade[6];
    float peso;
};

// Função para ler os dados do arquivo PlAl.txt
int lerArquivoTxt(struct produto produtos[], const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return 0;
    }

    char linha[256];
    int contador = 0;
    while (fgets(linha, sizeof(linha), file)) {
        if (linha[0] == '#') {
            continue; // Ignora linhas que começam com #
        }
        sscanf(linha, "%50[^,],%f,%5[^,],%f",
               produtos[contador].nome,
               &produtos[contador].quantidade,
               produtos[contador].unidade,
               &produtos[contador].peso);
        contador++;
    }
    fclose(file);
    return contador;
}

// Função para escrever os dados no arquivo PlAl.csv
void escreverCSV(struct produto produtos[], int quantidade, const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", nomeArquivo);
        return;
    }

    fprintf(file, "nome,quantidade,unidade,peso\n");
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%s,%.2f,%s,%.2f\n",
                produtos[i].nome, produtos[i].quantidade,
                produtos[i].unidade, produtos[i].peso);
    }
    fclose(file);
    printf("Dados gravados com sucesso em %s.\n", nomeArquivo);
}

// Função para escrever os dados no arquivo sai.txt
void escreverTXT(struct produto produtos[], int quantidade, const char *nomeArquivo) {
    FILE *file = fopen(nomeArquivo, "w");
    if (!file) {
        printf("Erro ao abrir o arquivo %s para escrita.\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "Nome: %s\nQuantidade: %.2f\nUnidade: %s\nPeso: %.2f\n\n",
                produtos[i].nome, produtos[i].quantidade,
                produtos[i].unidade, produtos[i].peso);
    }
    fclose(file);
    printf("Dados gravados com sucesso em %s.\n", nomeArquivo);
}

// Função principal
int main() {
    struct produto produtos[100]; // Array para armazenar produtos
    int quantidadeProdutos;

    // Ler os dados do arquivo PlAl.txt
    quantidadeProdutos = lerArquivoTxt(produtos, "PlAl.txt");

    // Escrever os dados no arquivo PlAl.csv
    escreverCSV(produtos, quantidadeProdutos, "PlAl.csv");

    // Escrever os dados no arquivo sai.txt
    escreverTXT(produtos, quantidadeProdutos, "sai.txt");

    return 0;
}
