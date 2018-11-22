#pragma once
class BinarySearch
{
private:

	static double epsillonFindValue; //data to search
	static int RecursiveBinarySearchAll(int* data, int start, int end);
public:
	BinarySearch();
	~BinarySearch();

	static int ContainsAll(int value, int* data, int length);
};
