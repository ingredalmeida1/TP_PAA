#include "sequencia.h"

void sequenciaFibonacci(int N, int **vetorFib)
{

    int fib1 = 1;
    int fib2 = 1;
    int soma = 0;

    for (int i = 3; i < N; i++)
    {
        soma = fib1 + fib2;
        fib1 = fib2;
        fib2 = soma;
    }

    return fib2;
}

void preencheSequenciaFib(int **vetorFib) {
    //(*vetorFib) = (int*)malloc(tam*sizeof(int));
}

void inicializaVetorSequencia(int **vetorSequencia, int N, int M)
{
    int tam = N * M;
    (*vetorSequencia) = (int *)malloc(tam * sizeof(int));
    for (int i = 0; i < tam; i++)
    {
        (*vetorSequencia)[i] = 0;
    }
    
}