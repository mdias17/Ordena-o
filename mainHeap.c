#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "printVetor.h"


#include "heapSort.h"



#define TAM 100

int main(){
	
	int vetor[TAM], vetor2[TAM], vetor3[TAM], i;
	clock_t t;


	/*printf("\n\n\tVETOR NAO ORDENADO\n");
	for(i = 0; i < TAM; i++){
		vetor[i] = rand()%TAM;
	}
	printVetor(vetor, TAM);
	*/
	/*
	printf("\n\n\tVETOR ORDENADO-CRESCENTE\n");
	for(i = 0; i < TAM; i++){
		vetor2[i] = i;
	}
	printVetor(vetor2, TAM);
	
	printf("\n\n\tVETOR ORDENADO-DECRESCENTE\n");
	for(i = TAM; i > 0; i--){
		vetor3[i] = i;
	}
	printVetor(vetor3, TAM);
	*/
	
	printf("\n\n\tVETOR (NAO ORDENADO) HEAP SORT\n");
	t = clock();
	heapSort(vetor, TAM);
	t = clock() - t; //tempo final - tempo inicial
 	//imprime o tempo na tela
 	printf("Tempo de execucao: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetor, TAM);
	
	/*
	printf("\n\n\tVETOR (ORDENADO - CRESCENTE) HEAP SORT\n");
	t = clock();
	heapSort(vetor2, TAM);
	t = clock() - t; //tempo final - tempo inicial
 	//imprime o tempo na tela
 	printf("Tempo de execucao: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	printVetor(vetor2, TAM);
	*/

	return 0;
}
