#include <stdio.h>
// my_sqrt.c

int my_sqrt(int x) {
    // Special case: the square root of negative numbers is 0.
    if (x < 0) {
        return 0;
    }

    // Special case: the square root of 0 and 1 is 0 and 1, respectively.
    if (x == 0) {
        return 0;
    }

    // Linear search for the square root of x.
    int result = 1;
    while (result * result <= x) {
        if (result * result == x) {
            return result;
        }
        result++;
    }

    return 0;
}

// int main() {
//     int num = 16;  
//     int result = my_sqrt(num);
//     if (result != 0) {
//         printf("La racine carrée de %d est %d\n", num, result);
//     } else {
//         printf("La racine carrée de %d n'est pas un entier.\n", num);
//    
//     return 0;
// }
