/*
 * FILE: NineGaps.c
 *
 * Created on: Nov. 19, 2019
 *
 * Author: Md Mahir Daian Alam Chowdhury
 *
 * Student ID: 110006473
 *
 * Description:
 *  	This is a console based version of the Nine Gaps Game
 */
#include<stdio.h>//import the standard input output library
#include <stdlib.h>//import the standard library
#include <time.h>//import the time library
#include <string.h>//import the string library

//Two utility functions for this game. Go to the bottom of the file for its documentation
char returnOperator();
int calculate_result(int x, char operator1, int y, char operator2, int z);

int main() {
	int main_board[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // It defines the main board to store all the values from 1-9
	int missing_array[9]; // This line generates an array of size 9 to keep track of missing values
	int old_missing_values[9]; // this is the array that holds the old missing values in case the user wants to use them again
	int game_board[9]; // It defines an array to form the actual game board with random numbers and hidden values
	int temp_board[9]; // It defines an array which is a copy of the game_board and will be displayed to the user and will be updated in each iteration
	int row_results[3]; // this is an array that stores the results of calculation of each row
	int column_results[3]; // this is an array that stores the results of calculation of each column
	char operators_array[12]; // this is an array that stores random operations
	int i, j; // these variables will be used for loop indexes
	int rand_num, temp1; // rand_num will be used to store the result of random number generations, temp1 will be used as a temporary variable
	int level; // this variable stores the level of difficulty
	int check_game; // this is a flag variable to determine if the user solves the game correctly >>>>>>>>>>>>>>>>>>>>>>>>>>>>
	int play_again; // this is a flag variable to determine if the user wants to play again or not
	int missing_count; // this is a variable that keep track of the number of missing values in the game board.s

	srand(time(NULL)); // It generates a seed, using current time, for the random generator

	do {

		// reset all elements of both of the following arrays to zero
		for (i = 0; i < 9; ++i) {
			old_missing_values[i] = 0;
			missing_array[i] = 0;
		}

		check_game = 1; //initialize it to true
		level = 0; //intitialize it to 0

		printf("Welcome to Nine-Gaps game!...\n");
		printf("*****************************\n");
		printf("      *****************      \n");
		printf("            *****            \n");
		printf("              *              \n");

		// get the level of difficulty from the user
		do {
			puts(
					"Choose the level of difficulty (1-Beginner, 2-Intermediate, 3-Advanced, 4-Expert):");
			scanf("%d", &level);
			if ((level < 1) || (level > 4))
				puts("The entered value is not valid");
			else {
				switch (level) {
				case 1:
					puts("You have chosen the Beginner level");
					break;
				case 2:
					puts("You have chosen the Intermediate level");
					break;
				case 3:
					puts("You have chosen the Advanced level");
					break;
				case 4:
					puts("You have chosen the Expert level");
					break;
				}
				break;
			}
		} while (1);
		//////////////////////////////////////////////////

		// 1- generate a random main board by shuffling the main_board      (COMPLETE THIS PART)

		// Start from the last element and swap one by one. No
		// need to run for the first element that's why x > 0
		for (int x = 8; x > 0; x--) {
			// Pick a random index from 0 to x
			rand_num = rand() % (x + 1);

			// Swap arr[x] with the element at random index

			temp1 = main_board[x];
			main_board[x] = main_board[rand_num];
			main_board[rand_num] = temp1;
		}
		/////////////////////////////////////////////////

		// 2- generate random operators ( + , - , x )      (COMPLETE THIS PART)
		// load up the operator array
		for (int x = 0; x < 12; x++) {
			operators_array[x] = returnOperator();
		}

		/////////////////////////////////////////////////

		// 3- Calculate the results in columns and rows      (COMPLETE THIS PART)

		row_results[0] = calculate_result(main_board[0], operators_array[0],
				main_board[1], operators_array[1], main_board[2]);

		row_results[1] = calculate_result(main_board[3], operators_array[2],
				main_board[4], operators_array[3], main_board[5]);

		row_results[2] = calculate_result(main_board[6], operators_array[4],
				main_board[7], operators_array[5], main_board[8]);

		column_results[0] = calculate_result(main_board[0], operators_array[6],
				main_board[3], operators_array[9], main_board[6]);

		column_results[1] = calculate_result(main_board[1], operators_array[7],
				main_board[4], operators_array[10], main_board[7]);

		column_results[2] = calculate_result(main_board[2], operators_array[8],
				main_board[5], operators_array[11], main_board[8]);

		//THIS IS FOR GETTING ALL VALUES WITHIN THE GAME MATRIX FOR DEBUGGING ONLY!!
//		printf("\n___________________________________________________\n");
//		for (int i = 0; i < 9; i++) {
//			printf("%d      ", main_board[i]);
//		}
//		printf("\n___________________________________________________\n");
		////////////////////////////////////////////////////////

		// 4- initializing missing array to 0      (COMPLETE THIS PART)
		for (int i = 0; i < 9; i++) {
			missing_array[i] = 0;
		}
		////////////////////////////////////////////////////////

		// 5- copy the main_board into game_board      (COMPLETE THIS PART)

		for (int i = 0; i < 9; i++) {
			game_board[i] = main_board[i];
		}
		/////////////////////////////////////////////////////////

		// Based on the selected level, 3 or 5 or 7 board values will be hidden.

		i = 0; // initializing i to 0

		while (i < level * 2 + 1) {
			int r = rand() % 3;
			int c = rand() % 3;
			if (game_board[3 * r + c] != '?') {
				missing_array[game_board[3 * r + c] - 1] =
						game_board[3 * r + c]; // the hidden values will be added to the set of missing values
				game_board[3 * r + c] = '?';
				i++;
			} // end of if
		} // end of while
		  ////////////////////////////////////////////////////////

		// 6- Copy the game board into a temporary board      (COMPLETE THIS PART)
		for (int i = 0; i < 9; i++) {
			temp_board[i] = game_board[i];
		}
		///////////////////////////////////////////////////////

		// the inner loop to get values from the user
		do {

			// Display the game board after each update

			printf("Game Board:\n");
			printf("---------------------------------------------------\n");
			for (i = 0; i < 3; i++) {
				if (i > 0) {                   // show the column operators
					for (j = 0; j < 3; j++) {
						printf(" %c\t\t", operators_array[3 * (i + 1) + j]);
					}
					printf("\n");
				}

				for (j = 0; j < 3; j++) {          // show the rows
					if (game_board[(i * 3) + j] != '?')
						printf(" %d\t ", temp_board[(i * 3) + j]);
					else if (game_board[(i * 3) + j]
							!= temp_board[(i * 3) + j]) {
						printf(" %d?\t ", temp_board[(i * 3) + j]);
					} else
						printf(" ?\t ");

					if (j < 2)
						printf(" %c\t", operators_array[(i * 2) + j]);
					else
						printf("= %d", row_results[i]); // show the rows results
				}
				printf("\n");
				if (i == 2)
					printf(" =\t\t =\t\t =\n");
			}
			for (i = 0; i < 3; i++)               // show the columnar results
				printf(" %d\t\t", column_results[i]);
			printf("\n---------------------------------------------------\n");

			////////////////////////////////////////////////////////

			// 7- Display the missing values and update the missing_count variable      (COMPLETE THIS PART)
			puts("Missing Values: ");
			missing_count = 0;               //reset the missing values counter

			// loop through the missing values array and print every non zero value
			for (int i = 0; (i < 9); i++) {
				if (missing_array[i] != 0) {
					printf(" %d ", missing_array[i]);
					missing_count++; //increment the counter everytime you hit a missing value
				}
			}

			puts("\n---------------------------------------------------\n");
			/////////////////////////////////////////////////////////

			// 8- break if the missing values are empty      (COMPLETE THIS PART)
			if (missing_count == 0) {
				break;
			}
			/////////////////////////////////////////////////////

			// Get user's guess (location and value) and check inputs' validity

			printf(
					"Enter a row number (1-3), column(1-3), value(One of the missing values):\n");
			int r, c, v;
			scanf("%d %d %d", &r, &c, &v);
			if (r == 0 || c == 0 || v == 0)
				break;

			if (r < 1 || r > 3 || c < 1 || c > 3) {
				puts("Invalid row and/or column numbers. Try again.");
				continue;
			}

			if (v < 1 || v > 9) {
				puts("Invalid cell value. Try again.");
				continue;
			}

			if (missing_array[v - 1] < 1) {
				puts("This value is already there. Try again.");
				continue;
			}

			//////////////////////////////////////////////////////
			// 9- if the selected cell is changeable, add the value into the cell and remove it from the missing values, in other case show an error and repeat the inner loop.
			//       (COMPLETE THIS PART)

			// THE FOLLWING WILL BE REFERENCED AS SO:
			// missing_array = bank
			// old_missing_values = used values bank

			//If the selected element is a blank...
			if (game_board[3 * (r - 1) + (c - 1)] == '?') {

				// insert the player's value into the following boards
				game_board[3 * (r - 1) + (c - 1)] = v;
				temp_board[3 * (r - 1) + (c - 1)] = v;

				// loop through the bank and remove the inputed value
				// and put it into the used values bank in case it is switched later
				// by the player for another missing value
				for (i = 0; i < 9; i++) {
					if (missing_array[i] == v) {
						missing_array[i] = 0;
						old_missing_values[i] = v;
					}
				}
			} else {//if the selected cell is not a question mark but rather a number,

				// check if user value is a previously used missing value. If so, then put
				// it back into the bank and remove it from the used values bank
				for (i = 0; i < 9; i++) {
					if (old_missing_values[i]
							== game_board[3 * (r - 1) + (c - 1)]) {
						missing_array[i] = old_missing_values[i];
						old_missing_values[i] = 0;
					}
				}

				// insert the player's value into the following boards
				game_board[3 * (r - 1) + (c - 1)] = v;
				temp_board[3 * (r - 1) + (c - 1)] = v;

				// update the missing value array and the old missing value array
				for (i = 0; i < 9; i++) {
					if (missing_array[i] == v) {
						missing_array[i] = 0;
						old_missing_values[i] = v;
					}
				}
			}				// end if else block

			//THE FOLLOWING BLOCK OF CODE IS FOR DEBUGGING PURPOSED ONLY
			//PLEASE UNCOMMENT IF YOU WANT TO SEE THE INNER WORKINGS OF THE
			//LOGIC ABOVE IN BETTER DETAIL
//			puts("\n");
//			for (i = 0; i < 9; i++) {
//				printf("%d ", old_missing_values[i]);
//			}
//
//			puts("\n");
//			for (i = 0; i < 9; i++) {
//				printf("%d ", missing_array[i]);
//			}
//			puts("\n");

			//////////////////////////////////////////////////////

		} while (1); // end of the inner loop

		//////////////////////////////////////////////////////////

		// 10- check the results by comparing gameboard's and mainboard's equality
		for (int i = 0; i < 9; i++) {
			if (game_board[i] != main_board[i]) {
				check_game = 0;
			}
		}
		//////////////////////////////////////////////////////

		if (check_game)             // display Wining/Losing Message
			printf("**** Congratulations!!!****\n ***You Won!!!!*** \n");
		else
			printf(":( Sorry it is not correct :( \n");

		printf("#######################################\n");
		printf("   Do you want to play again? (Yes:1, No:0)\n"); // ask the user to play again
		printf("#######################################\n");
		scanf("%d", &play_again);

		if (!play_again) {
			printf("Bye!");
			break;
		}
	} while (1); // end of the outer loop
}

/**
 * return_operator() returns a random operator [+,*, -, /] as a character
 * parameters: none
 * returns: char operator ['+', '*', '-', '/']
 */
char returnOperator() {
	//create an array of operator chars
	char operators[4] = { '+', '*', '-', '/' };
	int i = rand() % 3;
	//return a random char
	return operators[i];
}

/*
 * calculate_result() computes result of rows or columns
 * parameters: 2 chars for operations, 3 ints
 * returns: computed int result
 */
int calculate_result(int x, char operator1, int y, char operator2, int z) {

	//if the second operator is a multiplication, then do that first to follow BEDMAS
	if (operator2 == '*') {
		int temp = y * z;
		return (operator1 == '+' ? temp + x :
				operator1 == '-' ? x - z : temp * x);
	}
	//otherwise, just follow the normal procedure for calculation as BEDMAS isn't affected
	int temp = (operator1 == '+' ? x + y : operator1 == '-' ? x - y : x * y);
	return (operator2 == '+' ? temp + z : operator2 == '-' ? temp - z : temp * z);
}
