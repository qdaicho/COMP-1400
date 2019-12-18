#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

	int n = 0;

	srand(time(NULL));

	//get positive array size from user
	while (1) {
		puts(
				"Please type down a positive integer\nto generate a 1d array of numbers\n");
		scanf("%d", &n);

		if (n > 0)
			break;
		else
			continue;
	}

	int array[n];

	//generate array
	for (int i = 0; i < n; i++) {
		array[i] = rand() % 100;
	}

	puts("\n\n UNSORTED ARRAY\n-------------");

	//print unsorted array
	for (int element = 0; element < n; element++) {
		printf("%d\n", array[element]);
	}

	int temp = 0;
	int isSwapped = 0;

	// Calculate the time taken by the bubble sort()
	clock_t t;
	t = clock();

	//bubble sort array
	for (int y = 0; y < (n - 1); y++) {
		isSwapped = 0;
		for (int x = 0; (x < (n - 1)); x++) {
			if (array[x] > array[x + 1]) {
				temp = array[x + 1];
				array[x + 1] = array[x];
				array[x] = temp;
				isSwapped = 1;
			}
		}
		if (!isSwapped)
			break;
	}

	//print sorted array
	puts("\n\n SORTED ARRAY\n-------------");
	for (int element = 0; element < n; element++) {
		printf("%d\n", array[element]);
	}

	t = clock() - t;
	double time_taken = ((double) t) / CLOCKS_PER_SEC; // in seconds

	printf("\n-------------\nThe bubble sort took %f seconds to execute \n",
			time_taken);

	return 0;
}
