#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Task {
    int id;
    char desk[128];
    int priority;
} Task;

typedef struct Node {
    Task task;
    struct Node* next;
} Node;

// #define NODE_NEW(val) ({               \
//     Node *n = malloc(sizeof(Node));    \
//     memset(n, 0, sizeof(Node));        \
//     if ((val) != NULL)                 \
//         n->task.id = (val);            \
//     n->next = NULL;                    \
//     n;                                 \
// })

extern Node *head;

Node* create_node(int id, const char *desk, int priory);
void add_task(const char*, int);
bool execute_task();
void display_task();
bool delete_task(int id);
void remove_list();

#endif