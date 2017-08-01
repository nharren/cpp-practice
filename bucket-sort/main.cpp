/*
Bucket Sort

Bucket sort sorts positive integers using array indexes. First, an array 
of zeros is created with a length equal to the maximum integer. Then for 
each integer, we increment at the index of that integer.

*/

#include<iostream>

using namespace std;

void BucketSort(const int integers[], const int length, int sortedIntegers[]);
void PrintBucketArray(int sortedIntegers[], const int maximumInteger);

void main()
{
	const int integers[10] = { 5, 2, 3, 5, 6, 1, 9, 4, 8, 3 };
	int sortedIntegers[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	BucketSort(integers, 10, sortedIntegers);
	PrintBucketArray(sortedIntegers, 10);
}

void BucketSort(const int integers[], const int integersLength, int sortedIntegers[])
{
	for (int index = 0; index < integersLength; index++)
	{
		int integer = integers[index];
		sortedIntegers[integer]++;
	}
}

void PrintBucketArray(int sortedIntegers[], const int maximumInteger)
{
	for (int index = 1; index < maximumInteger; index++)
	{
		for (int integerCount = 0; integerCount < sortedIntegers[index]; integerCount++)
		{
			cout << index << " ";
		}
	}

	cout << endl;
}