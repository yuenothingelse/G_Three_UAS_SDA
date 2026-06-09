#include <stdio.h>
#include <stdlib.h>

#include "../include/history.h"
#include "../include/search.h"
#include "../include/globals.h"

StackNode *historyTop = NULL;


//PUSH HISTORY


void pushHistory(
    int songId
){

    StackNode *newNode =
        (StackNode*)malloc(
            sizeof(StackNode)
        );

    newNode->songId =
        songId;

    newNode->next =
        historyTop;

    historyTop =
        newNode;
}

//REMOVE FROM HISTORY


void removeFromHistory(
    int songId
){

    StackNode *curr =
        historyTop;

    StackNode *prev =
        NULL;

    while(curr){

        if(curr->songId == songId){

            StackNode *temp =
                curr;

            if(prev == NULL){

                historyTop =
                    curr->next;

                curr =
                    historyTop;
            }
            else{

                prev->next =
                    curr->next;

                curr =
                    curr->next;
            }

            free(temp);

            continue;
        }

        prev = curr;
        curr = curr->next;
    }
}

//SHOW HISTORY

void showHistory(){

    StackNode *temp =
        historyTop;

    printf(
        "\n===== HISTORY =====\n"
    );

    if(temp == NULL){

        printf(
            "Belum ada history\n"
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


//FREE HISTORY


void freeHistory(){

    StackNode *temp;

    while(historyTop){

        temp =
            historyTop;

        historyTop =
            historyTop->next;

        free(temp);
    }
}
