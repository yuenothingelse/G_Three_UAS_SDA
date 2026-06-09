#ifndef HISTORY_H
#define HISTORY_H

#include "song.h"

extern StackNode *historyTop;

void pushHistory(int songId);

void removeFromHistory(int songId);

void showHistory();

void freeHistory();

#endif
