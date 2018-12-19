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
	int finalBusArrveTime = 540 + (n - 1) * t;	//막차가 도착하는 시간

	if (hasRideSuccess)// 크루 중 단 한 사람이라도 버스에 탈 수 있는 사람이 있다면	
	{
		if (hasBusRemained) //버스에 탈 수 있었던 크루들 중에서, 마지막으로 탑승하는 크루가 타는 버스가 막차가 아니라면
		{
			resultTime =finalBusArrveTime;	///콘은 느긋하게 막차 도착 시간에 맞추어 막차를 타면 된다.
		}
		else //버스에 탈 수 있었던 크루 중, 마지막으로 탑승한 크루가 탄 버스가 막차였다면
		{
			/*콘은 절대 이 차를 놓쳐서는 안된다!!*/

			if (hasBusSeatRemained)// 그런데 막차에 남은 자리가 있었다면
			{
				resultTime = finalBusArrveTime;	///콘은 느긋하게 막차 도착 시간에 맞추어 막차를 타면 된다.
			}
			else// 막차에 남은 자리가 하나도 없다면
			{
				resultTime = lastRideSuccessTime - 1;	///콘은 반드시 마지막으로 탑승한 크루의 탑승시간 보다 1분 먼저 도착해 있어야 한다.
			}
		}

	}
	else// 크루 중 아무도 버스에 탈 수 없는 경우라면
	{
		resultTime = finalBusArrveTime;;	///콘은 느긋하게 막차 도착 시간에 맞추어 막차를 타면 된다.
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
