#include <stdio.h>

void divide(int *num) {
    // Check if the pointer is NULL
    if (num != NULL) {
        *num = *num / 2;
    } else {
    
        printf("Erreur : pointeur NULL\n");
    }
}

// int main() {
//     int number = 10;
//     printf("Avant la division : %d\n", number);

//     divide(&number);

//     printf("Après la division : %d\n", number);

//     return 0;
// }
