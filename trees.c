#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct _tree_node_t
{
    int key;
    struct _tree_node_t *left;
    struct _tree_node_t *right;
} tree_node_t;

tree_node_t *mk_tree_node(int key, tree_node_t *left, tree_node_t *right)
{
    tree_node_t *node = (tree_node_t *) malloc(sizeof(tree_node_t));
    node->key = key;
    node->left = left;
    node->right = right;
    return node;
}

bool tree_node_empty(tree_node_t *node)
{
    return node == NULL;
}

tree_node_t *mk_empty_tree()
{
    return NULL;
}

void tree_insert(tree_node_t **root, int key)
{
    if (tree_node_empty(*root))
    {
        *root = mk_tree_node(key, mk_empty_tree(), mk_empty_tree());
    }
    else if (key < (*root)->key)
    {
        tree_insert(&(*root)->left, key);
    }
    else if (key > (*root)->key)
    {
        tree_insert(&(*root)->right, key);
    }
}

bool tree_search(tree_node_t *root, int key)
{
    if (tree_node_empty(root))
    {
        return false;
    }

    if (key == root->key)
    {
        return true;
    }

    if (key < root->key)
    {
        return tree_search(root->left, key);
    }

    return tree_search(root->right, key);
}

void preorder(tree_node_t *root)
{
    if (tree_node_empty(root))
    {
        return;
    }
    printf("%d\n", root->key);
    preorder(root->left);
    preorder(root->right);
}

void inorder(tree_node_t *root)
{
    if (tree_node_empty(root))
    {
        return;
    }
    inorder(root->left);
    printf("%d\n", root->key);
    inorder(root->right);
}

void postorder(tree_node_t *root)
{
    if (tree_node_empty(root))
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->key);
}

//         4
//     2       6
//  1     3 5     7

int main(int argc, char *argv[])
{
    char numbers[] = { 4, 2, 6, 1, 3, 5, 7 };

    tree_node_t *root = mk_empty_tree();
    assert(tree_node_empty(root));
    int i;
    for (i = 0; i < sizeof(numbers); ++i)
    {
        tree_insert(&root, numbers[i]);
    }

    assert(!tree_node_empty(root));
    assert(root->key == 4);

    assert(tree_search(root, 7));

    printf("=== pre ===\n");
    preorder(root);
    printf("=== in ===\n");
    inorder(root);
    printf("=== post ===\n");
    postorder(root);

    return 0;
}
