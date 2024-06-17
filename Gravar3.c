#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    float quantidade;
    char unidquant[6];
    float peso;
    char unidpeso[6];
} Produto;

void inserirProduto(Produto *produtos, int *tamanho) {
    printf("Digite o nome do produto: ");
    scanf("%50s", produtos[*tamanho].nome);
    
    printf("Digite a quantidade do produto (ex: 9999.99): ");
    scanf("%f", &produtos[*tamanho].quantidade);
    
    printf("Digite a unidade de quantidade (ex: kg, l): ");
    scanf("%5s", produtos[*tamanho].unidquant);
    
    printf("Digite o peso do produto: ");
    scanf("%f", &produtos[*tamanho].peso);
    
    printf("Digite a unidade de peso (ex: kg, l): ");
    scanf("%5s", produtos[*tamanho].unidpeso);
    
    (*tamanho)++;
}

void gravarProdutosCSV(Produto *produtos, int tamanho) {
    FILE *file = fopen("saida.csv", "w");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fprintf(file, "Nome,Quantidade,UnidQuant,Peso,UnidPeso\n");
    
    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%s,%.2f,%s,%.2f,%s\n",
                produtos[i].nome,
                produtos[i].quantidade,
                produtos[i].unidquant,
                produtos[i].peso,
                produtos[i].unidpeso);
    }
    
    fclose(file);
}

void listarProdutosCSV() {
    FILE *file = fopen("saida.csv", "r");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    char linha[1024];
    
    // Ignora a primeira linha (cabeçalho)
    fgets(linha, 1024, file);

    while (fgets(linha, 1024, file)) {
        // Processa cada campo separadamente
        char *token = strtok(linha, ",");
        if (token) {
            // Completa o campo 'nome' com espaços até atingir 50 caracteres
            printf("%-50s\t", token);
        }

        while ((token = strtok(NULL, ","))) {
            printf("%s\t", token);
        }
        printf("\n"); // Adiciona uma nova linha após cada registro
    }
    
    fclose(file);
}

int main() {
    Produto produtos[100]; // Ajuste este numero conforme necessario
    int tamanho = 0;
    
    char opcao;
    
    do {
        printf("Escolha uma opcao:\nG - Gravar novo produto\nL - Listar produtos\nS - Sair\nOpcao: ");
        scanf(" %c", &opcao);
        
        switch (opcao) {
            case 'G':
            case 'g':
                inserirProduto(produtos, &tamanho);
                gravarProdutosCSV(produtos, tamanho);
                break;
            case 'L':
            case 'l':
                listarProdutosCSV();
                break;
            case 'S':
            case 's':
                return 0;
            default:
                printf("Opcao invalida.\n");
        }
        
    } while (opcao != 'S' && opcao != 's');
    
    return 0;
}
