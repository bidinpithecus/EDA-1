#include <stdio.h>
#include <string.h>
#include "sorts.h"
#define MAX 1000
#define NUM_RANDOM_ARRAYS 10
#define EXECUTIONS 2

int main(void) {
	srand(time(NULL));
	int iterations;
	int arraySize;
	int execsMade = 0;
	int *v = NULL;
	FILE *pAvg;
	FILE *pBest;
	FILE *pWorst;

	pAvg = fopen("results/medio.txt", "a");
	pBest = fopen("results/melhor.txt", "a");
	pWorst = fopen("results/pior.txt", "a");

	if(pAvg == NULL) {
    perror("Erro ao abrir arquivo de caso medio.");
		exit(-1);
	}
	if(pBest == NULL) {
    perror("Erro ao abrir arquivo de melhor caso.");
		exit(-1);
	}
	if(pWorst == NULL) {
    perror("Erro ao abrir arquivo de pior caso.");
		exit(-1);
	}
	do {
		arraySize = randomNum(MAX);
		v = malloc(sizeof(int) * arraySize);
		fprintf(pAvg, "%d\t", arraySize);
		fprintf(pBest, "%d\t", arraySize);
		fprintf(pWorst, "%d\t", arraySize);

		printf("	Se tratam de vetores de %d inteiros que serao ordenados utilizando diferentes metodos de ordenacao\n", arraySize);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\n	Para o melhor caso, em que se considera um vetor ordenado crescente, foi gerado um vetor [0..%d]:\n", (arraySize - 1));
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		printf("\n	Para o caso medio, em que se considera o conjunto de dados desordenado sem seguir nenhum padrao, foram gerados %d vetores e o numero de iteracoes realizadas para ordena-lo, trata-se de um resultado medio da ordenacao desses %d vetores\n", NUM_RANDOM_ARRAYS, NUM_RANDOM_ARRAYS);
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		printf("\n	Para o pior caso, em que se considera um vetor ordenado decrescente, foi gerado um vetor: [%d..0]\n", (arraySize - 1));
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");


		// inicio bubble
		printf("\n~~~~~~~~~~~~~~~~~~~~~");
		printf("\n~~~~ BUBBLE SORT ~~~~");
		printf("\n~~~~~~~~~~~~~~~~~~~~~\n");

		sortedArray(v, arraySize);
		iterations = bubbleSort(v, arraySize);
		fprintf(pBest, "%d\t", iterations);
		printf("\n	Melhor caso: %d iteracoes;\n", iterations);

		iterations = iterationsRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, bubbleSort);
		fprintf(pAvg, "%d\t", iterations);
		printf("\n	Caso medio: %d iteracoes em media;\n", iterations);

		sortedBackwardsArray(v, arraySize);
		iterations = bubbleSort(v, arraySize);
		fprintf(pWorst, "%d\t", iterations);
		printf("\n	Pior caso: %d iteracoes.\n", iterations);
		// fim bubble


		// inicio insertion
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~");
		printf("\n~~~~ INSERTION SORT ~~~~");
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");

		sortedArray(v, arraySize);
		iterations = insertionSort(v, arraySize);
		fprintf(pBest, "%d\t", iterations);
		printf("\n	Melhor caso: %d iteracoes;\n", iterations);

		iterations = iterationsRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, insertionSort);
		fprintf(pAvg, "%d\t", iterations);
		printf("\n	Caso medio: %d iteracoes em media;\n", iterations);

		sortedBackwardsArray(v, arraySize);
		iterations = insertionSort(v, arraySize);
		fprintf(pWorst, "%d\t", iterations);
		printf("\n	Pior caso: %d iteracoes.\n", iterations);
		// fim insertion


		// inicio heap
		printf("\n~~~~~~~~~~~~~~~~~~~");
		printf("\n~~~~ HEAP SORT ~~~~");
		printf("\n~~~~~~~~~~~~~~~~~~~\n");

		sortedArray(v, arraySize);
		iterations = heapSort(v, arraySize);
		fprintf(pBest, "%d\t", iterations);
		printf("\n	Melhor caso: %d iteracoes;\n", iterations);

		iterations = iterationsRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, heapSort);
		fprintf(pAvg, "%d\t", iterations);
		printf("\n	Caso medio: %d iteracoes em media;\n", iterations);

		sortedBackwardsArray(v, arraySize);
		iterations = heapSort(v, arraySize);
		fprintf(pWorst, "%d\t", iterations);
		printf("\n	Pior caso: %d iteracoes.\n", iterations);
		// fim heap


		// inicio merge
		printf("\n~~~~~~~~~~~~~~~~~~~~");
		printf("\n~~~~ MERGE SORT ~~~~");
		printf("\n~~~~~~~~~~~~~~~~~~~~\n");

		sortedArray(v, arraySize);
		iterations = mergeSort(v, arraySize);
		fprintf(pBest, "%d\t", iterations);
		printf("\n	Melhor caso: %d iteracoes;\n", iterations);

		iterations = iterationsRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, mergeSort);
		fprintf(pAvg, "%d\t", iterations);
		printf("\n	Caso medio: %d iteracoes em media;\n", iterations);

		sortedBackwardsArray(v, arraySize);
		iterations = mergeSort(v, arraySize);
		fprintf(pWorst, "%d\t", iterations);
		printf("\n	Pior caso: %d iteracoes.\n", iterations);
		// fim merge


		// inicio quick
		printf("\n~~~~~~~~~~~~~~~~~~~~");
		printf("\n~~~~ QUICK SORT ~~~~");
		printf("\n~~~~~~~~~~~~~~~~~~~~\n");

		sortedArray(v, arraySize);
		iterations = quickSort(v, arraySize);
		fprintf(pBest, "%d\t", iterations);
		printf("\n	Melhor caso: %d iteracoes;\n", iterations);

		iterations = iterationsRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, quickSort);
		fprintf(pAvg, "%d\t", iterations);
		printf("\n	Caso medio: %d iteracoes em media;\n", iterations);

		sortedBackwardsArray(v, arraySize);
		iterations = quickSort(v, arraySize);
		fprintf(pWorst, "%d\t", iterations);
		printf("\n	Pior caso: %d iteracoes.\n", iterations);
		// fim quick


		// inicio radix
		printf("\n~~~~~~~~~~~~~~~~~~~~");
		printf("\n~~~~ RADIX SORT ~~~~");
		printf("\n~~~~~~~~~~~~~~~~~~~~\n");

		sortedArray(v, arraySize);
		iterations = radixSort(v, arraySize);
		fprintf(pBest, "%d\n", iterations);
		printf("\n	Melhor caso: %d iteracoes;\n", iterations);

		iterations = iterationsRandomArrays(v, arraySize, MAX, NUM_RANDOM_ARRAYS, radixSort);
		fprintf(pAvg, "%d\n", iterations);
		printf("\n	Caso medio: %d iteracoes em media;\n", iterations);

		sortedBackwardsArray(v, arraySize);
		iterations = radixSort(v, arraySize);
		fprintf(pWorst, "%d\n", iterations);
		printf("\n	Pior caso: %d iteracoes.\n", iterations);
		// fim radix
		execsMade++;

	} while (execsMade != EXECUTIONS);

	fclose(pAvg);
	fclose(pBest);
	fclose(pWorst);

	return 0;
}
