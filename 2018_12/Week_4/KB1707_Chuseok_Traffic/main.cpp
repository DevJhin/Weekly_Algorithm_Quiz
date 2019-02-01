#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;
enum TimeState { Start, End };

class TimeLine
{
public:

	double startTime;
	double endTime;

	TimeLine(double startTime, double endTime) :startTime(startTime),endTime(endTime)
	{
	
	}

	bool IsProcessed(double checkStartTime, double checkEndTime)
	{
		if (startTime > checkEndTime || endTime < checkStartTime)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

bool CmpSchedule(const TimeLine &a, const TimeLine &b)
{
	return a.startTime < b.startTime;
}

int GetStartTime(const string* log)
{
	int startTime = 0;

	return startTime;
}

int GetDuration(const string* log)
{
	int duration = 0;

	return duration;
}
int solution(vector<string> logs) {
	vector<TimeLine> Schedule;
	for (int i = 0; i < logs.size(); i++)
	{
		int year, month, day, hour, minute;
		double  second, duration;
		sscanf(logs[i].c_str(), "%d-%d-%d %d:%d:%lf %lfs", &year, &month, &day, &hour, &minute, &second, &duration);
		//printf("%d-%d-%d %d:%d:%lf %lfs", year, month, day, hour, minute, second, duration);
		vector<string> splitResult;

		double startTime = day * 216000 + hour * 3600 + minute * 60 + second;
		double endTime = startTime + duration;

		Schedule.push_back(TimeLine(startTime,endTime));
		printf("%lf %lf",startTime,endTime);
	}

	int maxProcess = 0;
	int currentProcess = 0;

	sort(Schedule.begin(), Schedule.end(), CmpSchedule);

	for (int i = 0; i < Schedule.size(); i++) {

		TimeLine timeLine = Schedule.front();
		
		if (timeLine.IsProcessed())
		{

		}
	}

	return maxProcess;
}
