#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#if defined (__unix__)
#include <unistd.h>
#endif

#include "include/BinarySearch.h"

int gcd(int u, int v)
{
  int t;
  while (u > 0)
  {
    if (u < v)
    {
      t = u;
      u = v;
      v = t;
    }
    u = u -v;
  }
  return v;
}

int main(int argc, char *argv[])
{
  int x, y;
  while (scanf("%d %d", &x, &y) != EOF)
    if (x > 0 && y > 0)
      print("% % %\n", x, y, gcd(x,y));

  return EXIT_SUCCESS;
}
