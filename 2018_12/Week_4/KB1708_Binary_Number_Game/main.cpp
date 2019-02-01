#include <string>
#include <vector>

using namespace std;
//Positional Notation

char digitName[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C', 'D', 'E', 'F' };

int Cheater(int index)
{
	int rlt;

	return rlt;
}

string solution(int base, int answerNum, int playerNum, int order) {
	string answer = "";
	for (int i = 0; i < answerNum; i++)
	{
		int turn = answerNum * playerNum + (order-1);
		answer += digitName[Cheater(turn)];
	}
	return answer;
}