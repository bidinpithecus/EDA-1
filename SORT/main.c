#include <stdio.h>
#include "sorts.h"
#define SIZE 10

int main(void) {
	int auxArr[SIZE] = {795, 227, 971, 851, 626, 222, 950, 120, 226, 674};
	int v[SIZE];
	int iterations;
	copyArr(auxArr, v, SIZE);

	printf("Vetor original:\n");
	printArray(v, SIZE);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");
	
	// inicio bubble
	printf("\n     Bubble Sort:\n");
	iterations = bubbleSort(v, SIZE);
	printf("\nVetor ordenado:\n");
	printArray(v, SIZE);
	printf("\nForam necessarias %d iteracoes para ordena-lo\n", iterations);
	// fim bubble

	copyArr(auxArr, v, SIZE);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// inicio insertion
	printf("\n     Insertion Sort:\n");
	iterations = insertionSort(v, SIZE);
	printf("\nVetor ordenado:\n");
	printArray(v, SIZE);
	printf("\nForam necessarias %d iteracoes para ordena-lo\n", iterations);
	// fim insertion
	
	copyArr(auxArr, v, SIZE);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");


	
	return 0;
}