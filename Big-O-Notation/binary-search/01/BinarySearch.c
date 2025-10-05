#include "include/BinarySearch.h"

#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <time.h>

data* binary_search(data** dat, int x, int y)
{
  return *dat;
}

void print(const char* fmt, ...)
{
    time_t now;
    struct tm *time_info;
    char time_str[128];

    time(&now);
    time_info = localtime(&now);

    if (strftime(time_str, sizeof(time_str), "%A %d %B %Y %H:%M:%S", time_info) == 0) {
        snprintf(time_str, sizeof(time_str), "Unknown time");
    }

    printf("[%s]: ", time_str);

    va_list args;
    va_start(args, fmt);

    const char* p = fmt;
    while (*p)
    {
        if (*p == '%' && *(p + 1) != '%') // satu %
        {
            /* 
             Default: asumsikan argumen berikut adalah int/double/char*
             Di sini deteksi tipe dengan pendekatan kasar:
             C tidak punya tipe info runtime, jadi kita asumsikan:
             urutan: int, double, string
            */

            int i = va_arg(args, int);
            printf("%d", i);
            p++; // lewati '%'
        }
        else if (*p == '%' && *(p + 1) == '%') // %%
        {
            putchar('%');
            p += 2; // lewati kedua %
        }
        else
        {
            putchar(*p++);
        }
    }

    va_end(args);
}
