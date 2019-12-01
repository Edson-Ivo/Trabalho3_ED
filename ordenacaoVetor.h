#include <iostream>

/// Recursivo/////////////////////////////
void bubbleSortRecursaoVetor(int v[], int n);
int bubbleSortRecursaoVetorCom(int v[], int n);
int bubbleSortRecursaoVetorTroca(int v[], int n);

void insertionSortRecursaoVetor(int v[], int n);
int insertionSortRecursaoVetorCom(int v[], int n);
int insertionSortRecursaoVetorTroca(int v[], int n);

void selectionSortRecursaoVetor(int v[], int n, int i=0);
int selectionSortRecursaoVetorCom(int v[], int n, int i=0);
int selectionSortRecursaoVetorTroca(int v[], int n, int i=0);

void quickSortRecursaoVetor(int v[], int min, int max);
int quickSortRecursaoVetorCom(int v[], int min, int max);
int quickSortRecursaoVetorTroca(int v[], int min, int max);

void mergesortRecursaoVetor(int A[], int p, int r);
int mergesortRecursaoVetorCom(int A[], int p, int r);
int mergesortRecursaoVetorTroca(int A[], int p, int r);

void heapSortRecursaoVetor(int v[], int n);
int heapSortRecursaoVetorCom(int v[], int n);
int heapSortRecursaoVetorTroca(int v[], int n);

/// Auxiliar dos Recursivos//////

void Intercala (int A[], int p, int q, int r);
void IntercalaTroca (int A[], int p, int q, int r);
void IntercalaCom (int A[], int p, int q, int r);

int separaRecursaoVetor(int A[], int p, int r);
int separaRecursaoVetorCom(int A[], int p, int r);
int separaRecursaoVetor(int A[], int p, int r);

void heapify(int v[], int n, int i);
void heapifyTroca(int v[], int n, int i);
void heapifyCom(int v[], int n, int i);

//////////////////////////////////////////////////////////////////
// IterativoVetor /////////////////////////////////////

void mergeSortIterativoVetor(int v[], int n);
int mergeSortIterativoVetorCom(int v[], int n);
int mergeSortIterativoVetorTroca(int v[], int n);

void heapsortIterativoVetor(int a[], int n);
int heapsortIterativoVetorCom(int a[], int n);
int heapsortIterativoVetorTroca(int a[], int n);

void quickSortIterativoVetor(int v[], int l, int h);
int quickSortIterativoVetorCom(int v[], int l, int h);
int quickSortIterativoVetorTroca(int v[], int l, int h);

void bubblesortIterativoVetor(int A[], int n);
int bubblesortIterativoVetorCom(int A[], int n);
int bubblesortIterativoVetorTroca(int A[], int n);

void insertionsortIterativoVetor(int A[], int n);
int insertionsortIterativoVetorCom(int A[], int n);
int insertionsortIterativoVetorTroca(int A[], int n);

void selectionsortIterativoVetor(int A[], int n);
int selectionsortIterativoVetorCom(int A[], int n);
int selectionsortIterativoVetorTroca(int A[], int n);


/// Auxiliar dos IterativoVetors//////
void merge(int v[], int l, int m, int r);
void mergeCom(int v[], int l, int m, int r);
void mergeTroca(int v[], int l, int m, int r);

int separaIterativoVetor(int A[], int p, int r);
int separaIterativoVetorCom(int A[], int p, int r);
int separaIterativoVetorTroca(int A[], int p, int r);

