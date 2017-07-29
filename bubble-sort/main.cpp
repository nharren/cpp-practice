/*
Bubble Sort

Bubble sort is a sorting algorithm which runs in O(n^2) time. In multiple passes through the array, 
adjacent elements are swapped if they are not in order. The worst case time occurs when the when the 
lowest element is at the end of the array, as it will require n - 1 passes (at 1 swap/pass) to shift 
the element to the beginning of the array. A pass with no swaps made indicates the list is sorted.

Example:
Starting Array: { 2, 3, 1 }
1) Pass 1:
	1) 2 & 3 in order, not swapped 
	   { 2, 3, 1 }
	2) 3 & 1 out of order, swapped
	   { 2, 1, 3 }
2) We made a swap, and we haven't made n - 1 passes, so we do another pass.
3) Pass 2:
	1) 2 & 1 out of order, swapped 
	   { 1, 2, 3 }
	2) 2 & 3 in order, not swapped
	   { 1, 2, 3 }
4) Becuase we have reached n - 1 passes, the list is sorted.
*/

#include <iostream>

using namespace std;

template <typename ItemType>
void Swap(ItemType *aPointer, ItemType *bPointer)
{
	ItemType temp = *aPointer;
	*aPointer = *bPointer;
	*bPointer = temp;
}

template <typename ItemType>
void BubbleSort(ItemType itemArray[], int length)
{
	bool madeSwap = true;

	for (int pass = 1; pass < length - 1 && madeSwap; pass++)
	{
		madeSwap = false;

		for (int index = 0; index < length - 1; index++)
		{
			if (itemArray[index] > itemArray[index + 1]) {
				Swap(&itemArray[index], &itemArray[index + 1]);
				madeSwap = true;
			}
		}
	}
}

template <typename ItemType>
void PrintArray(ItemType numbers[], int length)
{
	cout << numbers[0];

	for (int index = 1; index < length; index++)
	{
		cout << " " << numbers[index];
	}

	cout << endl;
}


void main() {
	int numbers[10] = { 6, 3, 2, 7, 8, 3, 1, 9, 5, 3 };

	cout << "Before:" << endl;
	PrintArray(numbers, 10);

	BubbleSort(numbers, 10);

	cout << endl;
	cout << "After:" << endl;
	PrintArray(numbers, 10);
}