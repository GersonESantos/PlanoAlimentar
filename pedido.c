#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float quantidade;
    int calorias;
    int carb;
    int fib;
    int prot;
    int gor;
} Alimento;

typedef struct {
    char nome[50];
    float quantidade;
} ItemCompra;

void imprimirPlanoAlimentar(Alimento refeicao[], int tamanho) {
    int totalCalorias = 0, totalCarb = 0, totalFib = 0, totalProt = 0, totalGor = 0;
    
    for (int i = 0; i < tamanho; i++) {
        printf("  %-20s %5.2f g %4d Kcal\n", refeicao[i].nome, refeicao[i].quantidade, refeicao[i].calorias);
        totalCalorias += refeicao[i].calorias;
        totalCarb += refeicao[i].carb;
        totalFib += refeicao[i].fib;
        totalProt += refeicao[i].prot;
        totalGor += refeicao[i].gor;
    }
    printf("  Total Calorias: %d Kcal\n", totalCalorias);
    printf("  Total Carb: %d g\n", totalCarb);
    printf("  Total Fib: %d g\n", totalFib);
    printf("  Total Prot: %d g\n", totalProt);
    printf("  Total Gor: %d g\n", totalGor);
    printf("\n");
}

void imprimirLista(ItemCompra lista[], int tamanho) {
    printf("Lista de compras:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("  %s: %.2f g\n", lista[i].nome, lista[i].quantidade);
    }
}

int main() {
    // Definindo os alimentos
    Alimento banana = {"Banana", 125, 124, 31, 3, 1, 0};
    Alimento aveia = {"Aveia em flocos", 30, 118, 20, 3, 4, 2};
    Alimento coco = {"Coco", 20, 71, 6, 2, 1, 7};
    Alimento whey = {"Whey 3 Protein", 30, 126, 3, 0, 25, 2};
    Alimento yakult = {"Yakult", 100, 51, 12, 0, 1, 0};
    
    Alimento arroz = {"Arroz branco", 125, 160, 35, 0, 3, 0};
    Alimento feijao = {"Feijão carioca", 90, 68, 12, 5, 4, 0};
    Alimento cenoura = {"Cenoura", 50, 43, 10, 3, 1, 0};
    Alimento tomate = {"Tomate", 25, 4, 1, 1, 0, 0};
    Alimento bife = {"Carne Bife", 150, 186, 0, 0, 30, 12};
    Alimento frango = {"Carne frango", 150, 130, 0, 0, 30, 4};
    Alimento peixe = {"Peixe assado", 150, 126, 0, 0, 28, 4};
    Alimento patinho = {"Patinho moída", 150, 146, 0, 0, 30, 6};
    Alimento carne_cozida = {"Carne cozida", 150, 116, 0, 0, 28, 4};
    Alimento porco = {"Carne de porco", 150, 130, 0, 0, 28, 6};
    
    Alimento tapioca = {"Tapioca de goma", 15, 37, 9, 0, 0, 0};
    Alimento ovo = {"Ovo", 2, 129, 1, 0, 11, 10};
    
    Alimento chocolate = {"Chocolate 70%", 25, 245, 13, 3, 3, 22};
    Alimento castanha = {"Castanha", 5, 77, 2, 1, 1, 7};

    // Plano alimentar
    Alimento dia1Cafe[] = {banana, aveia, coco, whey, yakult};
    Alimento dia1Almoco[] = {arroz, feijao, cenoura, tomate, bife};
    Alimento dia1Lanche[] = {tapioca, ovo, patinho, tomate};
    Alimento dia1Ceia[] = {banana, chocolate, whey, coco, castanha};

    Alimento dia2Almoco[] = {arroz, feijao, cenoura, tomate, frango};
    Alimento dia3Almoco[] = {arroz, feijao, cenoura, tomate, peixe};
    Alimento dia4Almoco[] = {arroz, feijao, cenoura, tomate, patinho};
    Alimento dia5Almoco[] = {arroz, feijao, cenoura, tomate, carne_cozida};
    Alimento dia6Almoco[] = {arroz, feijao, cenoura, tomate, porco};
    Alimento dia7Almoco[] = {arroz, feijao, cenoura, tomate, patinho};

    printf("Dia 1\n");
    printf("12:00 - Café\n");
    imprimirPlanoAlimentar(dia1Cafe, sizeof(dia1Cafe) / sizeof(dia1Cafe[0]));
    printf("14:00 - Almoço\n");
    imprimirPlanoAlimentar(dia1Almoco, sizeof(dia1Almoco) / sizeof(dia1Almoco[0]));
    printf("18:30 - Lanche da tarde\n");
    imprimirPlanoAlimentar(dia1Lanche, sizeof(dia1Lanche) / sizeof(dia1Lanche[0]));
    printf("22:00 - Ceia\n");
    imprimirPlanoAlimentar(dia1Ceia, sizeof(dia1Ceia) / sizeof(dia1Ceia[0]));

    printf("Dia 2\n");
    printf("14:00 - Almoço\n");
    imprimirPlanoAlimentar(dia2Almoco, sizeof(dia2Almoco) / sizeof(dia2Almoco[0]));

    printf("Dia 3\n");
    printf("14:00 - Almoço\n");
    imprimirPlanoAlimentar(dia3Almoco, sizeof(dia3Almoco) / sizeof(dia3Almoco[0]));

    printf("Dia 4\n");
    printf("14:00 - Almoço\n");
    imprimirPlanoAlimentar(dia4Almoco, sizeof(dia4Almoco) / sizeof(dia4Almoco[0]));

    printf("Dia 5\n");
    printf("14:00 - Almoço\n");
    imprimirPlanoAlimentar(dia5Almoco, sizeof(dia5Almoco) / sizeof(dia5Almoco[0]));

    printf("Dia 6\n");
    printf("14:00 - Almoço\n");
    imprimirPlanoAlimentar(dia6Almoco, sizeof(dia6Almoco) / sizeof(dia6Almoco[0]));

    printf("Dia 7\n");
    printf("14:00 - Almoço\n");
    imprimirPlanoAlimentar(dia7Almoco, sizeof(dia7Almoco) / sizeof(dia7Almoco[0]));

    return 0;
}
