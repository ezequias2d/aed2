#ifndef BSD_H
#define BSD_H
#define BST_PRE 0
#define BST_IN 1
#define BST_POS 2
#define NULL ((void*)0)
typedef int data_t;
typedef unsigned long size64_t;

struct BST_NODE{
    data_t key;
    struct BST_NODE* left;
    struct BST_NODE* right;
};

typedef struct BST_NODE BST_NODE;

BST_NODE* BST_insert(BST_NODE* root, data_t key);

BST_NODE* BST_remove(BST_NODE* root, data_t key);

BST_NODE* BST_remove2(BST_NODE* root, data_t key);

BST_NODE* BST_remove3(BST_NODE* root, data_t key);

BST_NODE* BST_maxNode(BST_NODE* root);

BST_NODE* BST_minNode(BST_NODE* root);

size64_t BST_height(BST_NODE* root);

BST_NODE* BST_search(BST_NODE* root, data_t key);

BST_NODE* BST_searchFather(BST_NODE* root, data_t key);

BST_NODE* BST_searchNext(BST_NODE* root, data_t key);

BST_NODE* BST_searchPrevious(BST_NODE* root, data_t key);

BST_NODE* BST_clear(BST_NODE* root);

void BST_print(BST_NODE* root, data_t stade);

void BST_slimPrint(BST_NODE* root);

#endif