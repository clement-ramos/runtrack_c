#include <stdlib.h>
#include <string.h>  

typedef struct {
    char titre[100];
    char artiste[100];
} Album;

// Function to reallocate the memory of an array of albums
Album* realloc_album(Album* tableau, size_t taille_actuelle, size_t nouvelle_taille) {
    if (tableau == NULL || nouvelle_taille == 0) {
        return NULL;
    }

    Album* nouveau_tableau = (Album*)malloc(nouvelle_taille * sizeof(Album));
    if (nouveau_tableau == NULL) {
        return NULL;
    }

    // Copy the elements from the old array to the new one
    size_t elements_a_copier = (taille_actuelle < nouvelle_taille) ? taille_actuelle : nouvelle_taille;
    memcpy(nouveau_tableau, tableau, elements_a_copier * sizeof(Album));

    free(tableau);

    // Return the new array
    return nouveau_tableau;
}

// int main() {
//     size_t taille_actuelle = 5;
//     size_t nouvelle_taille = 10;

//     Album* tableau = (Album*)malloc(taille_actuelle * sizeof(Album));

//     tableau = realloc_album(tableau, taille_actuelle, nouvelle_taille);

//     free(tableau);

//     return 0;
// }
