#include "stdio.h"
#include "stdlib.h"
#include "time.h"

struct tipoArvoreAVL{
	int valor;
	int balance;
	struct tipoArvoreAVL *esq;
	struct tipoArvoreAVL *dir;
};
typedef struct tipoArvoreAVL ArvoreAVL;

int altura(ArvoreAVL *t){
	if(t==NULL) return 0;
	int hesq = altura(t->esq);
	int hdir = altura(t->dir);

	if(hesq>hdir) return hesq+1;
	else return hdir+1;
}

ArvoreAVL *cria(int valor, ArvoreAVL *esq, ArvoreAVL *dir){
	ArvoreAVL *novo = (ArvoreAVL *)malloc(sizeof(ArvoreAVL));

	novo->valor = valor;
	novo->balance = (altura(dir) - altura(esq));
	novo->esq = esq;
	novo->dir = dir;

	return novo;
}

int verificaAVL(ArvoreAVL *t){
	if(t==NULL) return 1;
	if(abs(altura(t->dir) - altura(t->esq)) <= 1) return 0;
}

void escreve(ArvoreAVL *t){
	if(t!=NULL){
		escreve(t->esq);
		printf("valor: %d balanceamento: (%d)\n", t->valor, t->balance);
		escreve(t->dir);
	}
}

void escreveVerifica(ArvoreAVL *t){
	if(!verificaAVL(t)) printf("NAO EH AVL!\n");
	escreve(t);
	printf("\n");
}

void rotacaoSimplesEsquerda(ArvoreAVL **t){
	ArvoreAVL *b = *t;
	ArvoreAVL *a = b->esq;
	b->esq = a->dir;
	a->dir = b;
	a->balance = 0;
	b->balance = 0;
	*t = a;
}

void rotacaoSimplesDireita(ArvoreAVL **t){
	ArvoreAVL *a = *t;
	ArvoreAVL *b = a->dir;
	a->dir = b->esq;
	b->esq = a;
	a->balance = 0;
	b->balance = 0;
	*t = b;
}

void rotacaoEsquerdaDireita(ArvoreAVL **t){
	ArvoreAVL *c = *t;
	ArvoreAVL *a = c->esq;
	ArvoreAVL *b = a->dir;

	c->esq = b->dir;
	a->dir = b->esq;
	b->esq = a;
	b->dir = c;

	switch(b->balance){
		case -1:
			a->balance = 0;
			c->balance = 1;
			break;
		case 0:
			a->balance = 0;
			c->balance = 0;
			break;
		case +1:
			a->balance = -1;
			c->balance = 0;
			break;
	}

	b->balance = 0;
	*t = b;
}

void rotacaoDireitaEsquerda(ArvoreAVL **t){
	ArvoreAVL *a = *t;
	ArvoreAVL *c = a->dir;
	ArvoreAVL *b = c->esq;

	c->esq = b->dir;
	a->dir = b->dir;
	b->esq = a;
	b->dir = c;

	switch(b->balance){
		case -1:
			a->balance = 0;
			c->balance = 1;
			break;
		case 0:
			a->balance = 0;
			c->balance = 0;
			break;
		case +1:
			a->balance = -1;
			c->balance = 0;
			break;
	}

	b->balance = 0;
	*t = b;
}

int auxInserir(ArvoreAVL **t,int valor, int cresceu){
	if(*t==NULL){
		*t = cria(valor, NULL, NULL);
		cresceu = 1;
		return 1;
	}

	if(valor==(*t)->valor) return 0;

	if(valor<(*t)->valor){
		if(auxInserir(&(*t)->esq, valor, cresceu)){
			if(cresceu){
				switch((*t)->balance){
					case -1:
						if((*t)->esq->balance==-1) rotacaoSimplesEsquerda(t);
						else rotacaoEsquerdaDireita(t);
						cresceu = 0;
						break;
					case 0:
						(*t)->balance = -1;
						cresceu = 1;
						break;
					case +1:
						(*t)->balance = 0;
						cresceu = 0;
						break;
				}
			}
			return 1;
		}else{
			return 0;
		}
	}

	if(auxInserir(&(*t)->dir, valor, cresceu)){
		if(cresceu){
			switch((*t)->balance){
				case -1:
					(*t)->balance = 0;
					cresceu = 0;
					break;
				case 0:
					(*t)->balance = +1;
					cresceu = 0;
					break;
				case +1:
					if((*t)->dir->balance==+1) rotacaoSimplesDireita(t);
					else rotacaoDireitaEsquerda(t);
					cresceu = 0;
					break;
			}
		}
		return 1;
	}else{
		return 0;
	}
}

int inserirAVL(ArvoreAVL **t, int valor){
	int cresceu;
	return auxInserir(t,valor,cresceu);
}
