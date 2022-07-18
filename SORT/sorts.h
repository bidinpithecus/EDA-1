// Metodos de ordenação ficarão neste header

#ifndef _SORTS_H
#define _SORTS_H

#include "helpers.h"

/*
	metodo --> assinatura;
	bubble-sort --> int bubbleSort(int v[], int n) return numIterations; OK
	insertion-sort --> int insertionSort(int v[], int n) return numIterations; OK
	heap-sort --> int heapSort(int v[], int n) return numIterations; OK
	merge-sort --> int mergeSort(int v[], int n) return numIterations; OK
	quick-sort --> int quickSort(int v[], int n) return numIterations; OK
	radix-sort --> int radixSort(int v[], int n) return numIterations; OK
*/

int bubbleSort (int v[], int n) {
	int numIterations = 0;
	
	for (int i = 0; i < n - 1; i++) {
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

int heapSort(int v[], int n) {
	int numIterations = 0;
	int i;

	for (i = (n / 2) - 1; i >= 0; i--) {
		heapify(v, n, i, &numIterations);
	}
	for (i = n - 1; i > 0; i--) {
		swap(v, 0, i);
		heapify(v, i, 0, &numIterations);
	}

	return numIterations;
}

int mergeSort(int v[], int size) {
	int numIterations = 0;
	halfMergeSort(v, 0, size - 1, &numIterations);
	return numIterations;
}

int quickSort(int v[], int size) {
	int numIterations = 0;
	pivotQuickSort(v, 0, size - 1, &numIterations);
	return numIterations;
}

int radixSort(int v[], int n) {
	int numIterations = 0;
  int Max = max(v, n);

	for(int exp = 1; Max/exp > 0; exp *=10){
		countingSort(v, n, exp, &numIterations);
	}
	return numIterations;
}

#endif