#define _POSIX_C_SOURCE 199309L

#include <bits/time.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#if defined (__unix__)
#include <unistd.h>
#endif

// Big-O-Notation (O(n)) Linear time
void sum_of_number(double n)
{
  struct timespec start, end;
  double sum = 0;

  clock_gettime(CLOCK_REALTIME, &start);

  for (uint64_t i = 1; i <= n; i++)
  {
    if (i <= 10) printf("Sum (loop): %.0f\n", sum);
    sum += i;
  }

  clock_gettime(CLOCK_REALTIME, &end);

  double elapsed = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;

  printf("Steps: %" PRIu64 "\n", (uint64_t)sum);
  printf("Time taken (O(n)): %.6f seconds\n", elapsed);
}

// Big-O-Notation (O(1)) constant time algorithm 
void sum_of_number2(double n)
{
  struct timespec start, end;

  clock_gettime(CLOCK_REALTIME, &start);

  double sum =  (n * (n + 1)) / 2;

  clock_gettime(CLOCK_REALTIME, &end);

  printf("%f ", sum);

  double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

  printf("Time taken (O(n)) : %.6f sec", elapsed);
  // return sum;
}

// Big-O-Notation (O(log n)) Logaritmic
void sum_of_number3(uint64_t n)
{
  struct timespec start, end;
  clock_gettime(CLOCK_REALTIME, &start);

  uint64_t num = 0;
  for (uint64_t i = n; i > 1; i /= 2)
  {
    printf("%" PRIu64 "\n", i);  // butuh #include <inttypes.h>
    num++;
  }

  clock_gettime(CLOCK_REALTIME, &end);

  double elapsed = (end.tv_sec - start.tv_sec) +
                   (end.tv_nsec - start.tv_nsec) / 1e9;

  printf("\nSteps: %" PRIu64 "\n", num);
  printf("Time taken (O(log n)): %.6f sec\n", elapsed);
}

void 

// Big-O-Notation (O(n^3)) cubic algorithm
void sum_of_number4(uint64_t n)
{

}

int main(int argc, char *argv[])
{
  // if (argc != 2)
  // {
  //   printf("Hello, World!");
  //   exit(0);
  // }
  
  // int result;
  //
  // for (int i = 2; i < argc; i++)
  // {  
  //   result = atoi(argv[i]);
  //   sum_of_number2(result);
  // }

  // printf("%d ", result);
  
  float numb;

  printf("enter no till which you want the sum : ");
  scanf("%f", &numb);

  sum_of_number(numb);

  return EXIT_SUCCESS;
}
