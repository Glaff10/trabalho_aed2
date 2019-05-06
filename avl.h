#ifndef ARVOREAVL_H
#define ARVOREAVL_H

//DEFINICAO DO TIPO ARVORE
typedef struct tipoArvoreAVL ArvoreAVL;

//FUNCOES DE MANIPULACAO DA ARVORE
ArvoreAVL *cria(int valor, ArvoreAVL *esq, ArvoreAVL *dir);
int altura(ArvoreAVL *t);
int verificaAVL(ArvoreAVL *t);
void escreve(ArvoreAVL *t);
void escreveVerifica(ArvoreAVL *t);
void rotacaoSimplesEsquerda(ArvoreAVL **t);
void rotacaoSimplesDireita(ArvoreAVL **t);
void rotacaoEsquerdaDireita(ArvoreAVL **t);
void rotacaoDireitaEsquerda(ArvoreAVL **t);
int inserirAVL(ArvoreAVL **t, int valor);
int auxInserir(ArvoreAVL **t,int valor, int *cresceu);

#endif
