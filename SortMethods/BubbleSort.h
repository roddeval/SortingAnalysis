#pragma once

#ifdef SORTMETHODS_EXPORTS
#define SORTMETHODS_API __declspec(dllexport)
#else
#define SORTMETHODS_API __declspec(dllimport)
#endif

#include <stdio.h> 
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm> 
#include <vector> 

using namespace std;

class BubbleSort
{
public:
	SORTMETHODS_API void bubbleSort(int arr[], int n);
	SORTMETHODS_API void printArray(int arr[], int size);

};

