#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0;i < n;i++) {
		//Bit Operator 'or'
		int temp = arr1[i] | arr2[i];
		char line[18];
		for (int j = 0;j < n;j++) {
			line[n - j - 1] = (temp % 2 == 1 ? '#' : ' ');
			temp /= 2;
		}
		string str = line;
		answer.push_back(str.substr(0, n));
	}
	return answer;
}