#include <stdio.h>

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

// int main() {
//     const char *str1 = "abc";
//     const char *str2 = "abd";

//     int result = my_strcmp(str1, str2);

//     if (result == 0) {
//         printf("Les chaînes sont identiques.\n");
//     } else if (result < 0) {
//         printf("La première chaîne est inférieure à la deuxième.\n");
//     } else {
//         printf("La première chaîne est supérieure à la deuxième.\n");
//     }

//     return 0;
// }
