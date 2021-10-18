// SortingAnalysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <fstream>
#include "BubbleSort.h"
#include "InseartionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "CycleSort.h"
#include "SelectionSort.h"
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace chrono;

class StartStop
{
	private:
		SYSTEMTIME startTime;
		SYSTEMTIME stopTime;
		SYSTEMTIME elapsedST;
		std::stringstream ssStart;
		std::stringstream ssStop;
		std::stringstream ssElapsed;
	public:

		StartStop()
		{
			SetStart();
		}

		void SetStart()
		{
			GetSystemTime(&startTime);
		}

		void SetStop()
		{
			GetSystemTime(&stopTime);
		}

		string Start()
		{
			string timeString;

			ssStart << startTime.wMonth << "/" << startTime.wDay << "/" << startTime.wYear << " " << startTime.wHour << ":" << startTime.wMinute << ":" << startTime.wSecond << "." << startTime.wMilliseconds;

			timeString = ssStart.str();

			return timeString;
		}

		string Stop()
		{
			string timeString;

			ssStop << stopTime.wMonth << "/" << stopTime.wDay << "/" << stopTime.wYear << " " << stopTime.wHour << ":" << stopTime.wMinute << ":" << stopTime.wSecond << "." << stopTime.wMilliseconds;

			timeString = ssStop.str();

			return timeString;
		}

		string Duration()
		{
			string timeString;
			FILETIME ft;
			FILETIME ftStop;
			FILETIME elapsed;
			ULARGE_INTEGER v_ui;
			__int64 v_right, v_left, v_res;

			SystemTimeToFileTime(&startTime, &ft);
			SystemTimeToFileTime(&stopTime, &ftStop);

			v_ui.LowPart = ftStop.dwLowDateTime;
			v_ui.HighPart = ftStop.dwHighDateTime;
			v_right = v_ui.QuadPart;

			v_ui.LowPart = ft.dwLowDateTime;
			v_ui.HighPart = ft.dwHighDateTime;
			v_left = v_ui.QuadPart;

			v_res = v_right - v_left;

			v_ui.QuadPart = v_res;
			elapsed.dwLowDateTime = v_ui.LowPart;
			elapsed.dwHighDateTime = v_ui.HighPart;
			FileTimeToSystemTime(&elapsed, &elapsedST);

			ssElapsed << elapsedST.wHour << ":" << elapsedST.wMinute << ":" << elapsedST.wSecond << "." << elapsedST.wMilliseconds << "," << elapsedST.wSecond << "." << elapsedST.wMilliseconds;

			timeString = ssElapsed.str();
			return timeString;
		}
};

class Process
{
	private:
		int* arrayToSort;

		void WriteToHeader(int limit)
		{
			int whereAt = 0;
			string messageText = "";
			fstream file;
			fstream file2;
			string line = "";
			bool ok = true;
			string pathFile = "";
			int value = 0;
			std::stringstream ssOut;
			int length = 0;
			switch (limit)
			{
			case 100:
				pathFile = "C:\\temp\\Sort_Analysis_100_numbers.csv";
				break;
			case 1000:
				pathFile = "C:\\temp\\Sort_Analysis_1000_numbers.csv";
				break;
			case 10000:
				pathFile = "C:\\temp\\Sort_Analysis_10000_numbers.csv";
				break;
			case 100000:
				pathFile = "C:\\temp\\Sort_Analysis_100000_numbers.csv";
				break;
			default:
				ok = false;
				break;
			}
			if (ok == true)
			{

				file.open(pathFile, ios::out);
				ssOut << "Sort Method,Limit,Start,Stop,Duration,FormattedDuration" << endl;
				messageText = ssOut.str();
				length = (int)strlen(messageText.c_str());
				file.write(messageText.c_str(), length);
				file.flush();
				file.close();

				if (limit == 100)
				{
					pathFile = "C:\\temp\\Sort_Analysis_all.csv";
					file2.open(pathFile, ios::out);
					file2.write(messageText.c_str(), length);
					file2.flush();
					file2.close();
				}


			}
		}

		void WriteToOutputFile(int limit, string sortMethod, StartStop* startStop)
		{
			int whereAt = 0;
			string messageText = "";
			fstream file;
			fstream file2;
			string line = "";
			bool ok = true;
			string pathFile = "";
			int value = 0;
			std::stringstream ssOut;
			int length = 0;

			switch (limit)
			{
			case 100:
				pathFile = "C:\\temp\\Sort_Analysis_100_numbers.csv";
				break;
			case 1000:
				pathFile = "C:\\temp\\Sort_Analysis_1000_numbers.csv";
				break;
			case 10000:
				pathFile = "C:\\temp\\Sort_Analysis_10000_numbers.csv";
				break;
			case 100000:
				pathFile = "C:\\temp\\Sort_Analysis_100000_numbers.csv";
				break;
			default:
				ok = false;
				break;
			}
			if (ok == true)
			{
				file.open(pathFile, ios::app);
				ssOut << sortMethod << "," << limit << "," << startStop->Start() << "," << startStop->Stop() << "," << startStop->Duration() << endl;
				messageText = ssOut.str();
				length = (int)strlen(messageText.c_str());
				file.write(messageText.c_str(), length);
				file.flush();
				file.close();

				pathFile = "C:\\temp\\Sort_Analysis_all.csv";
				file2.open(pathFile, ios::app);
				file2.write(messageText.c_str(), length);
				file2.flush();
				file2.close();

			}
		}

		void Read(int limit)
		{
			int whereAt = 0;
			fstream file;
			string line = "";
			bool ok = true;
			string pathFile = "";
			int value = 0;
			std::string::size_type sz;

			switch (limit)
			{
			case 100:
				pathFile = "C:\\temp\\100_numbers.txt";
				break;
			case 1000:
				pathFile = "C:\\temp\\1000_numbers.txt";
				break;
			case 10000:
				pathFile = "C:\\temp\\10000_numbers.txt";
				break;
			case 100000:
				pathFile = "C:\\temp\\100000_numbers.txt";
				break;
			default:
				ok = false;
				break;
			}
			if (ok == true)
			{
				file.open(pathFile, ios::in);

				while (getline(file, line))
				{
					value = std::stoi(line, &sz);
					if (whereAt < limit)
					{
						arrayToSort[whereAt] = value;
						whereAt++;
					}
				}

				file.close();
			}

		}

		void LoadFile(int limit)
		{
			arrayToSort = new int[limit];
			for (int i = 0; i < limit; i++)
			{
				arrayToSort[i] = 0;
			}

			Read(limit);

		}

		void Process100()
		{
			string messageText = "";
			string sortMethod = "";
			std::stringstream ss1;
			std::stringstream ss2;
			std::stringstream ss3;
			std::stringstream ss4;
			std::stringstream ss5;
			std::stringstream ss6;

			std::stringstream ss1b;
			std::stringstream ss2b;
			std::stringstream ss3b;
			std::stringstream ss4b;
			std::stringstream ss5b;
			std::stringstream ss6b;

			int limit = 100;

			StartStop* bubbleSortStartStop = NULL;
			StartStop* selectionSortStartStop = NULL;
			StartStop* cycleSortStartStop = NULL;
			StartStop* heapSortStartStop = NULL;
			StartStop* insertionSortStartStop = NULL;
			StartStop* quickStartStop = NULL;

			BubbleSort b;
			SelectionSort s;
			CycleSort c;
			HeapSort h;
			InseartionSort i;
			QuickSort q;

			LoadFile(limit);
			WriteToHeader(limit);
			sortMethod = "Bubble Sort";
			ss1 << sortMethod << " start";
			messageText = ss1.str();
			cout << messageText << " " << limit << endl;
			bubbleSortStartStop = new StartStop();
			b.bubbleSort(arrayToSort, limit);
			b.printArray(arrayToSort, limit);
			bubbleSortStartStop->SetStop();
			ss1b << sortMethod << " stopped";
			messageText = ss1b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, bubbleSortStartStop);

			sortMethod = "Selection Sort";
			ss2 << sortMethod << " start";
			messageText = ss2.str();
			cout << messageText << " " << limit << endl;
			selectionSortStartStop = new StartStop();
			s.selectionSort(arrayToSort, limit);
			s.printArray(arrayToSort, limit);
			selectionSortStartStop->SetStop();
			ss2b << sortMethod << " stopped";
			messageText = ss2b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, selectionSortStartStop);

			sortMethod = "Cycle Sort";
			ss3 << sortMethod << " start";
			messageText = ss3.str();
			cout << messageText << " " << limit << endl;
			cycleSortStartStop = new StartStop();
			c.cycleSort(arrayToSort, limit);
			c.printArray(arrayToSort, limit);
			cycleSortStartStop->SetStop();
			ss3b << sortMethod << " stopped";
			messageText = ss3b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, cycleSortStartStop);

			sortMethod = "Heap Sort";
			ss4 << sortMethod << " start";
			messageText = ss4.str();
			cout << messageText << " " << limit << endl;
			heapSortStartStop = new StartStop();
			h.heapSort(arrayToSort, limit);
			h.printArray(arrayToSort, limit);
			heapSortStartStop->SetStop();
			ss4b << sortMethod << " stopped";
			messageText = ss4b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, heapSortStartStop);

			sortMethod = "Insertion Sort";
			ss5 << sortMethod << " start";
			messageText = ss5.str();
			cout << messageText << " " << limit << endl;
			insertionSortStartStop = new StartStop();
			i.insertionSort(arrayToSort, limit);
			i.printArray(arrayToSort, limit);
			insertionSortStartStop->SetStop();
			ss5b << sortMethod << " stopped";
			messageText = ss5b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, insertionSortStartStop);

			sortMethod = "Quick Sort";
			ss6 << sortMethod << " start";
			messageText = ss6.str();
			cout << messageText << " " << limit << endl;
			quickStartStop = new StartStop();
			q.quickSort(arrayToSort, arrayToSort[0], arrayToSort[limit]);
			q.printArray(arrayToSort, limit);
			quickStartStop->SetStop();
			ss6b << sortMethod << " stopped";
			messageText = ss6b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, quickStartStop);

		}

		void Process1000()
		{
			string messageText = "";
			string sortMethod = "";
			int limit = 1000;
			StartStop* bubbleSortStartStop = NULL;
			StartStop* selectionSortStartStop = NULL;
			StartStop* cycleSortStartStop = NULL;
			StartStop* heapSortStartStop = NULL;
			StartStop* insertionSortStartStop = NULL;
			StartStop* quickStartStop = NULL;
			std::stringstream ss1;
			std::stringstream ss2;
			std::stringstream ss3;
			std::stringstream ss4;
			std::stringstream ss5;
			std::stringstream ss6;

			std::stringstream ss1b;
			std::stringstream ss2b;
			std::stringstream ss3b;
			std::stringstream ss4b;
			std::stringstream ss5b;
			std::stringstream ss6b;

			BubbleSort b;
			SelectionSort s;
			CycleSort c;
			HeapSort h;
			InseartionSort i;
			QuickSort q;

			LoadFile(limit);
			WriteToHeader(limit);
			sortMethod = "Bubble Sort";
			ss1 << sortMethod << " start";
			messageText = ss1.str();
			cout << messageText << " " << limit << endl;
			bubbleSortStartStop = new StartStop();
			b.bubbleSort(arrayToSort, limit);
			b.printArray(arrayToSort, limit);
			bubbleSortStartStop->SetStop();
			ss1b << sortMethod << " stopped";
			messageText = ss1b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, bubbleSortStartStop);

			sortMethod = "Selection Sort";
			ss2 << sortMethod << " start";
			messageText = ss2.str();
			cout << messageText << " " << limit << endl;
			selectionSortStartStop = new StartStop();
			s.selectionSort(arrayToSort, limit);
			s.printArray(arrayToSort, limit);
			selectionSortStartStop->SetStop();
			ss2b << sortMethod << " stopped";
			messageText = ss2b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, selectionSortStartStop);

			sortMethod = "Cycle Sort";
			ss3 << sortMethod << " start";
			messageText = ss3.str();
			cout << messageText << " " << limit << endl;
			cycleSortStartStop = new StartStop();
			c.cycleSort(arrayToSort, limit);
			c.printArray(arrayToSort, limit);
			cycleSortStartStop->SetStop();
			ss3b << sortMethod << " stopped";
			messageText = ss3b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, cycleSortStartStop);

			sortMethod = "Heap Sort";
			ss4 << sortMethod << " start";
			messageText = ss4.str();
			cout << messageText << " " << limit << endl;
			heapSortStartStop = new StartStop();
			h.heapSort(arrayToSort, limit);
			h.printArray(arrayToSort, limit);
			heapSortStartStop->SetStop();
			ss4b << sortMethod << " stopped";
			messageText = ss4b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, heapSortStartStop);

			sortMethod = "Insertion Sort";
			ss5 << sortMethod << " start";
			messageText = ss5.str();
			cout << messageText << " " << limit << endl;
			insertionSortStartStop = new StartStop();
			i.insertionSort(arrayToSort, limit);
			i.printArray(arrayToSort, limit);
			insertionSortStartStop->SetStop();
			ss5b << sortMethod << " stopped";
			messageText = ss5b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, insertionSortStartStop);

			sortMethod = "Quick Sort";
			ss6 << sortMethod << " start";
			messageText = ss6.str();
			cout << messageText << " " << limit << endl;
			quickStartStop = new StartStop();
			q.quickSort(arrayToSort, arrayToSort[0], arrayToSort[limit]);
			q.printArray(arrayToSort, limit);
			quickStartStop->SetStop();
			ss6b << sortMethod << " stopped";
			messageText = ss6b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, quickStartStop);
		}

		void Process10000()
		{
			string messageText = "";
			string sortMethod = "";
			int limit = 10000;
			StartStop* bubbleSortStartStop = NULL;
			StartStop* selectionSortStartStop = NULL;
			StartStop* cycleSortStartStop = NULL;
			StartStop* heapSortStartStop = NULL;
			StartStop* insertionSortStartStop = NULL;
			StartStop* quickStartStop = NULL;
			std::stringstream ss1;
			std::stringstream ss2;
			std::stringstream ss3;
			std::stringstream ss4;
			std::stringstream ss5;
			std::stringstream ss6;

			std::stringstream ss1b;
			std::stringstream ss2b;
			std::stringstream ss3b;
			std::stringstream ss4b;
			std::stringstream ss5b;
			std::stringstream ss6b;

			BubbleSort b;
			SelectionSort s;
			CycleSort c;
			HeapSort h;
			InseartionSort i;
			QuickSort q;

			LoadFile(limit);
			WriteToHeader(limit);
			sortMethod = "Bubble Sort";
			ss1 << sortMethod << " start";
			messageText = ss1.str();
			cout << messageText << " " << limit << endl;
			bubbleSortStartStop = new StartStop();
			b.bubbleSort(arrayToSort, limit);
			b.printArray(arrayToSort, limit);
			bubbleSortStartStop->SetStop();
			ss1b << sortMethod << " stopped";
			messageText = ss1b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, bubbleSortStartStop);

			sortMethod = "Selection Sort";
			ss2 << sortMethod << " start";
			messageText = ss2.str();
			cout << messageText << " " << limit << endl;
			selectionSortStartStop = new StartStop();
			s.selectionSort(arrayToSort, limit);
			s.printArray(arrayToSort, limit);
			selectionSortStartStop->SetStop();
			ss2b << sortMethod << " stopped";
			messageText = ss2b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, selectionSortStartStop);

			sortMethod = "Cycle Sort";
			ss3 << sortMethod << " start";
			messageText = ss3.str();
			cout << messageText << " " << limit << endl;
			cycleSortStartStop = new StartStop();
			c.cycleSort(arrayToSort, limit);
			c.printArray(arrayToSort, limit);
			cycleSortStartStop->SetStop();
			ss3b << sortMethod << " stopped";
			messageText = ss3b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, cycleSortStartStop);

			sortMethod = "Heap Sort";
			ss4 << sortMethod << " start";
			messageText = ss4.str();
			cout << messageText << " " << limit << endl;
			heapSortStartStop = new StartStop();
			h.heapSort(arrayToSort, limit);
			h.printArray(arrayToSort, limit);
			heapSortStartStop->SetStop();
			ss4b << sortMethod << " stopped";
			messageText = ss4b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, heapSortStartStop);

			sortMethod = "Insertion Sort";
			ss5 << sortMethod << " start";
			messageText = ss5.str();
			cout << messageText << " " << limit << endl;
			insertionSortStartStop = new StartStop();
			i.insertionSort(arrayToSort, limit);
			i.printArray(arrayToSort, limit);
			insertionSortStartStop->SetStop();
			ss5b << sortMethod << " stopped";
			messageText = ss5b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, insertionSortStartStop);

			sortMethod = "Quick Sort";
			ss6 << sortMethod << " start";
			messageText = ss6.str();
			cout << messageText << " " << limit << endl;
			quickStartStop = new StartStop();
			q.quickSort(arrayToSort, arrayToSort[0], arrayToSort[limit]);
			q.printArray(arrayToSort, limit);
			quickStartStop->SetStop();
			ss6b << sortMethod << " stopped";
			messageText = ss6b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, quickStartStop);
		}

		void Process100000()
		{
			string messageText = "";
			string sortMethod = "";
			int limit = 100000;
			StartStop* bubbleSortStartStop = NULL;
			StartStop* selectionSortStartStop = NULL;
			StartStop* cycleSortStartStop = NULL;
			StartStop* heapSortStartStop = NULL;
			StartStop* insertionSortStartStop = NULL;
			StartStop* quickStartStop = NULL;
			std::stringstream ss1;
			std::stringstream ss2;
			std::stringstream ss3;
			std::stringstream ss4;
			std::stringstream ss5;
			std::stringstream ss6;

			std::stringstream ss1b;
			std::stringstream ss2b;
			std::stringstream ss3b;
			std::stringstream ss4b;
			std::stringstream ss5b;
			std::stringstream ss6b;

			BubbleSort b;
			SelectionSort s;
			CycleSort c;
			HeapSort h;
			InseartionSort i;
			QuickSort q;

			LoadFile(limit);
			WriteToHeader(limit);
			sortMethod = "Bubble Sort";
			ss1 << sortMethod << " start";
			messageText = ss1.str();
			cout << messageText << " " << limit << endl;
			bubbleSortStartStop = new StartStop();
			b.bubbleSort(arrayToSort, limit);
			b.printArray(arrayToSort, limit);
			bubbleSortStartStop->SetStop();
			ss1b << sortMethod << " stopped";
			messageText = ss1b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, bubbleSortStartStop);

			sortMethod = "Selection Sort";
			ss2 << sortMethod << " start";
			messageText = ss2.str();
			cout << messageText << " " << limit << endl;
			selectionSortStartStop = new StartStop();
			s.selectionSort(arrayToSort, limit);
			s.printArray(arrayToSort, limit);
			selectionSortStartStop->SetStop();
			ss2b << sortMethod << " stopped";
			messageText = ss2b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, selectionSortStartStop);

			sortMethod = "Cycle Sort";
			ss3 << sortMethod << " start";
			messageText = ss3.str();
			cout << messageText << " " << limit << endl;
			cycleSortStartStop = new StartStop();
			c.cycleSort(arrayToSort, limit);
			c.printArray(arrayToSort, limit);
			cycleSortStartStop->SetStop();
			ss3b << sortMethod << " stopped";
			messageText = ss3b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, cycleSortStartStop);

			sortMethod = "Heap Sort";
			ss4 << sortMethod << " start";
			messageText = ss4.str();
			cout << messageText << " " << limit << endl;
			heapSortStartStop = new StartStop();
			h.heapSort(arrayToSort, limit);
			h.printArray(arrayToSort, limit);
			heapSortStartStop->SetStop();
			ss4b << sortMethod << " stopped";
			messageText = ss4b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, heapSortStartStop);

			sortMethod = "Insertion Sort";
			ss5 << sortMethod << " start";
			messageText = ss5.str();
			cout << messageText << " " << limit << endl;
			insertionSortStartStop = new StartStop();
			i.insertionSort(arrayToSort, limit);
			i.printArray(arrayToSort, limit);
			insertionSortStartStop->SetStop();
			ss5b << sortMethod << " stopped";
			messageText = ss5b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, insertionSortStartStop);

			sortMethod = "Quick Sort";
			ss6 << sortMethod << " start";
			messageText = ss6.str();
			cout << messageText << " " << limit << endl;
			quickStartStop = new StartStop();
			q.quickSort(arrayToSort, arrayToSort[0], arrayToSort[limit]);
			q.printArray(arrayToSort, limit);
			quickStartStop->SetStop();
			ss6b << sortMethod << " stopped";
			messageText = ss6b.str();
			cout << messageText << " " << limit << endl;
			WriteToOutputFile(limit, sortMethod, quickStartStop);
		}

	public:
		void Go()
		{

			Process100();
			Process1000();
			Process10000();
			Process100000();

		}

};

int main()
{
	Process process;
	process.Go();
}
