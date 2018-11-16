#include<iostream>
#define Square(num)((num) * (num))
#define Print(rlt)std::cout <<rlt<<"\n";
//시도 횟수 0회
int main() {
	int T;
	std::cin >> T;
	int x_1, y_1, r_1, x_2, y_2, r_2;


	while (T--) {
		std::cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		int distance = Square(x_1 - x_2) + Square(y_1 - y_2);

		int diameter_Sum = Square(r_1 + r_2);
		int diameter_Diff = Square(r_1 - r_2);

		if (distance > diameter_Sum) { // 중심 간 거리가 두 원의 반지름 합 보다 크면 교점이 0개
			Print(0);
		}
		else if (distance == diameter_Sum) {
			Print(1);// 중심 간 거리가 두 원의 반지름 합과 같으면 교점이 1개.
		}
		else {

			if (distance > diameter_Diff) { //중심 간 거리가 두 원의 반지름 차이보다 크면 교점은 2개
				Print(2);
			}
			else if (distance == diameter_Diff) {
				if (distance == 0){//중심 간 거리와 두 원의 반지름 차이와 0으로 같으면(원이 일치) 교점은 무한대
					Print(-1);
				}
				else {//중심 간 거리가 두 원의 반지름 차이와 같으면 교점은 1개
					Print(1);
				}

			}
			else {//중심 간 거리가 두 원의 반지름 차이보다 작으면 교점은 0개

				Print(0);
			}
		}

	}

}
 