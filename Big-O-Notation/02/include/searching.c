#include "searching.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int binary_search_one(int *arr, int n, int target) {
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

void binary_search(int *arr, int n, ...)
{
  va_list ap;
  va_start(ap, n);

  printf("Binary Search:\n");

  int count = va_arg(ap, int); 

  for (int i = 0; i < count; i++) {
    int target = va_arg(ap, int);
    int index = binary_search_one(arr, n, target);
    if (index != -1)
      printf("  %d ditemukan di indeks %d\n", target, index);
    else
      printf("  %d tidak ditemukan\n", target);
  }

  va_end(ap);
}

void linear_search(int *arr, int n, ...)
{
  va_list ap;
  va_start(ap, n);

  printf("Linear Search:\n");

  int count = va_arg(ap, int); 
  for (int i = 0; i < count; i++) {
    int target = va_arg(ap, int);
    int found = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j] == target) {
        printf("  %d ditemukan di indeks %d\n", target, j);
        found = 1;
        break;
      }
    }
    if (!found)
      printf("  %d tidak ditemukan\n", target);
  }

  va_end(ap);
}

