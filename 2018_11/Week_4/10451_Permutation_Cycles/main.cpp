#include <iostream>
int data[1010];
bool dataVisited[1010];

int main() {

	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {

		int dataNum;
		scanf("%d", &dataNum);

		int cycle = 0;

		for (int i = 1; i <= dataNum; i++) {
			scanf("%d", &data[i]);
			dataVisited[i] = false;
		}

		for (int index = 1; index <= dataNum; index++) {
			if (!dataVisited[index]) {
				int head = index;
				while (!dataVisited[head]) {
					dataVisited[head] = true;
					head = data[head];
				}
				cycle++;
			}
		}
		std::cout << cycle << std::endl;

	}
	return 0;
}
