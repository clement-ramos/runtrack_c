#include <stdio.h>

int my_atoi(const char *str) {
    int result = 0;
    int sign = 1; // 1 for positive, -1 for negative

    // Ignore Spaces
    while (*str == ' ') {
        str++;
    }

    // Handle the sign
    if (*str == '-' || *str == '+') {
        sign = (*str == '-') ? -1 : 1;
        str++;
    }

    // CConvert string to integer
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    // Apply the sign
    return sign * result;
}

// int main() {
//     const char *str = "   -12345";
//     int result = my_atoi(str);

//     printf("La conversion de la chaîne '%s' donne : %d\n", str, result);

//     return 0;
// }
