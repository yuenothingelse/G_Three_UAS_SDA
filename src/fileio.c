#include <stdio.h>

#include "../include/fileio.h"
#include "../include/bst.h"

static FILE *fp;


//SAVE

static void writeData(
    SongNode *root
){

    if(root == NULL)
        return;

    writeData(root->left);

    fprintf(
        fp,
        "%d|%s|%s|%d\n",
        root->id,
        root->title,
        root->artist,
        root->playCount
    );

    writeData(root->right);
}

void saveSongs(
    SongNode *root
){

    fp =
        fopen(
            "data/songs.txt",
            "w"
        );

    if(fp == NULL){

        printf(
            "Gagal save file\n"
        );

        return;
    }

    writeData(root);

    fclose(fp);
}


//LOAD


SongNode* loadSongs(
    SongNode *root
){

    fp =
        fopen(
            "data/songs.txt",
            "r"
        );

    if(fp == NULL)
        return root;

    int id;
    int playCount;

    char title[100];
    char artist[100];

    while(
        fscanf(
            fp,
            "%d|%99[^|]|%99[^|]|%d\n",
            &id,
            title,
            artist,
            &playCount
        ) == 4
    ){

        root =
            insertBST(
                root,
                id,
                title,
                artist,
                playCount
            );
    }

    fclose(fp);

    return root;
}
