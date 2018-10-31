#define CAIXEIRO_H

#define TRUE 1
#define FALSE 0
#define ERRO -1

typedef struct lista LISTA;

LISTA* inicializa(); //COLOCA OS PONTEIROS EM NULL
int isEmpty(LISTA* l);
int insereCidades(LISTA* l, int n); //ALOCA N CIDADES
int insereCustos(LISTA*l, int i, int j, int d);
void imprimeLista(LISTA* l);
int calculaCusto(LISTA* l, int* vet, int n);
int consulta(LISTA* l, int i, int j);
void minCusto(LISTA* l, int vetor[], int inf, int sup, int *custo, int **resp);
void vizinhoProx(LISTA* l, int vetor[], int inf, int sup, int *custo, int **resp);
void clear(LISTA** l);
