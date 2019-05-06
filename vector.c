#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "time.h"

int *criarVetor(int tam){
	int *vet = (int *)malloc(sizeof(int)*tam);

	return vet;
}

void preencheVetor(int *vet, int tam){
	int cont, valor;

	valor = rand() % 10;
	for(cont=0;cont<tam;cont++){
		valor = valor + rand() % 10;
		vet[cont] = valor;
	}
}

void preencheVetorTeste(int *vet, int tam){
	int cont, valor;

	valor = rand() % 10;
	for(cont=0;cont<tam;cont++){
		valor = valor + rand() % 1000;
		vet[cont] = valor;
	}	
}

void bubleSort(int *vetor, int tam){
	int cont, aux;
	bool relou;

	do{
		relou = false;
		for(cont=0;cont<tam-1;cont++){
			if(vetor[cont]>vetor[cont+1]){
				aux = vetor[cont];
				vetor[cont] = vetor[cont+1];
				vetor[cont+1] = aux;
				relou = true;
			}
		}
	}while(relou);
}

void insertionSort(int *vetor, int tam){
	int cont, constante, indMenor;

	for(constante=0;constante<tam-1;constante++){
		indMenor = constante;
		for(cont=constante+1;cont<tam;cont++){
			if(vetor[cont]<vetor[indMenor]) indMenor = cont;

			int aux = vetor[constante];
			vetor[constante] = vetor[indMenor];
			vetor[indMenor] = aux;
		}
	}
}

void quickSort(int *vetor, int inicio, int fim){
	int pivo, aux, i, j, meio;

	i = inicio;
	j = fim;
	meio = (int)((i+j)/2);
	pivo = vetor[meio];

	do{
		while(vetor[i]<pivo) i++;
		while(vetor[j]>pivo) j--;

		if(i<=j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}while(j>i);

	if(inicio<j) quickSort(vetor,inicio,j);
	if(i<fim) quickSort(vetor,i,fim);
}

int buscaBinariaVetor(int *vet, int tam, int chave){
	int inicio, fim, meio;

	inicio = 0;
	fim = tam-1;
	meio = (inicio+fim)/2;

	while(fim>inicio){
		if(vet[meio]==chave) return 0;
		else if(vet[meio]>chave) fim--;
		else if(vet[meio]<chave) inicio++;

		meio = (inicio+fim)/2;
	}

	return 1;
}

int buscaSequencialVetor(int *vet, int tam, int chave){
	int cont;

	while(cont>tam){
		if(vet[cont]==chave) return 0;

		cont++;
	}

	return 1;
}
