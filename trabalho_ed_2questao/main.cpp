#include <iostream>
#include "QX_List.h"

using namespace std;

int main(){

    QX_List lista1,lista2,lista3,lista4,lista5,lista6,*copia,*sep;
    Node *x;
    int v[]={1,5,3,4};

    // fazendo o push_back/////////////
    lista1.push_back(1);
    lista1.push_back(2);
    lista1.push_back(2);
    lista1.push_back(2);
    lista1.push_back(3);
    lista1.push_back(3);
    lista1.push_back(4);
    lista1.push_back(4);

    lista2.push_back(2);
    lista2.push_back(2);
    lista2.push_back(2);
    lista2.push_back(2);
    lista2.push_back(2);
    lista2.push_back(2);
    lista2.push_back(2);

    lista3.push_back(1);
    lista3.push_back(2);
    lista3.push_back(3);
    lista3.push_back(4);
    lista3.push_back(5);
    lista3.push_back(6);

    lista4.push_back(1);
    lista4.push_back(2);
    lista4.push_back(3);

    lista5.push_back(1);
    lista5.push_back(2);
    lista5.push_back(3);

    lista6.push_back(1);
    lista6.push_back(2);
    lista6.push_back(3);

////////////////////////////////////////

    //print das listas
    lista1.print();
    lista2.print();
    lista3.print();
    //print reverso
    lista1.printReverse();
    lista2.printReverse();
    lista3.printReverse();
    ////////////////////////////////////////////////
    //fazendo o pop_back da lista 3////
    lista3.pop_back();
    lista3.print();
    //
    //fazendo o insertAfter
    lista3.insertAfter(6,6);//invalido
    lista3.insertAfter(6,5);//valido
    lista3.print();
    ///////////////////////////////////////////////
    //fazendo remove,removeAll,removeNode,removeNodeAt lista3 e lista1
    lista3.remove(4);
    lista3.print();
    lista1.print();
    lista1.removeAll(3);
    lista1.print();
    x=lista1.search(4);// deixei seach() como public para poder receber um node para a função removeNode funcionar
    //x = o nó  anterior do nó com o valor 4, no caso nesse exemplo, x será o nó 2 que é anterior a 4;
    lista1.removeNode(x);
    lista1.print();
    lista3.print();
    lista3.removeNodeAt(3);
    lista3.print();
    ///////////////////////////////////////
    //Verificar se está vazia e ver tamanho da lista3
    cout<<"e vazia: "<<lista3.isEmpty()<<" /tamanho: "<<lista3.size()<<endl;
    //limpando a lista 3
    lista3.clear();
    //Verificar se está vazia e ver tamanho da lista3
    cout<<"e vazia: "<<lista3.isEmpty()<<" /tamanho: "<<lista3.size()<<endl;
    ////////////////////////////////////////
    //fazer o Concact()////////////////////
    lista1.print();
    lista4.print();
    lista1.concat(&lista4);
    lista1.print();
    lista4.print();
    cout<<endl;// ta bugando os endl da função print()
    //////////////////////////////////////////
    //fazer o *copy()////////////////
    copia=lista5.copy();
    lista1.print();
    lista1.concat(copia);// fazendo o concat() da cópia da lista5
    lista1.print();
    /////////////////////////////////////////
    //fazer o copyArray()/////////////////
    lista5.print();
    lista5.copyArray(v,4);
    lista5.print();
    /////////////////////////////////////////
    //fazer o equal()/////////////
    cout<<lista6.equal(&lista6)<<endl;
    cout<<lista6.equal(&lista5)<<endl;
    /////////////////////////////////////
    // fazer o Separate
    sep=lista5.separate(5);// sep recebe o retorno do separate da lista5
    sep->print();// imprime o sep
    ////////////////////////////////////
    // fazer o merge_lists
    lista5.merge_lists(&lista2);
    lista5.print();
    lista2.print();
    /////////////////////////////////////////////////////////////
    return 0;
}