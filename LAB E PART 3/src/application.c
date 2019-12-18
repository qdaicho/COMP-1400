/*
 * application.c
 *
 *  Created on: Oct. 21, 2019
 *      Author: emsee
 */

#include <stdio.h>

int counter = 1;

void recursiveTri(int starHeight) {
	int counter2 = 0;
	if (counter <= starHeight) {
		while (counter2 < counter) {
			printf("*");
			counter2++; // 1
		}
		printf("\n");
		counter++;
		recursiveTri(starHeight);
	}
}

int main(void) {
//	int num;
//	puts("Please type down the height of the triangle\n");
//	scanf("%d", &num);
//	puts("\n");
//	recursiveTri(num);

			return 0;
		}
