#include "Gear.h"

Gear::Gear()
{
}

Gear::~Gear()
{
}

void Gear::Initialize(const char* temp) {
	for (int i = 0; i < 8; i++) {
		data[i] = (Polar)(temp[i] - 48);
	}
}

void Gear::RotateGear(Direction direction) {
	switch (direction)
	{
	case Clockwise: {
		topIndex = --topIndex < 0 ? 7 : topIndex;
		rightIndex = --rightIndex < 0 ? 7 : rightIndex;
		leftIndex = --leftIndex < 0 ? 7 : leftIndex;
		break;
	}
	case Anti_Clockwise: {
		topIndex = ++topIndex > 7 ? 0 : topIndex;
		rightIndex = ++rightIndex > 7 ? 0 : rightIndex;
		leftIndex = ++leftIndex > 7 ? 0 : leftIndex;

		break;
	}
	}
}

Polar Gear::GetTopPolar() {
	return data[topIndex];
}

Polar Gear::GetRightPolar() {
	return data[rightIndex];
}

Polar Gear::GetLeftPolar() {
	return data[leftIndex];
}
