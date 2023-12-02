#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

char** split(const char* input) {
    // Allocation mémoire pour le tableau de pointeurs de chaînes de caractères
    char** result = (char**)malloc(MAX_STR_LEN * sizeof(char*));
    if (result == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Copie de la chaîne d'entrée pour ne pas la modifier
    char* input_copy = strdup(input);
    if (input_copy == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Utilisation de strtok pour séparer la chaîne en mots
    char* token = strtok(input_copy, " \t\n");
    int i = 0;

    // Boucle pour remplir le tableau de pointeurs
    while (token != NULL) {
        result[i] = strdup(token);
        if (result[i] == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(EXIT_FAILURE);
        }
        i++;
        token = strtok(NULL, " \t\n");
    }

    // Ajout d'un pointeur NULL à la fin du tableau
    result[i] = NULL;

    // Libération de la mémoire utilisée pour la copie de la chaîne
    free(input_copy);

    return result;
}

// int main() {
//     const char* input = "hello world have fun";
//     char** result = split(input);

//     // Affichage du résultat
//     for (int i = 0; result[i] != NULL; i++) {
//         printf("%s\n", result[i]);
//         free(result[i]); // Libération de la mémoire allouée pour chaque sous-chaîne
//     }

//     // Libération de la mémoire allouée pour le tableau de pointeurs
//     free(result);

//     return 0;
// }
