#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;


struct MuziAlgorithm
{
private:

	//Get head part of file name, by string value
	static void GetHeadPart(const string& name, string& headRef)
	{
		headRef = "";
		// add character until digit number is discovered
		for (int i = 0; i < name.length(); i++)
		{
			if (!isdigit(name[i]))
			{
				headRef += name[i];
			}
			else
			{
				break;
			}
		}
	}

	//Get number part of name, by integer value
	static int GetNumberPart(const string& name)
	{
		int numberStartIndex = 0;

		while (!isdigit(name[numberStartIndex]))
		{
			numberStartIndex += 1;
		}

		int number = 0;
		int	numberLength = 0;

		for (int i = numberStartIndex; i < name.length(); i++)
		{
			if (isdigit(name[i]) && numberLength < 5) {
				number *= 10;
				number += name[i] - '0';

				numberLength += 1;
			}
			else
			{
				break;
			}
		}
		return number;
	}

	static int CompareHeadPart(const string& name_1, const string& name_2)
	{
		string head_1;
		string head_2;

		GetHeadPart(name_1, head_1);
		GetHeadPart(name_2, head_2);
		int minLength = min(head_1.length(), head_2.length());

		for (int i = 0; i < minLength; i++) {
			if (toupper(head_1[i]) < toupper(head_2[i]))
			{
				return -1;
			}
			else if (toupper(head_1[i]) > toupper(head_2[i]))
			{
				return 1;
			}
		}

		if (head_1.length() < head_2.length())
		{
			return -1;
		}
		else if (head_1.length() == head_2.length())
		{
			return 0;
		}
		else if (head_1.length() > head_2.length())
		{
			return 1;
		}
	}

	static int CompareNumberPart(const string& name_1, const string& name_2)
	{
		int number_1 = GetNumberPart(name_1);
		int number_2 = GetNumberPart(name_2);

		if (number_1 < number_2)
		{
			return -1;
		}
		else if(number_1 == number_2)
		{
			return 0;
		}
		else if (number_1  > number_2)
		{
			return 1;
		}
	}

public:
	
	static bool Compare(const pair<string, int>& str_1, const pair<string, int>& str_2)
	{
		//Compare head part first
		int headResult = CompareHeadPart(str_1.first, str_2.first);
		if (headResult < 0)
		{
			return true;
		}
		else if (headResult > 0)
		{
			return false;
		}
		else
		{
			int numberResult = CompareNumberPart(str_1.first, str_2.first);

			if (numberResult < 0)
			{
				return true;
			}
			else if (numberResult > 0)
			{
				return false;
			}
			else
			{
				return str_1.second < str_2.second;
			}
		}
	}
};

vector<string> solution(vector<string> files) {
	vector<pair<string, int>> data;
	for (int i = 0; i < files.size(); i++) 
	{
		data.push_back(pair<string, int>(files[i], i));
	}

	sort(data.begin(), data.end(), MuziAlgorithm::Compare);

	vector<string> answer;
	for (int i = 0; i < files.size(); i++)
	{
		answer.push_back(data[i].first);
	}
	return answer;
}