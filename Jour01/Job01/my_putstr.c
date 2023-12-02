
void my_putchar(char c);

void my_putstr(const char *str) {
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
}

// void main () {
//     my_putstr("Hello World!\n");
// }