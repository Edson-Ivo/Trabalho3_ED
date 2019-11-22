#include <iostream>
#include "ordenacaoVetor.h"

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Recursivo/////////////////////////////////
void bubbleSort(int v[], int n) { 
    if (n != 1) {
    for (int i=0; i<n-1; i++) 
        if (v[i] > v[i+1]) 
            swap(v[i], v[i+1]); 
  
    bubbleSort(v, n-1);
    }else{
        return;
    } 
}

void insertionSortRecursive(int v[], int n) { 
    if (n <= 1) 
        return;     
  
    insertionSortRecursive( v, n-1 ); 
  
    int key = v[n-1]; 
    int j = n-2; 
  
    while (j >= 0 && v[j] > key) 
    { 
        v[j+1] = v[j]; 
        j--; 
    } 
    v[j+1] = key; 
}

void selectionSort(int v[], int n, int i=0){
	int min = i;
	for (int j = i + 1; j < n; j++)
	{
		if (v[j] < v[min])
			min = j;	
	}
	swap(v[min],v[i]);

	if (i + 1 < n) {
		selectionSort(v,n,i + 1);
	}
}
