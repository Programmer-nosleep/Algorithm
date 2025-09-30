#ifndef SEARCHING_H
#define SEARCHING_H

typedef struct Node *node_t;

int binary_search_one(int *arr, int n, int target);
void binary_search(int arr[], int n, ...);
void linear_search(int arr[], int n, ...);

#endif
