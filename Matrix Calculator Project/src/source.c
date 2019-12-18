/*
 * source.c
 *
 *  Created on: Nov. 12, 2019
 *      Author: emsee
 */

int add(int x, int y) {
	return x + y;
}

int m1; //num of rows for Matrix A
int n1; //num of columns for Matrix A

int n2; //num of rows for Matrix B
int p2; //num of columns for Matrix B

//int answer[m1][p2];

int** multiplyMatrix(int matrixA[m1][n1], int matrixB[n2][p2]) {

	int **answer;
	answer = malloc(sizeof(int*) * 3);

	//mxn x nxp = mxp

	//first check if the matrices can be multiplied
	if (n1 != n2) {
		puts("\n These matrices can't be multiplied!!\n");
//		return;
	} else {

		//Answer matrix is of dimension mp
//	int answer[m1][p2];
		int temp = 0;

		int counter = 0;

		for (int row = 0; row < m1; row++) {
			for (int col = 0; col < p2; col++) {
				//this multiplies elements of a row of A and a column of B
				for (int j = 0; j < n2; j++) {
					temp += matrixA[row][j] * matrixB[j][col];
				}

				//put temp in the correct spot of the answer matrix
				for (int i = 0; i < p2; i++) {
					answer[row][counter] = temp;
					if (i == counter) {
						break;
					}
				}
				counter++;
				temp = 0;

			}

			counter = 0;
		}
	}

	return answer;
}

void printArray(int arry[m1][p2]) {
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < p2; j++) {
			printf("%3d ", arry[i][j]);
		}
		puts("\n");
	}

}
