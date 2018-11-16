#pragma once
class Deque
{
private:
	int* data;
	int size;

	void PrintMessage(int val);
public:
	Deque();
	~Deque();

	enum OrderType{ Push_Back = 0, Push_Front, Pop_Front, Pop_Back, Front, Back, Size, Empty };
	void PushFront(int x);
	void PushBack(int x);

	void PopFront();
	void PopBack();

	void PrintSize();

	void PrintIsEmpty();

	void PrintFront();
	void PrintBack();

	static OrderType ConvertToOrder(const char* val);
};

