#include <stdio.h>
#include <string.h>

struct Alimento {
    char nome[50];
    float quantidade;
    char unidade[10];
    int calorias;
};

struct ItemCompra {
    char nome[50];
    float quantidade;
    char unidade[10];
};

void imprimirPlanoAlimentar(struct Alimento alimentos[], int tamanho, const char* refeicao) {
    int caloriasTotais = 0;
    printf("%s\n", refeicao);
    for (int i = 0; i < tamanho; i++) {
        printf("%-20s %6.2f %s  %4d Kcal\n", alimentos[i].nome, alimentos[i].quantidade, alimentos[i].unidade, alimentos[i].calorias);
        caloriasTotais += alimentos[i].calorias;
    }
    printf("Calorias totais: %d Kcal\n\n", caloriasTotais);
}

void imprimirLista(struct ItemCompra lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d. %-20s %6.2f %s\n", i + 1, lista[i].nome, lista[i].quantidade, lista[i].unidade);
    }
}

void adicionarItem(struct ItemCompra lista[], int *tamanho, char nome[], float quantidade, char unidade[]) {
    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(lista[i].nome, nome) == 0) {
            lista[i].quantidade += quantidade;
            return;
        }
    }
    strcpy(lista[*tamanho].nome, nome);
    lista[*tamanho].quantidade = quantidade;
    strcpy(lista[*tamanho].unidade, unidade);
    (*tamanho)++;
}

int main() {
    struct Alimento cafe_da_manha[] = {
        {"Cafe", 10.0, "g", 0},
        {"Cha", 5.0, "g", 0},
        {"Limao", 1.0, "unid", 0},
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

    struct ItemCompra listaDeCompras[100];
    int tamanho_lista = 0;

    // Refeições por dia
    int dias_da_semana = 7;
    for (int dia = 0; dia < dias_da_semana; dia++) {
        printf("Dia %d:\n", dia + 1);

        printf("12:00 - Cafe da Manha\n");
        imprimirPlanoAlimentar(cafe_da_manha, sizeof(cafe_da_manha) / sizeof(cafe_da_manha[0]), "12:00 - Cafe da Manha");
        for (int i = 0; i < sizeof(cafe_da_manha) / sizeof(cafe_da_manha[0]); i++) {
            adicionarItem(listaDeCompras, &tamanho_lista, cafe_da_manha[i].nome, cafe_da_manha[i].quantidade, cafe_da_manha[i].unidade);
        }

        printf("14:00 - Almoco\n");
        imprimirPlanoAlimentar(almoco, sizeof(almoco) / sizeof(almoco[0]), "14:00 - Almoco");
        for (int i = 0; i < sizeof(almoco) / sizeof(almoco[0]); i++) {
            adicionarItem(listaDeCompras, &tamanho_lista, almoco[i].nome, almoco[i].quantidade, almoco[i].unidade);
        }

        printf("15:00 - Cafe\n\n");

        printf("18:30 - Lanche da Tarde\n");
        imprimirPlanoAlimentar(lanche_da_tarde, sizeof(lanche_da_tarde) / sizeof(lanche_da_tarde[0]), "18:30 - Lanche da Tarde");
        for (int i = 0; i < sizeof(lanche_da_tarde) / sizeof(lanche_da_tarde[0]); i++) {
            adicionarItem(listaDeCompras, &tamanho_lista, lanche_da_tarde[i].nome, lanche_da_tarde[i].quantidade, lanche_da_tarde[i].unidade);
        }

        printf("22:00 - Ceia\n");
        imprimirPlanoAlimentar(ceia, sizeof(ceia) / sizeof(ceia[0]), "22:00 - Ceia");
        for (int i = 0; i < sizeof(ceia) / sizeof(ceia[0]); i++) {
            adicionarItem(listaDeCompras, &tamanho_lista, ceia[i].nome, ceia[i].quantidade, ceia[i].unidade);
        }
    }

    printf("Lista de Compras:\n");
    imprimirLista(listaDeCompras, tamanho_lista);

    return 0;
}
