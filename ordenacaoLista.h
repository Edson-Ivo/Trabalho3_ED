#include <iostream>
#include "QX_List.h"

/// Recursivo/////////////////////////////

//void quickSortRecursaoLista(int v[], int min, int max);

//void mergesortRecursaoLista(QX_List *l, Node *p, Node *r);

//void heapSortRecursaoLista(int v[], int n);

/// Auxiliar dos Recursivos//////

//void intercalaLista(QX_List *l, Node *p, Node *q, Node *r);

//Node * percorreLista(Node *ini, int n);

//int separaRecursaoLista(int A[], int p, int r);

//void heapifyLista(int v[], int n, int i);


//////////////////////////////////////////////////////////////////
// Iterativo /////////////////////////////////////

void bubblesortIterativoLista(QX_List *l);
int bubblesortIterativoListaTroca(QX_List *l);
int bubblesortIterativoListaCom(QX_List *l);

void insertionsortIterativoLista(QX_List *l);
int insertionsortIterativoListaTroca(QX_List *l);
int insertionsortIterativoListaCom(QX_List *l);

void selectionsortIterativoLista(QX_List *l);
int selectionsortIterativoListaTroca(QX_List *l);
int selectionsortIterativoListaCom(QX_List *l);




//Auxiliar Iterativo //////////////////////////////////////////////////////////////
Node* separaIterativaLista(QX_List* l, Node* esq, Node* dir);
