#include <iostream>

int RemainderFactorial(int val);

#define _PRIMARY_NUMBER 10007	//This number should be a primary number to achieve reverse MOD

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int r1 = RemainderFactorial(N);
	int r2 = RemainderFactorial(K);
	int r3 = RemainderFactorial(N-K);

	int R = r2 * r3 % _PRIMARY_NUMBER;	//Mod(R, 10007) = Mod((r2 * r3, 10007)

	//Find reverse MOD
	for (int i = 0; i < _PRIMARY_NUMBER; i++) {
		if ((_PRIMARY_NUMBER * i + r1 )% R == 0) {
			printf("%d", (_PRIMARY_NUMBER * i + r1 )/ R);
			break;
		}
	}

}

//Returns the remainder value of factorial calulation
int RemainderFactorial(int val) {
	int rlt = 1;
	int _OVERFLOW_MIN = 2147483647 / _PRIMARY_NUMBER;
	for (int i = 1; i <= val; i++) {
		rlt *= i;
		if(rlt>	_OVERFLOW_MIN) rlt%= _PRIMARY_NUMBER;	//This prevents int overflow 
	}
	rlt %= _PRIMARY_NUMBER;
	return rlt;
}