#include "sequencia.h"

int sequenciaFibonacci(int N) // algoritmo comum para calcular a sequência de fibonacci
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

void preencheVetorFib(int **vetorFib, int N, int M) // função que preenche um vetor com a sequência de fibonacci
{
    int i = 0;
    int count = 0;

    while (count < (N * M)) // este while me retorna qual o tamanho necessário do vetor de fibonacci
    {                       // para que eu possa replica-lá na sequência da sequência, é a soma que
        i++;                // aparece na especificação
        count += i;
    }

    (*vetorFib) = (int *)malloc(i * sizeof(int));
    (*vetorFib)[0] = 1;
    (*vetorFib)[1] = 1;

    for (int j = 2; j < i; j++)
    {
        (*vetorFib)[j] = sequenciaFibonacci(j); // apenas preenche com os valores de fib
    }
}

void inicializaVetorSequencia(int **vetorSequencia, int N, int M) // função apenas para inicializar o vetor da sequencia da sequenica
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
    int indice = 0;
    int c = 0;
    int count = 0;

    while (count < (N * M)) // a mesma explicação 
    {
        c++;
        count += c;
    }

    int i = 1, j = 0;  // i começa de 1 pq pegamos 1 primeiro. antes de 1 1 e 1 1 2

    while(indice < N * M){    
        if(j == i){ // isso é como se fosse um for, quando j = i, zeramos j e fazemos i++.
            i+= 1; // antes era um for dentro do outro, mas estava ultrapassando o número de alocações do vetor de sequencias
            j = 0;
        }

        (*vetorSequencia)[indice] = (*vetorFib)[j]; // o j me diz qual valor eu preciso pegar no vetor de fib
        indice++; // posicao no vetor da sequencia que irá inserir
        j++; // é aquele trem de 1, depois 1 1, depois 1 1 2
    }

}

void imprimeSequencia(int N, int M, int **vetorSequencia)
{
    int tam = N * M;
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", (*vetorSequencia)[i]);
    }
    printf("\n");
}