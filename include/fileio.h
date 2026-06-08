#ifndef FILEIO_H
#define FILEIO_H

#include "bst.h"

SongNode* loadSongs(
    SongNode *root
);

void saveSongs(
    SongNode *root
);

#endif 
