/*
 * Mert Aytöre
 * 21400923
 * CS202-01
 * HW1
 */
#include <iostream>
#include <string>
using namespace std;

#ifndef SORTING_H_
#define SORTING_H_

//given methods
void selectionSort( int *arr, int size, int &compCount, int &moveCount);
void mergeSort( int *arr, int size, int &compCount, int &moveCount);
void quickSort( int *arr, int size, int &compCount, int &moveCount);

//extra methods
void actualMergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void actualQuickSort(int *arr, int first, int last, int &compCount, int &moveCount);

void merge( int *arr, int first, int mid, int last, int &compCount, int &moveCount);
void partition( int *arr, int first, int last, int &pIndex, int &compCount, int &moveCount);

#endif
/* SORTING_H_ */
