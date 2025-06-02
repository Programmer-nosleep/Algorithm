#include <stdio.h>
#include <stdlib.h>

#include "../include/node.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    println("Hello, %", "World!");
    return 0;
  }

  return EXIT_SUCCESS;
}
