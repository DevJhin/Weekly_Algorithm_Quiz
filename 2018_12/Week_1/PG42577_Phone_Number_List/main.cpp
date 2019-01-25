#include <string>
#include <vector>
#include <map>

using namespace std;

class Node
{
private:
	map<char, Node*> nodes;
public:
	Node()
	{
	
	}


	bool HasNextNode()
	{
		if (nodes.size() > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	Node* AddNode(char c)
	{
		Node* node = new Node();
		auto ret = nodes.insert(make_pair(c, node));
		return node;
	}

	int GetNextNodeSize()
	{
		return nodes.size();
	}

	Node* GetNextNode(char c)
	{
		auto ret = nodes.find(c);
		if (ret == nodes.end())
		{
			return NULL;
		}
		else
		{
			return ret->second;
		}
	}

	~Node()
	{
		for (map<char, Node*>::iterator it = nodes.begin(); it != nodes.end(); ++it) 
		{
			delete it->second;
		}
	}
};

class Trie
{
private:
	Node * root;

public:
	Trie()
	{
		root = new Node();
	}

	bool Add(const string& str)
	{
		Node* head = root;

		int length = str.length();
		bool isNewPrefix = false;
		for (int i = 0; i < length; i++)
		{
			Node*next = head->GetNextNode(str[i]);
			if (next == NULL)
			{
				isNewPrefix = true;
				next = head->AddNode(str[i]);
			}
			else
			{
				if (next->GetNextNodeSize() == 0) return false;
			}
			head = next;
		}
		return isNewPrefix;
	}

};

bool solution(vector<string> phone_book) {
	int dataSize = phone_book.size();

	Trie trie;
	for (int i = 0; i < dataSize; i++)
	{
		if (!trie.Add(phone_book[i])) {
			return false;
		}
	}

	return true;
}

int main()
{
	vector<string> data= { "12232332", "12", "222222" };
	solution(data);
}