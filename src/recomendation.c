#include <stdio.h>

#include "../include/recommendation.h"

static SongNode *songList[1000];
static int totalSongs;


//BST TO ARRAY

static void copySongs(
    SongNode *root
){

    if(root == NULL)
        return;

    copySongs(root->left);

    songList[totalSongs++] =
        root;

    copySongs(root->right);
}

//BUBBLE SORT

static void sortRecommendation(){

    for(
        int i=0;
        i<totalSongs-1;
        i++
    ){

        for(
            int j=0;
            j<totalSongs-i-1;
            j++
        ){

            if(
                songList[j]->playCount <
                songList[j+1]->playCount
            ){

                SongNode *temp =
                    songList[j];

                songList[j] =
                    songList[j+1];

                songList[j+1] =
                    temp;
            }
        }
    }
}

//TOP SONGS

void generateRecommendation(
    SongNode *root
){

    totalSongs = 0;

    copySongs(root);

    if(totalSongs == 0){

        printf(
            "Belum ada lagu\n"
        );

        return;
    }

    sortRecommendation();

    printf(
        "\n===== TOP RECOMMENDATION =====\n"
    );

    int limit =
        totalSongs > 5 ?
        5 :
        totalSongs;

    for(
        int i=0;
        i<limit;
        i++
    ){

        printf(
            "\n%d.\n",
            i+1
        );

        printf(
            "ID     : %d\n",
            songList[i]->id
        );

        printf(
            "Judul  : %s\n",
            songList[i]->title
        );

        printf(
            "Artis  : %s\n",
            songList[i]->artist
        );

        printf(
            "Played : %d\n",
            songList[i]->playCount
        );
    }
}
