#include <string.h>

#include "../include/search.h"

//SEARCH BY ID
//O(log n)

SongNode* searchById(
    SongNode *root,
    int id
){

    if(root == NULL)
        return NULL;

    if(id == root->id)
        return root;

    if(id < root->id){

        return searchById(
            root->left,
            id
        );
    }

    return searchById(
        root->right,
        id
    );
}

//SEARCH BY TITLE
//O(n)

SongNode* searchByTitle(
    SongNode *root,
    char title[]
){

    if(root == NULL)
        return NULL;

    if(
        strcmp(
            root->title,
            title
        ) == 0
    ){

        return root;
    }

    SongNode *leftResult =
        searchByTitle(
            root->left,
            title
        );

    if(leftResult)
        return leftResult;

    return searchByTitle(
        root->right,
        title
    );
}