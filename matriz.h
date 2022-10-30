#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct posicao{
    int valor;
    int marcado;
}Posicao;

void inicializaMatriz(int N, int M, Posicao ***matriz);

void imprimeMatriz(int N, int M, Posicao **matriz);

void caminho(int **vetorSequencia, Posicao ***matriz, int N, int M);

void caminhoI(int **vetorSequencia, Posicao ***matriz, int N, int M, int linha, int coluna, int indiceSeq, int marcacao);

void imprimeCaminho(Posicao ***matriz, int N, int M);

void imprimeCaminhoI(Posicao ***matriz, int linha, int coluna, int N, int M, int indiceMarcado);