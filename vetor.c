#include "vetor.c"


void criarLista(tipoLista *p){
	p->prim = NULL;
}

void inserirLista(tipoLista *p, int num){
	tipoNo *aux;
	 aux = (tipoNo *) malloc (sizeof(tipoNo));
	 aux->d = num;

	 aux->prox = p->prim;
	 p->prim = aux;

}
void preencheVetorDesordenado (int n,,int v[]){
	int valor,i;

	for(i = 0;i<n;i++){
		valor = rand()%1000000000 + 1;
		v[i] = valor;
	}
	
}


void preencheListaVetor (int n, tipoLista *lista,int v[]){
	int valor,i;

	for(i = 0;i<n;i++){
		valor = (i<0)?(rand()%):(rand()%);
		v[i] = valor;
		inserirLista(&lista, valor);


	}
}

void preencheVetorDesordenado (int n,,int v[]){
	int valor,i;

	for(i = 0;i<n;i++){
		valor = rand()%1000000000 + 1;
		v[i] = valor;
	}



void insertionSort(int  v[], int tamanho) {
    int i, j;
    int pivot;

    
    for(j = 1; j < tamanho; j++ ) {
      i = j -1;
      pivot = v[j];
      while((i>=0) && (v[i]>pivot)) {
	  v[i+1] = v[i];
	i--;
      }
      v[i+1] = pivot;
    }
  }

  
void bubbleSort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        printf("\n[%d] ", k);

        for (j = 0; j < n - 1; j++) {
            printf("%d, ", j);

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void quickSort(int v[], int tamanho) {

  qSortInterno(v, 0, tamanho-1);
}


void qSortInterno(int v[], int inicio, int fim) {
  int pivot;
  int temp;
  int i,j;

  if(fim - inicio > 0) { 
    i = inicio;
    j = fim;
    pivot = v[(i+j)/2];
    
    do {
      while(v[i] < pivot) i++; 
      while(v[j] > pivot) j--;
      if(i<= j) { 
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
	i++; j--;
      }
    } while (i<=j);
    qSortInterno(v,inicio, j);
    qSortInterno(v, i,fim);
  }
}



