/*
 * app.c
 *
 *  Created on: Nov. 11, 2019
 *      Author: emsee
 */

#include <stdio.h>

double circleArea(double radius) {
	return 3.141596 * radius * radius;
}

int main() {

	puts("Please type down any radius for a circle:\n");
	double radius;
	scanf("%lf", &radius);
	double area = circleArea(radius);
	printf("\nThe area of the circle is %f.\n", area);

	return 0;
}
