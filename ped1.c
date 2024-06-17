#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Alimento
typedef struct {
    char nome[51];
    float quantidade;
    char kcal[6];
} Alimento;

// Função para imprimir plano alimentar e calcular total de calorias
int imprimirPlanoAlimentar(FILE *arquivo, Alimento refeicao[], int tamanho, char *nomeRefeicao) {
    int totalCalorias = 0;

    fprintf(arquivo, "%s\n", nomeRefeicao);
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "  %-15s %5.1fg %7s Kcal\n", refeicao[i].nome, refeicao[i].quantidade, refeicao[i].kcal);
        totalCalorias += atoi(refeicao[i].kcal);
    }

    // Exemplo de valores nutricionais, ajustar conforme necessário
    int carb = 0, fib = 0, prot = 0, gor = 0;
    if (strcmp(nomeRefeicao, "12:00 - Dejejum") == 0) {
        carb = 74; fib = 10; prot = 21; gor = 15;
    } else if (strcmp(nomeRefeicao, "14:00 - Almoco") == 0) {
        carb = 58; fib = 11; prot = 40; gor = 6;
    } else if (strcmp(nomeRefeicao, "18:30 - Lanche da tarde") == 0) {
        carb = 11; fib = 0; prot = 38; gor = 13;
    } else if (strcmp(nomeRefeicao, "22:00 - Ceia") == 0) {
        carb = 87; fib = 18; prot = 25; gor = 2;
    }

    fprintf(arquivo, "  Cal %d Kcal   carb %dg  Fib %dg Prot %dg Gor %dg\n\n", totalCalorias, carb, fib, prot, gor);
    return totalCalorias;
}

int main() {
    // Definindo os alimentos
    Alimento dejejum[] = {
        {"Banana", 125, "124"},
        {"Aveia em flocos", 30, "118"},
        {"Coco", 20, "71"},
        {"Whey 3 Protein", 30, "126"},
        {"Yakult", 100, "51"}
    };

    Alimento almoco[] = {
        {"Arroz branco", 125, "160"},
        {"Feijao carioca", 90, "68"},
        {"Cenoura", 50, "43"},
        {"Tomate", 25, "4"},
        {"Carne Bife", 150, "186"}
    };

    Alimento lanche[] = {
        {"Tapioca de goma", 15, "37"},
        {"Ovo", 2, "129"},
        {"Patinho moida", 120, "160"},
        {"Tomate", 25, "4"}
    };

    Alimento ceia[] = {
        {"Banana", 125, "124"},
        {"Chocolate 70%", 25, "245"},
        {"Whey 3 Protein", 30, "126"},
        {"Coco", 20, "71"},
        {"Castanha", 5, "77"}
    };

    // Abrir os arquivos CSV e TXT para escrita
    FILE *arquivoCSV = fopen("saida.csv", "w");
    FILE *arquivoTXT = fopen("saida.txt", "w");

    if (arquivoCSV == NULL || arquivoTXT == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    int totalCaloriasGeral = 0;

    // Imprimir cabeçalho
    fprintf(arquivoCSV, "Plano Alimentar\n");
    fprintf(arquivoTXT, "Plano Alimentar\n");

    // Imprimir detalhes das refeições nos arquivos
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, dejejum, sizeof(dejejum) / sizeof(dejejum[0]), "12:00 - Dejejum");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoTXT, dejejum, sizeof(dejejum) / sizeof(dejejum[0]), "12:00 - Dejejum");

    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, almoco, sizeof(almoco) / sizeof(almoco[0]), "14:00 - Almoco");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoTXT, almoco, sizeof(almoco) / sizeof(almoco[0]), "14:00 - Almoco");

    
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, lanche, sizeof(lanche) / sizeof(lanche[0]), "18:30 - Lanche da tarde");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoTXT, lanche, sizeof(lanche) / sizeof(lanche[0]), "18:30 - Lanche da tarde");

    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, ceia, sizeof(ceia) / sizeof(ceia[0]), "22:00 - Ceia");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoTXT, ceia, sizeof(ceia) / sizeof(ceia[0]), "22:00 - Ceia");

    // Imprimir total geral de calorias
    fprintf(arquivoCSV, "Total Calorias Geral,%d Kcal\n", totalCaloriasGeral);
    fprintf(arquivoTXT, "Total Calorias Geral,%d Kcal\n", totalCaloriasGeral);

    // Fechar os arquivos
    fclose(arquivoCSV);
    fclose(arquivoTXT);

    printf("Plano alimentar escrito em saida.csv e saida.txt com sucesso.\n");

    return 0;
}
