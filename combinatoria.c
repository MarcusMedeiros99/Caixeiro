#include <malloc.h>

int fatorial (int n) {
    int aux = 1;
    for (int i = 1; i <=n; i++) {
        aux = aux*i;
    }
    return aux;
}

int combinacao (int n, int p) { //Combinação de n elementos, tomados p em p
    return fatorial(n) / (fatorial(p) * fatorial(n - p));
}

int* initVetor(int n, int inicio) { //inicializa um vetor com as cidades, cujo primeiro elemento é a cidade inicial
    int* vet = (int *) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        vet[i] = i + 1;
    }
    vet[inicio - 1] = vet[0];
    vet[0] = inicio;
    return vet;
}