#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
}treenode;

typedef struct binarytree
{
    treenode* root;
}binarytree;

treenode* createtreenode(int data)
{
    treenode* newnode = (treenode*)malloc(sizeof(treenode*));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
