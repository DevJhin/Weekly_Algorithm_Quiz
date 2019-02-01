#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Job
{
	int requestTime;
	int processTime;

	Job(int requestTime, int processTime) :requestTime(requestTime), processTime(processTime)
	{

	}
};

int solution(vector<vector<int>> data) {
	int answer = 0;
	int dataSize = data.size();

	vector<Job> jobs;
	for (int i = 0; i < dataSize; i++)
	{
		jobs.push_back(Job(data[i][0], data[i][1]));
	}

	vector<Job> queue;
	make_heap(queue.begin(), queue.end());

	for (int i = 0; i < dataSize; i++)
	{
		queue.jobs.push_back(Job(data[i][0], data[i][1]));
	}

	return answer;
}