#ifndef __TREE_H__
#define __TREE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NodeTree {
    int data;
    struct NodeTree* left;
    struct NodeTree* right;
} NodeTree;

NodeTree *create_node_tree(int);
NodeTree *build_tree();
void inorder(NodeTree*);
void preorder(NodeTree*);
void postorder(NodeTree*);
void remove_tree(NodeTree*);

#endif