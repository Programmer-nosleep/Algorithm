#include <iostream>

int number_of_step(int num)
{
  int steps = 0;

  /**
   * @brief calculate the number of steps to reduce the number up to 0
   * conclusion: 
   *  - using operand bit for efficienly:
   *    - num & 1 is meaning is to check the number odd/even (to faster than modulo %)
   *    - num >>= 1 is meaning is to divede 2 (to faster than num /= 2)
   *
   *  - it's so odd is devide 2, and even is minus 1
   * */
  while(num > 0)
  {
    // before we used num % 2
    if ((num & 1) % 2 == 0)
    {
      // before we used num /= 2;
      num >>= 1;
    } 
    else
    {
      // minus 1 is even
      num--;
    }

    // counting of steps
    steps++;
  }

  // returning function to count of steps
  return steps;
}

/**
 * @brief function main of program entry point
 *
 * @param argc count of argument to command line
 * @param argv array of C-String arguments
 * @return type int to exit the code program (0 is success to exit or EXIT_SUCCESS program terminated successfully)
 *  - non-zero like -1 or -99 - 99 is program terminated with an error.
 * */
int main(int argc, char** argv)
{
  for (int i = 0; i < 10; i++)
  {
    std::cout << number_of_step(i) << " "; 
  }

  return 0;
}
