#include <iostream>

int Factorial(int val);

int main() {
	int num;
	scanf("%d", &num);

	printf("%d", Factorial(num));

}

int Factorial(int val) {
	int rlt = 1;

	for (int i = 1; i <= val; i++) {
		rlt *= i;
	}

	return rlt;
}