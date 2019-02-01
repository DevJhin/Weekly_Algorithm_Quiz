#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class RotateBoard {
private:
	vector<int> foodTimes;
	int currentFoodNum;
	int EatRoutine()
	{

	}
public:

	RotateBoard(vector<int>& foodTimes)
	{
		this->foodTimes = foodTimes;
		currentFoodNum = 0;
	}

	int GetCurrentFoodNum()
	{
		return currentFoodNum;
	}

	void EatUntil(long long endTime)
	{
		map<int, vector<int>> timeMap;

		long long timeSum = 0;
		int totalCnt = foodTimes.size();

		for (int i = 0; i < totalCnt; i++)
		{
			int key = foodTimes[i];

			timeMap[key].push_back(i);
			timeSum += key;
		}

		if (timeSum < endTime)
		{
			currentFoodNum = -1;
			return;
		}

		stable_sort(foodTimes.begin(), foodTimes.end());

		long long currentTime = 0;
		int currentFoodCnt = totalCnt;
		long long timeRemainder = 0;

		for (int i = 0; i < totalCnt-1; i++)
		{
			int foodTime = foodTimes[i];
			int nextFoodTime= foodTimes[i + 1];
			
			int intervalTime = nextFoodTime - foodTime;
			if(intervalTime )


			if (currentTime + currentFoodCnt >= endTime)
			{
				timeRemainder = endTime - currentTime;
				break;
			}
			else
			{
				currentTime += currentFoodCnt;
			}
			currentFoodCnt -= timeMap[foodTime].size();
		}



		//printf("[%d, %d, %d]", currentTime, timeRemainder, maxFoodTime);
		
	}
};



int solution(vector<int> food_times, long long k) {

	RotateBoard board(food_times);

	board.EatUntil(k + 1);

	return board.GetCurrentFoodNum();
}