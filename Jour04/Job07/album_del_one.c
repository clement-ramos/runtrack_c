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
void album_del_one(AlbumList** list, Album* album) {
    if (*list != NULL && (*list)->album == album) {
        AlbumList* temp = *list;
        *list = (*list)->suivant;
        free(temp->album);
        free(temp);
        return;
    }
    // Search for the album in the list
    AlbumList* current = *list;
    AlbumList* previous = NULL;

    while (current != NULL && current->album != album) {
        previous = current;
        current = current->suivant;
    }

    // if isn't in the list
    if (current == NULL) {
        return;
    }

    previous->suivant = current->suivant;
    free(current->album);
    free(current);
}

int main() {
    AlbumList* listeAlbums = NULL;

    Album* album1 = (Album*)malloc(sizeof(Album));
    strncpy(album1->titre, "Album1", sizeof(album1->titre) - 1);
    album1->titre[sizeof(album1->titre) - 1] = '\0';
    strncpy(album1->artiste, "Artiste1", sizeof(album1->artiste) - 1);
    album1->artiste[sizeof(album1->artiste) - 1] = '\0';
    album1->annee = 2000;

    Album* album2 = (Album*)malloc(sizeof(Album));
    strncpy(album2->titre, "Album2", sizeof(album2->titre) - 1);
    album2->titre[sizeof(album2->titre) - 1] = '\0';
    strncpy(album2->artiste, "Artiste2", sizeof(album2->artiste) - 1);
    album2->artiste[sizeof(album2->artiste) - 1] = '\0';
    album2->annee = 1995;

    Album* album3 = (Album*)malloc(sizeof(Album));
    strncpy(album3->titre, "Album3", sizeof(album3->titre) - 1);
    album3->titre[sizeof(album3->titre) - 1] = '\0';
    strncpy(album3->artiste, "Artiste3", sizeof(album3->artiste) - 1);
    album3->artiste[sizeof(album3->artiste) - 1] = '\0';
    album3->annee = 2022;

    listeAlbums = (AlbumList*)malloc(sizeof(AlbumList));
    listeAlbums->album = album1;
    listeAlbums->suivant = (AlbumList*)malloc(sizeof(AlbumList));
    listeAlbums->suivant->album = album2;
    listeAlbums->suivant->suivant = (AlbumList*)malloc(sizeof(AlbumList));
    listeAlbums->suivant->suivant->album = album3;
    listeAlbums->suivant->suivant->suivant = NULL;

    printf("Avant la suppression :\n");
    AlbumList* current = listeAlbums;
    while (current != NULL) {
        printf("Titre: %s, Artiste: %s, Année: %d\n", current->album->titre, current->album->artiste, current->album->annee);
        current = current->suivant;
    }

    album_del_one(&listeAlbums, album2);

    printf("\nAprès la suppression de l'album2 :\n");
    current = listeAlbums;
    while (current != NULL) {
        printf("Titre: %s, Artiste: %s, Année: %d\n", current->album->titre, current->album->artiste, current->album->annee);
        current = current->suivant;
    }

    current = listeAlbums;
    while (current != NULL) {
        AlbumList* next = current->suivant;
        free(current->album);
        free(current);
        current = next;
    }

    return 0;
}
