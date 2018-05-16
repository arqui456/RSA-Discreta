#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "RSA_math.h"

#define MA(x, y) (x > y) ? (x) : (y)
#define MN(x, y) (x < y) ? (x) : (y)

int prime_list[1000];

void prime_gen ()
{
    int achou = 0, j = 0 , u, i, size, primos = 0;
    int primo = 0;

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

    // Declaração de  variáveis.

    int opcao, case_1, indice_p, indice_q, p, q;
    unsigned long long int phi, e, n;
    
    //Geração do menu.

    while(1)
    {    
        printf("1 - Gerar chave pública.\n");
        printf("2 - Encriptar.\n");
        printf("3 - Desencriptar.\n");
        printf("4 - Sair\n");

        scanf("%d", &opcao);

        if(opcao == 1)
        {
            printf ("1 - Gerar P, Q e E.\n");
            printf ("2 - Inserir P, Q e E manualmente.\n");
            scanf ("%d", &case_1);
            if (case_1 == 1)
                {
                    prime_gen();
                    indice_p = rand() % 499;
                    indice_q = (rand() % 499) + 500;
                    n = prime_list[indice_p] * prime_list[indice_q];
                    phi = (prime_list[indice_p] - 1) * (prime_list[indice_q] - 1);
                    while (1)
                        {
                            e = rand() % 1000;
                            if (al_euclides (MA(e, phi), MN(e, phi)) == 1)
                                {
                                    break;
                                }
                        }

                    //Criação do ponteiro pra gerar o arquivo com as chaves.

                    FILE *f = fopen("chave publica.txt", "w");
                    if (f == NULL)
                        {
                            printf("Error opening file!\n");
                            exit(1);
                        }

                    fprintf (f, "n = %llu\n e = %llu\n", n, e);
                    fclose(f); 
                }
            else if (case_1 == 2)
                {
                    while (1)
                    {
                        printf ("Digite dois números primos P e Q distintos.\n");
                        scanf ("%d%d", &p, &q);  
                        if (p != q)
                        {
                            break;
                        }
                    }



                    //fprintf (f, "p = %d\n, q = %d\n, e = %llu\n", p, q, e);
                }
            else
                {
                    //Tratamento de erro.
                    printf ("Digite uma opção válida! abestado\n");
                }
        }
        else if(opcao == 2)
            {
                //encriptar
            }

        else if(opcao == 3)
            {
                //desencriptar
            }

        else if(opcao == 4)
            {
                break;
            }

        else
            {
                //Tratamento de erro.
                printf ("Digite uma opção válida! abestado\n");
            }
        }
	return 0;
}