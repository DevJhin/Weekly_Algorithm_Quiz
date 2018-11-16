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

		if (distance > diameter_Sum) { // �߽� �� �Ÿ��� �� ���� ������ �� ���� ũ�� ������ 0��
			Print(0);
		}
		else if (distance == diameter_Sum) {
			Print(1);// �߽� �� �Ÿ��� �� ���� ������ �հ� ������ ������ 1��.
		}
		else {

			if (distance > diameter_Diff) { //�߽� �� �Ÿ��� �� ���� ������ ���̺��� ũ�� ������ 2��
				Print(2);
			}
			else if (distance == diameter_Diff) {
				if (distance == 0){//�߽� �� �Ÿ��� �� ���� ������ ���̿� 0���� ������(���� ��ġ) ������ ���Ѵ�
					Print(-1);
				}
				else {//�߽� �� �Ÿ��� �� ���� ������ ���̿� ������ ������ 1��
					Print(1);
				}

			}
			else {//�߽� �� �Ÿ��� �� ���� ������ ���̺��� ������ ������ 0��

				Print(0);
			}
		}

	}

}
 