#define CAIXEIRO_H

typedef struct cidadeij CIDADEij;
typedef struct lista LISTA;

LISTA* inicializa(); //COLOCA OS PONTEIROS EM NULL
int isEmpty(LISTA* l);
int insereCidades(LISTA* l, int n); //ALOCA N CIDADES
int insereCustos(LISTA*l, int i, int j, int d);
void imprimeLista(LISTA* l);
int calculaCusto(LISTA* l, int* vet, int n);
int consulta(LISTA* l, int i, int j);