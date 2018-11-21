#include <iostream>
#include <math.h>

int N, row, col;
int main() {
	
	scanf("%d %d %d",&N,&row,&col);

	int value = 0;
	int mult = 1;

	for (int i = 0; i < N; i++) {
		value += (col%2)*mult;
		col /= 2;
		mult *=2;

		value += (row % 2)*mult;
		row /= 2;
		mult *= 2;
	}

	printf("%d", value);
}