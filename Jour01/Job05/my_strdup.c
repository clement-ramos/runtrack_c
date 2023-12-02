#include <stdlib.h>
#include <string.h>

char* my_strdup(const char* source) {
    // Vérifier si la chaîne source n'est pas NULL
    if (source == NULL) {
        return NULL;
    }

    // Allouer de la mémoire pour la nouvelle chaîne
    size_t length = strlen(source);
    char* destination = (char*)malloc((length + 1) * sizeof(char));

    // Vérifier si l'allocation de mémoire a réussi
    if (destination == NULL) {
        return NULL; // Échec de l'allocation
    }

    // Copier la chaîne source dans la nouvelle mémoire allouée
    strcpy(destination, source);

    return destination;
}

// int main() {
//     const char* original = "Hello, World!";
//     char* duplicate = my_strdup(original);

//     if (duplicate != NULL) {
//         printf("Original: %s\n", original);
//         printf("Duplicate: %s\n", duplicate);

//         // N'oubliez pas de libérer la mémoire allouée
//         free(duplicate);
//     } else {
//         printf("Erreur d'allocation de mémoire.\n");
//     }

//     return 0;
// }