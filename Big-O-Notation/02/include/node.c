#include "node.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

struct Node* constructor(struct Node** head, size_t length, int data)
{
  struct Node* handler = (struct Node*)malloc(sizeof(struct Node));

  handler->self = *head;
  
  return *head;
}

struct Node* deconstructor(struct Node** head)
{
  if ((*head) == NULL)
  {
    
  }

  return *head;
}

void println(const char *fmt, ...)
{
  va_list args;
  va_start(args, fmt);

  while (*fmt)
  {
    if (*fmt == '%')
    {
      fmt++; 
      switch (*fmt)
      {
        case 's': {
          const char *str = va_arg(args, const char *);
          printf("%s", str);
          break;
        }
        case 'd': {
          int val = va_arg(args, int);
          printf("%d", val);
          break;
        }
        case 'f': {
          double fval = va_arg(args, double);
          printf("%f", fval);
          break;
        }
        case '%': {
          putchar('%');
          break;
        }
        default:
          putchar('%');
          putchar(*fmt);
          break;
      }
    }
    else
    {
      putchar(*fmt);
    }

    fmt++;
  }

  putchar('\n');
  va_end(args);
}



void file(const char *file, const char *args, ...)
{
  va_list ap;
  const char *arr[BUFFER_CHAR];

  int argno = 0;

  va_start(ap, args);

  while (args) 
  {
    arr[argno++] = args;
    args = va_arg(ap, const char*);
  }

  arr[argno] = (char*)0;
  va_end(ap);
}
