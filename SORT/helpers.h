// Todas as funções auxiliares utilizadas no decorrer do programa ficarão neste header

#ifndef _HELPERS_H
#define _HELPERS_H

#include <time.h>
#include <stdlib.h>
#include "sorts.h"

// função que dado um vetor e dois indices, faz a troca dos elementos dos indices dados do vetor
void swap(int v[], int i, int j) {
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

// função não irá mais ser utilizada, mantendo-a apenas caso haja a necessidade de algum teste
// função que dado um vetor e seu tamanho, printa todos os elementos deste vetor
void printArray(int v[], int n) {
	printf("{ ");
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			printf("%d }\n", v[i]);
		} else {
			printf("%d, ", v[i]);
		}
	}
}

// função não irá mais ser utilizada, mantendo-a apenas caso haja a necessidade de algum teste
// função que copia um vetor de origem para um de destino, recebendo também o tamanho destes
void copyArr(int arrSrc[], int arrDest[], int n) {
	for (int i = 0; i < n; i++) {
		arrDest[i] = arrSrc[i];
	}
}

// função auxiliar do Heap Sort
// função que recebe o vetor, seu tamanho, e o indice do pivo ("subarvore" a ser analisada)
void heapify(int v[], int n, int i, int *iterations) {
	int center = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left < n && v[left] > v[center]) {
		center = left;
	}
	if (right < n && v[right] > v[center]) {
		center = right;
	}
	if (center != i) {
		swap(v, i, center);
		(*iterations) += 1;
		heapify(v, n, center, iterations);
	} else {
		(*iterations) += 1;
	}
}

// função auxiliar do Merge Sort
void merge(int v[], int head, int half, int tail, int *iterations) {
	int *aux = malloc((tail - head + 1) * sizeof(int));
	int i = head, j = half + 1, k = 0;

	while (i <= half && j <= tail) {
		aux[k++] = v[i] <= v[j] ? v[i++] : v[j++];
	}

	while (i <= half) {
		aux[k++] = v[i++];
	}

	while (j <= tail) {
		aux[k++] = v[j++];
	}

	for (int i = head, k = 0; i <= tail; i++, k++) {
		(*iterations) += 1;
		v[i] = aux[k];
	}
}

// função auxiliar do Merge Sort
void halfMergeSort(int v[], int head, int tail, int *iterations) {
	int plus, minus;
	// Encontra o meio
 	int half = (head + tail) / 2;

 	if(head < tail) {
		// Metade superior
 		halfMergeSort(v, head, half, *(&iterations));
		// Metade inferior
 		halfMergeSort(v, half + 1, tail, *(&iterations));
		merge(v, head, half, tail, *(&iterations));
	}
}

// funcao que gera um numero pseudo-aleatorio
int randomNum(int max) {
	return ((rand() % max) + 1);
}

// funcao que gera conjuntos de numeros pseudo-aleatorios e popula um array com tais numeros gerados
int iterationsRandomArrays(int arr[], int size, int limit, int numArrays, int (*sortMethod)(int*, int)) {
	int iterations = 0;
	for (int i = 0; i < numArrays; i++) {
		for (int j = 0; j < size; j++) {
			arr[j] = randomNum(limit);
		}
		iterations += sortMethod(arr, size);
	}
	return iterations/numArrays;
}

// funcao que popula um array ordenada de forma crescente de 0 ate o limite passado
void sortedArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
}

// funcao que popula um array ordenada de forma decrescente de do limite passado ate 0
void sortedBackwardsArray(int arr[], int size) {
	for (int i = size - 1; i >= 0; i--) {
		arr[(size - 1)-i] = i;
	}
}

#endif