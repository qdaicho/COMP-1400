/*
 * main.c
 *
 *  Created on: Nov. 5, 2019
 *      Author: emsee
 */

#include <stdio.h>

int binarySearch(int array[], int value, int low, int high) {

	if (high < low) {
		return -1;
	}

	int mid = (low + high) / 2;

	if (array[mid] > value) {
		return binarySearch(array, value, low, mid - 1);
	} else if (array[mid] < value) {
		return binarySearch(array, value, low, mid + 1);
	} else {
		return mid;
	}
}

int linearSearch(int array[], int value, int length) {
	for (int i = 0; i < length - 1; i++) {
		if (array[i] == value)
			return i;
	}
	return -1;
}

void bubbleSort(int array[], int length) {
	int isSwapped = 0;
	int temp;
	for (int j = 0; j < length - 1; j++) {
		isSwapped = 0;
		for (int i = 0; i < length - 1; ++i) {
			if (array[i] > array[i + 1]) {
				temp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = temp;
				isSwapped = 1;
			}
		}

		if (!isSwapped)
			break;
	}
}

//Get the first value keep comparing with values at the right until it is greater
// every value that is picked up should be

void insertionSort(int array[], int length) {
	int j;
	int temp;

	for (int i = 1; i <= length - 1; i++) {
		j = i;

		while (j > 0 && array[j - 1] > array[j]) {
			temp = array[j + 1];
			array[j + 1] = array[j];
			array[j] = temp;
			j = j-1;
		}

	}
}

int main(void) {

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int array2[] = { 4, 5, 9, 10, 11, 7, 2, 0 };

	int length1 = (int) (sizeof(array) / sizeof(array[0]));
	int length2 = (int) (sizeof(array2) / sizeof(array2[0]));
//
//	int answer = binarySearch(array, 7, 0, 98);
//	printf("\n Binary search answer: %d\n", answer);
//
//	answer = linearSearch(array, 7, length1);
//	printf("\n Linear search answer: %d\n", answer);

//	bubbleSort(array2, length2);
//	puts("\n Iterative bubble sort:\n");
//	for (int var = 0; var < length2; var++) {
//		printf("%2d ", array2[var]);
//	}

	insertionSort(array2, length2);
	puts("\n\n Iterative insertion sort:\n");
	for (int var = 0; var < length2; var++) {
		printf("%2d ", array2[var]);
	}

}
