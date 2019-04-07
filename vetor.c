#include "vetor.c"
#include <stdlib.h>
#include <time.h>


void criarListaEncadeada(tipoLista *p){
	p->prim = NULL;
}



No* CriaNo(int num){
	No*aux;
	aux = (No*)malloc(sizeof(No));
	aux->prox = NULL;
	aux->d = num;
	return aux;
}

void CriaNoListaEncadeada(ListaEncadeada *lista, int num){
	No*i = lista->prim;
	if(i){
		No*j = lista->ult;
		j->prox = CriaNode(num);
		lista->ult = j->prox;
	}
	else{
		lista->prim = CriaNo(num);
		lista->ult = lista->prim;
	}
}




void preencheVetorOrdenado(int n, int v[]){
	clock_t t;
	srand((unsigned)time(t));
	for(int i=0; i<n; i++)
		v[i] =  (i>0)?(v[i-1] + rand()%10+1):(rand()%10+1);
}



void preencheListaVetor (int n, tipoLista *lista,int v[]){
	int valor,i;

	for(i = 0;i<n;i++){
		valor = (i<0)?(rand()%):(rand()%);
		v[i] = valor;
		CriaNoListaEncadeada(&lista, valor);


	}
}


void preencheVetorDesordenado (int n,,int v[]){
	int valor,i;

	for(i = 0;i<n;i++){
		valor = rand()%1000000000 + 1;
		v[i] = valor;
	}
	
	

int buscaBinariaVetor(int chave, int n, int v[]){
	int ini = 0, fim = n-1, meio;
	while(ini<=fim){
		meio = (ini+fim)/2;
		if(v[meio] < chave)
			ini = meio + 1;
		else if(v[meio] > chave)
			fim = meio - 1;
		else
			return meio;
	}
	return -1;
}
	

int BuscaSequencialVetor(int chave, int n, int v[]){
	for(int i=0; i<n; i++)
		if(v[i] == chave)
			return i;
	return -1;
}

int BuscaSequencialListaEncadeada(int chave, tipoLista lista){
	for(No* i = lista.prim; ; i = i->prox){
		if(!i)
			break;
		if(i->d == chave)
			return 1;
	}
	return 0;
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

  
	
void bubbleSort (int vetor[], int n){
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
