#include <iostream>
#include "ordenacaoVetor.h"

using namespace std;

//// Auxiliares do recursivo/////////////////////////////////////////////////////////////////////////
void intercala (int A[], int p, int q, int r) {
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
 int contMSt=0;
 void intercalaTroca(int A[], int p, int q, int r) {
    int i, j, k;
    int *W = new int[r-p+1]; 
    i = p; j = q+1; k = 0;

        while (i <= q && j <= r) {
            if (A[i] <= A[j]){
            W[k++] = A[i++];
            contMSt++;
            }
            else{
            W[k++] = A[j++];
            contMSt++;
            }
        }

    while (i <= q) W[k++] = A[i++];
    while (j <= r) W[k++] = A[j++];

    for (i = p; i <= r; i++)
        A[i] = W[i-p];
    delete[] W;
 }
 int contMSc=0;
 void intercalaCom(int A[], int p, int q, int r) {
    int i, j, k;
    int *W = new int[r-p+1]; 
    i = p; j = q+1; k = 0;

        while (i <= q && j <= r) {
            if (A[i] <= A[j])
            W[k++] = A[i++];
            else
            W[k++] = A[j++];

        contMSc++;
        }

    while (i <= q) W[k++] = A[i++];
    while (j <= r) W[k++] = A[j++];

    for (i = p; i <= r; i++)
        A[i] = W[i-p];
    delete[] W;
 }
int contQSt=0;
int separaRecursaoVetorTroca(int A[], int p, int r) {
    int c = A[r];
    int j = p;
    for (int k = p; k < r; k++) {
        if (A[k] <= c) {
            swap(A[k], A[j]);
            j++;
            contQSt++;
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}

int contQSc=0;
int separaRecursaoVetorCom(int A[], int p, int r) {
    int c = A[r];
    int j = p;
    for (int k = p; k < r; k++) {
        if (A[k] <= c) {
            swap(A[k], A[j]);
            j++;
        }
        contQSc++;
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}
int separaRecursaoVetor(int A[], int p, int r) {
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
int contHSt=0;
void heapifyTroca(int v[], int n, int i){ 
    int temp = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && v[l] > v[temp]){
        temp = l; 
        contHSt++;
    }
  
    if (r < n && v[r] > v[temp]){ 
        temp = r;
        contHSt++;
    } 
  
    if (temp != i) { 
        swap(v[i], v[temp]); 
        heapifyTroca(v, n, temp); 
        contHSt++;
    }
} 
int contHSc=0;
void heapifyCom(int v[], int n, int i){ 
    int temp = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    
    contHSc++;
    if (l < n && v[l] > v[temp]) 
        temp = l; 
  
    if (r < n && v[r] > v[temp]) 
        temp = r; 
  
    if (temp != i) { 
        swap(v[i], v[temp]); 
        heapifyCom(v, n, temp); 
    } 
} 
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Recursivo/////////////////////////////////
void bubbleSortRecursaoVetor(int v[], int n) { 
    if (n != 1) {
    for (int i=0; i<n-1; i++) 
        if (v[i] > v[i+1]) 
            swap(v[i], v[i+1]); 
  
    bubbleSortRecursaoVetor(v, n-1);
    }else{
        return;
    } 
}
int comC=0;
int bubbleSortRecursaoVetorCom(int v[], int n) { 
    if (n != 1) {
    for (int i=0; i<n-1; i++) {
        if (v[i] > v[i+1]) 
            swap(v[i], v[i+1]);
    comC++;       
    } 
  
    bubbleSortRecursaoVetorCom(v, n-1);
    }else{
        return comC;
    } 
}
int contB=0;
int bubbleSortRecursaoVetorTroca(int v[], int n) { 
    if (n != 1) {
    for (int i=0; i<n-1; i++) {
        if (v[i] > v[i+1]){
            swap(v[i], v[i+1]); 
            contB++;
        }     
    }
    bubbleSortRecursaoVetorTroca(v, n-1);
    }else{
        return contB;
    } 
}

void insertionSortRecursaoVetor(int v[], int n) { 
    if (n <= 1) 
        return;     
  
    insertionSortRecursaoVetor( v, n-1 ); 
    int key = v[n-1]; 
    int j = n-2; 
  
    while (j >= 0 && v[j] > key) 
    { 
        v[j+1] = v[j]; 
        j--; 
    } 
    v[j+1] = key; 
}
int contIRt=0;
int insertionSortRecursaoVetorTroca(int v[], int n) { 
    if (n <= 1) 
        return contIRt;     
  
    insertionSortRecursaoVetorTroca( v, n-1 ); 
    int key = v[n-1]; 
    int j = n-2; 
  
    while (j >= 0 && v[j] > key) 
    { 
        v[j+1] = v[j]; 
        j--;
    contIRt++; 
    } 
    v[j+1] = key; 
}
int contIRc=0;
int insertionSortRecursaoVetorCom(int v[], int n) { 
    if (n <= 1) 
        return contIRc;     
  
    insertionSortRecursaoVetorCom( v, n-1 ); 
    int key = v[n-1]; 
    int j = n-2; 
    
    while (j >= 0 && v[j] > key) 
    { 
        v[j+1] = v[j]; 
        j--; 
    } 
    v[j+1] = key; 
    contIRc++;
}

void mergesortRecursaoVetor(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; 
        mergesortRecursaoVetor(A, p, q);
        mergesortRecursaoVetor(A, q + 1, r);
        intercala(A, p, q, r);
    }
}

int mergesortRecursaoVetorTroca(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; 
        mergesortRecursaoVetorTroca(A, p, q);
        mergesortRecursaoVetorTroca(A, q + 1, r);
        intercalaTroca(A, p, q, r);
    }
    return contMSt;
}

int mergesortRecursaoVetorCom(int A[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2; 
        mergesortRecursaoVetorCom(A, p, q);
        mergesortRecursaoVetorCom(A, q + 1, r);
        intercalaCom(A, p, q, r);
    }
    return contMSc;
}

void selectionSortRecursaoVetor(int v[], int n, int i){
	int min = i;
	for (int j = i + 1; j < n; j++)
	{
		if (v[j] < v[min])
			min = j;	
	}
	swap(v[min],v[i]);

	if (i + 1 < n) {
		selectionSortRecursaoVetor(v,n,i + 1);
	}
}
int contSR=0;
int selectionSortRecursaoVetorTroca(int v[], int n, int i){
	int min = i;
	for (int j = i + 1; j < n; j++)
	{
		if (v[j] < v[min]){
            min = j;
            contSR++;	
        }
			
	}
	swap(v[min],v[i]);

	if (i + 1 < n) {
		selectionSortRecursaoVetorTroca(v,n,i + 1);
	}
    return contSR;
}

int contSRc=0;
int selectionSortRecursaoVetorCom(int v[], int n, int i){
	int min = i;
	for (int j = i + 1; j < n; j++)
	{
        contSRc++;
		if (v[j] < v[min])
			min = j;	
	}
	swap(v[min],v[i]);

	if (i + 1 < n) {
		selectionSortRecursaoVetor(v,n,i + 1);
	}
    return contSRc;
}

void quickSortRecursaoVetor(int v[], int min, int max) {  
    if (min < max){  
        int x = separaRecursaoVetor(v, min, max);  
        quickSortRecursaoVetor(v, min, x - 1);  
        quickSortRecursaoVetor(v, x + 1, max);  
    }  
}

int quickSortRecursaoVetorCom(int v[], int min, int max) {  
    if (min < max){  
        int x = separaRecursaoVetorCom(v, min, max);  
        quickSortRecursaoVetorCom(v, min, x - 1);  
        quickSortRecursaoVetorCom(v, x + 1, max);  
    }
    return contQSc;  
}

int quickSortRecursaoVetorTroca(int v[], int min, int max) {  
    if (min < max){  
        int x = separaRecursaoVetorTroca(v, min, max);  
        quickSortRecursaoVetorTroca(v, min, x - 1);  
        quickSortRecursaoVetorTroca(v, x + 1, max);  
    }  
    return contQSt;
}


void heapSortRecursaoVetor(int v[], int n){ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(v, n, i); 
    for (int i=n-1; i>=0; i--){ 
        swap(v[0], v[i]); 
        heapify(v, i, 0); 
    } 
}

int heapSortRecursaoVetorTroca(int v[], int n){ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapifyTroca(v, n, i); 
    for (int i=n-1; i>=0; i--){ 
        swap(v[0], v[i]); 
        heapifyTroca(v, i, 0); 
    } 
    return contHSt;
}

int heapSortRecursaoVetorCom(int v[], int n){ 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapifyCom(v, n, i); 
    for (int i=n-1; i>=0; i--){ 
        swap(v[0], v[i]); 
        heapifyCom(v, i, 0); 
    }
    return contHSc; 
}

// Auxiliar de IterativoVetor ///////////////////////////////////////////////////////////////
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
int contMSIt=0;
void mergeTroca(int v[], int l, int m, int r){ 

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
            contMSIt++; 
        } 
        else{ 
            v[k] = v2[j]; 
            j++;
            contMSIt++; 
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
int contMSIc=0;
void mergeCom(int v[], int l, int m, int r){ 

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
        contMSIc++;
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

int separaIterativoVetor(int A[], int p, int r) {
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
int contQSIc=0;
int separaIterativoVetorCom(int A[], int p, int r) {
    int c = A[r];
    int j = p;
    for (int k = p; k < r; k++) {
        if (A[k] <= c) {
            swap(A[k], A[j]);
            j++;
        }
        contQSIc++;
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}
int contQSIt=0;
int separaIterativoVetorTroca(int A[], int p, int r) {
    int c = A[r];
    int j = p;
    for (int k = p; k < r; k++) {
        if (A[k] <= c) {
            swap(A[k], A[j]);
            j++;
            contQSIt++;
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//// IterativoVetor///////////////////////////////////////////////////////////////

void mergeSortIterativoVetor(int v[], int n) 
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

int mergeSortIterativoVetorCom(int v[], int n) 
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
           mergeCom(v, esq, mid, dir); 
       } 
    }
    return contMSIc; 
} 
int mergeSortIterativoVetorTroca(int v[], int n) { 
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
           mergeTroca(v, esq, mid, dir); 
       } 
    }
    return contMSIt; 
} 
void heapsortIterativoVetor(int v[], int n) {
   int i = n / 2, p, f, t;
   while(true) {
      if (i > 0) {
          i--;
          t = v[i];
      } else {
          n--;
          if (n <= 0) return;
          t = v[n];
          v[n] = v[0];
      }
      p = i;
      f = i * 2 + 1;
      while (f < n) {
          if ((f + 1 < n)  &&  (v[f + 1] > v[f]))
              f++;
          if (v[f] > t) {
             v[p] = v[f];
             p = f;
             f = p * 2 + 1;
          } else {
             break;
          }
      }
      v[p] = t;
   }
}
int heapsortIterativoVetorCom(int v[], int n) {
    int cont=0;
     int i = n / 2, p, f, t;
   while(true) {
      if (i > 0) {
          i--;
          t = v[i];
      } else {
          n--;
          if (n <= 0) break;
          t = v[n];
          v[n] = v[0];
      }
      p = i;
      f = i * 2 + 1;
      while (f < n) {
          if ((f + 1 < n)  &&  (v[f + 1] > v[f]))
              f++;
          if (v[f] > t) {
             v[p] = v[f];
             p = f;
             f = p * 2 + 1;
          } else {
             break;
          }
          cont++;
      }
      v[p] = t;
      cont++;
   }
   return cont;
}
int heapsortIterativoVetorTroca(int v[], int n) {
   int cont=0;
     int i = n / 2, p, f, t;
   while(true) {
      if (i > 0) {
          i--;
          t = v[i];
      } else {
          n--;
          if (n <= 0) break;
          t = v[n];
          v[n] = v[0];
          cont++;
      }
      p = i;
      f = i * 2 + 1;
      while (f < n) {
          if ((f + 1 < n)  &&  (v[f + 1] > v[f]))
              f++;
          if (v[f] > t) {
             v[p] = v[f];
             p = f;
             f = p * 2 + 1;
             cont++;
          } else {
             break;
          }
          
      }
      v[p] = t;
      
   }
   return cont;
}

void quickSortIterativoVetor(int v[], int l, int h) { 
    int vec[h - l + 1]; 

    int top = -1; 
  
    vec[++top] = l; 
    vec[++top] = h; 
  
    while (top >= 0) { 
        h = vec[top--]; 
        l = vec[top--]; 
        int p = separaIterativoVetor(v, l, h); 
  
       
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
int quickSortIterativoVetorCom(int v[], int l, int h) { 
    int vec[h - l + 1]; 

    int top = -1; 
  
    vec[++top] = l; 
    vec[++top] = h; 
  
    while (top >= 0) { 
        h = vec[top--]; 
        l = vec[top--]; 
        int p = separaIterativoVetorCom(v, l, h); 
  
       
        if (p - 1 > l) { 
            vec[++top] = l; 
            vec[++top] = p - 1; 
        } 
  
        if (p + 1 < h) { 
            vec[++top] = p + 1; 
            vec[++top] = h; 
        } 
    } 

    return contQSIc;
} 
int quickSortIterativoVetorTroca(int v[], int l, int h) { 
    int vec[h - l + 1]; 

    int top = -1; 
  
    vec[++top] = l; 
    vec[++top] = h; 
  
    while (top >= 0) { 
        h = vec[top--]; 
        l = vec[top--]; 
        int p = separaIterativoVetorTroca(v, l, h); 
  
       
        if (p - 1 > l) { 
            vec[++top] = l; 
            vec[++top] = p - 1; 
        } 
  
        if (p + 1 < h) { 
            vec[++top] = p + 1; 
            vec[++top] = h; 
        } 
    }
    return contQSIt; 
}  

void bubblesortIterativoVetor(int A[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; j--)
            if (A[j] < A[j-1])
                std::swap(A[j],A[j-1]);
}
int bubblesortIterativoVetorCom(int A[], int n){
    int cont=0;
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; j--){
            if (A[j] < A[j-1])
                std::swap(A[j],A[j-1]);
        cont++;
        }
    return cont;    
}
int bubblesortIterativoVetorTroca(int A[], int n){
    int cont=0;
    for (int i = 0; i < n-1; i++)
        for (int j = n-1; j > i; j--)
            if (A[j] < A[j-1]){
                std::swap(A[j],A[j-1]);
                cont++;
            }
    return cont;            
}

void insertionsortIterativoVetor(int A[], int n) {
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
int insertionsortIterativoVetorCom(int A[], int n) {
    int cont=0;
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j-1;

        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
            
        }
        A[i+1] = key;
        cont++;
    }
    return cont;
}
int insertionsortIterativoVetorTroca(int A[], int n) {
    int com=0;
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j-1;

        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
            com++;
        }
        A[i+1] = key;
    }
}

void selectionsortIterativoVetor(int A[], int n) {
    for (int i = 0; i < n-1; i++) {
    int min = i;

    for (int j = i+1; j < n; j++)
        if(A[j] < A[min])
            min = j;

    std::swap(A[i],A[min]);
    }
}
int selectionsortIterativoVetorCom(int A[], int n) {
    int cont=0;
    for (int i = 0; i < n-1; i++) {
    int min = i;

    for (int j = i+1; j < n; j++){
        if(A[j] < A[min])
            min = j;
        cont++;
    }
    std::swap(A[i],A[min]);
    }
}
int selectionsortIterativoVetorTroca(int A[], int n) {
    int cont=0;
    for (int i = 0; i < n-1; i++) {
    int min = i;

    for (int j = i+1; j < n; j++)
        if(A[j] < A[min]){
            cont++;
            min = j;
        }

    std::swap(A[i],A[min]);
    }
    return cont;
}
  





