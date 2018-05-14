#include "stdio.h"
#include "math.h"

int main(void) 
{
  int prime_list [1000];
  int primo = achou = j = 0,u,i,size,primos = 0;

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
	  return 0;
}