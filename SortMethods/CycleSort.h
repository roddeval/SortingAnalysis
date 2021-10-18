#pragma once
#include "BubbleSort.h"

#ifdef SORTMETHODS_EXPORTS
#define SORTMETHODS_API __declspec(dllexport)
#else
#define SORTMETHODS_API __declspec(dllimport)
#endif

class CycleSort
{
public:
	SORTMETHODS_API void cycleSort(int arr[], int n);
	SORTMETHODS_API void printArray(int arr[], int size);
};

