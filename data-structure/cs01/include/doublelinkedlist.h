#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int key, value;
    struct Node* next;
    struct Node* prev;
} Node;

#define KAPASITAS 3
#define HASH_MAP 100

extern Node* _head;
extern Node* _tail;
extern Node* _cache_map[HASH_MAP];

Node* created_node(int key, int value);
void deleted_node(Node *node);
void adding_front_node(Node *node);
Node* remove_list_node();
bool get_key(int key, int *val);
void add(int key, int val);
void display_cache();
void clear();

#endif