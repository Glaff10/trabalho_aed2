#include "vetor.h"

clock_t start, end;
double cpu_time_used;

int main(){

	double media_bin=0, media_seq=0;
	int *V;

    V = (int*) malloc(sizeof(int)*1000000);

    preencheVetorOrdenado(1000000, V);

    int i=0;
	for( i=0; i<30; i++){

		int x;
		int r = rand() % 20;

		start = clock();

		x = buscaBinariaVetor(r, 1000000, V);

		end = clock();

		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

		media_bin += cpu_time_used;

		printf("O tempo de execução da %d busca, procurando o elemento %d em busca binaria no vetor foi: %lf\n", i, x, cpu_time_used);

		x = BuscaSequencialVetor(r, 1000000, V);

		end = clock();

		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

		media_seq += cpu_time_used;

		printf("O tempo de execução da %d busca, procurando o elemento %d em busca sequencial no vetor foi: %lf\n", i, x, cpu_time_used);
	}

	printf("A media do tempo de execução na busca binaria == %lf\nA media do tempo de execução na busca sequencial == %lf\n", media_bin/30, media_seq/30);

	return 0;
}
