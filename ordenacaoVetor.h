#include <iostream>

/// Recursivo/////////////////////////////
void bubbleSortRecursao(int v[], int n);

void insertionSortRecursao(int v[], int n);

void selectionSortRecursao(int v[], int n, int i=0);

void quickSortRecursao(int v[], int min, int max);

void mergesortRecursao(int A[], int p, int r);

void heapSortRecursao(int v[], int n);

/// Auxiliar dos Recursivos//////

void Intercala (int A[], int p, int q, int r);

int separaRecursao(int A[], int p, int r);

void heapify(int v[], int n, int i);

//////////////////////////////////////////////////////////////////
// Iterativo /////////////////////////////////////

void mergeSortIterativo(int v[], int n);

void heapsortIterativo(int a[], int n);

void quickSortIterativo(int v[], int l, int h);

void bubblesortIterativo(int A[], int n);

void insertionsortIterativo(int A[], int n);

void selectionsort(int A[], int n);


/// Auxiliar dos Iterativos//////
void merge(int v[], int l, int m, int r);

int separaIterativo(int A[], int p, int r);

