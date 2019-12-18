#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void) {
	puts(
			"\nPlease type an integer number to check\nif it is a prime number or not: \n");

	int num;

	scanf("%d", &num);

	int squareRoot = (int)(sqrt((double)(num)));
	bool isSquareRoot = false;

	for (int i = 1; i < squareRoot; i++) {

		if ((num > 1) && (num % i == 0) && (i != 1)) {
			isSquareRoot = false;
			break;
		} else {
			isSquareRoot = true;
		}
	}

	if (!isSquareRoot) {
		printf("The number %d IS NOT a prime number\n", num);
	} else {
		printf("The number %d IS a prime number\n", num);
	}

	return 0;
}
