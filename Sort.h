#pragma once
#include <string>

using String = std::string;

class Sort {
public:
	Sort(); // constructor
	void insertionSortAscending(int[], int);
	void insertionSortDescending(int[], int);
	void mergeSort(int[], int);

private:
	void merge(int[], int, int, int);
	void mergeSortHelper(int[], int, int);
};
