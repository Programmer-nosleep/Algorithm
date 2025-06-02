#ifndef SORTING_H
#define SORTING_H

typedef struct Data 
{
  int data;
  int index[];
};

void lsort(struct Data* data, int n, ...);
void bsort(struct Data* data, int n, ...);
void qsort(struct Data* data, int n, ...);
void  

#endif
