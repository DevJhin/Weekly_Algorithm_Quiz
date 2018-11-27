#include <iostream>

int Factorial(int val);
int BinomialCoefficient(int N, int K);

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	printf("%d", BinomialCoefficient(N, K));

}

int Factorial(int val) {
	int rlt = 1;

	for (int i = 1; i <= val; i++) {
		rlt *= i;
	}

	return rlt;
}

//Calculate Binomial Coeffiecient => N!/((K!)(N-K)!)
int BinomialCoefficient(int N, int K) {
	return Factorial(N) / (Factorial(K)*Factorial(N - K));
}