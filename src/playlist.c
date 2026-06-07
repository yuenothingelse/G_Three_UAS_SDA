#include <stdio.h>
#include <stdlib.h>

#include "../include/playlist.h"
#include "../include/search.h"
#include "../include/history.h"
#include "../include/globals.h"

PlaylistNode *playlistHead = NULL;
PlaylistNode *playlistTail = NULL;
PlaylistNode *currentTrack = NULL;

//ADD PLAYLIST

void addToPlaylist(
    int songId
){

    PlaylistNode *newNode =
        (PlaylistNode*)malloc(
            sizeof(
                PlaylistNode
            )
        );

    newNode->songId =
        songId;

    newNode->next = NULL;
    newNode->prev = NULL;

    if(playlistHead == NULL){

        playlistHead =
        playlistTail =
            newNode;

        currentTrack =
            playlistHead;

        return;
    }

    playlistTail->next =
        newNode;

    newNode->prev =
        playlistTail;

    playlistTail =
        newNode;
}

//SHOW PLAYLIST

void showPlaylist(){

    PlaylistNode *temp =
        playlistHead;

    printf(
        "\n===== PLAYLIST =====\n"
    );

    if(temp == NULL){

        printf(
            "Playlist kosong\n"
        );

        return;
    }

    while(temp){

        SongNode *song =
            searchById(
                catalogRoot,
                temp->songId
            );

        if(song){

            printf(
                "%d | %s | %s\n",
                song->id,
                song->title,
                song->artist
            );
        }

        temp =
            temp->next;
    }
}

//NEXT TRACK

void nextTrack(){

    if(currentTrack == NULL){

        printf(
            "Playlist kosong\n"
        );

        return;
    }

    SongNode *song =
        searchById(
            catalogRoot,
            currentTrack->songId
        );

    if(song){

        song->playCount++;

        pushHistory(
            song->id
        );

        printf(
            "\nNow Playing\n"
        );

        printf(
            "ID     : %d\n",
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

    if(currentTrack->next){

        currentTrack =
            currentTrack->next;
    }
}

//PREVIOUS TRACK

void previousTrack(){

    if(
        currentTrack == NULL
    ){

        printf(
            "Playlist kosong\n"
        );

        return;
    }

    if(
        currentTrack->prev == NULL
    ){

        printf(
            "Tidak ada lagu sebelumnya\n"
        );

        return;
    }

    currentTrack =
        currentTrack->prev;

    SongNode *song =
        searchById(
            catalogRoot,
            currentTrack->songId
        );

    if(song){

        printf(
            "\nPrevious Track\n"
        );

        printf(
            "%s - %s\n",
            song->title,
            song->artist
        );
    }
}

//FREE PLAYLIST

void freePlaylist(){

    PlaylistNode *temp;

    while(playlistHead){

        temp =
            playlistHead;

        playlistHead =
            playlistHead->next;

        free(temp);
    }
}

//REMOVE

void removeFromPlaylist(int songId)
{
    PlaylistNode *curr = playlistHead;

    while(curr)
    {
        PlaylistNode *next = curr->next;

        if(curr->songId == songId)
        {
            if(currentTrack == curr)
            {
                if(curr->next)
                    currentTrack = curr->next;
                else
                    currentTrack = curr->prev;
            }

            if(curr == playlistHead)
            {
                playlistHead = curr->next;

                if(playlistHead)
                    playlistHead->prev = NULL;
            }

            if(curr == playlistTail)
            {
                playlistTail = curr->prev;

                if(playlistTail)
                    playlistTail->next = NULL;
            }

            if(curr->prev)
                curr->prev->next = curr->next;

            if(curr->next)
                curr->next->prev = curr->prev;

            free(curr);
        }

        curr = next;
    }

    if(playlistHead == NULL)
    {
        playlistTail = NULL;
        currentTrack = NULL;
    }
}
