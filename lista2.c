#include <stdio.h>

struct Alimento {
    char nome[50];
    float quantidade;
    char unidade[10];
    int calorias;
};

struct ItemCompra {
    char nome[50];
    char quantidade[30];
};

void imprimirPlanoAlimentar(struct Alimento alimentos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%-20s %6.2f %s  %4d Kcal\n", alimentos[i].nome, alimentos[i].quantidade, alimentos[i].unidade, alimentos[i].calorias);
    }
}

void imprimirLista(struct ItemCompra lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d. %-30s %s\n", i + 1, lista[i].nome, lista[i].quantidade);
    }
}

int main() {
    struct Alimento cafe_da_manha[] = {
        {"Cha", 620.0, "ml", 0},
        {"Limonada", 620.0, "ml", 0},
        {"Banana", 125.0, "g", 124},
        {"Aveia em flocos", 30.0, "g", 118},
        {"Coco", 20.0, "g", 71},
        {"Whey 3 Protein", 30.0, "g", 126},
        {"Yakult", 100.0, "ml", 51}
    };

    struct Alimento almoco[] = {
        {"Arroz branco", 125.0, "g", 160},
        {"Feijao carioca", 90.0, "g", 68},
        {"Cenoura", 50.0, "g", 43},
        {"Tomate", 25.0, "g", 4},
        {"Carne Bife", 150.0, "g", 186},
        {"Limonada", 620.0, "ml", 0}
    };

    struct Alimento lanche_da_tarde[] = {
        {"Tapioca de goma", 15.0, "g", 37},
        {"Ovo", 2.0, "unid", 129},
        {"Patinho moida", 120.0, "g", 160},
        {"Tomate", 25.0, "g", 4},
        {"Limonada", 620.0, "ml", 0}
    };

    struct Alimento ceia[] = {
        {"Banana", 125.0, "g", 124},
        {"Chocolate 70%", 25.0, "g", 245},
        {"Whey 3 Protein", 30.0, "g", 126},
        {"Coco", 20.0, "g", 71},
        {"Castanha", 5.0, "g", 77}
    };

    printf("12:00 - Cafe da Manha\n");
    imprimirPlanoAlimentar(cafe_da_manha, sizeof(cafe_da_manha) / sizeof(cafe_da_manha[0]));
    printf("\n14:00 - Almoco\n");
    imprimirPlanoAlimentar(almoco, sizeof(almoco) / sizeof(almoco[0]));
    printf("\n15:00 - Cafe puro\n\n");
    printf("18:30 - Lanche da Tarde\n");
    imprimirPlanoAlimentar(lanche_da_tarde, sizeof(lanche_da_tarde) / sizeof(lanche_da_tarde[0]));
    printf("\n22:00 - Ceia\n");
    imprimirPlanoAlimentar(ceia, sizeof(ceia) / sizeof(ceia[0]));
    printf("\n");

    struct ItemCompra listaDeCompras[] = {
        {"Cha", "Quantidade suficiente para 620 ml"},
        {"Limoes", "3 unidades"},
        {"Bananas", "2 unidades (aproximadamente 250 g)"},
        {"Aveia em flocos", "30 g"},
        {"Coco", "40 g"},
        {"Whey 3 Protein", "60 g"},
        {"Yakult", "1 unidade (100 ml)"},
        {"Arroz branco", "125 g"},
        {"Feijao carioca", "90 g"},
        {"Cenoura", "50 g"},
        {"Tomate", "1 unidade grande ou 2 pequenas (aproximadamente 50 g)"},
        {"Carne Bife", "150 g"},
        {"Tapioca de goma", "15 g"},
        {"Ovos", "2 unidades"},
        {"Patinho moida", "120 g"},
        {"Chocolate 70%", "25 g"},
        {"Castanha", "5 g"}
    };

    int tamanho_lista = sizeof(listaDeCompras) / sizeof(listaDeCompras[0]);
    printf("Lista de Compras:\n");
    imprimirLista(listaDeCompras, tamanho_lista);

    return 0;
}
