#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Stage
{
public:
	int stageNum;
	double failureRate;

	Stage(int stageNum, int challengeCnt, int totalChallengeCnt) :stageNum(stageNum)
	{
		failureRate = GetFailureRate(challengeCnt, totalChallengeCnt);
	}

	double GetFailureRate(int challengeCnt, int totalChallengeCnt)
	{
		if (totalChallengeCnt > 0) {
			return challengeCnt / (double)totalChallengeCnt;
		}
		else
		{
			return 0.0;
		}
	}

	bool operator<(const Stage &other) const {

		return this->failureRate < other.failureRate || (this->failureRate == other.failureRate && this->stageNum > other.stageNum);
	}
};


vector<int> solution(int N, vector<int> playerData) {

	int challengeCounts[510] = {0,};

	int playerNum = playerData.size();

	for (int i = 0; i < playerNum; i++)
	{
		int challengingStage = playerData[i];
		if (challengingStage <= N) {
			challengeCounts[challengingStage - 1] += 1;
		}
	}

	int totalChallengeCount = playerNum;

	vector<Stage> stages;

	for (int i = 0; i < N; i++)
	{
		Stage stage(i + 1, challengeCounts[i], totalChallengeCount);
		stages.push_back(stage);

		totalChallengeCount -= challengeCounts[i];
	}
	sort(stages.rbegin(), stages.rend());

	vector<int> answer;
	for (int i = 0; i < N; i++)
	{
		answer.push_back(stages[i].stageNum);
	}

	return answer;
}