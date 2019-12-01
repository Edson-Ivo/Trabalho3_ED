/**
 * Tipo QX_List
 * Corresponde a uma lista simplesmente encadeada.
 * A implementacao para esta aula deve ser feita 
 * com no cabeca.
 */
#ifndef QX_LIST_H
#define QX_LIST_H

struct Node;

class QX_List {
    private:
        /**
         * Cabeca da lista encadeada
         */
       
        
        

    public:
     Node *head;
        /**
         * Operacao privada auxiliar invocada pela 
         * operacao publica clearRecursive()
         */
        void clearRecursive(Node *node);
        /**
         * Operacao privada auxiliar invocada pela 
         * operacao publica printRecursive()
         */
        void printRecursive(Node *node);
        /**
         * Realiza uma busca pelo elemento x na lista
         * simplesmente encadeada. Se o elemento x for
         * encontrado, retorna o endereco da celula que 
         * precede a celula na qual x esta armazenado; 
         * caso contrario, retorna NULL
         */
        Node *search(int x);
        // Construtor
        QX_List();

        // Destrutor
        ~QX_List();
        
        /**
         * Insere um inteiro x ao final da lista encadeada
         */
        void push_back(int x); 

        /**
         * Remove um inteiro x ao final da lista encadeada
         */
        int pop_back();

        /**
         * Insere uma nova celula com valor x após a 
         * k-esima celula da lista. 
         * Devemos ter 0 <= k <= size() para que a insercao seja
         * realizada; caso contrario, nao sera realizada.
         */
        void insertAfter(int x, int k);

        /**
         * Remove da lista a primeira ocorrencia 
         * do inteiro x
         */
        void remove(int x); 

        /**
         * Remove da lista todas as ocorrencias
         * do inteiro x
         */
        void removeAll(int x);

        /**
         * Remove a k-esima celula da lista encadeada 
         * e retorna o seu valor; Note que devemos 
         * ter 1 <= k <= size().
         * Caso contrario, o programa libera memoria alocada
         * e finaliza chamando exit(1)
         */
        int removeNodeAt(int k);

        /**
         * Remove o o nó apontado pelo ponteiro p.
         */
        void removeNode(Node *p);

        /**
         * Imprime a lista
         */
        void print();

        /**
         * Imprime a lista reversa
         */
        void printReverse();

        /**
         * Imprime a lista
         * Versao recursiva do comando print()
         */
        void printRecursive();

        /**
         * A lista está vazia?
         */
        bool isEmpty();


        // Retorna o número de nos da lista
        int size();

        /**
         * Remove todos os elementos da lista e deixa
         * apenas o no cabeca
         */
        void clear();

        /**
         * Versão recursiva de clear()
         * Remove todos os elementos da lista e deixa
         * apenas o no cabeca
         */
        void clearRecursive();

        /**
         * Concatena a lista atual com a lista 'lst' 
         * passada por referencia. Apos essa operacao
         * ser executada, lst sera uma lista vazia, ou seja, 
         * o unico no de lst sera o no cabeca.
         */
        void concat(QX_List *lst);

        /**
         * Retorna um ponteiro para uma copia desta lista
         */
        QX_List* copy();

        /**
         * Copia os elementos do array v para a lista.
         * O array v tem n elementos.
         * Todos os elementos anteriores da lista são apagados.
         */
        void copyArray(int *arr, int n); 

        /**
         * Determina se a lista passada por parametro eh
         * igual a lista em questao. Duas listas sao iguais
         * se elas tem o mesmo tamanho e o valor do k-esimo 
         * elemento da primeira lista eh igual ao k-esimo 
         * valor da segunda lista.
         */
        bool equal(QX_List *lst); 


        /**
         * Recebe uma QX List como parâmetro e
         * constrói uma nova lista com a intercalação dos nós da lista original com os nós
         * da lista passada por parâmetro. Ao nal desta operação, list2 deve car vazia.
         */
        void merge_lists(QX_List *list2);

        /**
         * Inverte a ordem das celulas da lista simplesmente
         * encadeada (a primeira celula passa a ser a ultima, a 
         * segunda passa a ser a penultima, etc.)
         * Essa operacao faz isso sem criar novas celulas,
         * apenas altera os ponteiros.
         */
        void reverse();

        /*Recebe como parâmetro um valor inteiro n e divide 
        *a lista em duas, de forma á segunda lista começar no primeiro nó logo após a
        *primeira ocorrência de n na lista original. A função deve retornar um ponteiro para
        *a segunda subdivisão da lista original, enquanto a cabeça da lista original deve
        *continuar apontando para o primeiro elemento da primeira lista, caso ele não tenha
        *sido o primeiro a ter valor n.
        */
        QX_List* separate(int n);
};

#endif