#include <cstring>
#include <string>
#include <vector> 
#include <list> 

using namespace std;

// Just a custom version of stricmp
int my_stricmp(const char* s1, const char* s2) {
		while (*s1 != NULL && s2 != NULL) {
			if (*s1 != *s2 && toupper(*s1) != toupper(*s2)) {
				return -1;
			}
			s1++;
			s2++;
		}
		return  (*s1 == NULL && *s2 == NULL) ? 0 : -1;
}

//Struct that holds cache data and manages cache data 
struct Cache{

	list<string> data;
	int cacheSize;

	Cache(int _cacheSize) 
	{
		cacheSize = _cacheSize;
	}

	//Uses Least Recently Used algorithms for cache replacement
	//If cache hit, return true
	//If cache miss, return false
	bool Caching(string value) 
	{
			list<string>::iterator iter;

			for (iter = data.begin(); iter != data.end(); iter++)
			{
				//Cache hit
				if (my_stricmp((*iter).c_str(), value.c_str()) == 0)
				{
					data.erase(iter++);
					data.push_front(value);
					return true;
				}

			}

			//Cache miss
			if (data.size() >= cacheSize)
			{
				data.pop_back();
				data.push_front(value);
			}
			else {
				data.push_front(value);
			}
			return false;
		}

};

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;

	Cache cache(cacheSize);

	//If cachesize is zero, there is no cache hit
	if (cacheSize == 0) return cities.size() * 5;
	
	for (int i = 0; i < cities.size(); i++) {
		//cache hit
		if (cache.Caching(cities[i]))
		{
			answer += 1;
		}
		//cache miss
		else
		{
			answer += 5;
		}
	}

	return answer;
}
