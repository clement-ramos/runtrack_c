#include <stdio.h>
#include <stdlib.h>

// Function to get the length of an integer
int getLength(int num) {
    int length = 0;
    if (num == 0) {
        return 1; // Handle the case of 0
    }
    while (num != 0) {
        num /= 10;
        length++;
    }
    return length;
}

// Function to convert an integer to a string
char* my_itoa(int num) {
    int length = getLength(num);

    // Handle the case of negative number
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        length++;
        num = -num;
    }

    char* str = (char*)malloc(length + 1);

    // Check if the allocation was successful
    if (str != NULL) {
        // Add the sign if necessary
        if (isNegative) {
            str[0] = '-';
        }

        // Convert the integer to a string
        int i = length - 1;
        do {
            str[i--] = num % 10 + '0';
            num /= 10;
        } while (num != 0);

        str[length] = '\0';
    }

    return str;
}

// int main() {
//     int number = -12345;
//     char* result = my_itoa(number);

//     if (result != NULL) {
//         printf("Integer: %d\nString: %s\n", number, result);
//         free(result); 
//     } else {
//         printf("Erreur d'allocation de mémoire\n");
//     }

//     return 0;
// }
