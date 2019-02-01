#include <string>
#include <vector>

using namespace std;

struct StringSearch {

private:
	static void BoyerMooreAlgorithm()
	{
		int prefix;
		int suffix;
		
	}

public:
	static vector<int> SearchAll(string pattern, string text)
	{
		vector<int> result;
		return result;
	}

};


class MusicInfo
{
private:
	string name;

	int startTime;
	int endTime;

	string notes;
public: 
	MusicInfo(string name, int startTime, int endTime, string notes) :name(name), startTime(startTime), endTime(endTime),notes(notes)
	{

	}

	string GetPlayedNotes() const
	{
		int scoreLength = notes.size();
		int playTime = endTime - startTime;

		int routine = scoreLength / playTime;
		int remains = scoreLength % playTime;

		string playedNotes="";

		for (int i = 0; i < routine; i++)
		{
			for (int i = 0; i < scoreLength; i++)
			{
				playedNotes.push_back(notes[i]);
			}
		}

		for (int i = 0; i < remains; i++)
		{
			playedNotes.push_back(notes[i]);
		}
		return playedNotes;
	}

	const int GetStartTime() const
	{
		return startTime;
	}
	const int GetEndTime() const
	{
		return endTime;
	}
	const string GetName() const
	{
		return name;
	}
};

class JustNowMusicService {
private:
	vector<MusicInfo> musicInfos;

	void AddMusicInfo(const string rawMusicInfo)
	{
		int startHour, startMinute, endHour, endMinute;

		char name[100];
		char rawScore[3000];

		sscanf(rawMusicInfo.c_str(), "%d:%d,%d:%d,%80[^,],%s", &startHour, &startMinute, &endHour, &endMinute, name, rawScore);

		musicInfos.push_back(MusicInfo(name, startHour * 60 + startMinute, endHour * 60 + endMinute, rawScore));
	}

public:
	JustNowMusicService(const vector<string> musicRawInfos)
	{
		for (int i = 0; i < musicRawInfos.size(); i++)
		{
			AddMusicInfo(musicRawInfos[i]);
		}
	}

	const string FindMusic(const string melody) const
	{
		string playedNotes = "";
		int prevEndTime = -2;
		for (int i = 0; i < musicInfos.size(); i++)
		{
			if (i >0 && prevEndTime != musicInfos[i].GetStartTime())
			{
				playedNotes += ' ';
			}
			playedNotes += musicInfos[i].GetPlayedNotes();

			prevEndTime = musicInfos[i].GetEndTime;
		}

		vector<int> index = StringSearch::SearchAll(melody, playedNotes);


		if (0) {
			return "Good";
		}
		else {
			return "`(None)`";
		}
	}
};


string solution(string melody, vector<string> musicRawInfos) {

	JustNowMusicService justNowMusicService(musicRawInfos);

	string answer = justNowMusicService.FindMusic(melody);
	return answer;
}
