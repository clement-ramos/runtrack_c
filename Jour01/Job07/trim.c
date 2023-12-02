#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* trim(const char* source) {
    // Vérifier si la chaîne source est nulle
    if (source == NULL) {
        return NULL;
    }

    // Ignorer les espaces au début de la chaîne
    while (*source == ' ' || *source == '\t' || *source == '\n') {
        source++;
    }

    // Si la chaîne est composée uniquement d'espaces, retourner une chaîne vide
    if (*source == '\0') {
        char* result = malloc(1);
        if (result == NULL) {
            // Gestion de l'échec de l'allocation mémoire
            perror("Allocation failed");
            exit(EXIT_FAILURE);
        }
        *result = '\0';
        return result;
    }

    // Ignorer les espaces à la fin de la chaîne
    const char* end = source + strlen(source) - 1;
    while (end > source && (*end == ' ' || *end == '\t' || *end == '\n')) {
        end--;
    }

    // Calculer la longueur de la nouvelle chaîne
    size_t length = end - source + 1;

    // Allouer de la mémoire pour la nouvelle chaîne
    char* result = malloc(length + 1);
    if (result == NULL) {
        // Gestion de l'échec de l'allocation mémoire
        perror("Allocation failed");
        exit(EXIT_FAILURE);
    }

    // Copier la chaîne sans les espaces inutiles
    strncpy(result, source, length);
    result[length] = '\0'; // Ajouter le caractère de fin de chaîne

    return result;
}

// int main() {
//     const char* input = "  hello world  ";
//     char* trimmed = trim(input);

//     printf("Original: \"%s\"\n", input);
//     printf("Trimmed : \"%s\"\n", trimmed);

//     // N'oubliez pas de libérer la mémoire allouée
//     free(trimmed);

//     return 0;
// }
