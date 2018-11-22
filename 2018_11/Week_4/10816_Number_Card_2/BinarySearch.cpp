#include "BinarySearch.h"

double BinarySearch::epsillonFindValue = 0.0f;

BinarySearch::BinarySearch()
{
}


BinarySearch::~BinarySearch()
{
}


int BinarySearch::ContainsAll(int _value, int* data, int length) {
	epsillonFindValue = _value - 0.5;	//Use a little smaller data to find first index of duplicating data
	int minIndex = RecursiveBinarySearchAll(data, 0, length - 1);

	epsillonFindValue = _value + 0.5;	//Use a little bigger data to find last index of duplicating data
	int maxIndex = RecursiveBinarySearchAll(data, 0, length - 1);

	return maxIndex - minIndex;	//

}

// modified recursive binary search algorithm to get the start/end indexes of duplicating data
int BinarySearch::RecursiveBinarySearchAll(int* data, int start, int end) {
	int mid = (start + end) / 2;
	if (start > end) {
		return start;	//find until recursive search ends
	}
	else {
		if (epsillonFindValue < data[mid]) {
			RecursiveBinarySearchAll(data, start, mid - 1);
		}
		else if (epsillonFindValue > data[mid]) {
			RecursiveBinarySearchAll(data, mid + 1, end);
		}
	}
}
