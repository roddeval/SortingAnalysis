#pragma once
#include "BubbleSort.h"

#ifdef SORTMETHODS_EXPORTS
#define SORTMETHODS_API __declspec(dllexport)
#else
#define SORTMETHODS_API __declspec(dllimport)
#endif

class HeapSort
{
public:
	SORTMETHODS_API void heapify(int arr[], int n, int i);
	SORTMETHODS_API void heapSort(int arr[], int n);
	SORTMETHODS_API void printArray(int arr[], int size);

};

