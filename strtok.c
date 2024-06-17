#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "maça,banana,laranja,pera"; // String original
    char delimitador[] = ","; // Delimitador para separar os tokens
    char *token;

    // Obtém o primeiro token
    token = strtok(str, delimitador);

    // Continua obtendo os próximos tokens até que não haja mais
    while (token != NULL) {
        printf("%s\n", token); // Imprime o token
        token = strtok(NULL, delimitador); // Obtém o próximo token
    }

    return 0;
}
