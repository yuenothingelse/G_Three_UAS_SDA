#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/history.h"
#include "../include/menu.h"
#include "../include/globals.h"
#include "../include/search.h"
#include "../include/bst.h"
#include "../include/playlist.h"

int inputId()
{
    char buffer[100];

    fgets(buffer, sizeof(buffer), stdin);

    buffer[strcspn(buffer, "\n")] = 0;

    if(strlen(buffer) == 0)
    {
        printf("Input ID harus berupa angka!\n");
        return -1;
    }

    for(int i = 0; buffer[i] != '\0'; i++)
    {
        if(!isdigit(buffer[i]))
        {
            printf("Input ID harus berupa angka!\n");
            return -1;
        }
    }

    return atoi(buffer);
}

void addSongMenu(){

    int id;

    char title[100];
    char artist[100];

    printf("\nID : ");
id = inputId();

if(id == -1)
{
    return;
}

    if(
        searchById(
            catalogRoot,
            id
        )
    ){

        printf(
            "ID sudah ada\n"
        );

        return;
    }

    printf("Judul : ");
    fgets(title,100,stdin);
    title[strcspn(title,"\n")] = 0;

    printf("Artis : ");
    fgets(artist,100,stdin);
    artist[strcspn(artist,"\n")] = 0;

    catalogRoot =
        insertBST(
            catalogRoot,
            id,
            title,
            artist,
            0
        );

    printf(
        "Berhasil ditambah\n"
    );
}

void showCatalogMenu(){

    printf(
        "\n===== KATALOG =====\n"
    );

    printf(
        "\nID    JUDUL    ARTIS    PLAY\n\n"
    );

    inorder(catalogRoot);
}

void searchSongMenu(){

    char title[100];

    printf(
        "Judul : "
    );

    fgets(title,100,stdin);

    title[
        strcspn(
            title,
            "\n"
        )
    ] = 0;

    SongNode *song =
        searchByTitle(
            catalogRoot,
            title
        );

    if(song == NULL){

        printf(
            "Tidak ditemukan\n"
        );

        return;
    }

    printf(
        "\nID     : %d\n",
        song->id
    );

    printf(
        "Judul  : %s\n",
        song->title
    );

    printf(
        "Artis  : %s\n",
        song->artist
    );

    printf(
        "Played : %d\n",
        song->playCount
    );
}

void updateSongMenu(){

    int id;

    printf(
        "ID lagu : "
    );

    id = inputId();

if(id == -1)
{
    return;
}

    

    SongNode *song =
        searchById(
            catalogRoot,
            id
        );

    if(song == NULL){

        printf(
            "Tidak ditemukan\n"
        );

        return;
    }

    printf(
        "Judul Baru : "
    );

    fgets(
        song->title,
        100,
        stdin
    );

    song->title[
        strcspn(
            song->title,
            "\n"
        )
    ] = 0;

    printf(
        "Artis Baru : "
    );

    fgets(
        song->artist,
        100,
        stdin
    );

    song->artist[
        strcspn(
            song->artist,
            "\n"
        )
    ] = 0;

    printf(
        "Berhasil update\n"
    );
}

void deleteSongMenu(){

    int id;

    printf(
        "ID Lagu : "
    );

    id = inputId();

if(id == -1)
{
    return;
}

    

    SongNode *song =
        searchById(
            catalogRoot,
            id
        );

    if(song == NULL){

        printf(
            "Lagu tidak ditemukan\n"
        );

        return;
    } 

    
    //Hapus semua referensi
    

    removeFromPlaylist(id);

    removeFromHistory(id);

    
    //Hapus dari BST
    

    catalogRoot =
        deleteBST(
            catalogRoot,
            id
        );

    printf(
        "Lagu berhasil dihapus\n"
    );
}
void addPlaylistMenu(){

    int id;

    printf(
        "ID Lagu : "
    );

    id = inputId();

if(id == -1)
{
    return;
}

    SongNode *song =
        searchById(
            catalogRoot,
            id
        );

    if(song == NULL){

        printf(
            "Tidak ditemukan\n"
        );

        return;
    }

    addToPlaylist(id);

    printf(
        "Masuk playlist\n"
    );
}

void showStatisticsMenu(){

    printf(
        "\nGunakan menu Recommendation\n"
    );
}
