#pragma once
class Node
{
private:
	Time data;
public:
	Node();
	~Node();

	Time GetData();
};

struct Time {
	int startTime;
	int endTime;
};