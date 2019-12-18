#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	srand(time(NULL));

	int array[30];

	puts("\nGenerating int array with elements between 0-20...\n");

	//generate array
	for (int i = 0; i < 30; i++) {
		array[i] = rand() % 20 + 0;
	}

	puts("\nDone...\n");

	for (int element = 0; element < 30; element++) {
		printf("%d ", array[element]);
		if (element == 15)
			puts("\n");
	}

	int num;

	puts(
			"\n\nPlease type down a number between 0-20\nto check for its frequency in the array...\n");

	scanf("%d", &num);

	int counter = 0;

	for (int i = 0; i < 30; i++) {
		if (array[i] == num)
			counter++;
	}

	printf("\nYour number appeared in the array %d times", counter);

	return 0;
}

