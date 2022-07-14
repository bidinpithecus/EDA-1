#include <stdio.h>
#include "sorts.h"
#define MAX 50
// VALOR BAIXO PARA TESTES
// MUDAR DEPOIS PARA 1000

int main(void) {
	int iterations;
	int arraySize = generateArraySize(MAX);
	int *auxArr = malloc(sizeof(int) * arraySize);
	int *v = malloc(sizeof(int) * arraySize);
	generateRandomArray(auxArr, arraySize, MAX);
	copyArr(auxArr, v, arraySize);


	printf("Foi gerado um vetor de %d inteiros que sera ordenado utilizando diferentes metodos de ordenacao\n\n", arraySize);
	printf("Vetor aleatorio original:\n");
	printArray(v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf("Vetor ordenado crescente original:\n");
	sortedArray(v, arraySize);
	printArray(v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf("Vetor ordenado decrescente original:\n");
	sortedBackwardsArray(v, arraySize);
	printArray(v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");


	// inicio bubble
	printf("\nBUBBLE SORT:\n");

	sortedArray(v, arraySize);
	iterations = bubbleSort(v, arraySize);
	printf("\n	Para ordenar o vetor previamente ordenado, ([0..%d]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	copyArr(auxArr, v, arraySize);
	iterations = bubbleSort(v, arraySize);
	printf("\n	Para o vetor aleatorio, foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	sortedBackwardsArray(v, arraySize);
	iterations = bubbleSort(v, arraySize);
	printf("\n	Para o vetor ordenado decrescente, ([%d..0]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo.\n", iterations);
	// fim bubble


	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n~~~ REORDENANDO VETOR ALEATORIO ~~~");
	copyArr(auxArr, v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// inicio insertion
	printf("\nINSERTION SORT:\n");

	sortedArray(v, arraySize);
	iterations = insertionSort(v, arraySize);
	printf("\n	Para ordenar o vetor previamente ordenado, ([0..%d]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	copyArr(auxArr, v, arraySize);
	iterations = insertionSort(v, arraySize);
	printf("\n	Para o vetor aleatorio, foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	sortedBackwardsArray(v, arraySize);
	iterations = insertionSort(v, arraySize);
	printf("\n	Para o vetor ordenado decrescente, ([%d..0]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo.\n", iterations);
	// fim insertion


	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n~~~ REORDENANDO VETOR ALEATORIO ~~~");
	copyArr(auxArr, v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// inicio heap
	printf("\nHEAP SORT:\n");

	sortedArray(v, arraySize);
	iterations = heapSort(v, arraySize);
	printf("\n	Para ordendar o vetor previamente ordenado, ([0..%d]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	copyArr(auxArr, v, arraySize);
	iterations = heapSort(v, arraySize);
	printf("\n	Para o vetor aleatorio, foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	sortedBackwardsArray(v, arraySize);
	iterations = heapSort(v, arraySize);
	printf("\n	Para o vetor ordenado inverso, ([%d..0]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo.\n", iterations);
	// fim heap

/*
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n~~~ REORDENANDO VETOR ALEATORIO ~~~");
	copyArr(auxArr, v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// inicio merge
	printf("\n     MERGE SORT:\n");

	sortedArray(v, arraySize);
	iterations = mergeSort(v, arraySize);
	printf("\nPara o vetor previamente ordenado, ([0..%d]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	copyArr(auxArr, v, arraySize);
	iterations = mergeSort(v, arraySize);
	printf("\nPara o vetor aleatorio ordenado, foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	sortedBackwardsArray(v, arraySize);
	iterations = mergeSort(v, arraySize);
	printf("\nPara o vetor ordenado inverso, ([%d..0]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo.\n", iterations);
	// fim merge

	
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n~~~ REORDENANDO VETOR ALEATORIO ~~~");
	copyArr(auxArr, v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// inicio quick
	printf("\n     QUICK SORT:\n");

	sortedArray(v, arraySize);
	iterations = quickSort(v, arraySize);
	printf("\nPara o vetor previamente ordenado, ([0..%d]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	copyArr(auxArr, v, arraySize);
	iterations = quickSort(v, arraySize);
	printf("\nPara o vetor aleatorio ordenado, foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	sortedBackwardsArray(v, arraySize);
	iterations = quickSort(v, arraySize);
	printf("\nPara o vetor ordenado inverso, ([%d..0]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo.\n", iterations);
	// fim quick

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n~~~ REORDENANDO VETOR ALEATORIO ~~~");
	copyArr(auxArr, v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	// inicio radix
	printf("\n     HEAP SORT:\n");

	sortedArray(v, arraySize);
	iterations = radixSort(v, arraySize);
	printf("\nPara o vetor previamente ordenado, ([0..%d]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	copyArr(auxArr, v, arraySize);
	iterations = radixSort(v, arraySize);
	printf("\nPara o vetor aleatorio ordenado, foram necessarias %d iteracoes para ordena-lo;\n", iterations);

	sortedBackwardsArray(v, arraySize);
	iterations = radixSort(v, arraySize);
	printf("\nPara o vetor ordenado inverso, ([%d..0]), ", (arraySize - 1));
	printf("foram necessarias %d iteracoes para ordena-lo.\n", iterations);
	// fim radix

	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	printf("\n~~~ REORDENANDO VETOR ALEATORIO ~~~");
	copyArr(auxArr, v, arraySize);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
*/
	
	return 0;
}