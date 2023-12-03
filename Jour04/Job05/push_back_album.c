#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct of an album
typedef struct {
    char titre[50];
    char artiste[50];
    int annee;
} t_album;

// Struct of a list of albums
typedef struct t_album_list {
    t_album album;
    struct t_album_list* suivant;
} t_album_list;

// Function to add an album to the end of a list of albums
void push_back_album(t_album_list* list, t_album_list* album) {
    t_album_list* copieAlbum = (t_album_list*)malloc(sizeof(t_album_list));

    if (copieAlbum == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }

    memcpy(&copieAlbum->album, & album->album, sizeof(t_album));

    // The next pointer of the new element is NULL
    copieAlbum->suivant = NULL;

    // id is empty, so the new element is the first one
    if (list == NULL) {
        list = copieAlbum;
    } else {
        // Else, we add the new element at the end of the list
        t_album_list* dernierAlbum = list;
        while (dernierAlbum->suivant != NULL) {
            dernierAlbum = dernierAlbum->suivant;
        }
        dernierAlbum->suivant = copieAlbum;
    }
}

// int main() {
//     t_album_list* maListe = NULL;

//     t_album_list nouvelAlbum;
//     strcpy(nouvelAlbum.album.titre, "Nom de l'album");
//     strcpy(nouvelAlbum.album.artiste, "Nom de l'artiste");
//     nouvelAlbum.album.annee = 2023;
//     nouvelAlbum.suivant = NULL;

//     push_back_album(maListe, &nouvelAlbum);

//     t_album_list* current = maListe;
//     while (current != NULL) {
//         t_album_list* temp = current;
//         current = current->suivant;
//         free(temp);
//     }

//     return 0;
// }
