#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "BubbleSort.h"
#include "InseartionSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "CycleSort.h"
#include "SelectionSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSortMethods
{
	TEST_CLASS(UnitTestSortMethods)
	{
	public:
		
		int* arrayToSort1;
		int* arrayToSort2;
		int* arrayToSort3;
		int* arrayToSort4;
		int* arrayToSort5;
		int* arrayToSort6;

		void Read(int limit, int* arrayToSort)
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

		void LoadFile(int limit, int* arrayToSort)
		{

			for (int i = 0; i < limit; i++)
			{
				arrayToSort[i] = 0;
			}

			Read(limit, arrayToSort);

		}

		TEST_METHOD(TestMethod1)
		{
			int limit = 0;
			BubbleSort b;

			int value = 0;
			int count = 0;
			// 100
			limit = 100;
			count = 0;
			arrayToSort1 = new int[limit];
			LoadFile(limit, arrayToSort1);
			b.bubbleSort(arrayToSort1, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 1000
			limit = 1000;
			count = 0;
			arrayToSort1 = new int[limit];
			LoadFile(limit, arrayToSort1);
			b.bubbleSort(arrayToSort1, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 10000
			limit = 10000;
			count = 0;
			arrayToSort1 = new int[limit];
			LoadFile(limit, arrayToSort1);
			b.bubbleSort(arrayToSort1, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 100000
			limit = 100000;
			count = 0;
			arrayToSort1 = new int[limit];
			LoadFile(limit, arrayToSort1);
			b.bubbleSort(arrayToSort1, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

		}

		TEST_METHOD(TestMethod2)
		{
			int limit = 0;
			SelectionSort s;
			int value = 0;
			int count = 0;

			// 100
			limit = 100;
			count = 0;
			arrayToSort2 = new int[limit];
			LoadFile(limit, arrayToSort2);
			s.selectionSort(arrayToSort2, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 1000
			limit = 1000;
			count = 0;
			arrayToSort2 = new int[limit];
			LoadFile(limit, arrayToSort2);
			s.selectionSort(arrayToSort2, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 10000
			limit = 10000;
			count = 0;
			arrayToSort2 = new int[limit];
			LoadFile(limit, arrayToSort2);
			s.selectionSort(arrayToSort2, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 100000
			limit = 100000;
			count = 0;
			arrayToSort2 = new int[limit];
			LoadFile(limit, arrayToSort2);
			s.selectionSort(arrayToSort2, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

		}

		TEST_METHOD(TestMethod3)
		{

			int limit = 0;
			CycleSort c;
			int value = 0;
			int count = 0;

			// 100
			limit = 100;
			count = 0;
			arrayToSort3 = new int[limit];
			LoadFile(limit, arrayToSort3);
			c.cycleSort(arrayToSort3, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 1000
			limit = 1000;
			count = 0;
			arrayToSort3 = new int[limit];
			LoadFile(limit, arrayToSort3);
			c.cycleSort(arrayToSort3, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 10000
			limit = 10000;
			count = 0;
			arrayToSort3 = new int[limit];
			LoadFile(limit, arrayToSort3);
			c.cycleSort(arrayToSort3, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 100000
			limit = 100000;
			count = 0;
			arrayToSort3 = new int[limit];
			LoadFile(limit, arrayToSort3);
			c.cycleSort(arrayToSort3, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

		}

		TEST_METHOD(TestMethod4)
		{

			int limit = 0;
			HeapSort h;
			int value = 0;
			int count = 0;

			// 100
			limit = 100;
			count = 0;
			arrayToSort4 = new int[limit];
			LoadFile(limit, arrayToSort4);
			h.heapSort(arrayToSort4, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 1000
			limit = 1000;
			count = 0;
			arrayToSort4 = new int[limit];
			LoadFile(limit, arrayToSort4);
			h.heapSort(arrayToSort4, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 10000
			limit = 10000;
			count = 0;
			arrayToSort4 = new int[limit];
			LoadFile(limit, arrayToSort4);
			h.heapSort(arrayToSort4, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 100000
			limit = 100000;
			arrayToSort4 = new int[limit];
			count = 0;
			LoadFile(limit, arrayToSort4);
			h.heapSort(arrayToSort4, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

		}

		TEST_METHOD(TestMethod5)
		{

			int limit = 0;
			InseartionSort i;
			int value = 0;
			int count = 0;

			// 100
			limit = 100;
			count = 0;
			arrayToSort5 = new int[limit];
			LoadFile(limit, arrayToSort5);
			i.insertionSort(arrayToSort5, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 1000
			limit = 1000;
			count = 0;
			arrayToSort5 = new int[limit];
			LoadFile(limit, arrayToSort5);
			i.insertionSort(arrayToSort5, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 10000
			limit = 10000;
			count = 0;
			arrayToSort5 = new int[limit];
			LoadFile(limit, arrayToSort5);
			i.insertionSort(arrayToSort5, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 100000
			limit = 100000;
			count = 0;
			arrayToSort5 = new int[limit];
			LoadFile(limit, arrayToSort5);
			i.insertionSort(arrayToSort5, limit);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

		}

		TEST_METHOD(TestMethod6)
		{
			int limit = 0;
			QuickSort q;
			int value = 0;
			int count = 0;

			// 100
			limit = 100;
			count = 0;
			arrayToSort6 = new int[limit];
			LoadFile(limit, arrayToSort6);
			q.quickSort(arrayToSort6, arrayToSort6[0], arrayToSort6[limit]);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 1000
			limit = 1000;
			count = 0;
			arrayToSort6 = new int[limit];
			LoadFile(limit, arrayToSort6);
			q.quickSort(arrayToSort6, arrayToSort6[0], arrayToSort6[limit]);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 10000
			limit = 10000;
			count = 0;
			arrayToSort6 = new int[limit];
			LoadFile(limit, arrayToSort6);
			q.quickSort(arrayToSort6, arrayToSort6[0], arrayToSort6[limit]);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

			// 100000
			limit = 100000;
			count = 0;
			arrayToSort6 = new int[limit];
			LoadFile(limit, arrayToSort6);
			q.quickSort(arrayToSort6, arrayToSort6[0], arrayToSort6[limit]);
			for (int i = 0; i < limit; i++)
			{
				count++;
			}
			Assert::IsTrue(count == limit);

		}

	};
}
