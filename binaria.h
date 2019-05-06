#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

//DEFINICAO DO TIPO ARVORE
typedef struct tipoArvore ArvoreBinaria;

//FUNCOES DE MANIPULACAO DA ARVORE
ArvoreBinaria *inicializa(void);
ArvoreBinaria *inserir(ArvoreBinaria *t, int valor);
ArvoreBinaria *preencheArvore(ArvoreBinaria *a, int tam);
ArvoreBinaria *preencheComVetor(ArvoreBinaria *t, int *vet, int tam);
ArvoreBinaria *busca(ArvoreBinaria *t, int chave);
ArvoreBinaria *retira(ArvoreBinaria *t, int valor);
ArvoreBinaria *recebeArquivo(int tam);
void preordem (ArvoreBinaria *a);
void central (ArvoreBinaria *a);
void posordem (ArvoreBinaria *a);
void montarArquivo(ArvoreBinaria *arquivo);

#endif
