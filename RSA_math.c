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