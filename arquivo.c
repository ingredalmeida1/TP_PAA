#include "arquivo.h"
#include "matriz.h"

void lerArquivo(int ***matriz)
{
    FILE *arquivo;
    int N, M;
    int i = 0;
    int j = 0;
    char entrada[20];

    printf("Entre com o nome do arquivo: ");
    scanf("%s", entrada);

    arquivo = fopen(entrada, "r"); // abre o arquivo em modo leitura
    if (arquivo == NULL)           // caso arquivo seja igual a NULL, encerra
    {
        printf("Erro na abertura do arquivo ou arquivo vazio\n");
        system("pause");
        exit(1);
    }

    fscanf(arquivo, "%d %d ", &N, &M);

    inicializaMatriz(N, M, matriz);

    char *vetorLinha;
    char linha[(M * 2) + 1];
    char *end;

    while (!feof(arquivo))
    {
        vetorLinha = fgets(linha, 201, arquivo); // foi escolhido 201 pois o número máximo de M é 100, mais os espaços e \n
        char *valor = strtok(vetorLinha, " ");
        while (valor != NULL)
        {
            int v = strtol(valor, &end, 10);    // função strtol que converte a string valor em um inteiro v
            (*matriz)[i][j] = v;                // preenche com v a matriz
            valor = strtok(NULL, " ");          // separa por espaço a linha lida do arquivo
            j++;
        }
        i++;
        j = 0;
    }

    imprimeMatriz(N, M, (*matriz));
}