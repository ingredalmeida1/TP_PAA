#include "matriz.h"

void inicializaMatriz(int N, int M, Posicao ***matriz)
{
    (*matriz) = (Posicao **)malloc(N * sizeof(Posicao *));

    for (int i = 0; i < N; i++)
    {
        (*matriz)[i] = (Posicao *)malloc(M * sizeof(Posicao));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            (*matriz)[i][j].valor = 0;
            (*matriz)[i][j].marcado = 0;
        }
    }
}

void imprimeMatriz(int N, int M, Posicao **matriz)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", matriz[i][j].valor);
        }
        printf("\n");
    }
}

void caminho(int **vetorSequencia, Posicao ***matriz, int N, int M)
{
    int flag = 0;
    int linha = 0;
    int indiceSeq = 0;
    int marcacao = 1;

    for (int coluna = 0; coluna < M; coluna++)
    {
        if ((*matriz)[linha][coluna].valor != (*vetorSequencia)[0])
        {
            flag++;
        }
        else
        {
            caminhoI(vetorSequencia, matriz, N, M, linha, coluna, indiceSeq, marcacao);
        }
    }
    if (flag == M)
    {
        printf("IMPOSSÍVEL!\n");
        return;
    }
}

void caminhoI(int **vetorSequencia, Posicao ***matriz, int N, int M, int linha, int coluna, int indiceSeq, int marcacao)
{
    int valorSeq = 0;
    int valor = 0;
    // se a posicao da matriz for igual ao valor na sequencia
    if ((*matriz)[linha][coluna].valor == (*vetorSequencia)[indiceSeq])
    {
        (*matriz)[linha][coluna].marcado = marcacao;
        if (linha != (N - 1))
        {
            valorSeq = (*vetorSequencia)[indiceSeq + 1];
            valor = (*matriz)[linha + 1][coluna].valor;
            if ((*matriz)[linha + 1][coluna].valor == (*vetorSequencia)[indiceSeq + 1]) // olhando posicao abaixo
            {
                if ((*matriz)[linha + 1][coluna].marcado == 0)
                {
                    caminhoI(vetorSequencia, matriz, N, M, (linha + 1), coluna, (indiceSeq + 1), (marcacao + 1));
                }
            }
        }

        if (linha != 0)
        {
            valorSeq = (*vetorSequencia)[indiceSeq + 1];
            valor = (*matriz)[linha - 1][coluna].valor;
            if ((*matriz)[linha - 1][coluna].valor == (*vetorSequencia)[indiceSeq + 1]) // olhando posicao acima
            {
                if ((*matriz)[linha - 1][coluna].marcado == 0)
                {
                    caminhoI(vetorSequencia, matriz, N, M, (linha - 1), coluna, (indiceSeq + 1), (marcacao + 1));
                }
            }
        }

        if (coluna != 0)
        {
            valorSeq = (*vetorSequencia)[indiceSeq + 1];
            valor = (*matriz)[linha][coluna - 1].valor;
            if ((*matriz)[linha][coluna - 1].valor == (*vetorSequencia)[indiceSeq + 1]) // olhando a esquerda
            {
                if ((*matriz)[linha][coluna - 1].marcado == 0)
                {
                    caminhoI(vetorSequencia, matriz, N, M, linha, (coluna - 1), (indiceSeq + 1), (marcacao + 1));
                }
            }
        }

        if (coluna != (M - 1))
        {
            valorSeq = (*vetorSequencia)[indiceSeq + 1];
            valor = (*matriz)[linha][coluna + 1].valor;
            if ((*matriz)[linha][coluna + 1].valor == (*vetorSequencia)[indiceSeq + 1]) // olhando a direita
            {
                if ((*matriz)[linha][coluna + 1].marcado == 0)
                {
                    caminhoI(vetorSequencia, matriz, N, M, linha, (coluna + 1), (indiceSeq + 1), (marcacao + 1));
                }
            }
        }

        if (linha == (N - 1))
        {
            imprimeCaminho(matriz, N, M);
            return;
        }

        else
        {
            (*matriz)[linha][coluna].marcado = 0;
            return;
        }
    }
}

void imprimeCaminho(Posicao ***matriz, int N, int M)
{
    for (int i = 0; i < M; i++)
    {
        if ((*matriz)[0][i].marcado == 1)
        {
            printf("1 %d\n", (i + 1));
            imprimeCaminhoI(matriz, 0, i, N, M, 2);
        }
    }
}

void imprimeCaminhoI(Posicao ***matriz, int linha, int coluna, int N, int M, int indiceMarcado)
{
    if (linha == (N - 1))
    {
        return;
    }

    if (linha != (N - 1))
    {
        if ((*matriz)[linha + 1][coluna].marcado == indiceMarcado)
        {
            printf("%d %d\n", (linha + 2), (coluna + 1));
            imprimeCaminhoI(matriz, (linha + 1), coluna, N, M, (indiceMarcado + 1));
        }
    }

    if (linha != 0)
    {
        if ((*matriz)[linha - 1][coluna].marcado == indiceMarcado)
        {
            printf("%d %d\n", linha, (coluna + 1));
            imprimeCaminhoI(matriz, (linha - 1), coluna, N, M, (indiceMarcado + 1));
        }
    }

    if (coluna != 0)
    {
        if ((*matriz)[linha][coluna - 1].marcado == indiceMarcado)
        {
            printf("%d %d\n", (linha + 1), coluna);
            imprimeCaminhoI(matriz, linha, (coluna - 1), N, M, (indiceMarcado + 1));
        }
    }

    if (coluna != (M - 1))
    {
        if ((*matriz)[linha][coluna + 1].marcado == indiceMarcado)
        {
            printf("%d %d\n", (linha + 1), (coluna + 2));
            imprimeCaminhoI(matriz, linha, (coluna + 1), N, M, (indiceMarcado + 1));
        }
    }
}