#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

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

int main() {
    setlocale(LC_NUMERIC, "C"); // Define a localidade para o padrão C (ponto como separador decimal)
    
    Produto produtos[100]; // Ajuste este número conforme necessário
    int tamanho = 0;
    
    char opcao;
    
    do {
        printf("Deseja inserir um novo produto? (S/N): ");
        scanf(" %c", &opcao);
        
        if (opcao == 'S' || opcao == 's') {
            inserirProduto(produtos, &tamanho);
        }
        
    } while (opcao == 'S' || opcao == 's');
    
    gravarProdutosCSV(produtos, tamanho);
    
    printf("Produtos gravados com sucesso em saida.csv.\n");
    
    return 0;
}
