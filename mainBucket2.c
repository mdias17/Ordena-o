#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "printVetor.h"

#include "bucketSort2.h"


#define TAM 10000000


int main(){
	
	int vetor[TAM], vetor2[TAM], i;
	clock_t t;


	printf("\n\n\tVETOR NAO ORDENADO\n");
	for(i = 0; i < TAM; i++){
		vetor[i] = rand()%TAM;
	}
//	printVetor(vetor, TAM);
	
	printf("\n\n\tVETOR BUCKET SORT\n");
	t = clock();
	bucketSort(vetor, TAM);
	t = clock() - t; //tempo final - tempo inicial
 	//imprime o tempo na tela
 	printf("Tempo de execucao: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	//printVetor(vetor, TAM);
	
	printf("\n\n\===========================================================================\n");
	
	printf("\n\n\tVETOR ORDENADO-CRESCENTE\n");
	for(i = 0; i < TAM; i++){
		vetor2[i] = i;
	}
	//printVetor(vetor2, TAM);
	
	
	printf("\n\n\tVETOR (ORDENADO - CRESCENTE) BUCKET SORT\n");
	t = clock();
	bucketSort(vetor2, TAM);
	t = clock() - t; //tempo final - tempo inicial
 	//imprime o tempo na tela
 	printf("Tempo de execucao: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
//	printVetor(vetor2, TAM);
	

	return 0;
}
