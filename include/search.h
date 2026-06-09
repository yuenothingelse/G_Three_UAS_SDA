#ifndef SEARCH_H
#define SEARCH_H

#include "song.h"

SongNode* searchById(
    SongNode *root,
    int id
);

SongNode* searchByTitle(
    SongNode *root,
    char title[]
);

#endif