#ifndef SONG_H
#define SONG_H

typedef struct SongNode{

    int id;
    char title[100];
    char artist[100];
    int playCount;

    struct SongNode *left;
    struct SongNode *right;

} SongNode;

typedef struct PlaylistNode{

    int songId;

    struct PlaylistNode *next;
    struct PlaylistNode *prev;

} PlaylistNode;

typedef struct StackNode{

    int songId;

    struct StackNode *next;

} StackNode;

#endif
