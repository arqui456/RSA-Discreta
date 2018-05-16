#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "RSA_math.h"

#define MA(x, y) (x > y) ? (x) : (y)
#define MN(x, y) (x < y) ? (x) : (y)

int TAM 100
int prime_list[1000];

//Função que gera a lista dos mil primeiros primos maiores que 500.

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

    int opcao, case_1, indice_p, indice_q, p, q, ascii_mensagem[TAM], i;
    unsigned long long int phi, e, n;
    char mensagem[TAM];

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

            //Opção automatica.

            if (case_1 == 1)
                {
                    prime_gen();
                    indice_p = rand() % 499;
                    indice_q = (rand() % 499) + 500;
                    p = prime_list[indice_p];
                    q = prime_list[indice_q];
                    n = p * q;
                    phi = (p - 1) * (q - 1);
                    while (1)
                        {
                            e = rand() % 1000;
                            if (al_euclides (MA(e, phi), MN(e, phi)) == 1)
                                {
                                    break;
                                }
                        }

                    //Abrir arquivo para salvar a chave pública.

                    FILE *f = fopen("chave publica.txt", "w");
                    if (f == NULL)
                        {
                            printf("Error opening file!\n");
                            exit(1);
                        }

                    fprintf (f, "n = %llu\n e = %llu\n", n, e);
                    fclose(f);
                }

                //Opção manual.

            else if (case_1 == 2)//encriptar
                {
                    printf ("Digite dois números primos P e Q distintos.\n");
                    while (1)
                    {
                        scanf ("%d%d", &p, &q);
                        if (p != q)
                        {
                            if (its_prime(p) == p && its_prime(q) == q)
                            {
                              break;
                            }
                            else
                              {
                                  printf("P e Q precisam ser primos!!\n");
                              }
                        }
                        else
                        {
                          printf("P e Q precisam ser diferentes!!\n");
                        }

                    }
                    n = p * q;
                    phi = (p-1)*(q-1);
                    while (1)
                    {
                        printf ("Digite um número E coprimo a PHI.\n");
                        scanf ("%llu", &e);
                        if (al_euclides (MA(e, phi), MN(e, phi)) == 1)
                            {
                                break;
                            }
                    }
                    FILE *f = fopen("chave publica.txt", "w");
                    if (f == NULL)
                        {
                            printf("Error opening file!\n");
                            exit(1);
                        }

                    fprintf (f, "n = %llu\n e = %llu\n", n, e);
                    fclose(f);

                }
            else
                {
                    //Tratamento de erro.
                    printf ("Digite uma opção válida!\n");
                }
        }
        else if(opcao == 2)
            {
              //Lendo a mensagem
                printf ("Digite uma mensagem a ser encriptada.\n");
                fgets (mensagem, TAM, stdin);

                for (i = 0; i < strlen(mensagem); ++i)
                {
                  // passar para ascii
                }

              //Lendo a chave pública


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
                printf ("Digite uma opção válida!\n");
                printf("Digite novamente: \n");
                scanf("%d", &opcao);
            }

        }
	return 0;
}
