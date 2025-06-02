#pragma once

#include <stddef.h>

#define BUFFER_CHAR 256

typedef struct Node *node_t;
struct Node 
{
  int data;
  struct Node *next;
  struct Node *self;
};

struct Node* constructor(struct Node** head, size_t length, int data);
struct Node* deconstructor(struct Node** head);

void println(const char* fmt, ...);
void file(const char *file, const char *args, ...);
