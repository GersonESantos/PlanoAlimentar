#include <stdio.h>

struct ItemCompra {
    char nome[50];
    char quantidade[30];
};

void imprimirLista(struct ItemCompra lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d. %-30s %s\n", i + 1, lista[i].nome, lista[i].quantidade);
    }
}

int main() {
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

    int tamanho = sizeof(listaDeCompras) / sizeof(listaDeCompras[0]);

    imprimirLista(listaDeCompras, tamanho);

    return 0;
}
