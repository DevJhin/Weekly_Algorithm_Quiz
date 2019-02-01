#include <string>
#include <vector>
#include<hash_map>

using namespace std;
 
class BaseAttribute
{

private:
	bool isDirty = false;
	bool isCandidate=false;
	hash_map<string, int> hash;
	vector<string> crashData;

public:
	explicit BaseAttribute(vector<string>& data)
	{

		hash.insert(hash_map<string,i >);
		//this->data = data;
	}

	
	void GetCrashTuple()
	{
	
	}

	void CompareCrashTuple()
	{
	
	}

	bool IsCadidate()
	{
		return crashData.size() == 0 ? true : false;
	}
};

class CandidateKeyManager
{
private:

public:
	void AddData()
	{
	
	}


	
};

int solution(vector<vector<string>> relation) {
	int tupleSize = relation.size();
	int attributeSize = relation[0].size();

	vector<BaseAttribute> baseAttributes;

	for (int i = 0; i < tupleSize; i++)
	{
		BaseAttribute attribute(relation[i]);
		baseAttributes.push_back(attribute);
	}


}