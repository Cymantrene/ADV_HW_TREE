#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef int32_t datatype;

typedef struct tree
{
    datatype key;
    struct tree *left, *right;
} tree;

void insert_t(tree **root, datatype key)
{
    if(!*root)
    {
        *root = (tree *)calloc(1, sizeof(tree));
        (*root)->key = key;
    }
    else if((*root)->key < key)
    {
        insert_t(&(*root)->right, key);
    }
    else
    {
        insert_t(&(*root)->left, key);
    }
}
void go_left(tree *root)
{
    if(root->left)
    {
        go_left(root->left);
    }
    printf("%d ",root->key);
}
void go_right(tree *root)
{
    printf("%d ",root->key);
    if(root->right)
    {
        go_right(root->right);
    }
}
void btUpView(tree *root)
{
    if(root == NULL)
    {
        return;
    }
    go_left(root);

    if(root->right)
    {
        go_right(root->right);
    }
}

int main()

{
    tree *my_tree = NULL;
    insert_t(&my_tree, 10);
    insert_t(&my_tree, 5);
    insert_t(&my_tree, 15);
    insert_t(&my_tree, 3);
    insert_t(&my_tree, 7);
    insert_t(&my_tree, 13);
    insert_t(&my_tree, 18);
    insert_t(&my_tree, 1);
    insert_t(&my_tree, 6);
    insert_t(&my_tree, 14);
    insert_t(&my_tree, 0);
    btUpView(my_tree);
    return 0;
}
