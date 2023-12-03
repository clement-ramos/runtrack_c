#include <stdio.h>

void swap(int *a, int *b) {
    int buffer = *a;
    
    // swap values
    *a = *b;
    *b = buffer;
}

// int main() {
//     int x = 5;
//     int y = 10;

//     printf("Avant l'échange : x = %d, y = %d\n", x, y);

//     swap(&x, &y);

//     printf("Après l'échange : x = %d, y = %d\n", x, y);

//     return 0;
// }
