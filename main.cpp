#include <iostream>
#include <fstream>
#include <chrono>
#include "ordenacaoLista.h"
#include "ordenacaoVetor.h"

using namespace std;

/** 
 * Função que gera arquivos binarios, cada um contendo numeros aleatorios
 */
void gera_dados(int num_iteracoes, const int vetor_tam[]) 
{
	for(int iteracao = 0; iteracao < num_iteracoes; iteracao++) {
		for(int semente = 0; semente < 5; semente++) {	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[iteracao];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); // gera numero aleatorio
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binario de mesmo nome que a 
 * string nomeArquivo
 */
void ler_dados(int n, int A[], const char *nomeArquivo) 
{	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++) 
	{
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor
	}
	fin.close(); // fecha o arquivo de leitura
}


/***************************** MAIN ********************************/
int main() 
{ 
	// Os tamanhos dos seis vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {1000,5000,10000,15000,30000};

	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'
	
	// Etapa 1: Gerar arquivos contendo números aleatórios
	gera_dados(TOTAL_N, tam);
	
	//------------------------------------------------------------
	// Etapa 2 - Execução do BubbleIterativoVetor
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs("resultados/BubbleIterativoVetor.txt", ofstream::out ); // abre arquivo de resultados do bubble
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubble = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// bubble ------------------------------------------------------
			// obtendo o tempo inicial
			auto ini = chrono::high_resolution_clock::now();
		
			bubblesortIterativoVetor(vetor, tamanho_vetor); // ordena o vetor usando o bubble

            comparacoes+=bubblesortIterativoVetorCom(vetor,tamanho_vetor);

            trocas+=bubblesortIterativoVetorTroca(vetor,tamanho_vetor);
		
			// obtendo o tempo final
			auto fim = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_bubble = chrono::duration_cast<chrono::microseconds>(fim - ini).count();
			
			duracao_media_bubble += duracao_bubble;
			
		}
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		cout << "[BubbleSortIterativoVetor] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_bubble << " microssegundos" << endl;
        cout << "[BubbleSortIterativoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[BubbleSortIterativoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs << tamanho_vetor << " " << duracao_media_bubble << "\n"; // grava no arquivo de resultados do bubble
	}
	
	ofs.close(); // fecha arquivo de resultados do Bubble Sort
	// ------------------------------------------------------------
	
	
	// ------------------------------------------------------------
	// Etapa 3 - Execução do SelectSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs2("resultados/SelectSortIterativoVetor.txt", ofstream::out ); // abre arquivo de resultados do select
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_Select = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// select ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			selectionsortIterativoVetor(vetor, tamanho_vetor); // ordena o vetor usando o SelectSort
           comparacoes+=selectionsortIterativoVetorCom(vetor, tamanho_vetor); // ordena o vetor usando o SelectSort
           trocas+= selectionsortIterativoVetorTroca(vetor, tamanho_vetor); // ordena o vetor usando o SelectSort
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_Select = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_Select += duracao_Select;			
		}	
		
		duracao_media_Select = duracao_media_Select / 5.0;
		cout << "[SelectionSortIterativoVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_Select << " microssegundos" << endl;
        cout << "[SelectionSortIterativoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " Trocas" << endl;
        cout << "[SelectionSortIterativoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " Comparacoes" << endl;
		ofs2 << tamanho_vetor << " " << duracao_media_Select << "\n"; // grava no arquivo de resultados do Select Sort
	}
	
	ofs2.close(); // fecha arquivo de resultados do Select Sort
	// ------------------------------------------------------------

    // ------------------------------------------------------------
	// Etapa 4 - Execução do InsertSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs3("resultados/InsertSortIterativoVetor.txt", ofstream::out ); // abre arquivo de resultados do insert
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_Insert = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// insert ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			insertionsortIterativoVetor(vetor, tamanho_vetor); // ordena o vetor usando o Insert
           comparacoes+= insertionsortIterativoVetorCom(vetor, tamanho_vetor); // ordena o vetor usando o Insert
           trocas+= insertionsortIterativoVetorTroca(vetor, tamanho_vetor); // ordena o vetor usando o Insert
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_Insert = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_Insert += duracao_Insert;			
		}	
		
		duracao_media_Insert = duracao_media_Insert / 5.0;
		cout << "[InsertSortIterativoVetor] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_Insert << " microssegundos" << endl;
        cout << "[InsertSortIterativoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " Trocas" << endl;
        cout << "[InsertSortIterativoVetor] N = " << tamanho_vetor << ", Numero de Comparacoes = " << comparacoes << " Comparacoes" << endl;
		ofs3 << tamanho_vetor << " " << duracao_media_Insert << "\n"; // grava no arquivo de resultados do Insert Sort
	}
	
	ofs3.close(); // fecha arquivo de resultados do Insert Sort
	// ------------------------------------------------------------

    // ------------------------------------------------------------
	// Etapa 5 - Execução do BubbleSortRecursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs4("resultados/BubbleSortRecursivoVetor.txt", ofstream::out ); // abre arquivo de resultados do bubblesortRecursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubbleR = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// BubbleSort ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
		   bubbleSortRecursaoVetor(vetor, tamanho_vetor); // ordena o vetor usando o BubbleSortRecursivo
           comparacoes+= bubbleSortRecursaoVetorCom(vetor, tamanho_vetor); // ordena o vetor usando o BubbleSortRecursivo
           trocas+= bubbleSortRecursaoVetorTroca(vetor, tamanho_vetor); // ordena o vetor usando o BubbleSortRecursivo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_bubbleR = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_bubbleR += duracao_bubbleR;			
		}	
		
		duracao_media_bubbleR = duracao_media_bubbleR / 5.0;
		cout << "[BubbleSortRecursivoVetor] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_bubbleR << " microssegundos" << endl;
        cout << "[BubbleSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de Trocas = " << trocas << " trocas" << endl;
        cout << "[BubbleSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de Comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs4 << tamanho_vetor << " " << duracao_media_bubbleR << "\n"; // grava no arquivo de resultados do Bubble Sort Recursivo
	}
	
	ofs4.close(); // fecha arquivo de resultados do Bubble Sort Recursivo
	// ------------------------------------------------------------

    //------------------------------------------------------------
	// Etapa 6 - Execução do SelectSortRecursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs5("resultados/SelectSortRecursivoVetor.txt", ofstream::out ); // abre arquivo de resultados do SelectsortRecursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_selectR = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o select sort recurt para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// selectleSort ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			selectionSortRecursaoVetor(vetor, tamanho_vetor); // ordena o vetor usando o Select SortRecursivo
           trocas+= selectionSortRecursaoVetorTroca(vetor, tamanho_vetor); // ordena o vetor usando o Select SortRecursivo
          comparacoes+= selectionSortRecursaoVetorCom(vetor, tamanho_vetor); // ordena o vetor usando o Select SortRecursivo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_selectR = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_selectR += duracao_selectR;			
		}	
		
		duracao_media_selectR = duracao_media_selectR / 5.0;
		cout << "[SelectSortRecursivoVetor] N = " << tamanho_vetor << ", tempo medio de execucao = " << duracao_media_selectR << " microssegundos" << endl;
        cout << "[SelectSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[SelectSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs5 << tamanho_vetor << " " << duracao_media_selectR << "\n"; // grava no arquivo de resultados do Select Sort Recursivo
	}
	
	ofs5.close(); // fecha arquivo de resultados do Select Sort Recursivo
	// ------------------------------------------------------------

    // ------------------------------------------------------------
	// Etapa 7 - Execução do InsertSortRecursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs6("resultados/InsertSortRecursivoVetor.txt", ofstream::out ); // abre arquivo de resultados do insert sort Recursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_insertR = 0.0;
        int trocas=0;
        int comparacoes=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o insert sort recursivo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// insert ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			insertionSortRecursaoVetor(vetor, tamanho_vetor); // ordena o vetor usando o insert SortRecursivo
            trocas+=insertionSortRecursaoVetorTroca(vetor, tamanho_vetor); // ordena o vetor usando o insert SortRecursivo
            comparacoes+=insertionSortRecursaoVetorCom(vetor, tamanho_vetor); // ordena o vetor usando o insert SortRecursivo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_insertR = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_insertR += duracao_insertR;			
		}	
		
		duracao_media_insertR = duracao_media_insertR / 5.0;
		cout << "[InsertSortRecursivoVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_insertR << " microssegundos" << endl;
        cout << "[InsertSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[InsertSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs6 << tamanho_vetor << " " << duracao_media_insertR << "\n"; // grava no arquivo de resultados do insert Sort Recursivo
	}
	
	ofs6.close(); // fecha arquivo de resultados do Select Sort Recursivo
	// ------------------------------------------------------------
    
    // -----------------------------------------------------------
	// Etapa 8 - Execução do QuickSortRecursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs7("resultados/QuickSortRecursivoVetor.txt", ofstream::out ); // abre arquivo de resultados do Quick sort Recursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_QuickR = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o quick sort recursivo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// quick ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			quickSortRecursaoVetor(vetor,0,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
            trocas+= quickSortRecursaoVetorTroca(vetor,0,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
            comparacoes+= quickSortRecursaoVetorCom(vetor,0,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_insertR = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_QuickR += duracao_insertR;			
		}	
		
		duracao_media_QuickR = duracao_media_QuickR / 5.0;
		cout << "[QuickSortRecursivoVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_QuickR << " microssegundos" << endl;
        cout << "[QuickSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[QuickSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs7 << tamanho_vetor << " " << duracao_media_QuickR << "\n"; // grava no arquivo de resultados do quick Sort Recursivo
	}
	
	ofs7.close(); // fecha arquivo de resultados do quick Sort Recursivo
	// ------------------------------------------------------------

    // -----------------------------------------------------------
	// Etapa 9 - Execução do MergeSortRecursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs8("resultados/MergeSortRecursivoVetor.txt", ofstream::out ); // abre arquivo de resultados do Merge sort Recursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_mergeR = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o merge sort recursivo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// merge ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			mergesortRecursaoVetor(vetor,0,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
          trocas+=  mergesortRecursaoVetorTroca(vetor,0,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
          comparacoes+=  mergesortRecursaoVetorCom(vetor,0,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_mergeR = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_mergeR += duracao_mergeR;			
		}	
		
		duracao_media_mergeR = duracao_media_mergeR / 5.0;
		cout << "[MergeSortRecursivoVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_mergeR << " microssegundos" << endl;
        cout << "[MergeSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[MergeSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs8 << tamanho_vetor << " " << duracao_media_mergeR << "\n"; // grava no arquivo de resultados do quick Sort Recursivo
	}
	
	ofs8.close(); // fecha arquivo de resultados do merge Sort Recursivo
	// ------------------------------------------------------------

    // -----------------------------------------------------------
	// Etapa 10 - Execução do heapSortRecursivo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs9("resultados/HeapSortRecursivoVetor.txt", ofstream::out ); // abre arquivo de resultados do heap sort Recursivo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_heapR = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o heap sort recursivo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// heap ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			heapSortRecursaoVetor(vetor,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
            trocas+=heapSortRecursaoVetorTroca(vetor,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
            comparacoes+=heapSortRecursaoVetorCom(vetor,tamanho_vetor); // ordena o vetor usando o quick SortRecursivo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_heapR = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_heapR += duracao_heapR;			
		}	
		
		duracao_media_heapR = duracao_media_heapR / 5.0;
		cout << "[HeapSortRecursivoVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_heapR << " microssegundos" << endl;
        cout << "[HeapSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[HeapSortRecursivoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs9 << tamanho_vetor << " " << duracao_media_heapR << "\n"; // grava no arquivo de resultados do heap Sort Recursivo
	}
	
	ofs9.close(); // fecha arquivo de resultados do heap Sort Recursivo
	// ------------------------------------------------------------

        // -----------------------------------------------------------
	// Etapa 11 - Execução do QuickSortIterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs10("resultados/QuickSortIterativoVetor.txt", ofstream::out ); // abre arquivo de resultados do QuickSortIterativo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_quickI = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o QuickSortIterativo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// QuickSortIterativo ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			quickSortIterativoVetor(vetor,0,tamanho_vetor); // ordena o vetor usando o QuickSortIterativo
            trocas+=quickSortIterativoVetorTroca(vetor,0,tamanho_vetor); // ordena o vetor usando o QuickSortIterativo
            comparacoes+=quickSortIterativoVetorCom(vetor,0,tamanho_vetor); // ordena o vetor usando o QuickSortIterativo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_quickI = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_quickI += duracao_quickI;			
		}	
		
		duracao_media_quickI = duracao_media_quickI / 5.0;
		cout << "[QuickSortIterativoVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_quickI << " microssegundos" << endl;
        cout << "[QuickSortIterativoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[QuickSortIterativoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs10 << tamanho_vetor << " " << duracao_media_quickI << "\n"; // grava no arquivo de resultados do QuickSortIterativo
	}
	
	ofs10.close(); // fecha arquivo de resultados do MergeSortIterativo
	// ------------------------------------------------------------

            // -----------------------------------------------------------
	// Etapa 12 - Execução do MergeSortIterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs11("resultados/MergeSortIterativoVetor.txt", ofstream::out ); // abre arquivo de resultados do MergeSortIterativo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_mergeI = 0.0;
        int comparacoes=0;
        int trocas=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o MergeSortIterativo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// MergeSortIterativo ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			mergeSortIterativoVetor(vetor,tamanho_vetor); // ordena o vetor usando o MergeSortIterativo
           trocas+= mergeSortIterativoVetorTroca(vetor,tamanho_vetor); // ordena o vetor usando o MergeSortIterativo
            comparacoes+=mergeSortIterativoVetorCom(vetor,tamanho_vetor); // ordena o vetor usando o MergeSortIterativo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_mergeI = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_mergeI += duracao_mergeI;			
		}	
		
		duracao_media_mergeI = duracao_media_mergeI / 5.0;
		cout << "[MergeSortIterativoVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_mergeI << " microssegundos" << endl;
        cout << "[MergeSortIterativoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[MergeSortIterativoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs11 << tamanho_vetor << " " << duracao_media_mergeI << "\n"; // grava no arquivo de resultados do MergeSortIterativo
	}
	
	ofs11.close(); // fecha arquivo de resultados do MergeSortIterativo
	// ------------------------------------------------------------

// -----------------------------------------------------------
	// Etapa 13 - Execução do HeapSortIterativo
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs12("resultados/HeapSortIterativoVetor.txt", ofstream::out ); // abre arquivo de resultados do HeapSortIterativo
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_heapI = 0.0;
        int trocas=0;
        int comparacoes=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o HeapSortIterativo para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// HeapSortIterativo ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();
		
			heapsortIterativoVetor(vetor,tamanho_vetor); // ordena o vetor usando o HeapSortIterativo
            trocas+=heapsortIterativoVetorTroca(vetor,tamanho_vetor); // ordena o vetor usando o HeapSortIterativo
            comparacoes+=heapsortIterativoVetorCom(vetor,tamanho_vetor); // ordena o vetor usando o HeapSortIterativo
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_heapI = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_heapI += duracao_heapI;			
		}	
		
		duracao_media_heapI = duracao_media_heapI / 5.0;
		cout << "[HeapSortIterativoVetor] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_heapI << " microssegundos" << endl;
        cout << "[HeapSortIterativoVetor] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[HeapSortIterativoVetor] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs12 << tamanho_vetor << " " << duracao_media_heapI << "\n"; // grava no arquivo de resultados do HeapSortIterativo
	}
	
	ofs12.close(); // fecha arquivo de resultados do HeapSortIterativo
	// ------------------------------------------------------------

    // -----------------------------------------------------------
	// Etapa 14 - Execução do bubblesortIterativoLista
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs13("resultados/BubbleIterativoLista.txt", ofstream::out ); // abre arquivo de resultados do BubbleIterativoLista
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubblesortIterativoLista = 0.0;
        int trocas=0;
        int comparacoes=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o BubbleIterativoLista para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// BubbleIterativoLista ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();

            QX_List *l=new QX_List;
            for(int i=0;i<tamanho_vetor;i++){
                l->push_back(vetor[i]);
            }
		
			bubblesortIterativoLista(l); // ordena o vetor usando o BubbleIterativoLista
            trocas+=bubblesortIterativoListaTroca(l); // ordena o vetor usando o BubbleIterativoLista
            comparacoes+=bubblesortIterativoListaCom(l); // ordena o vetor usando o BubbleIterativoLista
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_bubblesortIterativoLista = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_bubblesortIterativoLista += duracao_bubblesortIterativoLista;

            delete l;			
		}	
		
		duracao_media_bubblesortIterativoLista = duracao_media_bubblesortIterativoLista / 5.0;
		cout << "[BubbleIterativoLista] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_bubblesortIterativoLista << " microssegundos" << endl;
        cout << "[BubbleIterativoLista] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[BubbleIterativoLista] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs13 << tamanho_vetor << " " << duracao_media_bubblesortIterativoLista << "\n"; // grava no arquivo de resultados do HeapSortIterativo
	}
	
	ofs13.close(); // fecha arquivo de resultados do BubbleIterativoLista
	// ------------------------------------------------------------

    // -----------------------------------------------------------
	// Etapa 15 - Execução do insertionsortIterativoLista
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs14("resultados/insertionsortIterativoLista.txt", ofstream::out ); // abre arquivo de resultados do insertionsortIterativoLista
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_InsertLista = 0.0;
        int trocas=0;
        int comparacoes=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o BubbleIterativoLista para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// BubbleIterativoLista ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();

            QX_List *l=new QX_List;
            for(int i=0;i<tamanho_vetor;i++){
                l->push_back(vetor[i]);
            }
		
			insertionsortIterativoLista(l); // ordena o vetor usando o BubbleIterativoLista
            trocas+=insertionsortIterativoListaTroca(l); // ordena o vetor usando o BubbleIterativoLista
            comparacoes+=insertionsortIterativoListaCom(l); // ordena o vetor usando o BubbleIterativoLista
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_InsertLista = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_InsertLista += duracao_InsertLista;

            delete l;			
		}	
		
		duracao_media_InsertLista = duracao_media_InsertLista / 5.0;
		cout << "[InsertionsortIterativoLista] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_InsertLista << " microssegundos" << endl;
        cout << "[InsertionsortIterativoLista] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[InsertionsortIterativoLista] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs14 << tamanho_vetor << " " << duracao_media_InsertLista << "\n"; // grava no arquivo de resultados do HeapSortIterativo
	}
	
	ofs14.close(); // fecha arquivo de resultados do BubbleIterativoLista
	// ------------------------------------------------------------

    // -----------------------------------------------------------
	// Etapa 15 - Execução do insertionsortIterativoLista
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ofstream ofs15("resultados/selectionsortLista.txt", ofstream::out ); // abre arquivo de resultados do selectionsortLista
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_selectionsortLista = 0.0;
        int trocas=0;
        int comparacoes=0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o selectionsortLista para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			string nome_arquivo = "dados/random"+to_string(iteracao)+"_"+to_string(semente)+".dat";
		
			ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			// selectionsortLista ---------------------------------------------------------
			// obtendo o tempo inicial
			auto ini2 = chrono::high_resolution_clock::now();

            QX_List *l=new QX_List;
            for(int i=0;i<tamanho_vetor;i++){
                l->push_back(vetor[i]);
            }
		
			selectionsortIterativoLista(l); // ordena o vetor usando o selectionsortLista
            trocas+=selectionsortIterativoListaTroca(l); // ordena o vetor usando o selectionsortLista
            comparacoes+=selectionsortIterativoListaCom(l); // ordena o vetor usando o selectionsortLista
		
			// obtendo o tempo final
			auto fim2 = chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao_selectionsortLista = chrono::duration_cast<chrono::microseconds>(fim2 - ini2).count();
			
			duracao_media_selectionsortLista += duracao_selectionsortLista;

            delete l;			
		}	
		
		duracao_media_selectionsortLista = duracao_media_selectionsortLista / 5.0;
		cout << "[SelectionsortLista] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media_selectionsortLista << " microssegundos" << endl;
        cout << "[SelectionsortLista] N = " << tamanho_vetor << ", Numero de trocas = " << trocas << " trocas" << endl;
        cout << "[SelectionsortLista] N = " << tamanho_vetor << ", Numero de comparacoes = " << comparacoes << " comparacoes" << endl;
		ofs15 << tamanho_vetor << " " << duracao_media_selectionsortLista << "\n"; // grava no arquivo de resultados do HeapSortIterativo
	}
	
	ofs15.close(); // fecha arquivo de resultados do SelectionsortLista
	// ------------------------------------------------------------
    
    
	
	return 0;
}
