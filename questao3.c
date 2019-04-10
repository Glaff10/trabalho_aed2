#include<stdio.h>
#include<time.h>

void bubbleSort (int vetor[], int n){
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void insertionSort(int  v[], int tamanho){
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

void preencheVetorDesordenado (int n,int v[]){
	int valor,i;

	for(i = 0;i<n;i++){
		valor = rand()%1000000000 + 1;
		v[i] = valor;
	}
}

int main(){
    int vet[100000];
    int i,x;
    clock_t in, f;
    double tempob, tempoi, tempoq;

    in clock();
    for(i=0;i<30;i++){
        preencheVetorDesordenado(100000,vet);
        bubbleSort(vet,100000);
    }
    f = clock();
    tempob = ((double) (f-in))/CLOCKS_PER_SEC;
    printf("tempo gasto %.1lf segundos\n",tempob);
    in = clock();
    for(i=0;i<30;i++){
        preencheVetorDesordenado(100000,vet);
        insertionSort(vet,100000);
    }
    f = clock();
    tempoi = ((double) (f-in))/CLOCKS_PER_SEC;
    printf("tempo gasto %.1lf segundos\n",tempoi);
    in = clock();
    for(i=0;i<30;i++){
        preencheVetorDesordenado(100000,vet);
        quickSort(vet,100000);
    }
    f = clock();
    tempoq = ((double) (f-in))/CLOCKS_PER_SEC;
    printf("tempo gasto %.1lf segundos\n",tempoq);

    return 1;
}
