/*
 * app.c
 *
 *  Created on: Nov. 18, 2019
 *      Author: emsee
 */

#include<stdio.h>
void lab_9(int a);

int x = 2;
int main() {
	printf("the value of x is:%d\n", x);
	lab_9(x);
	printf("the value of x is:%d", x);
}
void lab_9(int a) {
	x = x * ++a;
}
