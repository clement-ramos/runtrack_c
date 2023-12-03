#include "../../Jour01/Job06/my_strcmp.h"
#include <stdio.h>

void bubbleSort(char *arr[]) {
    int i, j;
    char *temp;

    // calc size of array
    int size = 0;
    while (arr[size] != NULL) {
        size++;
    }

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            // Comapre in ASCII order
            if (my_strcmp(arr[j], arr[j + 1]) > 0) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// int main() {
//     char *strings[] = {"banana", "apple", "orange", "grape", NULL};

//     bubbleSort(strings);

//     printf("Tableau trié :\n");
//     for (int i = 0; strings[i] != NULL; i++) {
//         printf("%s\n", strings[i]);
//     }

//     return 0;
// }