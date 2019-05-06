#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "arvoreBinaria.h"
#include "vetor.h"

int main(){
	int *vet = criarVetor(1000000), *teste = criarVetor(30);
	ArvoreBinaria *tree = inicializa(), *aux;
	char *op;
	int cont, valor;
	clock_t ticks[2];
	double tempoVet, tempoArv, mediaVet, mediaArv;

	printf("PREENCHENDO O VETOR\n");
	preencheVetor(vet,1000000);
	printf("PREENCHENDO O TESTE\n");
	preencheVetorTeste(teste,30);
	printf("PREENCHENDO A ARVORE\n");
	tree = preencheComVetor(tree,vet,1000000);
	mediaVet = 0.0f;
	mediaArv = 0.0f;

	printf("INICIAR TESTE DE BUSCA NO VETOR E NA ARVORE\n");
	for(cont=0;cont<30;cont++){
		valor = teste[cont];
		printf("buscando pelo valor %d\n", valor);
		printf("BUSCA NO VETOR\n");
		ticks[0] = clock();
		if(buscaBinariaVetor(vet,valor,1000000)==0) printf("ACHOU!\n");
		else printf("N ACHOU!\n");
		ticks[1] = clock();
		tempoVet = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;

		printf("BUSCA NA ARVORE\n");
		ticks[0] = clock();
		aux = busca(tree,valor);
		if(aux!=NULL) printf("ACHOU!\n");
		else printf("N ACHOU!\n");
		ticks[1] = clock();
		tempoArv = (ticks[1] - ticks[0]) * 1000.0 / CLOCKS_PER_SEC;		

		mediaVet = mediaVet + tempoVet;
		mediaArv = mediaArv + tempoArv;
		printf("TEMPO DA BUSCA NO VETOR: %g ms.\n", tempoVet);
		printf("TEMPO DA BUSCA NA ARVORE: %g ms.\n", tempoArv);
	}

	mediaVet = mediaVet/30.0;
	mediaArv = mediaArv/30.0;
	printf("\n\n");
	printf("MEDIA DA BUSCA NO VETOR: %g ms.\n", mediaVet);
	printf("MEDIA DA BUSCA NA ARVORE: %g ms.\n", mediaArv);
	printf("DIGITA ALGO AE SO PRA TRAVAR O PROGRAMA:\n");
	scanf("%s", op);
	printf("ACABOU!\n");

	return 1;
}
