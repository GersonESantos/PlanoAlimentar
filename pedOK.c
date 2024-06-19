#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Alimento
typedef struct {
    char nome[51];
    float quantidade;
    char g[2]; // Unidade de medida (g, ml, etc.)
    char kcal[6];
} Alimento;

// Função para imprimir plano alimentar e calcular total de calorias
int imprimirPlanoAlimentar(FILE *arquivo, Alimento refeicao[], int tamanho) {
    int totalCalorias = 0;

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%s,%.2f%s,%s\n", refeicao[i].nome, refeicao[i].quantidade, refeicao[i].g, refeicao[i].kcal);
        totalCalorias += atoi(refeicao[i].kcal);
    }
    fprintf(arquivo, "Total Calorias,%d Kcal\n\n", totalCalorias);
    return totalCalorias;
}

// Função para imprimir a lista de compras
void listaDeCompras(FILE *arquivo, Alimento lista[], int tamanho) {
    fprintf(arquivo, "Lista de Compras\n");
    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%s,%.2f%s\n", lista[i].nome, lista[i].quantidade, lista[i].g);
    }
    fprintf(arquivo, "\n");
}

int main() {
    // Definindo os alimentos
    Alimento dejejum[] = {
        {"Banana", 125, "g", "124"},
        {"Aveia em flocos", 30, "g", "118"},
        {"Coco", 20, "g", "71"},
        {"Whey 3 Protein", 30, "g", "126"},
        {"Yakult", 100, "ml", "51"}
    };

    Alimento almoco[] = {
        {"Arroz branco", 125, "g", "160"},
        {"Feijao carioca", 90, "g", "68"},
        {"Cenoura", 50, "g", "43"},
        {"Tomate", 25, "g", "4"},
        {"Carne Bife", 150, "g", "186"},
        {"Limao", 1, "unid", "0"} // Lembrar que limão não foi especificado em calorias
    };

    Alimento lanche[] = {
        {"Tapioca de goma", 15, "g", "37"},
        {"Ovo", 2, "unid", "129"},
        {"Patinho moida", 120, "g", "160"},
        {"Tomate", 25, "g", "4"},
        {"Limao", 1, "unid", "0"} // Lembrar que limão não foi especificado em calorias
    };

    Alimento ceia[] = {
        {"Banana", 125, "g", "124"},
        {"Chocolate 70%", 25, "g", "245"},
        {"Whey 3 Protein", 30, "g", "126"},
        {"Coco", 20, "g", "71"},
        {"Castanha", 5, "g", "77"}
    };

    // Definindo a lista de compras
    Alimento listaCompras[] = {
        {"Banana", 250, "g"},
        {"Aveia em flocos", 60, "g"},
        {"Coco", 40, "g"},
        {"Whey 3 Protein", 60, "g"},
        {"Yakult", 200, "ml"},
        {"Arroz branco", 125, "g"},
        {"Feijao carioca", 90, "g"},
        {"Cenoura", 50, "g"},
        {"Tomate", 50, "g"},
        {"Carne Bife", 150, "g"},
        {"Tapioca de goma", 15, "g"},
        {"Ovo", 2, "unid"},
        {"Patinho moida", 120, "g"},
        {"Chocolate 70%", 25, "g"},
        {"Castanha", 5, "g"},
        {"Limao", 2, "unid"} // Limões não especificados na lista de compras
    };

    // Abrir os arquivos CSV e TXT para escrita
    FILE *arquivoCSV = fopen("saida.csv", "w");
    FILE *arquivoTXT = fopen("saida.txt", "w");
    FILE *arquivoListaCSV = fopen("lista.csv", "w");
    FILE *arquivoListaTXT = fopen("lista.txt", "w");

    if (arquivoCSV == NULL || arquivoTXT == NULL || arquivoListaCSV == NULL || arquivoListaTXT == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    int totalCaloriasGeral = 0;

    // Imprimir detalhes das refeições nos arquivos
    fprintf(arquivoCSV, "12:00 - Dejejum\n");
    fprintf(arquivoTXT, "12:00 - Dejejum\n");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, dejejum, sizeof(dejejum) / sizeof(dejejum[0]));
    imprimirPlanoAlimentar(arquivoTXT, dejejum, sizeof(dejejum) / sizeof(dejejum[0]));

    fprintf(arquivoCSV, "14:00 - Almoco\n");
    fprintf(arquivoTXT, "14:00 - Almoco\n");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, almoco, sizeof(almoco) / sizeof(almoco[0]));
    imprimirPlanoAlimentar(arquivoTXT, almoco, sizeof(almoco) / sizeof(almoco[0]));

    fprintf(arquivoCSV, "18:30 - Lanche da tarde\n");
    fprintf(arquivoTXT, "18:30 - Lanche da tarde\n");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, lanche, sizeof(lanche) / sizeof(lanche[0]));
    imprimirPlanoAlimentar(arquivoTXT, lanche, sizeof(lanche) / sizeof(lanche[0]));

    fprintf(arquivoCSV, "22:00 - Ceia\n");
    fprintf(arquivoTXT, "22:00 - Ceia\n");
    totalCaloriasGeral += imprimirPlanoAlimentar(arquivoCSV, ceia, sizeof(ceia) / sizeof(ceia[0]));
    imprimirPlanoAlimentar(arquivoTXT, ceia, sizeof(ceia) / sizeof(ceia[0]));

    // Imprimir total geral de calorias
    fprintf(arquivoCSV, "Total Calorias Geral,%d Kcal\n", totalCaloriasGeral);
    fprintf(arquivoTXT, "Total Calorias Geral,%d Kcal\n", totalCaloriasGeral);

    // Imprimir lista de compras nos arquivos
    listaDeCompras(arquivoListaCSV, listaCompras, sizeof(listaCompras) / sizeof(listaCompras[0]));
    listaDeCompras(arquivoListaTXT, listaCompras, sizeof(listaCompras) / sizeof(listaCompras[0]));

    // Fechar os arquivos
    fclose(arquivoCSV);
    fclose(arquivoTXT);
    fclose(arquivoListaCSV);
    fclose(arquivoListaTXT);

    printf("Plano alimentar escrito em saida.csv e saida.txt com sucesso.\n");
    printf("Lista de compras escrita em lista.csv e lista.txt com sucesso.\n");

    return 0;
}
