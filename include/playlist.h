#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"

extern PlaylistNode *playlistHead;
extern PlaylistNode *playlistTail;
extern PlaylistNode *currentTrack;

void addToPlaylist(int songId);

void removeFromPlaylist(int songId);

void showPlaylist();

void nextTrack();

void previousTrack();

void freePlaylist();

#endif
