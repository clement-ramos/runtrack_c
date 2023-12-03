#include <stdio.h>
#include <stdlib.h>

char* itoa_hex(int value) {
    if (value == 0) {
        char* result = (char*)malloc(2 * sizeof(char));
        if (result == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(EXIT_FAILURE);
        }
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // calc size of the resulting string
    int temp = value;
    int size = 0;
    while (temp != 0) {
        temp /= 16;
        size++;
    }

    char* result = (char*)malloc((size + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Build the string
    result[size] = '\0';
    while (value != 0) {
        int remainder = value % 16;
        char digit;
        if (remainder < 10) {
            digit = remainder + '0';
        } else {
            digit = remainder - 10 + 'A';
        }
        size--;
        result[size] = digit;
        value /= 16;
    }

    return result;
}

int main() {
    int num = 255;
    char* hex_str = itoa_hex(num);
    printf("La représentation hexadécimale de %d est : %s\n", num, hex_str);

    free(hex_str);

    return 0;
}
