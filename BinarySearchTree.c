#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
}treenode;



treenode* insertnode(treenode *root, int val)
{
    if(root == NULL)
    {
        return createtreenode(val);
    }

    if(val < root->data)
    {
        root->left = insertnode(root->left, val);
    }
    else if(val > root->data)
    {
        root->right = insertnode(root->right, val);
    }
    return root;
}

int in_order_traversal(treenode* root)
{
    if(root != NULL)
    {
        in_order_traversal(root->left);
        printf("%d\n", root->data);
        in_order_traversal(root->right);
    }
    return 0;
}

int pre_order_traversal(treenode* root)
{
    if(root != NULL)
    {
        printf("%d\n", root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
    return 0;
}

int post_order_traversal(treenode* root)
{
    if(root != NULL)
    {
        post_order_traversal(root->left);
        post_order_traversal(root->right);
        printf("%d\n", root->data);
    }
    return 0;
}

int main()
{
    binarytree tree;
    tree.root = NULL;

    tree.root = insertnode(tree.root,5);
    tree.root = insertnode(tree.root, 7);
}
