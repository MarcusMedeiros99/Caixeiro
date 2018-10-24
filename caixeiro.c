#include <malloc.h>

#define TRUE 1
#define FALSE 0


//estrutura das cidades
typedef struct cidadeij {
    int **custos;
} CIDADEIJ;

//estrutura da lista
typedef struct lista {
    int **inicio;
    int ordem; //uma matriz n por n é de ordem n
} LISTA;

//inicializa a lista, colocando valor NULL no seu inicio
LISTA* inicializa() { 
    LISTA* new = (LISTA *) malloc(sizeof(LISTA));

    if (new != NULL) {
        new->inicio = NULL;
        new->ordem = 0;
    }

    return new;
}

int isEmpty(LISTA* l) {
    return l->ordem == 0;
}

int insereCidades(LISTA* l,int n) {
    l->inicio = (int **)malloc( n * sizeof(int *)); //se for matriz, coloca n
    if (l->inicio != NULL) {
        l->ordem = n;
        for (int i = 0; i < n; i++) {
            (l->inicio)[i] = (int *)  malloc( n * sizeof(int)); 
            if (l->inicio[i] == NULL) return FALSE;
            printf("aloquei\n");
        }
        return TRUE;
    }
    return TRUE;
}
int insereCustos(LISTA* l, int i, int j, int d) {
    l->inicio[i][j]  = d;
    l->inicio[j][i] = d;
    return TRUE;
}

void imprimeIJ (LISTA* l, int i, int j) {
    printf("%d ", l->inicio[i][j]);
}

void imprimeLista (LISTA* l) {
    for (int i = 0; i < l->ordem; i++) {
        for (int j = 0; j < l->ordem; j++) {
            imprimeIJ(l, i, j);
            
        }
        printf("\n");
    }
}