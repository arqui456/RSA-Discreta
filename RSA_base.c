#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int prime_list[1000];

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



int main() 
{
    FILE *f = fopen("chave publica.txt", "w");
    if (f == NULL)
        {
            printf("Error opening file!\n");
            exit(1);
        }

    int opcao, case_1, indice_p, indice_q;
    unsigned long long int p, q, phi, e, n;
    
    while(1)
    {    
        printf("1 - Gerar chave pública.\n");
        printf("2 - Encriptar.\n");
        printf("3 - Desencriptar.\n");
        printf("4 - Sair\n");

        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf ("1 - Gerar P e Q\n");
                printf ("2 - Inserir P e Q manualmente\n");
                scanf ("%d", &case_1);
                if (case_1 == 1)
                {
                    prime_gen();
                    indice_p = rand() % 499;
                    indice_q = (rand() % 499) + 500;
                    n = prime_list[indice_p] * prime_list[indice_q];
                    fprintf (f, "n = %llu\n e = %llu\n", n, e);           
                }
                else if (case_1 == 2)
                {
                    scanf ("%llu%llu%llu", &p, &q, &e);
                    fprintf (f, "p = %llu\n, q = %llu\n, e = %llu\n", p, q, e);
                }

            case 2:
            case 3:
            case 4:
                break;
            default:
                printf ("Digite uma opcao valida! abestado\n");
            break;
        }
    }
	return 0;
}