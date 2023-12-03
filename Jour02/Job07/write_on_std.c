#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

// Convert a string to lowercase
char* toLowercase(const char* str) {
    int length = strlen(str);
    char* result = (char*)malloc(length + 1);  // +1 for the null character
    
    if (result == NULL) {
        perror("Erreur lors de l'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        result[i] = tolower(str[i]);
    }

    result[length] = '\0';  
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <chaine1> [<chaine2> ...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    for (int i = 1; i < argc; i++) {
        char* lowercaseStr = toLowercase(argv[i]);

        // Write the lowercase string to the standard output
        if (write(STDOUT_FILENO, lowercaseStr, strlen(lowercaseStr)) == -1) {
            perror("Erreur lors de l'écriture sur la sortie standard");
            exit(EXIT_FAILURE);
        }

        free(lowercaseStr);

        if (write(STDOUT_FILENO, "\n", 1) == -1) {
            perror("Erreur lors de l'écriture sur la sortie standard");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
