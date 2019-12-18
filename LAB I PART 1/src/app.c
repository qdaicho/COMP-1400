/*
 * app.c
 *
 * A program on variable scope in C
 *  Created on: Nov. 18, 2019
 *      Author: emsee
 */

#include<stdio.h>

int main(void) {

	int x = 1;
	int y = 2;
	int z = 3;
	printf(" x = %d, y = %d, z = %d \n", x, y, z);
	{
		int x = 10;
		double y = 15;
		int z = 4;
		printf(" x = %d, y = %f, z = %d \n", x, y, z);
		{
			int x = 10;
			double y = 15;
			int z = 50;
			printf(" x = %d, y = %f, z = %d \n", x, y, z);
		}
	}
}
