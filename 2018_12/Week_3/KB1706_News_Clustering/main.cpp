#include <cstring>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
class Element
{
private:
	int key;

public:
	Element()
	{
	}

	Element(char first, char second)
	{
		this->key = (toupper(first) - 'A') * 26 + (toupper(second) - 'A');
	}

	int GetKey() const
	{
		return key;
	}
};

class Collection
{
private:
	vector<Element> elements;
	int multiplicity[700] = {0,};

	int size=0;

public:
	Collection(string str) 
	{
		for (int i = 0; i < str.length()-1; i++)
		{
			if (isalpha(str[i]) && isalpha(str[i+1]))
			{
				Element newElement(str[i], str[i + 1]);

				int key = newElement.GetKey();
				if (!multiplicity[key])
				{
					elements.push_back(newElement);
				}
				multiplicity[newElement.GetKey()] += 1;
				size++;
			}
		}
	}

	int GetSize() const{
		return size;
	}

	int GetElementSize() const {
		return elements.size;
	}

	int GetMultiplicityOf(Element& element) const {
		int key = element.GetKey();

		return multiplicity[key];
	}

	const vector<Element>& GetAllElements() const{
			return elements;
	}

};

struct CollectionMath
{
public:
	static int GetIntersectionSize(const Collection& collection_1, const Collection& collection_2) {

		int cnt = 0;

		int size = 0;
		vector<Element> elements;

		if (collection_1.GetElementSize() < collection_2.GetElementSize())
		{
			elements = collection_1.GetAllElements();
		}
		else
		{
			elements = collection_2.GetAllElements();
		}

		for (int i = 0; i <elements.size(); i++) {

			int data_1 = collection_1.GetMultiplicityOf(elements[i]);
			int data_2 = collection_2.GetMultiplicityOf(elements[i]);

			if (data_1 && data_2)
			{
				cnt += data_1 < data_2 ? data_1 : data_2;
			}
		}

		return cnt;
	}


	static double Jaccard(const Collection& data1, const Collection& data2) {

		if (data1.GetSize() == 0 && data2.GetSize() == 0)
		{
			return 1.0;
		}
		int intersectionSize = GetIntersectionSize(data1, data2);
		int unionSize = data1.GetSize() + data2.GetSize() - intersectionSize;


		double rlt = ((double)intersectionSize) / unionSize;


		return rlt;
	}

};

int solution(string str1, string str2) {
	Collection collection_1(str1);
	Collection collection_2(str2);
	
	int answer = CollectionMath::Jaccard(collection_1,collection_2)*65536;

	return answer;
}