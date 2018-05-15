#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int prime_list[1000];

int main() 
{

    //Criação do ponteiro pra gerar o arquivo com as chaves.

    FILE *f = fopen("chave publica.txt", "w");
    if (f == NULL)
        {
            printf("Error opening file!\n");
            exit(1);
        }

    // Declaração de  variáveis.

    int opcao, case_1, indice_p, indice_q;
    unsigned long long int p, q, phi, e, n;
    
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