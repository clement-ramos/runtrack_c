#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Struct for an album
typedef struct Album {
    char artiste[50];
    char titre[50];
    int annee;
    struct Album *next;
} Album;

// Function to create an album
Album* create_album(const char* artiste, const char* titre, int annee) {
    Album *nouvelAlbum = (Album*)malloc(sizeof(Album));

    if (nouvelAlbum == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire pour l'album.\n");
        exit(EXIT_FAILURE);
    }

    // Init the album fields
    strncpy(nouvelAlbum->artiste, artiste, sizeof(nouvelAlbum->artiste) - 1);
    nouvelAlbum->artiste[sizeof(nouvelAlbum->artiste) - 1] = '\0'; 
    strncpy(nouvelAlbum->titre, titre, sizeof(nouvelAlbum->titre) - 1);
    nouvelAlbum->titre[sizeof(nouvelAlbum->titre) - 1] = '\0'; // 
    nouvelAlbum->annee = annee;
    nouvelAlbum->next = NULL; // Initi the next pointer to NULL

    return nouvelAlbum;
}

// int main() {
//     Album* monAlbum = create_album("Artiste 1", "Titre 1", 2023);

//     free(monAlbum);

//     return 0;
// }
