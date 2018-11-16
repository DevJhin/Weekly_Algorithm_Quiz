#include <iostream>
#include <cstring>

#include "Deque.h"

Deque::Deque()
{
	size = 0;
	data = (int*)malloc(sizeof(int)*size);	
}

Deque::~Deque()
{
	free(data);
}

void Deque::PushFront(int _newData) {
	size += 1;
	data = (int*)realloc(data, (sizeof(int)*size));
	for (int i = size - 1; i > 0; i--) {
		data[i] = data[i - 1];
	}
	data[0] = _newData;
}
void Deque::PushBack(int _newData) {
	size += 1;
	data = (int*)realloc(data, (sizeof(int)*size));
	data[size - 1] = _newData;
}
void Deque::PopFront() {
	if (size == 0) {
		PrintMessage(-1);
		return;
	}

	int popValue = data[0];
	for (int i = 0; i <size-1; i++) {
		data[i] = data[i + 1];
	}
	size -= 1;
	data = (int*)realloc(data, (sizeof(int)*size));
	PrintMessage(popValue);
}
void Deque::PopBack() {
	if (size == 0) {
		PrintMessage(-1);
		return;
	}
	int popValue = data[size-1];
	size -= 1;
	data = (int*)realloc(data, (sizeof(int)*size));
	PrintMessage(popValue);
}

void Deque::PrintSize() {
	PrintMessage(size);
}

void Deque::PrintIsEmpty() {
	if (size != 0) PrintMessage(0);
	else PrintMessage(1);
}

void Deque::PrintFront(){
	if (size == 0) PrintMessage(-1);
	else PrintMessage(data[0]);
}
void Deque::PrintBack() {
	if (size == 0) PrintMessage(-1);
	else PrintMessage(data[size-1]);
}

void Deque::PrintMessage(int val) {
	std::cout << val << std::endl;
}
Deque::OrderType Deque::ConvertToOrder(const char* val) {

	if (strcmp(val, "push_back") == 0) {
		return Push_Back;
	}
	else if (strcmp(val, "push_front") == 0) {
		return Push_Front;
	}
	else if (strcmp(val, "front") == 0) {
		return Front;
	}
	else if (strcmp(val, "back") == 0) {
		return Back;
	}
	else if (strcmp(val, "size") == 0) {
		return Size;
	}
	else if (strcmp(val, "empty") == 0) {
		return Empty;
	}
	else if (strcmp(val, "pop_front") == 0) {
		return Pop_Front;
	}
	else if (strcmp(val, "pop_back") == 0) {
		return Pop_Back;
	}
}