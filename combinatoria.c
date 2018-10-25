#include "caixeiro.c"

#define FIM -1


#include <stdio.h>
#include <time.h>


void troca(int vetor[], int i, int j)
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

void permuta(int vetor[], int inf, int sup, int *custo)
{
    if(inf == sup)
    {
        for(int i = 0; i <= sup; i++)
            printf("%d ", vetor[i]);
        printf("\n");
        int x = calcCusto(vet, sup + 1);
        if (x < *custo) *custo = x;
      
    }
    else
    {
        for(int i = inf; i <= sup; i++)
        {
            troca(vetor, inf, i);
            permuta(vetor, inf + 1, sup);
            troca(vetor, inf, i); // backtracking
        }
    }
}

void removeX(int* vet, int x, int n) {
    int i = 0;
    while (vet[i] != x) i++;
    for (i = i; i < n - 1; i++) {
        vet[i] = vet[i + 1];
    }
    vet[i] = FIM;
}

/*int caminhos (LISTA* cidades, int* resp, int* pode, int n, int pos, int x, int custo) {
    if (pode[0] == FIM) {
        for (int i = 0; i < n; i++) {
            printf("%d ", resp[i]);
        }
        printf("\n");
        //calcCusto(cidades, resp);
        return 0;
    }
    else {
        resp[pos] = x;
        removeX(pode, x, n);
        //pos++;

        for (int i = 0; i < n - pos -1; i++) {
            caminhos(cidades, resp, pode, n, pos+1, pode[i], custo);
            printf("oi\n");
        }
    }
}
*/
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



int main () {
    int n = 5;
    int vetor[5] = {1,2,3,4,5};
    int resp[5] = {0,0,0,0,0};
    int custo = 0;
    caminhos(NULL, resp, vetor, n, 0, 2, custo);

    return 0;
}