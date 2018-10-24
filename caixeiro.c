#include <malloc.h>

#define TRUE 1
#define FALSE 0


//estrutura das cidades
typedef struct cidadeij {
    /*union {
        int distancia; //distancia da cidade i até a j. Se distancia = 0, esse elemento é uma lista;
        struct cidadeij* abaixo;
    }*/
    int **custos;
} CIDADEIJ;

//estrutura da lista
typedef struct lista {
    //CIDADEIJ* inicio;
    int ** custos;
    int tamanho;
} LISTA;

//inicializa a lista, colocando valor NULL no seu inicio
LISTA* inicializa() { 
    LISTA* new = (LISTA *) malloc(sizeof(LISTA));

    if (new != NULL) {
        new->inicio = NULL;
        new->tamanho = 0;
    }

    return new;
}

int isEmpty(LISTA* l) {
    return l->tamanho == 0;
}

int insereCidades(LISTA* l,int n) {
    l->inicio = (CIDADEIJ *)malloc( (n - 1)  * sizeof(CIDADEIJ));
    if (l->inicio != NULL) {
        l->tamanho = n;
        for (int i = 0; i < n - 1; i++) {
            //(l->inicio)[i].distancia = 0;
            (l->inicio)[i].abaixo =  malloc((n - 1 - i)  * sizeof(CIDADEIJ)); //pq tinha warning???
            if (l->inicio[i].abaixo != NULL) return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}
int insereCustos(LISTA* l, int i, int j, int d) {
    l->inicio[i].abaixo[j].distancia  = d;
    return TRUE;
}

void imprimeIJ (LISTA* l, int i, int j) {
    printf("%d", l->inicio[i].abaixo[i].distancia);
}

void imprimeLista (LISTA* l) {
    for (int i = 0; i < l->tamanho - 1; i++) {
        for (int j = 0; j < l->tamanho - 1; j++) {
            imprimeIJ(l, i, j);
        }
    }
}