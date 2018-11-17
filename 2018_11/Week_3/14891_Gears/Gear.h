#pragma once

enum Polar { N = 0, S = 1 };
enum Direction { Clockwise = 1, Anti_Clockwise = -1 };

class Gear{
private:
	Polar data[8];
	int topIndex=0, rightIndex=2, leftIndex=6;

public:
	Gear();
	~Gear();

	void Initialize(const char* temp);
	void RotateGear(Direction direction);

	Polar GetTopPolar();
	Polar GetRightPolar();
	Polar GetLeftPolar();
};

