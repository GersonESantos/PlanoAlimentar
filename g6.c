#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Constantes para o tamanho da matriz de posicao
#define NUM_ARMARIOS 5
#define NUM_PRATELEIRAS 7

void escreverCSV(struct produto produtos[], int quantidade) {
    FILE *file = fopen("saida.csv", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo saida.csv.\n");
        return;
    }

    fprintf(file, "codigo,nome,quantidade,unidade,valor,posicaox,posicaoy\n");
    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "%d,%s,%.2f,%s,%.2f,%d,%d\n",
                produtos[i].codigo, produtos[i].nome, produtos[i].quantidade,
                produtos[i].unidade, produtos[i].valor, produtos[i].posicaox, produtos[i].posicaoy);
    }

    fclose(file);
    printf("Dados gravados com sucesso em saida.csv.\n");
}

void escreverTXT(struct produto produtos[], int quantidade) {
    FILE *file = fopen("saida.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo saida.txt.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(file, "Codigo: %d\nNome: %s\nQuantidade: %.2f\nUnidade: %s\nValor: %.2f\nPosicao X: %d\nPosicao Y: %d\n\n",
                produtos[i].codigo, produtos[i].nome, produtos[i].quantidade,
                produtos[i].unidade, produtos[i].valor, produtos[i].posicaox, produtos[i].posicaoy);
    }

    fclose(file);
    printf("Dados gravados com sucesso em saida.txt.\n");
}

int main() {
    struct produto produtos[100];
    int quantidadeProdutos = 0;
    char continuar;

    // Tentar ler o arquivo CSV existente
    FILE *file = fopen("saida.csv", "r");
    if (file) {
        char linha[256];
        fgets(linha, sizeof(linha), file); // Ignorar cabeçalho
        while (fgets(linha, sizeof(linha), file)) {
            sscanf(linha, "%d,%50[^,],%f,%5[^,],%f,%d,%d",
                   &produtos[quantidadeProdutos].codigo,
                   produtos[quantidadeProdutos].nome,
                   &produtos[quantidadeProdutos].quantidade,
                   produtos[quantidadeProdutos].unidade,
                   &produtos[quantidadeProdutos].valor,
                   &produtos[quantidadeProdutos].posicaox,
                   &produtos[quantidadeProdutos].posicaoy);
            quantidadeProdutos++;
        }
        fclose(file);
    }

    // Preenchimento automático dos produtos
    int armario = 0, prateleira = 0;
    for (int i = 0; i < quantidadeProdutos; i++) {
        produtos[i].posicaox = armario;
        produtos[i].posicaoy = prateleira;
        prateleira++;
        if (prateleira >= NUM_PRATELEIRAS) {
            prateleira = 0;
            armario++;
            if (armario >= NUM_ARMARIOS) {
                printf("Limite de armários alcançado.\n");
                break;
            }
        }
    }

    // Inserção manual de novos produtos até código 999
    do {
        printf("Digite os dados do produto %d:\n", quantidadeProdutos + 1);
        printf("Codigo: ");
        scanf("%d", &produtos[quantidadeProdutos].codigo);
        
        if (produtos[quantidadeProdutos].codigo == 999) {
            break;
        }

        printf("Nome: ");
        scanf(" %[^\n]%*c", produtos[quantidadeProdutos].nome);
        printf("Quantidade: ");
        scanf("%f", &produtos[quantidadeProdutos].quantidade);
        printf("Unidade: ");
        scanf("%s", produtos[quantidadeProdutos].unidade);
        printf("Valor: ");
        scanf("%f", &produtos[quantidadeProdutos].valor);

        // Atribuição automática da posição
        produtos[quantidadeProdutos].posicaox = armario;
        produtos[quantidadeProdutos].posicaoy = prateleira;

        // Incremento automático da posição
        prateleira++;
        if (prateleira >= NUM_PRATELEIRAS) {
            prateleira = 0;
            armario++;
            if (armario >= NUM_ARMARIOS) {
                printf("Limite de armários alcançado.\n");
                break;
            }
        }

        quantidadeProdutos++;
        if (quantidadeProdutos >= 100) {
            printf("Numero maximo de produtos atingido.\n");
            break;
        }

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    // Escrever os dados nos arquivos CSV e TXT
    escreverCSV(produtos, quantidadeProdutos);
    escreverTXT(produtos, quantidadeProdutos);

    return 0;
}
