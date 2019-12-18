/*
 * ASSIGNMENT 2 PART 2
 *
 *  Created on: Oct. 22, 2019
 *  Author: Mahir Daian Chowdhury
 *  ID: 110006473
 */
#include <stdio.h>// C Standard Library for input/output functions
#include <stdlib.h>// C Standard Library for some utility functions, such as rand()
#include <time.h>// C Standard Library for date and time functions

//beginning of the main function
int main(void) {

	srand(time(0)); // Seed the random function

	int num[2]; //Create a number array of two elements to hold the two numbers that will be operated on

	//generate integer values for the two numbers between 1 and 9
	num[0] = rand() % 9 + 1;
	num[1] = rand() % 9 + 1;

	//generate integer values for the random variable between 0 and 2s
	int random = rand() % 2 + 0;

	//do a random operation on the two numbers based on the random variable and print it out to the console
	// 0 represents addition
	// 1 represents subtraction
	// 2 represents multiplication
	(random == 0) ? printf("%d + %d = %d", num[0], num[1], num[0] + num[1]) :
	(random == 1) ?
			printf("%d - %d = %d", num[0], num[1], num[0] - num[1]) :
			printf("%d x %d = %d", num[0], num[1], num[0] * num[1]);

	return 0;
}	// end of the main function
