# include <stdio.h>


int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

// void main()
// {
//     char *str = "Hello World!\n";
//     printf("%d\n", my_strlen(str));
// }