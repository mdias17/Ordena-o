#include <stdio.h>
#include <stdlib.h> // srand, rand
#include <time.h> // time
#define TAM 1000000
#include "printVetor.h"

#include "radixSort.h"


int main()
{
	// vetor que será ordenado
	int vetor[TAM], i;
	
	clock_t t;
	
	printf("\n\n\tVETOR NAO ORDENADO\n");
	for(i = 0; i < TAM; i++){
		vetor[i] = rand()%TAM;
	}
	//printVetor(vetor, TAM);
	
	
	// inicializa random seed
	srand(time(NULL));
	 
	
	printf("\n\n\tVETOR QUICK SORT\n");
	t = clock();
	
	// chamada do quicksort
	radixSort(vetor, TAM);
	
	t = clock() - t; //tempo final - tempo inicial
 	
	//imprime o tempo na tela
 	printf("Tempo de execucao: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	//printVetor(vetor, TAM);
	
	
	return 0; 
}
