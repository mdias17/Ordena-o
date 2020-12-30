#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int SIZE;
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void show(int arr[]) {
	int i;
	for(i = 0; i < SIZE; ++i) printf("%d ", arr[i]);
	printf("\n");
}

int pickPivot(int* arr, int a, int b) { // median-of-three
	int i = (a+b)>>1, x = arr[a], y = arr[i], z = arr[b];
	if(x > y) {
		if(y > z) return i;
		if(x > z) return b;
		return a;
	}
	if(y < z) return i;
	if(x < z) return b;
	return a;
}

int partition(int* arr, int a, int b, int pivotPosition) {
	int pivotValue = arr[pivotPosition];
	int i, newPivot;
	
	if(a != pivotPosition) swap(arr, a, pivotPosition);

	for(i = newPivot = a+1; i <= b; ++i) {
		if(arr[i] > pivotValue) continue;
		swap(arr, i, newPivot);
		++newPivot;
	}
	
	--newPivot;
	swap(arr, newPivot, a);
	return newPivot;
}

void quicksort(int* arr, int a, int b) {
	if(b-a < 2) {
		if(b-a == 1 && arr[a] > arr[b]) swap(arr, a, b);
		return;
	}
	
	int p = pickPivot(arr, a, b);
	int newPivot = partition(arr, a, b, p);

	quicksort(arr, a, newPivot-1);
	quicksort(arr, newPivot+1, b);
}


void quick(int arr[]) {
	quicksort(arr, 0, SIZE-1);
}

int main(int argc, char** argv) {
	
	clock_t t;

	
	SIZE = argc > 1 ? atoi(argv[1]) : 100000000;
	int* arr = malloc(SIZE*sizeof(int));
	int* arr2 = malloc(SIZE*sizeof(int));
	int i;

	srand(time(NULL));
	for(i = 0; i < SIZE; i++) arr[i] = rand() % SIZE;

	//printf("\nBefore: ");
	//show(arr);
	
	t = clock();

	quick(arr);
	
	t = clock() - t; //tempo final - tempo inicial
 	
	//printf("\n\nAfter: ");
	//show(arr);

	free(arr);
	
	//imprime o tempo na tela
 	printf("\n\n1 Tempo de execucao: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	printf("\n\n===========================================================================\n\n");
	
	
	srand(time(NULL));
	for(i = 0; i < SIZE; i++) arr2[i] = i;

	printf("\nBefore: ");
	//show(arr2);
	
	t = clock();

	quick(arr2);
	
	t = clock() - t; //tempo final - tempo inicial
 	
	//printf("\n\nAfter: ");
	//show(arr2);

	free(arr2);
	
	//imprime o tempo na tela
 	printf("\n\n2 Tempo de execucao: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
	
	
	return 0;
}
