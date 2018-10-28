

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //contém a constante INT_MAX
//#include <time.h>
#include "caixeiro.h"
#include "combinatoria.h"

typedef struct linha { //estrutura que representa uma linha de entrada do arquivo
    int origem;
    int destino;
    int distancia;
} LINHA;

void printLinha(LINHA *l);

int main (int argc, char* argv[ ]) {
    LISTA* cidades = inicializa();
    int n; //recebe a quantidade de linhas a ser lida
    LINHA l; //variável que armazena temporariamente uma linha lida
    
    FILE* entrada; //ponteiro para leitura de arquivo
    entrada = fopen(argv[1], "rt"); //abertura do arquivo para leitura

    //INICIO - LEITURA DE ARQUVIO E ALOCAÇÃO NA ESTRUTURA DE DADOS
    if (entrada != NULL) { //verifica se a abertura do arquivo foi realizada
        fscanf(entrada, "%d", &n); //lê a primeira linha do arquivo, que indica quantas cidades existem no arquivo
        insereCidades(cidades, n);//aloca a memória pras cidades
        
        int comb = combinacao(n,2); //calcula a quantidade de linhas a serem lidas
        
        for (int i = 0; i < comb; i++) { //loop para ler as proximas comb linhas
            fscanf(entrada, "%d%d%d", &(l.origem), &(l.destino), &(l.distancia) ); //armazena uma das linhas numa estrutura do tipo LINHA 
            insereCustos(cidades, l.origem - 1, l.destino - 1, l.distancia); //insere, na estrutura de dados, a distancia de origem até destino
            //imprimeLista(cidades);
        }
    }

    fclose(entrada); //fechar o arquivo lido

    //FIM - LEITURA DE ARQUIVO E ALOCAÇÃO NA ESTRUTURA DE DADOS;
    

    //clock_t tempo;
    //tempo = clock();

    //INICIO - CÁLCULO DOS CUSTOS DE CADA PERCURSO COMPLETO
    int custoMin = INT_MAX; //Esse é o valor do maior inteiro em C, o que garante que ele será substituído na primeira iteração
    int inicio;
    scanf("%d", &inicio);//leitura da cidade inicial
    int *vetorCidades = initVetor(n, inicio); //inicializa um vetor com as cidades, cujo primeiro elemento é a cidade inicial
    int *resp;
    minCusto(cidades, vetorCidades, 1, n - 1, &custoMin, &resp);
    clear(&cidades);
    //FIM - CÁLCULO DOS CUSTOS DE CADA PERCURSO COMPLETO

    //INICIO -  EXBIÇÂO DO MENOR CUSTO E MENOR CAMINHO
    printf("custo min: %d\n", custoMin);
    printf("caminho: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", resp[i]);
    }
    printf("%d\n", vetorCidades[0]);
    //FIM - EXIBIÇÂO DO MENOR CUSTO E MENOR CAMINHO
    //printf("Tempo:%lf\n",(clock() - tempo) / (double)CLOCKS_PER_SEC);
   
    return 0;
}

void printLinha(LINHA *l) {
    printf("%d %d %d\n", l->origem, l->destino, l->distancia);
}