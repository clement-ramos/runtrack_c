#include <stdlib.h>
#include <string.h>

void delete_str_array(char ***str_array) {
    if (str_array == NULL || *str_array == NULL) {
        return;  
    }

    char **array = *str_array;

    // Release the memory allocated for each string
    for (int i = 0; array[i] != NULL; ++i) {
        free(array[i]);
    }

    // Release the memory allocated for the array
    free(array);

    // Put the pointer to NULL
    *str_array = NULL;
}

// int main() {
//     char **str_array = (char **)malloc(4 * sizeof(char *));  

//     // Allocation dynamique pour chaque chaîne de caractères
//     str_array[0] = strdup("Premiere chaine");
//     str_array[1] = strdup("Deuxieme chaine");
//     str_array[2] = strdup("Troisieme chaine");
//     str_array[3] = NULL;  

//     delete_str_array(&str_array);

//     return 0;
// }
