#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to compare strings
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to trim whitespace from a string
char *trim(char *str) {
    while (*str == ' ' || *str == '\t') {
        str++;
    }

    int len = strlen(str);
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) {
        len--;
    }

    str[len] = '\0';
    return str;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <mot1> <mot2> ... <motN>\n", argv[0]);
        return 1;
    }

    char **words = (char **)malloc((argc - 1) * sizeof(char *));
    if (words == NULL) {
        perror("Allocation mémoire échouée");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        words[i - 1] = trim(strdup(argv[i]));
    }

    qsort(words, argc - 1, sizeof(char *), compare);

    for (int i = 0; i < argc - 1; i++) {
        printf("%s", words[i]);
        if (i < argc - 2) {
            printf(" ");
        }
    }
    printf("\n");

    for (int i = 0; i < argc - 1; i++) {
        free(words[i]);
    }
    free(words);

    return 0;
}
