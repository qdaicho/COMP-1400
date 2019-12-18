/*
 * app.c
 *
 *  Created on: Nov. 18, 2019
 *      Author: emsee
 */

//#include <stdio.h>
//int main(void) {
//	{
//		int x = 10;
//	}
//	{
//		printf("%d", x);
//	}
//}


#include <stdio.h>
void f();
int i = 20;
int main() {
	int i = 5;
	printf("%d ", i);
	f();
	printf("%d ", i);
	f();
	return 0;
}
void f() {
	static int j;
	if (i > 20) {
		int i = 3;
		printf("%d ", i);
	}
	printf("%d ", i + j);
	i++;
	j++;
}
