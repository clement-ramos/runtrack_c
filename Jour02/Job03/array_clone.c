#include <stdlib.h>
#include <string.h>

char** array_clone(char** input_array, int n) {
    if (input_array == NULL) {
        return NULL;
    }

    // memory allocation
    char** output_array = (char**)malloc((n + 1) * sizeof(char*));  // +1 pour le pointeur NULL à la fin

    // Check if the memory allocation succeeded
    if (output_array == NULL) {
        return NULL;
    }

    // Copy the strings from the input array to the output array
    int i;
    for (i = 0; i < n && input_array[i] != NULL; ++i) {
        // alloc memory for the string
        output_array[i] = (char*)malloc(strlen(input_array[i]) + 1);

        // Check if the memory allocation succeeded
        if (output_array[i] == NULL) {
            // In case of error, free the memory allocated so far
            for (int j = 0; j < i; ++j) {
                free(output_array[j]);
            }
            free(output_array);
            return NULL;
        }

        // copy the string from the input array to the output array
        strcpy(output_array[i], input_array[i]);
    }

    // 
    output_array[i] = NULL;

    return output_array;
}

// int main() {
//     char* input[] = {"Bonjour", "le", "monde", NULL};
//     int n = 2;
//     char** output = array_clone(input, n);
//     // do not forget to free the memory allocated
//     for (int i = 0; output[i] != NULL; ++i) {
//         free(output[i]);
//     }
//     free(output);
//     return 0;
// }
