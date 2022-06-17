#ifndef __TREE__
#define __TREE__
#include <stdio.h>
#include <stdlib.h>
#define N 8


typedef struct Tnode {
    int key;
    struct Tnode* descender[N];
} TNode;





//Tree create
TNode* node_create(int);
TNode* add_node(TNode*, int);

int tree_from_file(TNode*, FILE*);

//Add an element in tree

#endif

