#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "RSA_math.h"

int al_euclides (int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        al_euclides (b, a%b);
    }
}

int its_prime (int x)
{
  int i;

  for (i = 2; i <= sqrt(x); ++i)
  {
    if (x % i == 0)
    {
      return 0;
    }
  }
  return x;
}
