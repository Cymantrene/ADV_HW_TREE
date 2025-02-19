

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int32_t datatype;

typedef struct tree
{
    datatype key;
    struct tree *left, *right;
    struct tree *parent;
} tree;


void insert_t(tree **root, datatype key)
{

    if(!*root)
    {
        *root = (tree *) calloc(1, sizeof(tree));
        (*root)->key = key;
        (*root)->parent = NULL;
    }

    else if((*root)->key < key)
    {
        insert_t(&(*root)->right, key);
        (*root)->right->parent = *root;
    }

    else
    {
        insert_t(&(*root)->left, key);
        (*root)->left->parent = *root;
    }
}



tree * findBrother(tree *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->key == key)
    {
        if (root->parent != NULL)
        {
            if (root->parent->left == root)
            {
                return root->parent->right;
            }
            else
            {
                return root->parent->left;
            }
        }
        else
        {
            return NULL;
        }
    }
    tree *brother = findBrother(root->left, key);
    if (brother != NULL)
    {
        return brother;
    }
    return findBrother(root->right, key);
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



    tree *brother = findBrother(my_tree, 18);
    if (brother != NULL)
    {
        printf("%d\n", brother->key);
    }
    else
    {
        printf("No Brother\n");
    }

    return 0;
}
