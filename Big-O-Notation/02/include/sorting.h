#ifndef SORTING_H
#define SORTING_H

typedef struct Data 
{
  int data;
  int index[];
};

void linearsort(struct Data* data, int n, ...);
void bubblesort(struct Data* data, int n, ...);
void quicksort(struct Data* data, int n, ...);
int compsort(const void* a, const void* b); 

#endif
