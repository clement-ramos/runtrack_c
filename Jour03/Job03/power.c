#include <stdio.h>

int power(int base, int exponent) {
    int result = 1;

    while (exponent > 0) {
        result *= base;
        exponent--;
    }

    return result;
}

// int main() {
//     // Exemple d'utilisation
//     int base = 3;
//     int exponent = 3;
//     int result = power(base, exponent);

//     printf("%d ^ %d = %d\n", base, exponent, result);

//     return 0;
// }
