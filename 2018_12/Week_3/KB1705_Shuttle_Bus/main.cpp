#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	deque<int> crewTime;
	for (int i = 0; i < timetable.size(); i++) {
		crewTime.push_back((timetable[i][0] - '0') * 600 + (timetable[i][1] - '0') * 60 + (timetable[i][3] - '0') * 10 + (timetable[i][4] - '0'));
	}
	sort(crewTime.begin(), crewTime.end());

	bool hasRideSuccess = false;

	int lastRideSuccessTime = -1;
	int lastRideSuccessBusCnt = -1;
	int lastRideSuccessBusSeatCnt = -1;

	bool hasBusRemained = true;
	bool hasBusSeatRemained = true;


	for (int busCnt=0; busCnt < n; busCnt) {
		int busTime = 540 + busCnt * t;
		for (int busSeatCnt=0; busSeatCnt < m; busSeatCnt) {
			if (crewTime.front() <= busTime)
			{
				hasRideSuccess = true;
				
				lastRideSuccessTime = crewTime.front();
				lastRideSuccessBusCnt = busCnt;
				lastRideSuccessBusSeatCnt = busSeatCnt;

				crewTime.pop_front();
				busSeatCnt+=1;
				if (crewTime.size() == 0)
				{
					break;
				}
			}
			else
			{

				break;
			}
		}
		busCnt++;
	}

	if (lastRideSuccessBusCnt < n - 1)
	{
		hasBusRemained = true;
	}
	else
	{
		hasBusRemained = false;
	}
	if (lastRideSuccessBusSeatCnt < m - 1)
	{
		hasBusSeatRemained = true;
	}
	else
	{
		hasBusSeatRemained = false;
	}

	int resultTime = 0;
	int finalBusArrveTime = 540 + (n - 1) * t;	//������ �����ϴ� �ð�

	if (hasRideSuccess)// ũ�� �� �� �� ����̶� ������ Ż �� �ִ� ����� �ִٸ�	
	{
		if (hasBusRemained) //������ Ż �� �־��� ũ��� �߿���, ���������� ž���ϴ� ũ�簡 Ÿ�� ������ ������ �ƴ϶��
		{
			resultTime =finalBusArrveTime;	///���� �����ϰ� ���� ���� �ð��� ���߾� ������ Ÿ�� �ȴ�.
		}
		else //������ Ż �� �־��� ũ�� ��, ���������� ž���� ũ�簡 ź ������ �������ٸ�
		{
			/*���� ���� �� ���� ���ļ��� �ȵȴ�!!*/

			if (hasBusSeatRemained)// �׷��� ������ ���� �ڸ��� �־��ٸ�
			{
				resultTime = finalBusArrveTime;	///���� �����ϰ� ���� ���� �ð��� ���߾� ������ Ÿ�� �ȴ�.
			}
			else// ������ ���� �ڸ��� �ϳ��� ���ٸ�
			{
				resultTime = lastRideSuccessTime - 1;	///���� �ݵ�� ���������� ž���� ũ���� ž�½ð� ���� 1�� ���� ������ �־�� �Ѵ�.
			}
		}

	}
	else// ũ�� �� �ƹ��� ������ Ż �� ���� �����
	{
		resultTime = finalBusArrveTime;;	///���� �����ϰ� ���� ���� �ð��� ���߾� ������ Ÿ�� �ȴ�.
	}

	string answer = "00:00";

	int hour = resultTime / 60;
	int min = resultTime % 60;

	answer[0] = hour / 10 + '0';
	answer[1] = hour % 10 + '0';

	answer[3] = min/ 10 + '0';
	answer[4] = min % 10 + '0';

	return answer;
}
