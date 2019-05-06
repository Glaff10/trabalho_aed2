#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct tipoArvore{
	int valor;
	struct tipoArvore *esq;
	struct tipoArvore *dir;
};
typedef struct tipoArvore ArvoreBinaria;

ArvoreBinaria *inicializa(void){
	return NULL;
}

ArvoreBinaria *inserir(ArvoreBinaria *t, int valor){
	if(t==NULL){
		t = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
		t->valor = valor;
		t->esq = t->dir = NULL;
	}else if(valor < t->valor){
		t->esq = inserir(t->esq,valor);
	}else{
		t->dir = inserir(t->dir,valor);
	}

	return t;
}

ArvoreBinaria *preencheArvore(ArvoreBinaria *a, int tam){
	int cont, valor;

	srand(time(NULL));
	for(cont=0;cont<tam;cont++){
		valor = rand() % (int)(2,5*tam);
		a = inserir(a,valor);
	}

	return a;
}

ArvoreBinaria *preencheComVetor(ArvoreBinaria *t, int *vet, int tam){
	int cont, valor;

	for(cont=0;cont<tam;cont++){
		t = inserir(t,vet[cont]);
	}

	return t;
}

ArvoreBinaria *busca(ArvoreBinaria *t, int chave){
	if(t==NULL) return NULL;
	else if(t->valor > chave) return busca(t->esq,chave);
	else if(t->valor < chave) return busca(t->dir,chave);
	else return t;
}

ArvoreBinaria *retira(ArvoreBinaria *t, int valor){
	if(t==NULL) return NULL;
	else if(t->valor>valor) t->esq = retira(t->esq,valor);
	else if(t->valor<valor) t->dir = retira(t->dir,valor);
	else{
		if(t->esq==NULL&&t->dir==NULL){
			free(t);
			t = NULL;
		}else if(t->esq==NULL){
			ArvoreBinaria *a = t;
			t = t->dir;
			free(a);
		}else if(t->dir==NULL){
			ArvoreBinaria *a = t;
			t = t->esq;
			free(a);
		}else{
			ArvoreBinaria *pai = t;
			ArvoreBinaria *filho = t->esq;
			while(filho->dir!=NULL){
				pai = filho;
				filho = filho->dir;
			}

			t->valor = filho->valor;
			filho->valor = valor;
			t->esq = retira(t->esq,valor);
		}

		return t;
	}
}

ArvoreBinaria *recebeArquivo(int tam){
	int cont, pacote;
	ArvoreBinaria *arquivo = inicializa();
	ArvoreBinaria *aux;

	cont=0;
	while(cont<tam){
		pacote = rand() % (tam*2);
		aux = busca(arquivo,pacote);
		if(aux==NULL){
			arquivo = inserir(arquivo,pacote);
			cont++;
		}else{
			printf("O PACOTE %d JAH FOI RECEBIDO\n", pacote);
		}
	}

	return arquivo;
}


void preordem (ArvoreBinaria *a){
	if (a!=NULL){
		printf("%d \n", a->valor); /* mostra raiz */
		preordem(a->esq); /* mostra sae */
		preordem(a->dir); /* mostra sad */
	}
}

void central (ArvoreBinaria *a){
	if (a!=NULL){
		central(a->esq); /* mostra sae */
		printf("%d \n", a->valor); /* mostra raiz */
		central(a->dir); /* mostra sad */
	}
}

void posordem (ArvoreBinaria *a){
	if (a!=NULL){
		posordem(a->esq); /* mostra sae */
		posordem(a->dir); /* mostra sad */
		printf("%d \n", a->valor); /* mostra raiz */
	}
}

void montarArquivo(ArvoreBinaria *arquivo){
	printf("MONTANDO ARQUIVO A PARTIR DOS PACOTES\n");
	central(arquivo);
}
