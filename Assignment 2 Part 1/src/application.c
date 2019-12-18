/*
 * ASSIGNMENT 2 PART 1
 *
 *  Created on: Oct. 22, 2019
 *  Author: Mahir Daian Chowdhury
 *  ID: 110006473
 */
#include <stdio.h>// C Standard Library for input/output functions
#include <stdlib.h>// C Standard Library for some utility functions, such as rand()
#include <time.h>// C Standard Library for date and time functions
#include <string.h> // C Standard Library for string functions

// Here you will later on (in the next assignments) declare some variables
// to use them inside the program
//Create the following variables to hold the number of filled, and blank squares

int filledSquare = 0; // the number of filled squares in the matrix based on difficulty
int blankSquare = 0; // the number of blank squares in the matrix based on difficulty
char difficulty[100] = " "; // this holds the user input for the difficulty of the game
int isSuccess = 0; // flag variable for checking if the user is successful in entering values
int numInput = 0; // user input
int row = 0; // user input for the row number
int column = 0; // user input for the column number

//MAIN FUNCTION
int main(void) {
	// Show a Welcome message to the player.
	printf("N I N E               G A P S\n");
	printf("*****************************\n");
	printf("      *****************      \n");
	printf("            *****            \n");
	printf("              *              \n");

	/* Start the outer loop to ask the level of difficulty from the player.
	 * This loop gives the player the opportunity to play again after the
	 * game is over. Complete this part:
	 */

	//MAIN LOOP
	while (1) {

		/*
		 * Ask the player to select the level of difficulty of the game, and
		 * check the validity of the user’s input. If the user enters an
		 * invalid level, program should provide a proper message and
		 * control should go the beginning of the outer loop.
		 * Complete // this part:
		 *
		 */
		puts(
				"\nChoose your difficulty:\n-novice\n-medium\n-advanced\n-expert\n\n");

		//scan for the difficulty
		scanf("%s", difficulty);

		//beginning of if else block
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
			puts("\n[That isn't a valid difficulty...try again...]\n");
			continue; //continue the main loop
		} //end of if else block

		/*
		 * Start the inner loop to repeatedly ask the player to enter a value
		 * between 1 and 9, and selected row and column, each one between 1 and 3.
		 * (The sentinel value is 0). If the inputs are not valid, show
		 * a proper message and control should go the beginning of the inner loop.
		 * Complete this part:
		 *
		 */

		//GAME LOOP
		while (!isSuccess) {

			// Ask for and get three integer values given below
			puts(
					"\nType a row[1-3], then a column[1-3], \nand a value between [1-9] for that coordinate:\n");
			scanf("%d %d %d", &row, &column, &numInput);

			//This is a sentinel value checker to break out of the game loop
			if (numInput == 0) {
				break;
			} // end of if block

			//beginning of if block that checks for column and row validity
			if (column > 3 || column < 1 || row > 3 || row < 1) {
				puts("\n[That is not a valid row/column number...try again]\n");
				continue; //continue the game loop
			} //end of the if block

			//beginning of if block that checks for number input validity
			if (numInput > 9 || numInput < 1) {
				puts("\n[That is not a valid input...try again]\n");
				continue; //continue the game loop
			} //end of if block

			/*
			 * Show a success or fail message and end the inner loop. Complete
			 * this part:
			 */
			//beginning of if else block that checks for success or failure of the user input
			if (numInput == 8) { //used 8 as an arbitrary value to break out of the game loop
				puts(
						"\n[You got the answer for that specific spot on the matrix!]\n");
			} else {
				puts("\n[Wrong answer...]\n");
				continue;
			} // end of if else block
		} // end of game while loop

		isSuccess = 0; //reset the flag variable in case the player wants to play again

		/*
		 * Ask the player if s/he wants to play again. If yes, control should
		 * go to the beginning of the outer loop. Otherwise, loop will end and
		 * program should exit after showing a Goodbye message to the player.
		 * Complete this part:
		 */
		int playAgain; //this holds whether or not the player wants to play again

		// ask the player
		printf(
				"\nDo you want to play again player?\n[1 == yes/ 0[or any key] == no]\n");

		//get the response from the player
		scanf("%d", &playAgain);

		// if else block to decide whether or not to start a new game
		if (playAgain == 1) {
			puts("\n-----------N E W   G A M E-----------\n");
			continue; //continue the main loop
		} else {
			puts("\nThank you for playing!\n"); // ending message
			break; //break out of the main loop
		} //end of if else block

	} // end of main while loop

} // end of the main function
