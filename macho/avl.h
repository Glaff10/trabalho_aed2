#include<stdio.h>
#include<stdlib.h>

struct avl{
  int num, altura;
  struct avl* esq;
  struct avl* dir;
};

typedef struct avl avl;

avl* criaAvl();

int taCerto(avl *atu, int n);

avl* inserirAvl(avl *a,int num);

void imprimeAvl(avl *a, int val);

avl* buscaAvl(avl *a, int num);

avl* liberaAvl(avl *a);

int taBalanceada(avl *atu);