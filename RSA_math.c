#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "RSA_math.h"

int prime_list[1000];

//Função pra criar um vetor com os 1000 primeiros primos maiores que 500.

void prime_gen ()
{
    int primo = 0, achou = 0, j = 0 , u, i, size, primos = 0;

	for(i=500 ;primos < 1500 ;i++)
    {
        primo = i;
        for(u=2;u<=sqrt(primo);u++)
            {
                achou = 0;
                if(primo%u==0)
                {
                    achou = 1;
                    break;
                }
            }
            if(!achou)
            {
                prime_list[j] = primo;
                ++j;
                primos++;
            }
	}
}