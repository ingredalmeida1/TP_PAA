#include "sequencia.h"

int sequenciaFibonacci(int N)
{

    int fib1 = 1;
    int fib2 = 1;
    int soma = 0;

    for (int i = 1; i < N; i++)
    {
        soma = fib1 + fib2;
        fib1 = fib2;
        fib2 = soma;
    }

    return fib2;
}

void preencheVetorFib(int **vetorFib, int N)
{
    (*vetorFib) = (int *)malloc(N * sizeof(int));
    (*vetorFib)[0] = 1;
    (*vetorFib)[1] = 1;

    for (int i = 2; i < N; i++)
    {
        (*vetorFib)[i] = 0;
    }

    for (int i = 2; i < N; i++)
    {
        (*vetorFib)[i] = sequenciaFibonacci(i);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", (*vetorFib)[i]);
    }
}

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 FIB

// 1 1 1

void inicializaVetorSequencia(int **vetorFib, int **vetorSequencia, int N, int M)
{
    int tam = N * M;
    (*vetorSequencia) = (int *)malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++)
    {
        (*vetorSequencia)[i] = 0;
    }
}

void preencheVetorSequencia(int **vetorFib, int **vetorSequencia, int N, int M)
{
    int tam = N * M;
    int valor = 0;
    int Nseq = 1;

    while (1)
    {
        for (int i = 0; i < Nseq; i++)
        {
            valor = (*vetorFib)[i];
            for (int i = 0; i < tam; i++)
            {
                if ((*vetorSequencia)[i] == 0)
                {
                    (*vetorSequencia)[i] = valor;
                }
            }
        }

        Nseq++;
    }
}