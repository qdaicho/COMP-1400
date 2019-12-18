/*
 * application.c
 *
 *  Created on: Oct. 20, 2019
 *      Author: emsee
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

int main(void) {

	// Show a Welcome message to the player.
	printf("Welcome to Nine-Gaps game!...\n");
	printf("*****************************\n");
	printf("*****************\n");
	printf("*****\n");
	printf("\n");

	//Create the following variables to hold the number of filled, and blank squares
	int filledSquare = 0;
	int blankSquare = 0;
	char difficulty[100] = " ";
	int flagVariable = 0;

	//START THE MAIN WHILE LOOP
	while (true) {

		//WHILE LOOP FOR DIFFICULTY CHOICE
		while (flagVariable != 1) {
			printf(
					"Please type down your difficulty:\n- novice\n- medium\n- advanced\n- expert\n\n");
			scanf("%s", difficulty);

			if (!strcmp("novice", difficulty)) {
				filledSquare = 6;
				blankSquare = 3;
			} else if (!strcmp("medium", difficulty)) {
				filledSquare = 4;
				blankSquare = 5;
			} else if (!strcmp("advanced", difficulty)) {
				filledSquare = 2;
				blankSquare = 7;
			} else if (!strcmp("expert", difficulty)) {
				filledSquare = 0;
				blankSquare = 9;
			} else {
				puts("\nThat isn't valid...try again...\n");
				continue;
			}

			flagVariable = 1;
			break;

		} //end nested while()

		break;
	} //end main while()

	puts("----------------------\nTHANK YOU FOR PLAYING!\n----------------------");

	return 0;
}
