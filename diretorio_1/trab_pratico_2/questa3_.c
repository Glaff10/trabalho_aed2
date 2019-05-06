/*Crie uma �rvore bin�ria de pesquisa com 1.000.000 (um milh�o) de elementos do tipo
inteiro. Implemente as opera��es de inser��o e de busca por um valor. Compare o
tempo da busca na �rvore com o tempo da busca bin�ria no vetor implementado no
trabalho pr�tico 1. Os valores presentes no vetor e na �rvore devem ser os mesmos.
Execute a busca 30 vezes usando os mesmos valores de busca para a �rvore e para o
vetor em cada execu��o. Calcule o tempo de execu��o para cada busca e a m�dia entre
as 30 execu��es para cada estrutura de dados. Observe a utiliza��o de mem�ria durante
a execu��o do programa: qual a menor e maior ocupa��o da mem�ria verificados*/

#include<stdio.h>
#include<time.h>


int main(){

    *prim = Cria_Arvore_Binaria();

    preenche_Arvore_Binaria(1000000, prim);

    preenche_Vetor(1000000, V);

    insercao_Arvore_Binaria(r);

    busca_Arvore_Binaria(r);

    int i,x;
    clock_t in, f;
    double tempob, tempoi, tempoq;


    for(i=0;i<30;i++){
        in = clock();

        x = 1000000/(i+1);
        int t = busca_binariaNoVetor(x, V);

        f = clock();

        tempoV += ((double) (f-in))/CLOCKS_PER_SEC

        in = clock();

        tempoV += ((double) (f-in))/CLOCKS_PER_SEC

        int h = busca_Arvore_Binaria(x, prim);

        f = clock();

        tempoA += ((double) (f-in))/CLOCKS_PER_SEC

        printf("%d� execucao, procurando %d no vetor e achando %d em %lf", i, x, t, tempoV);
        printf("%d� execucao, procurando %d na arvore e achando %d em %lf", i, x, h, tempoA);
    }

    tempoV /= 30;
    tempoA /= 30;

    printf("tempo gasto em media no vetor foi: %.1lf segundos\n", tempoV);
    printf("tempo gasto em media na arvore foi: %.1lf segundos\n", tempoA);

    return 0;
}
