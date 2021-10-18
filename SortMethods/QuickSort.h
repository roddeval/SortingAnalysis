#pragma once
#include "BubbleSort.h"

#ifdef SORTMETHODS_EXPORTS
#define SORTMETHODS_API __declspec(dllexport)
#else
#define SORTMETHODS_API __declspec(dllimport)
#endif

class QuickSort
{
public:
	SORTMETHODS_API void swap1(int* a, int* b);
	SORTMETHODS_API int partition(int arr[], int low, int high);
	SORTMETHODS_API void quickSort(int arr[], int low, int high);
	SORTMETHODS_API void printArray(int arr[], int size);

};

