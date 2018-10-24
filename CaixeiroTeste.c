#include <stdio.h>
#include <stdlib.h>
#include "caixeiro.h"

typedef struct linha { //estrutura que representa uma linha de entrada do arquivo
    int origem;
    int destino;
    int distancia;
} LINHA;

void printLinha(LINHA *l); //função para imprimir uma estrutura linha

int main () {
    LISTA* cidades = inicializa();
    int n; //recebe a quantidade de linhas a ser lida
    LINHA l; //variável que armazena temporariamente uma linha lida
    
    FILE* entrada; //ponteiro para leitura de arquivo
    entrada = fopen("teste1.txt", "rt"); //abertura do arquivo para leitura

    if (entrada != EOF) { //verifica se a abertura do arquivo foi realizada
        fscanf(entrada, "%d", &n); //lê a primeira linha do arquivo, que indica quantas linhas vêm a seguir
        insereCidades(cidades, n);//aloca a memória pras cidades
        printf("%d\n", n);

        //CALCULA COMBINAÇÃO SEU OTÁRIO!!!!!!
        n = combinacao(n,2);
        for (int i = 0; i < n; i++) { //loop para ler as proximas n linhas
            fscanf(entrada, "%d%d%d", &(l.origem), &(l.destino), &(l.distancia) ); //armazena uma das linhas numa estrutura do tipo LINHA 
            printLinha(&l);
            printf("oi\n");
            insereCustos(cidades, l.origem - 1, l.destino - 1, l.distancia); //insere, na estrutura de dados, a distancia de origem até destino
            //imprimeLista(cidades);
        }
    }

    fclose(entrada); //fechar o arquivo lido
    return 0;
}

void printLinha(LINHA *l) {
    printf("%d %d %d\n", l->origem, l->destino, l->distancia);
}

int fatorial (int n) {
    int aux = 1;
    for (int i = 1; i <=n; i++) {
        aux = aux*i;
    }
    return aux;
}

int combinacao (int n, int p) { //Cn,p
    return factorial(n) / (factorial(p) * factorial(n - p));
}
