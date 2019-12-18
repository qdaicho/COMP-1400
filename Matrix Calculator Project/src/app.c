/*
 * app.c
 *
 *  Created on: Nov. 12, 2019
 *      Author: emsee
 */
#include <stdio.h>
#include "header.h"

int main() {
	m1 = 3;
	n1 = 3;

	n2 = 3;
	p2 = 4;

	int A[3][3] = { { 1, 1, 1 }, { 2, 3, 4 }, { 2, 1, 3 } };

	int B[3][4] = { { 1, 1, 1, 6 }, { 5, 1, 1, 4 }, { 1, 1, 1, 2 } };

	int** answer[m1][p2];

	answer = multiplyMatrix(A, B);

//	printArray(answer);
//	int **answer =

	puts("\n\n\n");

	return 0;
}

