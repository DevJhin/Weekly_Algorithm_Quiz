#include<iostream>
#define Square(num)((num) * (num))
#define Print(rlt)std::cout <<rlt<<"\n";
//�õ� Ƚ�� 0ȸ
int main() {
	int T;
	std::cin >> T;
	int x_1, y_1, r_1, x_2, y_2, r_2;


	while (T--) {
		std::cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
		int distance = Square(x_1 - x_2) + Square(y_1 - y_2);

		int diameter_Sum = Square(r_1 + r_2);
		int diameter_Diff = Square(r_1 - r_2);

		if (distance > diameter_Sum) { // if distance between center is bigger than the sum of diamter, no intersect exists
			Print(0);
		}
		else if (distance == diameter_Sum) {// if distance between center is equal to the sum of diamter, one intersect exists
			Print(1);
		}
		else {

			if (distance > diameter_Diff) { // if distance between center is bigger than the diff of diamter, two intersect exists
				Print(2);
			}
			else if (distance == diameter_Diff) {
				if (distance == 0){ // if the two circles are indentical, infinite intersect exists
					Print(-1);
				}
				else { 	// if distance between center is equal to the diff of diamter(but the cirles are not identical), one intersect exists
					Print(1);
				}

			}
			else {// if distance between center is smaller than the diff of diamter, no intersect exists
				Print(0);
			}
		}

	}

}
 
