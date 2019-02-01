#include <string>
#include <vector>
#include<map>

using namespace std;
typedef map<string, int> HashMap;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	HashMap hashMap;

	int completionSize = completion.size();
	for (int i = 0; i < completionSize; i++)
	{
		auto result = hashMap.find(completion[i]);
		if (result != hashMap.end())
		{
			result->second += 1;
		}
		else
		{
			hashMap[completion[i]] = 1;
		}

	}

	int participantSize = participant.size();

	for (int i = 0; i < participantSize; i++)
	{
		auto result = hashMap.find(participant[i]);
		if (result != hashMap.end() && result->second > 0)
		{
			result->second -= 1;
		}
		else
		{
			answer = participant[i];
			break;
		}
	}
	return answer;
}