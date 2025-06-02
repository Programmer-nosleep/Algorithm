#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>

#if defined (__unix__)
#include <unistd.h>

#endif

typedef struct Node node_t;
struct Node
{
  int data;
  int index;
  node_t* next;
};

struct Node* Constructor(struct Node** head, int data, size_t len);
node_t* Deconstructor(struct Node** head);

void printline(const char* fmt, ...);

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printline("Hello %", "World!");
    exit(0);
  }

  return EXIT_SUCCESS;
}

void printline(const char* fmt, ...)
{
  va_list va_ap;

  const char *p, *sval;
  int val;
  double dval;

  va_start(va_ap, fmt);

  for (p = fmt; *p; p++)
  {
    if (*p != '%')
    {
      putchar(*p);
      continue;
    }

    switch (*++p) 
    {
      case 'd':
        val = va_arg(va_ap, int);
        printf("%d", val);
        break; 

      case 'f':
        dval = va_arg(va_ap, double);
        printf("%f", dval);
        break;
      
      case 'p':


      case 's':
        for (sval = va_arg(va_ap, char*); *sval; sval++)
          putchar(*sval);
      default:
        putchar(*p);
        break;
    
    }
  }
  va_end(va_ap);
}
