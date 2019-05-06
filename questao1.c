#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "arvoreBinaria.h"
#include "vetor.h"

int main(){
	ArvoreBinaria *tree = inicializa();

	tree = preencheArvore(tree,50);
	printf("PRE-ORDEM\n");
	preordem(tree);
	printf("CENTRAL\n");
	central(tree);
	printf("POS-ORDEM\n");
	posordem(tree);
	printf("\n");
	return 1;
}
