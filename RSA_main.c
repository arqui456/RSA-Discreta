#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "RSA_math.h"

#define MA(x, y) (x > y) ? (x) : (y)
#define MN(x, y) (x < y) ? (x) : (y)
#define TAM 100

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
    unsigned long long int phi, e, n, encri_mens[TAM];
    char mensagem[TAM];
    char input1[10], input2[10];
    //Geração do menu.

    while(1)
    {
        printf("1 - Gerar chave pública.\n");
        printf("2 - Encriptar.\n");
        printf("3 - Desencriptar.\n");
        printf("4 - Sair\n");

        scanf("%s", input1);
        while(input1[0] < '1' || input1[0] > '4'){
            printf("Escolha uma opção válida:  ");
            scanf("%s", input1);
        }
        opcao = atoi(input1);

        if(opcao == 1)
        {
            printf ("1 - Gerar P, Q e E.\n");
            printf ("2 - Inserir P, Q e E manualmente.\n");

            scanf("%s", input2);
            while(input2[0] < '1' || input2[0] > '2'){
                printf("Escolha uma opção válida: ");
                scanf("%s", input2);
            }
            case_1 = atoi(input2);

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
        }
        else if(opcao == 2)
            {
                FILE *f2 = fopen("mensagem encriptada.txt", "w");
                    if (f2 == NULL)
                        {
                            printf("Error opening file!\n");
                            exit(1);
                        }

                printf("Insira a chave publica composta por N e E:");
                scanf("%llu%llu", &n, &e);

                printf("Insira a mensagem a ser encriptada:");
                scanf("%s", mensagem);

                for (int i = 0; i < strlen(mensagem); ++i)
                {
                    ascii_mensagem[i] = atoi(mensagem[i]);
                }

                for (int i = 0; i < strlen(ascii_mensagem); ++i)
                {
                    encri_mens[i] = modular_expo(ascii_mensagem[i], e, n);
                    fprintf (f2, "%llu", encri_mens[i]);
                }

                fclose(f2);
            }
        else if(opcao == 3)
            {
                //desencriptar
            }
        else if(opcao == 4)
            {
                break;
            }
        }
	return 0;
}
