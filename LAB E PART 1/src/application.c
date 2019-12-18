/*
 * application.c
 *
 *  Created on: Oct. 21, 2019
 *      Author: emsee
 */

#include <stdio.h>

int main(void) {
	int array[10];

//	puts("debug");

	for (int i = 0; i < 10; i++) {
		puts("Please type an integer: ");
		scanf("%d", &array[i]);
	}

	int sum = 0;

	for (int i = 0; i < 10; i++) {
		sum = sum + array[i];
	}
	printf("The total sum is: %d", sum);
	printf("\nThe average is: %d", (sum / 10));

	return 0;
}
