// Todas as funções auxiliares utilizadas no decorrer do programa ficarão neste header

#ifndef _HELPERS_H
#define _HELPERS_H

#include <time.h>
#include <stdlib.h>

// função que dado um vetor e dois indices, faz a troca dos elementos dos indices dados do vetor
void swap(int v[], int i, int j) {
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

// função que dado um vetor e seu tamanho, printa todos os elementos deste vetor
void printArray(int v[], int n) {
	printf("{");
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			printf("%d}\n", v[i]);
		} else {
			printf("%d, ", v[i]);
		}
	}
}

// função que copia um vetor de origem para um de destino, recebendo também o tamanho destes
void copyArr(int arrSrc[], int arrDest[], int n) {
	for (int i = 0; i < n; i++) {
		arrDest[i] = arrSrc[i];
	}
}

// função que recebe o vetor, seu tamanho, e o indice do pivo ("subarvore" a ser analisada)
void heapify(int v[], int n, int i) {
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
		heapify(v, n, center);
	}
}

// funcao que gera um numero pseudo-aleatorio "sempre o mesmo"
int randomNum(int max) {
	return (rand() % (max + 1));
}

// funcao que gera um um numero pseudo-aleatorio, "sempre diferente"
int generateArraySize(int max) {
	srand(time(NULL));
	return (rand() % (max + 1));
}

// funcao que gera um conjunto de numeros pseudo-aleatorios e popula um array com tais numeros gerados
void generateRandomArray(int arr[], int size, int limit) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = randomNum(limit);
	}
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