#include <iostream>
#include "ordenacaoVetor.h"

using namespace std;

void imprimir(int v[],int tam){
    for(int i=0;i<tam;i++){
        cout<<v[i]<<",";
    }
    cout<<endl;
}

int main(){
    int v[]={3,2,1,7,5,4,9,8,0,6};
    imprimir(v,10);
    selectionsort(v,10);
    imprimir(v,10);

    

    return 0;
}