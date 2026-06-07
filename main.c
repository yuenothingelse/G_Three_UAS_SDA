#include <stdio.h>

#include "include/globals.h"
#include "include/bst.h"
#include "include/playlist.h"
#include "include/history.h"
#include "include/recommendation.h"
#include "include/fileio.h"
#include "include/menu.h"

SongNode *catalogRoot = NULL;

int main(){

    int choice;

    catalogRoot =
        loadSongs(
            catalogRoot
        );

    do{

        printf(
        "\n===========================\n");
        printf(
        "    DRAG MUSIC SYSTEM\n");
        printf(
        "===========================\n");

        printf("1. Tambah Lagu\n");
        printf("2. Lihat Katalog\n");
        printf("3. Cari Lagu\n");
        printf("4. Edit Lagu\n");
        printf("5. Hapus Lagu\n");
        printf("6. Tambah Playlist\n");
        printf("7. Lihat Playlist\n");
        printf("8. Next Track\n");
        printf("9. Previous Track\n");
        printf("10. History\n");
        printf("11. Recommendation\n");
        printf("0. Exit\n");

        printf("\nPilihan : ");

        scanf(
            "%d",
            &choice
        );

        getchar();

        switch(choice){

        case 1:
            addSongMenu();
            break;

        case 2:
            showCatalogMenu();
            break;

        case 3:
            searchSongMenu();
            break;

        case 4:
            updateSongMenu();
            break;

        case 5:
            deleteSongMenu();
            break;

        case 6:
            addPlaylistMenu();
            break;

        case 7:
            showPlaylist();
            break;

        case 8:
            nextTrack();
            break;

        case 9:
            previousTrack();
            break;

        case 10:
            showHistory();
            break;

        case 11:
            generateRecommendation(
                catalogRoot
            );
            break;
        }

    }while(choice != 0);

    saveSongs(
        catalogRoot
    );

    freeBST(
        catalogRoot
    );

    freePlaylist();
    freeHistory();

    return 0;
}