#include <stdio.h>

int char_is_digit(char c);

int str_is_digit(const char *str) {
    while (*str != '\0') {
        if (!char_is_digit(*str)) {
            return 0; // Si un caractère n'est pas un chiffre, retourne 0
        }
        str++;
    }
    return 1; // Si tous les caractères sont des chiffres, retourne 1
}

// int main() {
//     // Test de char_is_digit
//     char testChar = '5';
//     if (char_is_digit(testChar)) {
//         printf("%c est un chiffre.\n", testChar);
//     } else {
//         printf("%c n'est pas un chiffre.\n", testChar);
//     }

//     // Test de str_is_digit
//     const char *testStr1 = "12345";
//     if (str_is_digit(testStr1)) {
//         printf("%s ne contient que des chiffres.\n", testStr1);
//     } else {
//         printf("%s ne contient pas que des chiffres.\n", testStr1);
//     }

//     const char *testStr2 = "abc123";
//     if (str_is_digit(testStr2)) {
//         printf("%s ne contient que des chiffres.\n", testStr2);
//     } else {
//         printf("%s ne contient pas que des chiffres.\n", testStr2);
//     }

//     return 0;
// }
