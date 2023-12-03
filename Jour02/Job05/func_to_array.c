#include <stdio.h>
#include <string.h>
#include <ctype.h>

void func_to_array(char *strings[], void (*func)(char*));

// To upper case
void strtoupper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// To lower case
void strtolower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Print string
void my_putstr(char *str) {
    printf("%s\n", str);
}

// Apply a function to each string in an array
void func_to_array(char *strings[], void (*func)(char*)) {
    for (int i = 0; strings[i] != NULL; i++) {
        func(strings[i]);
    }
}

// int main() {
//     char str1[] = "Hello";
//     char str2[] = "World";
//     char str3[] = "C";
//     char str4[] = "Programming";

//     char *strings[] = {str1, str2, str3, str4};

//     printf("Original strings:\n");
//     func_to_array(strings, my_putstr);

//     printf("\nAfter strtoupper:\n");
//     func_to_array(strings, strtoupper);
//     func_to_array(strings, my_putstr);

//     printf("\nAfter strtolower:\n");
//     func_to_array(strings, strtolower);
//     func_to_array(strings, my_putstr);

//     return 0;
// }
