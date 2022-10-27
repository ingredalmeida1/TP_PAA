#include "matriz.h"

void inicializaMatriz(int N, int M, int ***matriz)
{   
    (*matriz) = (int**) malloc(N*sizeof(int*));

    for (int i = 0; i < N; i++)
    {
        (*matriz)[i] = (int*) malloc(M*sizeof(int));
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            (*matriz)[i][j] = 0;
        }
    }
}

void imprimeMatriz(int N, int M, int **matriz)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}