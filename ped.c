#include <stdio.h>
#include <stdlib.h>

// Define the Alimento structure
typedef struct {
    char nome[51];
    float quantidade;
    char Kcal[6];
} Alimento;

// Function to print the food plan and calculate total calories
int imprimirPlanoAlimentar(Alimento *refeicao, int tamanho, const char *nomeRefeicao, FILE *fp_csv, FILE *fp_txt) {
    fprintf(fp_csv, "%s\n", nomeRefeicao);
    fprintf(fp_txt, "%s\n", nomeRefeicao);

    int totalCalorias = 0;

    for (int i = 0; i < tamanho; i++) {
        fprintf(fp_csv, "%s,%f,%s\n", refeicao[i].nome, refeicao[i].quantidade, refeicao[i].Kcal);
        fprintf(fp_txt, "%s %f %s\n", refeicao[i].nome, refeicao[i].quantidade, refeicao[i].Kcal);
        totalCalorias += atoi(refeicao[i].Kcal);
    }

    fprintf(fp_csv, "Total Calorias,%d\n", totalCalorias);
    fprintf(fp_txt, "Total Calorias %d\n", totalCalorias);

    return totalCalorias;
}

int main() {
    FILE *fp_csv = fopen("saida.csv", "w");
    FILE *fp_txt = fopen("saida.txt", "w");

    if (fp_csv == NULL || fp_txt == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Example usage with one meal (Dejejum)
    Alimento dejejum[] = {
        {"Banana", 125, "124"},
        {"Aveia em flocos", 30, "118"},
        // Add other foods here...
    };
    
    int tamanhoDejejum = sizeof(dejejum) / sizeof(dejejum[0]);
    
    // Initialize totalCaloriasGeral
    int totalCaloriasGeral = 0;
    
    // Print header for the plan
    fprintf(fp_csv, "            Plano Alimentar\n");
    fprintf(fp_txt, "            Plano Alimentar\n");

    // Process each meal and update totalCaloriasGeral
    totalCaloriasGeral += imprimirPlanoAlimentar(dejejum, tamanhoDejejum, "12:00 - Dejejum", fp_csv, fp_txt);
    
    // Add other meals here...

    // Print general total of calories at the end
    fprintf(fp_csv, "Total Calorias Geral,%d\n", totalCaloriasGeral);
    fprintf(fp_txt, "Total Calorias Geral %d\n", totalCaloriasGeral);

    fclose(fp_csv);
    fclose(fp_txt);

    return 0;
}
