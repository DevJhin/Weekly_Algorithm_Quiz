#include <iostream>
#include "Gear.h"

using namespace std;

#define MAX_GEAR_SIZE 4

void PrintScore();

Gear gears[MAX_GEAR_SIZE];

int main() {

	//Initialize gear data
	for (int i = 0; i < MAX_GEAR_SIZE; i++) {
		char input[10];
		scanf("%s", input);
		gears[i].Initialize(input);
	}

	int rotateCnt = 0;
	scanf("%d", &rotateCnt);

	for (int i = 0; i < rotateCnt; i++) {

		int gearIndex;
		int direction;

		scanf("%d %d", &gearIndex, &direction);

		gearIndex -= 1;

		int rightDirection = direction;
		int leftDirection = direction;

		int rightPolar = gears[gearIndex].GetRightPolar();
		int leftPolar = gears[gearIndex].GetLeftPolar();

		//Rotate first gear
		gears[gearIndex].RotateGear((Direction)direction);

		//Check the right-side gears
		for (int i = gearIndex; i < MAX_GEAR_SIZE - 1; i++) {
			if (gears[i + 1].GetLeftPolar() == rightPolar) {
				break;
			}
			rightDirection *= -1;	//Next gear rotates to opposite direction
			rightPolar = gears[i + 1].GetRightPolar();	//Saves the right-side polar value before rotating gear
			gears[i + 1].RotateGear((Direction)rightDirection);
		}

		//Check the left-side gears
		for (int i = gearIndex; i > 0; i--) {
			if (gears[i - 1].GetRightPolar() == leftPolar) {
				break;
			}
			leftDirection *= -1;//Next gear rotates to opposite direction
			leftPolar = gears[i - 1].GetLeftPolar();	//Saves the left-side polar value before rotating gear
			gears[i - 1].RotateGear((Direction)leftDirection);
		}

	}
	PrintScore();
}

void PrintScore() {
	int sum = 0;
	int score = 1;
	for (int i = 0; i < MAX_GEAR_SIZE; i++) {
		if (gears[i].GetTopPolar() == S) {
			sum += score;
		}
		score *= 2;
	}
	cout << sum << endl;
}