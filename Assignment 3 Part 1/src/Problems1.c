/*
 * FILE: Problems1.c
 *
 * Created on: Nov. 19, 2019
 *
 * Author: Md Mahir Daian Alam Chowdhury
 *
 * Student ID: 110006473
 *
 * Description:
 *  	This is program that lets the user enter data into an empty 2d flat smatrix until
 *  	its full.
 *
 *  	This gets the row and column numbers along with the value from the user
 *  	and stores the value in the corresponding position inside the one dimensional array.
 */

#include <stdio.h> // import standard input output library

int main(void) {

	int m; //number of rows
	int n; // number of columns
	int flag = 0;

	// ask user to enter in dimensions
	printf("Please enter the dimensions of the array (row then column)\n\n");
	scanf("%d %d", &m, &n);

	int array[m * n]; // create a flat array of given dimensions

	// initialize all elements of the array to 0
	for (int i = 0; i < (m * n); i++) {
		array[i] = 0;
	}

	// print out the array
	for (int i = 0; i < (m * n); i++) {
		printf("  %3d  ", array[i]);
		if ((i + 1) % n == 0) {
			puts("\n");
		}
	}

	// start the while loop for entering data while there are still zero elements
	while (flag == 0) {

		flag = 1;

		// prompt the user for the following
		printf("Enter a row number (1-%d), column(1-%d), value (any int):\n", m,
				n);

		int r, c, v; //holds the row, column, and value respectively
		scanf("%d %d %d", &r, &c, &v);

		// the sentinel value is 0 for r,c, and v
		if (r == 0 || c == 0 || v == 0)
			break;

		// if the row and col numbers are out of bounds, restart the loop after error message
		if (r < 1 || r > m || c < 1 || c > n) {
			puts("Invalid row and/or column numbers. Try again.");
			continue;
		}

		// replace the selected cell value with user input
		array[(n) * (r - 1) + (c - 1)] = v;

		// print out the array after every iteration
		for (int i = 0; i < (m * n); i++) {
			printf("  %3d  ", array[i]);
			if ((i + 1) % n == 0) {
				puts("\n");
			}
		}

		// checking for any 0's in the matrix and changing the flag if there are
		for (int i = 0; i < (m * n); i++) {
			if (array[i] == 0) {
				flag = 0;
			}
		}
	}
	printf("\n FINISHED...\n");
}
