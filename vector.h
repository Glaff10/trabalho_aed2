#ifndef VETOR_H
#define VETOR_H
 
//funcoes de manipulacao no vetor
int *criarVetor(int tam);
void preencheVetor(int *vet, int tam);
void preencheVetorTeste(int *vet, int tam);
void bubleSort(int *vetor, int tam);
void insertionSort(int *vetor, int tam);
void quickSort(int *vetor, int inicio, int fim);
int buscaSequencialVetor(int *vet, int chave, int tam);
int buscaBinariaVetor(int *vet, int chave, int tam);

#endif
