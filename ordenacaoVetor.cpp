#include <iostream>
#include "ordenacaoVetor.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Recursivo/////////////////////////////////
void bubbleSortRecursao(int v[], int n) { 
    if (n != 1) {
    for (int i=0; i<n-1; i++) 
        if (v[i] > v[i+1]) 
            swap(v[i], v[i+1]); 
  
    bubbleSortRecursao(v, n-1);
    }else{
        return;
    } 
}

void insertionSortRecursao(int v[], int n) { 
    if (n <= 1) 
        return;     
  
    insertionSortRecursao( v, n-1 ); 
    int key = v[n-1]; 
    int j = n-2; 
  
    while (j >= 0 && v[j] > key) 
    { 
        v[j+1] = v[j]; 
        j--; 
    } 
    v[j+1] = key; 
}

void mergesortRecursao(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; 
        mergesortRecursao(A, p, q);
        mergesortRecursao(A, q + 1, r);
        Intercala(A, p, q, r);
    }
}

void selectionSortRecursao(int v[], int n, int i){
	int min = i;
	for (int j = i + 1; j < n; j++)
	{
		if (v[j] < v[min])
			min = j;	
	}
	swap(v[min],v[i]);

	if (i + 1 < n) {
		selectionSortRecursao(v,n,i + 1);
	}
}

void quickSortRecursao(int v[], int min, int max) {  
    if (min < max){  
        int x = separaRecursao(v, min, max);  
        quickSortRecursao(v, min, x - 1);  
        quickSortRecursao(v, x + 1, max);  
    }  
}


void heapSortRecursao(int v[], int n){ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(v, n, i); 
    for (int i=n-1; i>=0; i--){ 
        swap(v[0], v[i]); 
        heapify(v, i, 0); 
    } 
}

//// Auxiliares do recursivo/////////////////////////////////////////////////////////////////////////
void Intercala (int A[], int p, int q, int r) {
    int i, j, k;
    int *W = new int[r-p+1]; 
    i = p; j = q+1; k = 0;

        while (i <= q && j <= r) {
            if (A[i] <= A[j])
            W[k++] = A[i++];
            else
            W[k++] = A[j++];
        }

    while (i <= q) W[k++] = A[i++];
    while (j <= r) W[k++] = A[j++];

    for (i = p; i <= r; i++)
        A[i] = W[i-p];
    delete[] W;
 }

int separaRecursao(int A[], int p, int r) {
    int c = A[r];
    int j = p;
    for (int k = p; k < r; k++) {
        if (A[k] <= c) {
            swap(A[k], A[j]);
            j++;
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}

void heapify(int v[], int n, int i){ 
    int temp = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && v[l] > v[temp]) 
        temp = l; 
  
    if (r < n && v[r] > v[temp]) 
        temp = r; 
  
    if (temp != i) { 
        swap(v[i], v[temp]); 
        heapify(v, n, temp); 
    } 
} 
///////////////////////////////////////////////////////////////////////////////////////////////////////
//// Iterativo///////////////////////////////////////////////////////////////

void mergeSortIterativo(int v[], int n) 
{ 
   int tam;  
   int esq; 

   for (tam=1; tam<=n-1; tam = 2*tam) { 
       for (esq=0; esq<n-1; esq += 2*tam) {
           int mid;
           int dir;
            if(esq+tam-1<n-1){
                mid=esq+tam-1;
            }else{
                mid=n-1;
            }
            if(esq+2*tam-1<n-1){
                dir=esq+2*tam-1;
            }else{
                dir=n-1;
            }
           merge(v, esq, mid, dir); 
       } 
    } 
} 

void heapsortIterativo(int a[], int n) {
   int i = n / 2, p, f, t;
   while(true) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n <= 0) return;
          t = a[n];
          a[n] = a[0];
      }
      p = i;
      f = i * 2 + 1;
      while (f < n) {
          if ((f + 1 < n)  &&  (a[f + 1] > a[f]))
              f++;
          if (a[f] > t) {
             a[p] = a[f];
             p = f;
             f = p * 2 + 1;
          } else {
             break;
          }
      }
      a[p] = t;
   }
}

void quickSortIterativo(int v[], int l, int h) { 
    int vec[h - l + 1]; 

    int top = -1; 
  
    vec[++top] = l; 
    vec[++top] = h; 
  
    while (top >= 0) { 
        h = vec[top--]; 
        l = vec[top--]; 
        int p = separaIterativo(v, l, h); 
  
       
        if (p - 1 > l) { 
            vec[++top] = l; 
            vec[++top] = p - 1; 
        } 
  
        if (p + 1 < h) { 
            vec[++top] = p + 1; 
            vec[++top] = h; 
        } 
    } 
} 

void bubblesortIterativo(int A[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; j--)
            if (A[j] < A[j-1])
                std::swap(A[j],A[j-1]);
}

void insertionsortIterativo(int A[], int n) {
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j-1;

        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

void selectionsort(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
    int min = i;

    for (int j = i+1; j < n; j++)
        if(A[j] < A[min])
            min = j;

    std::swap(A[i],A[min]);
    }
}
  
// Auxiliar de Iterativo ///////////////////////////////////////////////////////////////
void merge(int v[], int l, int m, int r){ 

    int i, j, k; 
    int x = m - l + 1; 
    int y =  r - m; 
  
    int v1[x], v2[y]; 
  
    for (i = 0; i < x; i++) 
        v1[i] = v[l + i]; 
    for (j = 0; j < y; j++) 
        v2[j] = v[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 

    while (i<x && j < y) { 
        if (v1[i] <= v2[j]){ 
            v[k] = v1[i]; 
            i++; 
        } 
        else{ 
            v[k] = v2[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < x){ 
        v[k] = v1[i]; 
        i++; 
        k++; 
    } 

    while (j < y){ 
        v[k] = v2[j]; 
        j++; 
        k++; 
    } 
} 

int separaIterativo(int A[], int p, int r) {
    int c = A[r];
    int j = p;
    for (int k = p; k < r; k++) {
        if (A[k] <= c) {
            swap(A[k], A[j]);
            j++;
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}




