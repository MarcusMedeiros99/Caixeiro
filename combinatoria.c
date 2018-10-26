#include "caixeiro.h"
#include <stdio.h>
#include <malloc.h>

int *copyInt(int* origem, int n) {
    int *destino = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
    return destino;
}

void troca(int vetor[], int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void permuta(LISTA* l, int vetor[], int inf, int sup, int *custo, int **resp, int inicio)
{   
    if (vetor[0] != inicio) return;
    if(inf == sup)
    {
        /*for(int i = 0; i <= sup; i++)
            printf("%d ", vetor[i]);
        printf("\n");*/
        int x = calculaCusto( l ,vetor, sup + 1);
        if (x < *custo) {
            *custo = x;
            *resp = copyInt(vetor, sup + 1);
        }
    }
    else
    {
        for(int i = inf; i <= sup; i++)
        {
            troca(vetor, inf, i);
            permuta(l, vetor, inf + 1, sup, custo, resp, inicio);
            troca(vetor, inf, i); // backtracking
        }
    }
}

int fatorial (int n) {
    int aux = 1;
    for (int i = 1; i <=n; i++) {
        aux = aux*i;
    }
    return aux;
}

int combinacao (int n, int p) { //Cn,p
    return fatorial(n) / (fatorial(p) * fatorial(n - p));
}

