#include <iostream>
#include "ordenacaoVetor.h"
#include "QX_List.h"

using namespace std;
struct Node {
    int value; // valor a ser guardado no nó
    Node *next; // ponteiro para o próximo nó da lista
    Node *previous; // ponteiro para o nó anterior da lista
};
//// Auxiliares do recursivo/////////////////////////////////////////////////////////////////////////
void intercala (QX_List *l, Node *p, Node *q, Node *r) {
    cout << "entrou intercala";
    Node *i = p;
    Node *j = q->next;
    QX_List *W = new QX_List;

    while(i != q->next && j != r->next){
        if(i->value <= j->value){
            W->push_back(i->value);
            i = i->next;
        }
        else{
            W->push_back(j->value);
            j = j->next;
        }
    }
    while(i != q->next){
        W->push_back(i->value);
        i = i->next;
    }
    while(j != r->next){
        W->push_back(j->value);
        j = j->next;
    }
    i = r;
    while(i != p->previous){
        i->value = W->pop_back();
        i = i->previous;
    }
    delete W;
    /*int i, j, k;
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
    delete[] W;*/
}

Node * percorreLista(QX_List *l,Node *ini, int n){
    Node *aux = ini;
    for(int i = 0; i < n; i++){
        aux = aux->next;
        if(aux==l->head){
            aux=aux->next;
        }
    }
        
    return aux;
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

/*void heapify(int v[], int n, int i){ 
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
} */
//////////////////////////////////////////////
// Recursivo/////////////////////////////////
// p   q   r
// 1 2 3 4 5 
// q = 6



void mergesortRecursao(QX_List *l, Node *p, Node *r) {
    QX_List *lex1;
    QX_List *lex2;

    if(p->next!= r){
        cout<<"eae";
       int count=0;
     Node *aux=r;
    while(aux->next!=r){//percorer todos os nós da lista
        count++;//incrementa o count
        aux=aux->next;
    }   
        int v= count/2;
        Node *q = percorreLista(l,p, v);
        mergesortRecursao(l, p, q);
        mergesortRecursao(l, q->next, r);
        intercala(l, p, q, r);

    }
    /*if (p < r) {
        int q = (p + r) / 2; 
        mergesortRecursao(A, p, q);
        mergesortRecursao(A, q + 1, r);
        intercala(A, p, q, r);
    }*/
}

void quickSortRecursao(int v[], int min, int max) {  
    
//    if (min < max){  
//        int x = separaRecursao(v, min, max);  
//        quickSortRecursao(v, min, x - 1);  
//        quickSortRecursao(v, x + 1, max);  
//    }  
}


void heapSortRecursaoLista(int v[], int n){ 
//    for (int i = n / 2 - 1; i >= 0; i--) 
//        heapify(v, n, i); 
//    for (int i=n-1; i>=0; i--){ 
//        swap(v[0], v[i]); 
//        heapify(v, i, 0); 
//    } 
}


// Auxiliar de Iterativo ///////////////////////////////////////////////////////////////
                                     //p          r
Node* separaIterativaLista(QX_List* l, Node* esq, Node* dir) {
    Node *c=l->head->previous;
    Node *j=esq;
    Node *k=esq;
    while(k->next!=dir){
        if(k->value<=c->value){
            swap(k,j);
            j=j->next;
        }
        k=k->next;
    }
    dir=j;
    j=c;

    return j;
    /*int c = A[r];
    int j = p;
    for (int k = p; k < r; k++) {
        if (A[k] <= c) {
            swap(A[k], A[j]);
            j++;
        }
    }
    A[r] = A[j];
    A[j] = c;
    return j;*/
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
//// Iterativo///////////////////////////////////////////////////////////////

Node *percorre(QX_List *l,Node *n,int tam){
    int t=tam;
    while(n!=l->head && t>0){
        n=n->next;
        tam--;
    }
    if(n==l->head){
        cout<<"n chegou no head";
    }
    return n;

}

void mergeSortIterativo(QX_List *l) { 
   Node *esq;
   Node *t=l->head->next->next;
   int m=1;
   while(t!=l->head){
       esq=l->head->next;
    

       m=m*2;
      t=percorre(l,t,m);
   }
   /*int tam;  
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
    } */
} 

void heapsortIterativo(int a[], int n) {
//   int i = n / 2, p, f, t;
//   while(true) {
//     if (i > 0) {
//          i--;
//          t = a[i];
//      } else {
//          n--;
//          if (n <= 0) return;
//          t = a[n];
//          a[n] = a[0];
//      }
//      p = i;
//      f = i * 2 + 1;
//      while (f < n) {
//          if ((f + 1 < n)  &&  (a[f + 1] > a[f]))
//              f++;
//          if (a[f] > t) {
//             a[p] = a[f];
//             p = f;
//             f = p * 2 + 1;
//          } else {
//             break;
//          }
//      }
//      a[p] = t;
//   }
}
                                    //  l             //h
void quickSortIterativo(QX_List *l, Node * esq, Node* dir) {

    QX_List *aux=new QX_List;
    aux->push_back(esq->value);
    aux->push_back(dir->value);
    Node *top=aux->head->previous;
    while(top!=aux->head){
        dir=top;
        top=top->previous;
        esq=top;
        top=top->previous;
        Node *p=separaIterativaLista(l,esq,dir);

//        if(p->previous!=esq){
//            top
//        }
    }



    /*int vec[h - l + 1]; 

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
    } */
} 

void bubblesortIterativoLista(QX_List *l) {
    Node* auxIni = l->head->next;
    Node* auxFim = l->head->previous;

    while(auxIni != l->head->previous){
        auxFim = l->head->previous;
        while(auxFim != auxIni){
            if(auxFim->value < auxFim->previous->value)
                swap(auxFim->value, auxFim->previous->value);
            auxFim = auxFim->previous;
        }
        auxIni = auxIni->next;
    }
}
int bubblesortIterativoListaCom(QX_List *l) {
    int cont=0;
    Node* auxIni = l->head->next;
    Node* auxFim = l->head->previous;

    while(auxIni != l->head->previous){
        auxFim = l->head->previous;
        while(auxFim != auxIni){
            if(auxFim->value < auxFim->previous->value)
                swap(auxFim->value, auxFim->previous->value);
            auxFim = auxFim->previous;
         cont++;   
        }
        auxIni = auxIni->next;
    }
    return cont;
}
int bubblesortIterativoListaTroca(QX_List *l) {
    int cont=0;
    Node* auxIni = l->head->next;
    Node* auxFim = l->head->previous;

    while(auxIni != l->head->previous){
        auxFim = l->head->previous;
        while(auxFim != auxIni){
            if(auxFim->value < auxFim->previous->value){
                swap(auxFim->value, auxFim->previous->value);
                cont++;
            }
            auxFim = auxFim->previous;
        }
        auxIni = auxIni->next;
    }
    return cont;
}

void insertionsortIterativoLista(QX_List *l) {
    int key;
    Node *aux_i;
    Node *aux_j = l->head->next->next;
    while(aux_j != l->head){
        key = aux_j->value;
        aux_i = aux_j->previous;
        while (aux_i != l->head && aux_i->value > key) {
            aux_i->next->value = aux_i->value;
            aux_i = aux_i->previous;
        }
        aux_i->next->value = key;
        aux_j = aux_j->next;
    }
    /*
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j-1;

        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }*/
}
int insertionsortIterativoListaTroca(QX_List *l) {
    int cont=0;
    int key;
    Node *aux_i;
    Node *aux_j = l->head->next->next;
    while(aux_j != l->head){
        key = aux_j->value;
        aux_i = aux_j->previous;
        while (aux_i != l->head && aux_i->value > key) {
            aux_i->next->value = aux_i->value;
            aux_i = aux_i->previous;
            cont++;
        }
        aux_i->next->value = key;
        aux_j = aux_j->next;
    }
    return cont;
    /*
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j-1;

        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }*/
}
int insertionsortIterativoListaCom(QX_List *l) {
    int cont=0;
    int key;
    Node *aux_i;
    Node *aux_j = l->head->next->next;
    while(aux_j != l->head){
        key = aux_j->value;
        aux_i = aux_j->previous;
        while (aux_i != l->head && aux_i->value > key) {
            aux_i->next->value = aux_i->value;
            aux_i = aux_i->previous;
        }
        aux_i->next->value = key;
        aux_j = aux_j->next;
        cont++;
    }
    return cont;
    /*
    int i, j, key;
    for (j = 1; j < n; j++) {
        key = A[j];
        i = j-1;

        while (i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }*/
}

void selectionsortIterativoLista(QX_List *l) {
    Node *aux_i = l->head->next;
    Node *aux_j;
    while(aux_i != l->head->previous){
        Node *min = aux_i;
        aux_j = aux_i->next;
        while(aux_j != l->head){
            if(aux_j->value < min->value)
                min = aux_j;
            aux_j = aux_j->next;
        }
        swap(aux_i->value, min->value);
        aux_i = aux_i->next;
    }
    /*for (int i = 0; i < n-1; i++) {
        int min = i;

        for (int j = i+1; j < n; j++)
            if(A[j] < A[min])
                min = j;

        std::swap(A[i],A[min]);
    }*/
}
int selectionsortIterativoListaCom(QX_List *l) {
    int cont=0;
    Node *aux_i = l->head->next;
    Node *aux_j;
    while(aux_i != l->head->previous){
        Node *min = aux_i;
        aux_j = aux_i->next;
        while(aux_j != l->head){
            if(aux_j->value < min->value)
                min = aux_j;
            aux_j = aux_j->next;
            cont++;
        }
        swap(aux_i->value, min->value);
        aux_i = aux_i->next;
    }
    return cont;
    /*for (int i = 0; i < n-1; i++) {
        int min = i;

        for (int j = i+1; j < n; j++)
            if(A[j] < A[min])
                min = j;

        std::swap(A[i],A[min]);
    }*/
}
int selectionsortIterativoListaTroca(QX_List *l) {
    int cont=0;
    Node *aux_i = l->head->next;
    Node *aux_j;
    while(aux_i != l->head->previous){
        Node *min = aux_i;
        aux_j = aux_i->next;
        while(aux_j != l->head){
            if(aux_j->value < min->value){
                min = aux_j;
                cont++;
            }
            aux_j = aux_j->next;
        }
        swap(aux_i->value, min->value);
        aux_i = aux_i->next;
    }
    return cont;
    /*for (int i = 0; i < n-1; i++) {
        int min = i;

        for (int j = i+1; j < n; j++)
            if(A[j] < A[min])
                min = j;

        std::swap(A[i],A[min]);
    }*/
}
  
