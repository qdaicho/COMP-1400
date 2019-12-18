/*
 * app.c
 *
 *  Created on: Oct. 28, 2019
 *      Author: emsee
 */

#include <stdio.h>

int main(void) {
	srand(time(NULL));
	int random = rand() % 50 + 1;

	printf("%d\n\n", random);

	int i = 0;
	int guess;

	do {
		puts("\nPlease type down a number between 1-50\n");

		scanf("%d", &guess);

		if (guess == random) {
			puts("\nYOU GOT IT!\n");
			break;
		} else if (guess < random) {
			puts("\nThat is too low\n");
		} else {
			puts("\nThat is too high\n");
		}

		i++;
	} while (i < 10);

	if (i == 10) {
		puts("\nYou had more than 10 attempts...\n");
		printf("\nSorry, the number was %d \n", random);
	}

	return 0;
}
