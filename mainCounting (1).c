#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "printVetor.h"


#include "countingSort.h"

#define TAM 100

int main(){
	
	int vetor[TAM], vetor2[TAM], i;
	clock_t t;


	printf("\n\n\tVETOR NAO ORDENADO\n");
	for(i = 0; i < TAM; i++){
		vetor[i] = rand()%TAM;
	}
	printVetor(vetor, TAM);
	
	printf("\n\n\tVETOR ORDENADO-CRESCENTE\n");
	for(i = 0; i < TAM; i++){
		vetor2[i] = i;
	}
	printVetor(vetor2, TAM);
	
	printf("\n\n\tVETOR (n ordenado) - COUNTING SORT\n");
	t = clock();
	countingSort(vetor, TAM);
	t = clock() - t; //tempo final - tempo inicial
 	//imprime o tempo na tela
 	printf("Tempo de execucao: %lf \n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetor, TAM);
	
	
	printf("\n\n\tVETOR ordenado) - COUNTING SORT\n");
	t = clock();
	countingSort(vetor2, TAM);
	t = clock() - t; //tempo final - tempo inicial
 	//imprime o tempo na tela
 	printf("Tempo de execucao: %lf \n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetor, TAM);


	return 0;
}
