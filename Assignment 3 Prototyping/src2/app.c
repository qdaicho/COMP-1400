#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int loadedArry[][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

char operatorCombination[12];
int counter = 0;
int rowOne;
int rowTwo;
int rowThree;
int columnOne;
int columnTwo;
int columnThree;

/**
 * This shuffles a 2d array
 */
void shuffle(int integerArry[3][3]) {

	for (int i = 2; i > 0; i--) {
		for (int j = 2; j > 0; j--) {
			int m = rand() % (i + 1);
			int n = rand() % (j + 1);

			int temp = integerArry[i][j];
			integerArry[i][j] = integerArry[m][n];
			integerArry[m][n] = temp;
		}
	}
}

/**
 * This function returns a random operator [+,*, -, /]
 */
char returnOperator() {
	char operators[4] = { '+', '*', '-', '/' };
	int i = rand() % 3;
	return operators[i];
}

/**
 * This method returns the answer to any row or column through two random
 * operations.
 */
int endResult(int x, int y, int z) {
	char combination[4];

	sprintf(combination, "%c%c", returnOperator(), returnOperator());

	if (!strcmp("++", combination)) {
		operatorCombination[counter] = '+';
		operatorCombination[counter + 1] = '+';
		return x + y + z;
	} else if (!strcmp("+-", combination)) {
		operatorCombination[counter] = '+';
		operatorCombination[counter + 1] = '-';
		return x + y - z;
	} else if (!strcmp("+*", combination)) {
		operatorCombination[counter] = '+';
		operatorCombination[counter + 1] = '*';
		return x + y * z;
	} else if (!strcmp("-+", combination)) {
		operatorCombination[counter] = '-';
		operatorCombination[counter + 1] = '+';
		return x - y + z;
	} else if (!strcmp("--", combination)) {
		operatorCombination[counter] = '-';
		operatorCombination[counter + 1] = '-';
		return x - y - z;
	} else if (!strcmp("-*", combination)) {
		operatorCombination[counter] = '-';
		operatorCombination[counter + 1] = '*';
		return x - y * z;
	} else if (!strcmp("*+", combination)) {
		operatorCombination[counter] = '*';
		operatorCombination[counter + 1] = '+';
		return x * y + z;
	} else if (!strcmp("*-", combination)) {
		operatorCombination[counter] = '*';
		operatorCombination[counter + 1] = '-';
		return x * y - z;
	} else if (!strcmp("**", combination)) {
		operatorCombination[counter] = '*';
		operatorCombination[counter + 1] = '*';
		return x * y * z;
	}

	return 0;
}

/**
 * This evaluates and loads up all the operators and row and column evaluations based on that.
 */
void evaluateArray() {
	counter = 0;
	rowOne = endResult(loadedArry[0][0], loadedArry[0][1], loadedArry[0][2]);

	counter = 2;
	rowTwo = endResult(loadedArry[1][0], loadedArry[1][1], loadedArry[1][2]);

	counter = 4;
	rowThree = endResult(loadedArry[2][0], loadedArry[2][1], loadedArry[2][2]);

	counter = 6;
	columnOne = endResult(loadedArry[0][0], loadedArry[1][0], loadedArry[2][0]);

	counter = 8;
	columnTwo = endResult(loadedArry[0][1], loadedArry[1][1], loadedArry[2][1]);

	counter = 10;
	columnThree = endResult(loadedArry[0][2], loadedArry[1][2],
			loadedArry[2][2]);
}

/**
 * This prints the solution array
 */
void printArray() {
	//first row
	printf("\n\n\n  %d  %c  %d  %c  %d  =  %d\n", loadedArry[0][0],
			operatorCombination[0], loadedArry[0][1], operatorCombination[1],
			loadedArry[0][2], rowOne);

	//first operators
	printf("\n  %c     %c     %c \n", operatorCombination[6],
			operatorCombination[8], operatorCombination[10]);

	//second row
	printf("\n  %d  %c  %d  %c  %d  =  %d\n", loadedArry[1][0],
			operatorCombination[2], loadedArry[1][1], operatorCombination[3],
			loadedArry[1][2], rowTwo);

	//second operators
	printf("\n  %c     %c     %c \n", operatorCombination[7],
			operatorCombination[9], operatorCombination[11]);

	//third row
	printf("\n  %d  %c  %d  %c  %d   =  %d\n", loadedArry[2][0],
			operatorCombination[4], loadedArry[2][1], operatorCombination[5],
			loadedArry[2][2], rowThree);

	//third operators
	printf("\n  =     =     =\n");

	printf("\n%3d   %3d   %3d", columnOne, columnTwo, columnThree);
}

int main(void) {
	srand(time(0));

	shuffle(loadedArry);
	evaluateArray();
	printArray();

	return 0;
}
