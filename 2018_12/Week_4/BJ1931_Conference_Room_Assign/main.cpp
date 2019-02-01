#include <iostream>
struct TimeData {
	int start;
	int end;

};

TimeData data[100000];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d",&(data[i].start), &(data[i].end));
	}

	

}