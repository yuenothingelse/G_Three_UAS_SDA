#ifndef BST_H
#define BST_H

#include "song.h"

SongNode* createSong(
    int id,
    char title[],
    char artist[],
    int playCount
);

SongNode* insertBST(
    SongNode *root,
    int id,
    char title[],
    char artist[],
    int playCount
);

SongNode* deleteBST(
    SongNode *root,
    int id
);

void inorder(
    SongNode *root
);

void freeBST(
    SongNode *root
);

#endif