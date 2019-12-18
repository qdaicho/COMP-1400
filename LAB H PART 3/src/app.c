/*
 * app.c
 *
 *  Created on: Nov. 11, 2019
 *      Author: emsee
 */
#include <stdio.h>

void convertBinary(int num) {
	int binary[40];
	int index = 0;

	while (num > 0) {
		binary[index++] = num % 2;
		num = num / 2;
	}

	puts("\nYour number in Binary is the following:");
	for (int i = index - 1; i >= 0; i--) {
		printf("%d ", binary[i]);
	}
}
int main() {

	puts("Please type down a number to convert to binary: \n");
	int num;
	scanf("%d", &num);
	convertBinary(num);
	return 0;
}

