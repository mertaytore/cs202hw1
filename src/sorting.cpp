/*
 * sorting.cpp
 * Mert Aytöre
 * 21400923
 * CS202-01
 * HW1
 */
#include <iostream>
#include "sorting.h"
using namespace std;

//SELECTION SORT
void selectionSort(int *arr, int size, int &compCount, int &moveCount){
	int largest;
	int num = 0;
	int temp = 0;
	for(int i = size-1; i >= 1; i--){
		compCount++;
		largest = 0;
		num = 0;
		for(int j = 1; j < i+1; j++){
			compCount++;
			if( arr[j] > arr[num]){
				compCount++;
				num = j;
			}
			largest = num;
		}
		temp = arr[largest];
		arr[largest] = arr[i];
		arr[i] = temp;
		moveCount++;
	}
}

//MERGESORT FUNCTIONS
void mergeSort( int *arr, int size, int &compCount, int &moveCount){
	actualMergeSort(arr, 0, size-1, compCount, moveCount);
}

void actualMergeSort( int *arr, int first, int last, int &compCount, int &moveCount){
	if (first < last){
		int mid = (first + last) / 2;
		actualMergeSort(arr, first, mid, compCount, moveCount);
		actualMergeSort(arr, mid+1, last, compCount, moveCount);
		merge(arr, first, mid, last, compCount, moveCount);
	}
	compCount++;
}

void merge( int *arr, int first, int mid, int last, int &compCount, int &moveCount){
	int* temp= new int[last-first+1];
	int tempFirst = first, tempLast1 = mid, tempFirst2 = mid+1, tempLast2 = last;
	moveCount+=4;

	//comparisons and sortings
	int index = 0;
	while((tempFirst <= tempLast1)&&(tempFirst2 <= tempLast2)){
		if(arr[tempFirst] < arr[tempFirst2]) {
			temp[index] = arr[tempFirst];
			tempFirst++;
		}else{
			temp[index] = arr[tempFirst2];
			tempFirst2++;
		}
		moveCount+=2;
		compCount++;
		index++;
	}

	//when it's done, first array it placed
	while(tempFirst<=tempLast1){
		temp[index] = arr[tempFirst];
		moveCount+=2;
		index++;
		tempFirst++;
	}

	//if not, same procedure for second array
	while(tempFirst2<=tempLast2){
		temp[index] = arr[tempFirst2];
		moveCount+=2;
		tempFirst2++;
		index++;
	}
	for(int i = 0; i <= last-first; i++){
		arr[first+i] = temp[i]; //back to original array
		moveCount++;
	}
	delete[] temp;
}

//QUICKSORT FUNCTIONS
void quickSort( int *arr, int size, int &compCount, int &moveCount){
	actualQuickSort(arr, 0, size-1, compCount, moveCount);
}

void actualQuickSort(int *arr, int first, int last, int &compCount, int &moveCount){
	int pIndex;
	if(first < last){
		partition(arr, first, last, pIndex, compCount, moveCount);
		actualQuickSort(arr,first, pIndex-1, compCount, moveCount);
		actualQuickSort(arr, pIndex+1, last, compCount, moveCount);
	}
	compCount++;
}

void partition( int *arr, int first, int last, int &pIndex, int &compCount, int &moveCount){
	pIndex = last;
	moveCount++;

	for ( int index = last; index > first; index--)
	{
		if ( arr[index] > arr[first])
		{
			std::swap(arr[index], arr[pIndex]);
			moveCount+=3;
			pIndex--;
			moveCount++;
		}

		compCount++;
	}
	std::swap(arr[pIndex], arr[last]);
	moveCount+=3;
}
