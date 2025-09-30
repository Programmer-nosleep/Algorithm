#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <stddef.h>

typedef struct Data
{
  int data;
  size_t len;
  int index[];
} data;

data* binary_search(data** data, int x, int y);

void print(const char* fmt, ...);

#endif