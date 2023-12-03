#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct of an album
typedef struct Album {
    char titre[100];
    char artiste[100];
    int annee;
    struct Album* suivant;
} Album;

// Strut of a list of albums
typedef struct AlbumList {
    Album* album;
    struct AlbumList* suivant;
} AlbumList;

// Function to add an album to the beginning of a list of albums
void push_front_album(AlbumList** list, Album* album) {
    AlbumList* nouvelElement = (AlbumList*)malloc(sizeof(AlbumList));

    if (nouvelElement == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    nouvelElement->album = album;

    nouvelElement->suivant = *list;
    *list = nouvelElement;
}

// int main() {

//     AlbumList* listeAlbums = NULL;

//     Album* album1 = (Album*)malloc(sizeof(Album));
//     strncpy(album1->titre, "Album1", sizeof(album1->titre) - 1);
//     album1->titre[sizeof(album1->titre) - 1] = '\0';
//     strncpy(album1->artiste, "Artiste1", sizeof(album1->artiste) - 1);
//     album1->artiste[sizeof(album1->artiste) - 1] = '\0';
//     album1->annee = 2000;

//     Album* album2 = (Album*)malloc(sizeof(Album));
//     strncpy(album2->titre, "Album2", sizeof(album2->titre) - 1);
//     album2->titre[sizeof(album2->titre) - 1] = '\0';
//     strncpy(album2->artiste, "Artiste2", sizeof(album2->artiste) - 1);
//     album2->artiste[sizeof(album2->artiste) - 1] = '\0';
//     album2->annee = 1995;

//     Album* album3 = (Album*)malloc(sizeof(Album));
//     strncpy(album3->titre, "Album3", sizeof(album3->titre) - 1);
//     album3->titre[sizeof(album3->titre) - 1] = '\0';
//     strncpy(album3->artiste, "Artiste3", sizeof(album3->artiste) - 1);
//     album3->artiste[sizeof(album3->artiste) - 1] = '\0';
//     album3->annee = 2022;

//     push_front_album(&listeAlbums, album1);
//     push_front_album(&listeAlbums, album2);
//     push_front_album(&listeAlbums, album3);

//     AlbumList* current = listeAlbums;
//     while (current != NULL) {
//         printf("Titre: %s, Artiste: %s, Année: %d\n", current->album->titre, current->album->artiste, current->album->annee);
//         current = current->suivant;
//     }
//     current = listeAlbums;
//     while (current != NULL) {
//         AlbumList* next = current->suivant;
//         free(current->album);
//         free(current);
//         current = next;
//     }

//     return 0;
// }
