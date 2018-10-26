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
    l->inicio = (int **)malloc( (n - 1) * sizeof(int *)); //se for matriz, coloca n
    if (l->inicio != NULL) {
        l->ordem = n;
        for (int i = 0; i < n - 1; i++) {
            (l->inicio)[i] = (int *)  malloc( (n - 1 - i) * sizeof(int)); 
            if (l->inicio[i] == NULL) return FALSE;
            
        }
        return TRUE;
    }
    return TRUE;
}
int insereCustos(LISTA* l, int i, int j, int d) {
    //l->inicio[i][j]  = d;
    //l->inicio[j][i] = d;

    if (j > i) l->inicio[i][j - i - 1] = d;
    else l->inicio[j][i - j - 1] = d;
    return TRUE;
}

int consulta(LISTA* l, int i, int j) {


    return  j > i?  l->inicio[i][j - i - 1] : l->inicio[j][i - j - 1] ;
}

void imprimeIJ (LISTA* l, int i, int j) {
    printf("%d ", l->inicio[i][j]);
    
}

void imprimeLista (LISTA* l) {
    for (int i = 0; i < l->ordem - 1; i++) {
        for (int j = 0; j < l->ordem - i - 1; j++) {
            imprimeIJ(l, i, j);
            
        }
        printf("\n");
    }
}
int calculaCusto(LISTA* l, int* vet, int n){
    int custo = consulta(l, vet[n-1] - 1, vet[0] - 1);
    int aux = vet[0];
    for (int i = 1; i < n; i++) {
        custo += consulta(l, aux - 1, vet[i] - 1);
        aux = vet[i];
    }
   
    return custo;
}