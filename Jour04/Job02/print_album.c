#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct album {
    char *title;
    char *artist;
    int year;
} t_album;

void print_album(t_album *album_ptr) {
    char buffer[100];
    int length = snprintf(buffer, sizeof(buffer), "\"%s\" by \"%s\" released in %d.\n",
                          album_ptr->title, album_ptr->artist, album_ptr->year);
    write(1, buffer, length);
}

// int main() {
//     // alloc dynamic memory for the struct
//     t_album my_album;
//     my_album.title = strdup("Master of Puppets");
//     my_album.artist = strdup("Metallica");
//     my_album.year = 1986;

//     print_album(&my_album);

//     // Free the memory allocated for the struct
//     free(my_album.title);
//     free(my_album.artist);

//     return 0;
// }
