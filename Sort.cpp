/**
* Name: Thomas Asuncion
* Program - Insert vs Merge Sort Analyzer
**/

#include "Sort.h"

Sort::Sort() { }

void Sort::insertionSortAscending(int arr[], int length)
{
	// CEIndex - Current Element Index, NEIndex - Next Element Index.
	int CEIndex, NEIndex, key;

	for (CEIndex = 1; CEIndex < length; CEIndex++) {
		NEIndex = CEIndex;

		// While the next element index is greater than zero and the current element is greater than the next element...
		while (NEIndex > 0 && arr[NEIndex - 1] > arr[NEIndex]) {
			key = arr[NEIndex];
			arr[NEIndex] = arr[NEIndex - 1];
			arr[NEIndex - 1] = key;
			NEIndex--;
		}
	}
}

void Sort::insertionSortDescending(int arr[], int length)
{
	// CEIndex - Current Element Index, NEIndex - Next Element Index.
	int CEIndex, NEIndex, key;

	for (CEIndex = 1; CEIndex < length; CEIndex++) {
		NEIndex = CEIndex;

		// While the next element index is greater than zero and the current element is greater than the next element...
		while (NEIndex > 0 && arr[NEIndex - 1] < arr[NEIndex]) {
			key = arr[NEIndex];
			arr[NEIndex] = arr[NEIndex - 1];
			arr[NEIndex - 1] = key;
			NEIndex--;
		}
	}
}

void Sort::merge(int arr[], int leftIndex, int middleIndex, int rightIndex)
{
	// Create a temp array to store values.
	int *temp = new int[rightIndex - leftIndex + 1];
	int i = leftIndex, j = middleIndex + 1;
	int k = 0;

	while (i <= middleIndex && j <= rightIndex) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	// For the elements on the left hand side:
	while (i <= middleIndex)
		temp[k++] = arr[i++];
	// For the lements on the right hand side:
	while (j <= rightIndex)
		temp[k++] = arr[j++];
	// Copy the mergered temp array to the original array.
	for (k = 0, i = leftIndex; i <= rightIndex; ++i, ++k)
		arr[i] = temp[k];

	delete[]temp;
}

void Sort::mergeSortHelper(int arr[], int leftIndex, int rightIndex)
{
	int mid;
	if (leftIndex < rightIndex) {
		mid = (leftIndex + rightIndex) >> 1;

		// Call itself recursively.
		mergeSortHelper(arr, leftIndex, mid);
		mergeSortHelper(arr, mid + 1, rightIndex);

		// Call back to the merge function.
		merge(arr, leftIndex, mid, rightIndex);
	}
}

void Sort::mergeSort(int arr[], int length)
{
	mergeSortHelper(arr, 0, length - 1);
}
