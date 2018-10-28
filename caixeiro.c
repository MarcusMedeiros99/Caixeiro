/*Funções para utlização das estruturas de dados
para resolução do problema do caixeiro viajante 
utilizando método de força bruta
Autores:
Marcus Vinícius Medeiros Pará
Mateus
Francisco Mattos Fortes
*/

#include <malloc.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define ERRO -1

//INICIO - DEFINIÇÃO E INICIALIZAÇÃO DAS ESTRUTURAS
//estrutura da lista
typedef struct lista {
    int **inicio;
    int ordem; //quantidade de cidades
} LISTA;

//inicializa a lista, colocando valor NULL no seu inicio
LISTA* inicializa() { 
    LISTA* new = (LISTA *) malloc(sizeof(LISTA));

    if (new != NULL) {
        new->inicio = NULL;
        new->ordem = 0;//quantidade inicial de cidades zerada
    }

    return new;
}

int insereCidades(LISTA* l,int n) {//aloca o espaço para posteriormente inserir os custos
    if (l) {
        l->inicio = (int **)malloc( (n - 1) * sizeof(int *)); //se for matriz, coloca n
        if (l->inicio != NULL) {
            l->ordem = n;
            for (int i = 0; i < n - 1; i++) {
                (l->inicio)[i] = (int *)  malloc( (n - 1 - i) * sizeof(int)); 
                if (l->inicio[i] == NULL) return FALSE;
            
            }
            return TRUE;
        }
        return FALSE;
    }
    return ERRO;
}

//FIM - DEFINIÇÂO E INICIALIZAÇÃO DAS ESTRUTURAS

int isEmpty(LISTA* l) {
    if (l) return l->ordem == 0;
    return ERRO;
}

//INICIO - INSERÇÂO E ACESSO DE DADOS
int insereCustos(LISTA* l, int i, int j, int d) {
    if (l) { 
        if (j > i) l->inicio[i][j - i - 1] = d;
        else l->inicio[j][i - j - 1] = d;
        return TRUE;
    }
    return FALSE;
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

//FIM - INSERÇÂO E ACESSO DE DADOS

//INICIO - LIMPEZA DA MEMÓRIA APÓS USO
void clearAux(LISTA *l) {
    for (int i = 0; i < l->ordem - 1; i++) {
        l->inicio[i] = 0;
        free(l->inicio[i]);
    }
    free(l->inicio);
    l->ordem = 0;
}

void clear(LISTA **l) {
    clearAux(*l);
    free(*l);
}
//FIM- LIMPEZA DA MEMÓRIA APÓS USO


//INICIO - CÁLCULO DO MENOR CUSTO E AUXILIARES
void troca(int vetor[], int i, int j) //troca as posições do elementos DE UM VETOR nas posições 'i' e 'j'
{
    int aux = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = aux;
}

int *copyInt(int* origem, int n) { //função auxiliar que retorna uma cópia do vetor origem[]
    int *destino = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
    return destino;
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

//A função minCusto() faz as permutações dos elementos de "vetor[]", mantendo fixo o primeiro elemento
//A cada permutação é calculado o custo do caminho correspondente ao "vetor"
//Se o custo for menor que o anterior, ele é substituído, e o vetor "resp" recebe esse caminho de menor custo

void minCusto(LISTA* l, int vetor[], int inf, int sup, int *custo, int **resp)
{    
    if(inf == sup)
    {
       /*for(int i = 0; i <= sup; i++)
            printf("%d ", vetor[i]);
        printf("\n");*/
        int x = calculaCusto( l ,vetor, sup + 1);
        if (x < *custo) {
            *custo = x;
            *resp = copyInt(vetor, sup + 1);
        }

    }
    else
    {
        for(int i = inf; i <= sup; i++)
        {
            troca(vetor, inf, i);
            minCusto(l, vetor, inf + 1, sup, custo, resp);
            troca(vetor, inf, i); 
        }
    }
}

//A função vizinhoProx() calcula o custo do caminho a partir da origem
//Buscando sempre o proximo no mais proximo
void vizinhoProx(LISTA* l, int vetor[], int inf, int sup, int *custo, int **resp) {
	int i, j;
	int aux, maisprox;
	int menor;
	*custo = 0;
	
	while(inf <= sup) {
		menor = INT_MAX;
		for(i = inf; i <= sup; i++) {
			aux = consulta(l, vetor[inf-1] - 1, vetor[i] - 1);
			if(aux < menor) {
				menor = aux;
				maisprox = i;
			}
		}
		troca(vetor, inf, maisprox);
		*custo += menor;
		inf++;
	}
	*custo += consulta(l, vetor[sup] - 1, vetor[0] - 1);
	*resp = copyInt(vetor, sup + 1);
}
//FIM - CÁLCULO DO MENOR CUSTO E AUXILIARES
