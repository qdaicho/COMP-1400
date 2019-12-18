/*
 * application.c
 *
 *  Created on: Oct. 21, 2019
 *      Author: emsee
 */
#include <stdio.h>

int main(void) {

	int num;
	int product;

	puts("Please type down any integer");
	scanf("%d", &num);

	for (int i = 0; i <= 10; i++) {
		product = num * i;
		printf("%2d x %2d = %2d\n", num, i, product);
	}

	return 0;
}
