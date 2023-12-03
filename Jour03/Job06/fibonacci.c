#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int n = atoi(argv[1]);
        if (n >= 0) {
            int result = fibonacci(n);
            printf("Le %d-ème nombre de la suite de Fibonacci est : %d\n", n, result);
        } else {
            fprintf(stderr, "Veuillez entrer un entier positif.\n");
            return 1;
        }
    }
    return 0;
}
