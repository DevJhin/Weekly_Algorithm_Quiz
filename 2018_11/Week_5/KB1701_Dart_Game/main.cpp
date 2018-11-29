#include <string>
#include <cmath>
using namespace std;

int solution(string dartResult);

struct ShotData {
	int score;
	int pow;	//S =1, D =2, T=3 

	int mult =1;	// 스타와 아차에 따른 점수 배율
};

int solution(string dartResult) {
	int answer = 0;
	int i = 0;

	ShotData data[3];
	//데이터 베이스에 점수 입력
	for (int num = 0; num < 3; num++) {

		if (dartResult[i] == '1') {
			if (dartResult[i + 1] < 'A') {
				data[num].score = 10;
				i++;
			}
			else {
				data[num].score = dartResult[i] - '0';
			}
		}
		else {
			data[num].score = dartResult[i] - '0';
		}
		i++;

		switch (dartResult[i]) {
		case 'S': {
			data[num].pow = 1;
			break;
		}

		case 'D': {
			data[num].pow = 2;
			break;
		}

		case 'T': {
			data[num].pow = 3;
			break;
		}
		}

		i++;


		switch (dartResult[i]) {
		case '*': {
			data[num].mult *= 2;
			if (num > 0) data[num-1].mult *= 2;
			i++;
			break;
		}

		case '#': {
			data[num].mult *= -1;
			i++;
			break;
		}
		}
	
	}

	// 데이터베이스에서 점수 계산
	for (int num = 0; num < 3; num++) {
		int tempScore = pow(data[num].score, data[num].pow)*data[num].mult;
		answer += tempScore;
	}
	

return answer;
}
