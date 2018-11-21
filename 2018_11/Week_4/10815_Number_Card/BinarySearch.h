#pragma once
class BinarySearch
{
private:

	static int findValue;
	static int RecursiveBinarySearch(int* data, int start, int end);
public:
	BinarySearch();
	~BinarySearch();

	static int Contains(int value, int* data, int length);
};

