#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    float quantidade;
    char unidade[6];
    float valor;
    int posicaox;
    int posicaoy;
} Produto;

int comparar(const void *a, const void *b) {
    Produto *produtoA = (Produto *)a;
    Produto *produtoB = (Produto *)b;
    
    if (produtoA->posicaox == produtoB->posicaox) {
        return produtoA->posicaoy - produtoB->posicaoy;
    } else {
        return produtoA->posicaox - produtoB->posicaox;
    }
}

void gerarRelatorioCSV(Produto *produtos, int tamanho) {
    FILE *file = fopen("saida.csv", "w");
    
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    fprintf(file, "Nome,Quantidade,Unidade,Valor,PosicaoX,PosicaoY\n");
    
    for (int i = 0; i < tamanho; i++) {
        fprintf(file, "%s,%.2f,%s,%.2f,%d,%d\n",
                produtos[i].nome,
                produtos[i].quantidade,
                produtos[i].unidade,
                produtos[i].valor,
                produtos[i].posicaox,
                produtos[i].posicaoy);
    }
    
    fclose(file);
}

int main() {
    // Substitua 10 pelo número de produtos que você deseja manipular
    Produto produtos[10];
    
    // Aqui você deve adicionar o código para preencher os produtos
    // Por exemplo: scanf("%s", produtos[0].nome);
    
    // Ordena os produtos
    qsort(produtos, 10, sizeof(Produto), comparar);
    
    // Gera o relatório em formato CSV
    gerarRelatorioCSV(produtos, 10);
    
    printf("Relatório gerado com sucesso.\n");
    
    return 0;
}
