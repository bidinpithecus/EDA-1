// Todas as funções auxiliares utilizadas no decorrer do programa ficarão neste header

#ifndef _HELPERS_H
#define _HELPERS_H

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

#endif