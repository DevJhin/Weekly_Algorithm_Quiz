#include <iostream>
#include <queue>

int row;

int col;

enum State { None = -1, Good, Rotten };

struct Vector2 {
	int x;
	int y;

	Vector2(int _x, int _y) :x(_x), y(_y) {}

};

State apples[1000][1000];

int main() {

	scanf("%d %d", &col,&row);
	std::queue<Vector2> rottenQueue;
	
	int totalAppleNum = col * row;
	bool noRottenApple=true;

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {

			int temp;

			scanf("%d",&temp);

			apples[i][j]= (State)temp;

			if (apples[i][j] == Rotten) {
				rottenQueue.push(Vector2(i,j));
			}
			else if (apples[i][j] == None) {
				totalAppleNum -= 1;
			}

		}

	}

	if (rottenQueue.size()==0) {	//If there is no rotten apple, print '-1' and quit application.
		printf("%d", -1);
		return 0;
	}

	int depth = 0;
	int rottenAppleNum = 0;

	while (!rottenQueue.empty()) {
		bool flag = false;

		int length = rottenQueue.size();

		rottenAppleNum += length;

		for (int cnt = 0; cnt < length; cnt++) {

			Vector2 temp = rottenQueue.front();

			int i = temp.x;
			int j = temp.y;

			if (i > 0 && apples[i - 1][j] == Good) {
				flag = true;
				apples[i - 1][j] = Rotten;
				rottenQueue.push(Vector2(i - 1, j));
			}
			if (i + 1 < row && apples[i + 1][j] == Good) {
				flag = true;
				apples[i + 1][j] = Rotten;
				rottenQueue.push(Vector2(i + 1, j));
			}
			if (j > 0 && apples[i][j - 1] == Good) {
				flag = true;
				apples[i][j - 1] = Rotten;
				rottenQueue.push(Vector2(i, j - 1));
			}
			if (j + 1 < col && apples[i][j + 1] == Good) {
				flag = true;
				apples[i][j + 1] = Rotten;
				rottenQueue.push(Vector2(i, j + 1));
			}
	
			rottenQueue.pop();
		}
	
		if (flag) depth++;

	}

	if (totalAppleNum == rottenAppleNum) {
		printf("%d",depth);;
	}
	else {
		printf("%d", -1);
	}
	return 0;
}
