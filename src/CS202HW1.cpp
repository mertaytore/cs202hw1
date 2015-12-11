/*
 * Mert Aytöre
 * 21400923
 * CS202-01
 * HW1
 */
#include <iostream>
#include "sorting.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

int main() {
	clock_t executionTime;
	const int arraySize = 40000;
	int arrS[arraySize];
	int arrM[arraySize];
	int arrQ[arraySize];

	//move and comp count initializations
	int compCount = 0;
	int moveCount = 0;
	/*for (int i = 0; i < arraySize; i++){
		arrS[i] = rand();
		arrM[i] = arrS[i];
		arrQ[i] = arrM[i];
	}*/
	/*for (int i = 0; i < arraySize; i++){ //ascending
		arrS[i] = i;
		arrM[i] = i;
		arrQ[i] = i;
	}*/
	for (int i = arraySize-1; i >= 0; i--){ //descending
		arrS[i] = i;
		arrM[i] = i;
		arrQ[i] = i;
	}

	//selectionsort
	cout << "Element count = "<< arraySize << endl;
	cout << "Selection Sort"<< endl;

	executionTime = clock();

	selectionSort(arrS, arraySize, compCount, moveCount);

	executionTime = clock() - executionTime;

	cout << "Time in milliseconds = " << (double)executionTime*1000/CLOCKS_PER_SEC << endl;
	cout << "Number of movements = " << moveCount << endl ;
	cout << "Number of comparisons = " << compCount << endl;

	cout << endl;

	//mergesort
	//resetting needed variables
	compCount = 0;
	moveCount = 0;
	executionTime = clock();

	cout << "Merge Sort" << endl;

	mergeSort(arrM, arraySize, compCount, moveCount);

	executionTime = clock() - executionTime;
	cout << "Time in milliseconds = " << (double)executionTime*1000/CLOCKS_PER_SEC << endl;
	cout << "Number of movements = " << moveCount << endl ;
	cout << "Number of comparisons = " << compCount << endl;

	cout << endl;

	//quicksort
	//resetting needed variables
	compCount = 0;
	moveCount = 0;
	executionTime = clock();

	cout << "Quick Sort" << endl;

	quickSort(arrQ, arraySize, compCount, moveCount);

	executionTime = clock() - executionTime;
	cout << "Time in milliseconds = " << (double)executionTime*1000/CLOCKS_PER_SEC << endl;
	cout << "Number of movements = " << moveCount << endl ;
	cout << "Number of comparisons = " << compCount << endl;

	cout << endl;

	return 0;
}
