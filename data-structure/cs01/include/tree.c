#include "tree.h"

NodeTree *create_node_tree(int val) {
    NodeTree *node = (NodeTree*)malloc(sizeof(NodeTree));

    if (!node) {
        fprintf(stderr, "ERROR: Alokasi memori gagal untuk node tree.\n");
        exit(EXIT_FAILURE);
    }

    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

NodeTree *build_tree() {
    NodeTree *root = create_node_tree(1);
    root->left = create_node_tree(2);
    root->right = create_node_tree(3);
    root->left->left = create_node_tree(4);
    root->left->right = create_node_tree(5);
    return root;
}

void inorder(NodeTree* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(NodeTree* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(NodeTree* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

void remove_tree(NodeTree* node) {
    if (node != NULL) {
        remove_tree(node->left);
        remove_tree(node->right);
        free(node);
    }
}
