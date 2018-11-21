#include "BinarySearch.h"

int BinarySearch::findValue = -1;

BinarySearch::BinarySearch()
{
}


BinarySearch::~BinarySearch()
{
}


int BinarySearch::Contains(int _value, int* data, int length) {
	findValue = _value;
	return RecursiveBinarySearch(data, 0, length - 1);
}

int BinarySearch::RecursiveBinarySearch(int* data, int start, int end) {
	int mid = (start + end) / 2;
	if (start > end) {
		return 0;
	}
	else {
		if (findValue == data[mid]) {
			return 1;
		}
		else if (findValue < data[mid]) {
			RecursiveBinarySearch(data, start, mid - 1);
		}
		else if (findValue > data[mid]) {
			RecursiveBinarySearch(data, mid + 1, end);
		}
	}
}
