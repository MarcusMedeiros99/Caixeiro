#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "caixeiro.h"
#include "combinatoria.h"

typedef struct linha { //estrutura que representa uma linha de entrada do arquivo
    int origem;
    int destino;
    int distancia;
} LINHA;

void printLinha(LINHA *l); //função para imprimir uma estrutura linha
int* initVetor(int n, int inicio);

int main () {
    LISTA* cidades = inicializa();
    int n; //recebe a quantidade de linhas a ser lida
    LINHA l; //variável que armazena temporariamente uma linha lida
    
    FILE* entrada; //ponteiro para leitura de arquivo
    entrada = fopen("teste1.txt", "rt"); //abertura do arquivo para leitura

    //INICIO - LEITURA DE ARQUVIO E ALOCAÇÃO NA MATRIZ
    if (entrada != EOF) { //verifica se a abertura do arquivo foi realizada
        fscanf(entrada, "%d", &n); //lê a primeira linha do arquivo, que indica quantas linhas vêm a seguir
        insereCidades(cidades, n);//aloca a memória pras cidades
        printf("%d\n", n);
        
        //CALCULA COMBINAÇÃO SEU OTÁRIO!!!!!!
        int comb = combinacao(n,2);
        
        for (int i = 0; i < comb; i++) { //loop para ler as proximas n linhas
            fscanf(entrada, "%d%d%d", &(l.origem), &(l.destino), &(l.distancia) ); //armazena uma das linhas numa estrutura do tipo LINHA 
            insereCustos(cidades, l.origem - 1, l.destino - 1, l.distancia); //insere, na estrutura de dados, a distancia de origem até destino
            //imprimeLista(cidades);
        }
    }

    fclose(entrada); //fechar o arquivo lido

    //FIM - LEITURA DE ARQUIVO E ALOCAÇÃO NA MATRIZ;
    int custoMin = INT_MAX;
    int inicio;
    scanf("%d", &inicio);
    int *vetorCidades = initVetor(n, inicio);
    int *resp;
    permuta(cidades, vetorCidades, 0, n - 1, &custoMin, &resp, inicio);
    printf("custo min: %d\n", custoMin);
    printf("caminho: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", resp[i]);
    }
    printf("%d\n", vetorCidades[0]);
    return 0;
}

void printLinha(LINHA *l) {
    printf("%d %d %d\n", l->origem, l->destino, l->distancia);
}


int* initVetor(int n, int inicio) {
    int* vet = (int *) malloc(n*sizeof(int));
    for (int i = 0; i < n; i++) {
        vet[i] = i + 1;
    }
    vet[inicio - 1] = vet[0];
    vet[0] = inicio;
    return vet;
}