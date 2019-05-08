#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "arvoreBinaria.h"
#include "arvoreAVL.h"
#include "vetor.h"

int main(){


    int cont;
    int *vet = criarVetor(1000000);
    int *vetbusca = criarVetor(30);
    preencheVetor(vetbusca,30);
    ArvoreBinaria *tree = inicializa();
    avl *arvore;

    int i,x;
    avl *aux;
    ArvoreBinaria *aux2;
    clock_t ticks[2];
    double tempoV, tempoA;

    for(i=0;i<10;i++){
        double tempoa, tempob;
        
        ArvoreBinaria *tree = inicializa();
        avl *arvore;
        preencheVetor(vet,10000);
        ticks[0] = clock();
        tree = preencheComVetor(tree,vet,10000);
        ticks[1] = clock();
        tempoa = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d° execucao, criando no arvore binaria em %lf", i, tempoa);
        printf("%d",altura(tree));
        ticks[0] = clock();
        for(cont=0;cont<10000;cont++){
        inserirAVL(arvore,vet[cont]);
        }
        ticks[1] = clock();
        tempob = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d° execucao, criando na arvore AVL em %lf", i, tempob);
        printf("%d",arvore->altura);
    }

    for(i=0;i<30;i++){
        ticks[0] = clock();
        aux2 = busca(tree,vetbusca[i]);
        if(aux2!=NULL) printf("Achou!\n");
        else printf("Não achou!\n");
        ticks[1] = clock();
        tempoA = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d° execucao, procurando %d na arvore binaria em %lf", i, vetbusca[i], tempoV);
        ticks[0] = clock();
        aux = buscavl(arvore,vetbusca[i]);
        if(aux!=NULL) printf("Achou!\n");
        else printf("Não achou!\n");
        ticks[1] = clock();
        tempoV = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        printf("%d° execucao, procurando %d na arvore AVL em %lf", i, vetbusca[i], tempoA);
    }

    tempoV /= 30;
    tempoA /= 30;

    printf("tempo gasto em media no vetor foi: %.1lf segundos\n", tempoV);
    printf("tempo gasto em media na arvore foi: %.1lf segundos\n", tempoA);

    return 1;
}