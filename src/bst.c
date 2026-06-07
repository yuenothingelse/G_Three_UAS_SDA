#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/bst.h"


//CREATE SONG


SongNode* createSong(
    int id,
    char title[],
    char artist[],
    int playCount
){

    SongNode *newNode =
        (SongNode*)malloc(
            sizeof(SongNode)
        );

    newNode->id = id;

    strcpy(
        newNode->title,
        title
    );

    strcpy(
        newNode->artist,
        artist
    );

    newNode->playCount =
        playCount;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


//INSERT BST


SongNode* insertBST(
    SongNode *root,
    int id,
    char title[],
    char artist[],
    int playCount
){

    if(root == NULL){

        return createSong(
            id,
            title,
            artist,
            playCount
        );
    }

    if(id < root->id){

        root->left =
            insertBST(
                root->left,
                id,
                title,
                artist,
                playCount
            );
    }

    else if(id > root->id){

        root->right =
            insertBST(
                root->right,
                id,
                title,
                artist,
                playCount
            );
    }

    return root;
}


//MIN VALUE NODE


static SongNode* minValueNode(
    SongNode *node
){

    SongNode *current =
        node;

    while(
        current &&
        current->left
    ){

        current =
            current->left;
    }

    return current;
}


//DELETE BST


SongNode* deleteBST(
    SongNode *root,
    int id
){

    if(root == NULL)
        return NULL;

    if(id < root->id){

        root->left =
            deleteBST(
                root->left,
                id
            );
    }

    else if(id > root->id){

        root->right =
            deleteBST(
                root->right,
                id
            );
    }

    else{

        
        //CASE 1
        //NO CHILD
        

        if(
            root->left == NULL &&
            root->right == NULL
        ){

            free(root);
            return NULL;
        }

        
        //CASE 2
        //ONE CHILD
        

        if(root->left == NULL){

            SongNode *temp =
                root->right;

            free(root);

            return temp;
        }

        if(root->right == NULL){

            SongNode *temp =
                root->left;

            free(root);

            return temp;
        }

    
        //CASE 3
        //TWO CHILD
        

        SongNode *temp =
            minValueNode(
                root->right
            );

        root->id =
            temp->id;

        strcpy(
            root->title,
            temp->title
        );

        strcpy(
            root->artist,
            temp->artist
        );

        root->playCount =
            temp->playCount;

        root->right =
            deleteBST(
                root->right,
                temp->id
            );
    }

    return root;
}


//INORDER


void inorder(
    SongNode *root
){

    if(root == NULL)
        return;

    inorder(root->left);

    printf(
        "%-5d %-30s %-20s %d\n",
        root->id,
        root->title,
        root->artist,
        root->playCount
    );

    inorder(root->right);
}


//FREE BST


void freeBST(
    SongNode *root
){

    if(root == NULL)
        return;

    freeBST(root->left);
    freeBST(root->right);

    free(root);
}