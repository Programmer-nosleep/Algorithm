#include <stdio.h>
#include <stdlib.h>

#include "../include/node.h"
#include "../include/sorting.h"
#include "../include/searching.h"

int main(int argc, char *argv[])
{
//   if (argc != 2)
//   {
//     println("Hello, %", "World!");
//     return 0;
//   }

  int arr[5] = { 1, 5, 4, 2, 3 };
  int n = sizeof(arr) / sizeof(arr[0]);

  // qsort(arr, n, sizeof(int), compsort);
  
  binary_search(arr, n, 3 , 9, 11, 13);
  linear_search(arr, n, 2, 11 ,4);

  // for (int i = 0; i < n; i++)
  // {
  //   println("%d", arr[i]);
  // }

  return EXIT_SUCCESS;
}
