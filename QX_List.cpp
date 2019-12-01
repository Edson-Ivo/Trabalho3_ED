/**
 * Implementacao da classe QX_List
 */
#include <iostream>
#include <limits.h>
#include "QX_List.h"

struct Node {
    int value; // valor a ser guardado no nó
    Node *next; // ponteiro para o próximo nó da lista
    Node *previous; // ponteiro para o nó anterior da lista
};

QX_List::QX_List() {// lista duplamente encadeada
    head = new Node;
    head->value = 0;
    head->next = head;
    head->previous = head;
}

QX_List::~QX_List() {
    clear();
    delete head;
}

void QX_List::clear() {
    Node *aux;
    while(this->head->next != this->head) {// vai rodar até que o próximo nó de head seja head
        aux = head->next;// aux pegará o valor posterior a head
        head->next = aux->next;// o nó posterior de head será o nó posterior a aux
        head->previous=aux->next;// o nó anterior a head será o nó posterior a aux
        aux->next = NULL;// tranformo o aux em vazio
        aux->previous = NULL;// tranformo o aux em vazio
        //std::cout << "Removendo " << aux->value << std::endl;
        delete aux;// libero a memória de aux
    }
}

Node* QX_List::search(int x) {
    Node *node = head;
    while(node->next != head && (node->next)->value != x)// vai rodar até a lista acabar ou até encontrar o valor
        node = node->next; 
    return (node->next == head) ? NULL : node;// retornará o nó anterior do nó->valor=x;
}

void QX_List::push_back(int x) {
    Node *ant = head;//          
    while(ant->next != head) // rodar até que ant seja o utimo nó da lista
        ant = ant->next;  
    Node *novo = new Node;// criando novo(novo nó)
    novo->value = x;// novo recebe valor do parâmetro
    novo->previous=ant;// o anterior de novo recebe ant;
    novo->next = head;// o posterior de novo recebe 'head', por ser circular
    head->previous=novo;// o anterior de 'head' será o novo, por ser circular
    ant->next = novo;// o posterior de ant será o novo, que o novo será o utimo nó da lista
    
}


int QX_List::pop_back() {
    Node *ant = head;
    int value;
    while(ant->next->next != head) //   vai percorrer até ant ser o penútimo nó
        ant = ant->next;              
    head->previous=ant;// o anterior de head vai ser ant
    ant->next->next=NULL;//o nó posterior de ant, deixando ele vazio 
    ant->next->previous=NULL; //o nó posterior de ant, deixando ele vazio
    value=ant->next->value;// pegando o valor do nó posterior de ant
    delete ant->next;// apagando o nó posterior de ant
    ant->next = head;// deixando o nó posterior de ant como 'head'
    return value;
}
void QX_List::insertAfter(int x, int k){
    Node *aux=head;
    if(size()<k || k<0)// vai verificar se k é válido para o tamanho da lista
        std::cout<<"Valor invalido"<<std::endl;
    else{
    for(int i=0;i<k;i++){ // vai procurar o k-ésimo nó
        aux=aux->next;
    }
    Node *novo=new Node;// criando novo(novo nó)
    novo->value=x;// o novo terá o valor dado no parâmetro x
    novo->next=aux->next;// o novo terá como o próximo, o próximo de aux
    novo->previous=aux;// o anterior de novo, será aux
    aux->next->previous=novo;// o próximo de aux terá como anterior, o novo
    aux->next=novo;// e o próximo de aux será novo
    }
}

void QX_List::print() {
    Node *aux = head->next;// recebe o 1° nó da lista
    if(isEmpty()){// verificar se a lista está vazia
        std::cout << "Lista Vazia";
    }else{
    while(aux != head) {// vai vai imprimindo os valores até chegar a head dnovo
        std::cout << aux->value << " ";
        aux = aux->next;
    }
    std::cout <<std::endl;
    }
}

void QX_List::printReverse() {
    Node *aux = head->previous;// recebe o valor anterior ao 'head', que será o útimo nó da lista, pois é circular
    if(isEmpty()){// verifica se está vazia
        std::cout << "Lista Vazia";
    }else{
        while(aux != head) {// vai imprimindo os valores até chegar a head dnovo
            std::cout << aux->value << " ";
         aux = aux->previous;
       }
       std::cout <<std::endl;
    }
}

void QX_List::remove(int x) {
    Node *anterior = search(x);//pegará o valor retorna do por search(x)
    if(anterior != NULL) {// vai verificar se o valor foi encontrado ou não
        Node *aux; //               
        aux = anterior->next;//  aux recebe o próximo nó de anterior, ou seja, o nó com o valor=x               
        anterior->next = aux->next;// o próximo nó de anterior será o nó posterior de aux
        aux->next->previous=anterior;//o nó anterior do posterior de aux será anterior
        aux->next = NULL;//deixando aux vazio
        aux->previous=NULL;//deixando aux vazio
        delete aux;// apagando aux
    }else{
        std::cout<<"Valor não encontrado"<<std::endl;
    }
}
bool QX_List::isEmpty(){
        if(head->next==head && head->previous==head)//verifica se o anterior e posterior de 'head' é 'head'
        return true;

        return false;
}
int QX_List::size(){
    if(isEmpty())//verifica se está vazia
        return 0;
    int count=0;
    Node *aux=head;
    while(aux->next!=head){//percorer todos os nós da lista
        count++;//incrementa o count
        aux=aux->next;
    }
    return count;// retorna o nmr de nós da lista
}
void QX_List::removeAll(int x){
    if(isEmpty())// verifica se ta vazio
    std::cout<<"A lista esta vazia"<<std::endl;
    else if(search(x)==NULL)//verifica se encontra o valor
    std::cout<<"Valor nao encontrado"<<std::endl;
    else{
        while(!isEmpty() && search(x)!=NULL){// caso encontre irá fazer o remove em todos os nós com o valor=x
            remove(x);
        }
    }
}

void QX_List::removeNode(Node *p){
    
    Node *node = head;
    while(node->next != head && node->next != p)// procurar o nó P na lista
        node = node->next;// node se tornará o valor anterior ao p-nó
    if(node->next==head)// caso não encontre
        std::cout<<"Nó não encontrado"<<std::endl;
    else{
    Node *aux=new Node;
    aux = node->next;//  aux recebe o próximo nó de node, ou seja, será p-nó
    node->next = aux->next; // o próximo nó de node será o nó posterior de aux(p-nó)
    aux->next->previous=node;//o nó anterior do posterior de aux(p-nó) será node
    aux->next = NULL;// deixando aux(p-nó) vazio
    aux->previous=NULL;// deixando aux(p-nó) vazio
    delete aux; // apagando aux(p-nó)
    }


}

int QX_List::removeNodeAt(int k){
    if(size()<k || k<=0){ // vai verificar se k é válido para o tamanho da lista
    clear();// libera a memória com o clear()
    exit(1);// encerra
    }
    else{
    Node *aux=head;
    int value;
    for(int i=0;i<k;i++){ // rodar até q aux seja o k-ésimo valor
        aux=aux->next;
    }
    aux->previous->next=aux->next; // o anterior de k-nó  terá como próximo nó o postorior de k-nó
    aux->next->previous=aux->previous;// o anterior do posterior de k-nó  terá como nó anterior o anterior de k-nó
    aux->next=NULL;// deixando o k-nó vazio
    aux->previous=NULL;//deixando o k-nó vazio
    value=aux->value;// pegando o valor de k-nó
    delete aux;// apagando k-nó
    return value;// retornando o valor de k-nó
    }
}

void QX_List::concat(QX_List *lst){
    Node *aux=this->head,*aux2=lst->head;

    while(aux->next!=this->head) // vai rodar até o utimo nó da lista principal
     aux=aux->next;

    while(aux2->next!=lst->head) // vai rodar até o utimo nó da lista do parâmetro
     aux2=aux2->next;

    aux2->next=this->head; // o útimo nó da lista do parâmetro, vai ter como seu próximo o 'head' da lista principal
    this->head->previous=aux2;// o 'head' terá como seu anterior o útimo nó da lista do parâmetro
    aux->next=lst->head->next;// útimo nó da lista principal terá como seu próximo, o 1° nó da lista do parâmetro
    lst->head->next->previous=aux;// o 1° nó da lista do parâmetro terá como seu anterior o útimo nó da lista principal
    lst->head->next=lst->head;//o próximo nó de 'head' da lista do parâmetro será 'head' da lista do parâmetro
    lst->head->previous=lst->head;//o nó anterior de 'head' da lista do parâmetro será 'head' da lista do parâmetro
                                // deixando assim a lista do parâmetro vazia
}

QX_List* QX_List::copy(){
    QX_List *aux = new QX_List;
    Node *no=this->head->next;
    while(no!=this->head){// vai rodar inserindo os valores no aux com os valores da lista principal
        aux->push_back(no->value);
        no=no->next;
    }
    return aux; // retorna a lista principal copiada para aux
}

void QX_List::copyArray(int *arr,int n){
    for(int i=0;i<n;i++){// vai pegar os valores do array e colocar como push_back(criar nós com os valores) na lista principal
        this->push_back(arr[i]);
    }
}

bool QX_List::equal(QX_List *lst){
    Node *aux=this->head,*aux2=lst->head;
    int cont=0;
    if(lst->size()==this->size()){// vai verificar 1° se a lista 1 e 2 tem o mesmo tamanho
        while(aux->next!=head && aux2->next!=head){ // rodar e contar para ver os valores iguais
            aux=aux->next;
            aux2=aux2->next;
            if(aux->value==aux2->value){// caso encontre valores iguais, cont é incrementado
                cont++;
            }else// se não, não é igual
            return false;
        }
        if(cont==lst->size() && cont==this->size())//verifica se o número de valores iguais é igual ao tamanho das 2 listas
            return true;
        else// se não, não é igual
            return false;
    }else// se não, não é igual
    return false;
}

void QX_List::merge_lists(QX_List *list2){
    QX_List *l3=new QX_List,*l1=this;
    Node *auxl1=l1->head;
    Node *auxl2=list2->head;
    int contl1=0;
    int contl2=0;
    while(l1->size()>contl1 || list2->size()>contl2){ // aqui é onde vai ficar inserindo os valores intercaladamente ex:(lista1->nó->valor,lista2->nó->valor,lista1->nó->valor....) até quando a lista dos 2 acabar.
        if(l1->size()>contl1){ // vai verificar se essa lista acabou ou não
            l3->push_back(auxl1->next->value);// vai inserir na nova lista os valores da lista principal
            auxl1=auxl1->next;
            contl1++;        // cont de comparação com o tamanho da lista principal
        }
        if(list2->size()>contl2){  // vai verificar se essa lista acabou ou não           
            l3->push_back(auxl2->next->value);// vai inserir na nova lista os valores da lista do parâmetro
            auxl2=auxl2->next;
            contl2++;// cont de comparação com o tamanho da lista do parâmetro
        }
    }
    list2->clear();// limpando a lista do parâmetro
    l1->clear();// limpando a lista principal
    l1->concat(l3); // fazendo a lista principal receber todos os valores da lista criada (l3)
}

QX_List* QX_List::separate(int x){
    QX_List *lst2=new QX_List;
    Node *aux=this->search(x)->next->next; // aux recebe o segundo nó posterior do nó retornado por search(x)
    Node *aux2=lst2->head;// aux2 recebe o nó 'head' da lista criada
    while (aux!=this->head){// vai inserindo o valor na lista criada com os nós posteriores a aux
     lst2->push_back(aux->value);
     aux=aux->next;   
    }
    aux=this->search(x)->next; // aux agora receberá o nó posterior do nó retornado por search(x)
    aux->next=this->head;// o próximo nó do próximo de aux, terá como nó 'head'
    this->head->previous=aux;// o 'head' receberá como seu anterior aux. Dividindo a 1 lista da 2
    return lst2;// retornando a 2 lista
}