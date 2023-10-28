#include "main.h"

/**
 * _env - Prints the environmental variable
 * Returns: void
*/

void _env(void)
{
  int i = 0;

  while (environ[i])
  {
    printf("%s", environ[i]);
    i++;
  }
}