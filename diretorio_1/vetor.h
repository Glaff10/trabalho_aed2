#ifndef VETOR_H
#define VETOR_H


typedef struct tipoNo {
  int d;
  struct tipoNo *prox;
} tipoNo;

typedef struct {
  tipoNo *prim, *ult;

} tipoLista;

void criarListaEncadeada(tipoLista *lista); // Cria Lista encadeada
tipoNo* CriaNo(int num); //Cria um novo no
void CriaNoListaEncadeada(tipoLista *lista, int num); //Cria um novo no na lista
void preencheVetorOrdenado(int n, int v[]); //preenche o vetor aleatoriamente padronizada
void preencheListaVetor (int n, tipoLista *lista,int v[]); //preenche lista e vetor com os mesmos valores
void preencheVetorDesordenado (int n,int v[]); //preenche o vetor de forma completamente aleatoria
int buscaBinariaVetor(int chave, int n, int v[]); //busca binaria no vetor
int BuscaSequencialVetor(int chave, int n, int v[]); //busca sequencial no vetor
int BuscaSequencialListaEncadeada(int chave, tipoLista lista); //busca sequencial lista Encadeada
void insertionSort(int  v[], int tamanho); // insertion sort
void bubbleSort (int vetor[], int n); //bubble sort
void quickSort(int v[], int tamanho); //quick sort



#endif
