#pragma once
#include "BubbleSort.h"

// SORTMETHODS_EXPORTS
#ifdef SORTMETHODS_EXPORTS
#define SORTMETHODS_API __declspec(dllexport)
#else
#define SORTMETHODS_API __declspec(dllimport)
#endif

class SelectionSort
{
public:
	SORTMETHODS_API void swap(int* xp, int* yp);
	SORTMETHODS_API void selectionSort(int arr[], int n);
	SORTMETHODS_API void printArray(int arr[], int size);

};

