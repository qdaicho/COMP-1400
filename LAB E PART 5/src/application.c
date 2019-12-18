/*
 * application.c
 *
 *  Created on: Oct. 21, 2019
 *      Author: emsee
 */

#include <stdio.h>

int main(void) {
	int input;
	puts("Type down any integer to represent a weekday");
	scanf("%d", &input);

	switch (input) {
	case 1:
		puts("\nYou mean Monday?");
		break;
	case 2:
		puts("\nYou mean Tuesday?");
		break;
	case 3:
		puts("\nYou mean Wednesday?");
		break;
	case 4:
		puts("\nYou mean Thursday?");
		break;
	case 5:
		puts("\nYou mean Friday?");
		break;
	case 6:
		puts("\nYou mean Saturday?");
		break;
	case 7:
		puts("\nYou mean Sunday?");
		break;
	}

	return 0;
}
