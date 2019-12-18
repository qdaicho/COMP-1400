/*
 * app.c
 *
 *  Created on: Nov. 11, 2019
 *      Author: emsee
 */
#include <stdio.h>

int factorial(int input) {
	int factorial = input;
	for (int i = input; i > 1; i--) {
		factorial *= (i - 1);
	}
	return factorial;
}
int main() {

	int input;
	scanf("%d", &input);

	printf("\n\nThe factorical of your number is: %d", factorial(input));

	return 0;
}
