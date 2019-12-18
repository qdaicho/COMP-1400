/*
 * app.h
 *
 *  Created on: Nov. 12, 2019
 *      Author: emsee
 */

#ifndef header
#define header

extern int m1; //num of rows for Matrix A
extern int n1; //num of columns for Matrix A

extern int n2; //num of rows for Matrix B
extern int p2; //num of columns for Matrix B

int** multiplyMatrix(int matrixA[m1][n1], int matrixB[n2][p2]);

void printArray(int arry[m1][p2]);

int add(int x, int y);

#endif /* SRC_HEADER_H_ */
