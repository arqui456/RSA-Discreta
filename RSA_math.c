#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "RSA_math.h"

unsigned long long int modular_expo(int a, unsigned long long int e, unsigned long long int n)
{

	long long A = a, P = 1, E = e;

	while(1){

		//Chegou ao fim da expansão, retorna o P
		if(E == 0)
			return P;

		//Se o expoente é ímpar
		else if(E%2 != 0){
			//Realizamos a redução módulo n de cada uma das multpilicações
			P = (A * P)%n;
			E = (E-1)/2;
		}

		//Se o expoente é par
		else{
			E = E/2;
		}
		//Obtém a sequência de potências
		A = (A*A)%n;
	}

}

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
