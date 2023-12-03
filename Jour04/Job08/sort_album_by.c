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

// Struct of a list of albums
typedef struct AlbumList {
    Album* album;
    struct AlbumList* suivant;
} AlbumList;

// Function to delete an album from a list of albums
int compare_by_year(const void* a, const void* b) {
    const Album* albumA = *(const Album**)a;
    const Album* albumB = *(const Album**)b;
    return albumA->annee - albumB->annee;
}

// Function to sort a list of albums
void sort_album_by(AlbumList** list, int (*comparer)(const void*, const void*)) {
    // find the number of albums in the list
    size_t count = 0;
    AlbumList* current = *list;
    while (current != NULL) {
        count++;
        current = current->suivant;
    }

    // Create a dynamic array of pointers to albums
    Album** albumsArray = (Album**)malloc(count * sizeof(Album*));
    if (albumsArray == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Fill the array with the albums from the list
    current = *list;
    size_t index = 0;
    while (current != NULL) {
        albumsArray[index++] = current->album;
        current = current->suivant;
    }

    // Sort the array with the qsort function
    qsort(albumsArray, count, sizeof(Album*), comparer);

    // Rebuid the list with the sorted albums
    *list = NULL;
    for (size_t i = 0; i < count; i++) {
        AlbumList* nouvelElement = (AlbumList*)malloc(sizeof(AlbumList));
        if (nouvelElement == NULL) {
            fprintf(stderr, "Erreur d'allocation mémoire\n");
            exit(EXIT_FAILURE);
        }

        nouvelElement->album = albumsArray[i];
        nouvelElement->suivant = *list;
        *list = nouvelElement;
    }

    free(albumsArray);
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

//     listeAlbums = (AlbumList*)malloc(sizeof(AlbumList));
//     listeAlbums->album = album1;
//     listeAlbums->suivant = (AlbumList*)malloc(sizeof(AlbumList));
//     listeAlbums->suivant->album = album2;
//     listeAlbums->suivant->suivant = (AlbumList*)malloc(sizeof(AlbumList));
//     listeAlbums->suivant->suivant->album = album3;
//     listeAlbums->suivant->suivant->suivant = NULL;

//     printf("Avant le tri :\n");
//     AlbumList* current = listeAlbums;
//     while (current != NULL) {
//         printf("Titre: %s, Artiste: %s, Année: %d\n", current->album->titre, current->album->artiste, current->album->annee);
//         current = current->suivant;
//     }

//     sort_album_by(&listeAlbums, compare_by_year);

//     printf("\nAprès le tri par année décroissante :\n");
//     current = listeAlbums;
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