// Metodos de ordenação ficarão neste header

#ifndef _SORTS_H
#define _SORTS_H

#include "helpers.h"

/*
metodo --> assinatura;
bubble-sort --> int bubbleSort(int v[], int n) return numIterations; OK
insertion-sort --> int insertionSort(int v[], int n) return numIterations; OK
heap-sort;
merge-sort;
quick-sort;
radix-sort;
*/

int bubbleSort (int v[], int n) {
	int numIterations = 0;
	
	for (int i = 0; i < n - 1; i++) {
		numIterations++;
		for (int j = i + 1; j < n; j++) {
			numIterations++;
			if (v[i] > v[j]) {
				swap(v, i, j);
			}
		}
	}
	return numIterations;
}

int insertionSort(int v[], int n) {
	int numIterations = 0;
	int center, j;

	for (int i = 1; i < n; i++) {
		center = v[i];
		j = i - 1;
		numIterations++;

		while (j >= 0 && center < v[j]) {
			v[j + 1] = v[j];
			j--;
			numIterations++;
		}
		v[j + 1] = center;
	}

	return numIterations;
}

#endif