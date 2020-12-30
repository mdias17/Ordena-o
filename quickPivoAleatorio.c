
#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time

#define TAM 1000000
#include "printVetor.h"


// função que realiza a troca entre dois elementos
void troca(int vet[], int i, int j)
{
	int aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

// particiona e retorna o índice do pivô
int particiona(int vet[], int inicio, int fim)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim]; // o pivô é sempre o último elemento
	pivo_indice = inicio;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
		if(vet[i] <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivo_indice);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(int vet[], int inicio, int fim)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim);
	// chama a particiona
	return particiona(vet, inicio, fim);
}

void quick_sort(int vet[], int inicio, int fim)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1);
		quick_sort(vet, pivo_indice + 1, fim);
	}
}

int main()
{
	
	int vet[TAM], i, x, aux;

	// vetor que será ordenado
	//int vet[] = {25,40,55,20,44,35,38,99,10,65,50};
	//int TAM = sizeof(vet) / sizeof(int);
	
	clock_t t;
	
	/*
	printf("\n\n\tVETOR NAO ORDENADO\n");
	for(i = 0; i < TAM; i++){
		vet[i] = rand()%TAM;
	}
	//printVetor(vet, TAM);
	
	--------------
	
	
	printf("\n\n\tVETOR ORDENADO-CRESCENTE\n");
	for(i = 0; i < TAM; i++){
		vet[i] = i;
	}
	//printVetor(vet, TAM);
	
	
	
	*/
	
	printf("\n\n\tVETOR ORDENADO-DECRESCENTE\n");
	for(i = 0; i < TAM; i++){
		vet[i] = i;
	}
	
	for(i = 0; i < TAM; i++){
		for(x = i + 1; x < TAM; x++){
			if(vet[i] < vet[x]){
				aux = vet[i];
				vet[i] = vet[x];
				vet[x] = aux;
			}
			else{
				printf("Error\n");
			}
		}
	}
	
	//printVetor(vet, TAM);
	
	// inicializa random seed
	srand(time(NULL));
	 
	t = clock();

 	printf("\n\nVETOR ORDENADO - QUICK SORT (PIVO ALEATORIO)");

	// chamada do quicksort
	quick_sort(vet, 0, TAM);

	t = clock() - t; //tempo final - tempo inicial
 	
	//imprime o tempo na tela
 	printf("\n\nTempo de execucao: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	// mostra o vetor ordenado
	//printVetor(vet, TAM);


}


