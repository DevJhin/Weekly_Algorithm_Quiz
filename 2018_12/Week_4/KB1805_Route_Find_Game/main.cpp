#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Vector2
{
	int x;
	int y;
	Vector2(int x, int y) :x(x), y(y)
	{

	}
	bool operator<(const Vector2& other)
	{
		if (this->y < other.y)
		{
			return true;
		}
		if (this->y > other.y)
		{
			return false;
		}
		if (this->x < other.x)
		{
			return true;
		}
		if (this->x > other.x)
		{
			return false;
		}
		if (this->x == other.x)
		{
			return false;
		}
	}
};

class Node {
	friend class RionTree;
private:

	Node * parent;

	Node* left;
	Node* right;

public:
	Vector2 key;
	int number;

	Node(int number, Vector2 position):number(number),key(position)
	{
		parent = NULL;
		left = NULL;
		right = NULL;
	}

};


class RionTree {

private:
	Node* root;
	
	void RecursivePreorder(Node* node, vector<int>& order) const
	{
		if (node == NULL)
		{
			return;
		}

		order.push_back(node->number);
		RecursivePreorder(node->left, order);
		RecursivePreorder(node->right, order);
	}

	void RecursivePostorder(Node* node, vector<int>& order) const
	{
		if (node == NULL)
		{
			return;
		}
		RecursivePostorder(node->left, order);
		RecursivePostorder(node->right, order);
		order.push_back(node->number);
	}

public:
	enum TraverseOrder { Preorder, Postorder };

	RionTree()
	{
		this->root = NULL;
	}

	void Add(int number, Vector2 key)
	{
		if (root == NULL)
		{
			printf("%d", 3);
			root = new Node(number, key);
			return;
		}

		Node* head = root;

		while (true)
		{
			if (key < head->key )
			{
				if (head->left == NULL)
				{
					Node* node = new Node(number, key);
					node->parent = head;
					head->left = node;
					return;
				}
				head = head->left;
			}
			else
			{
				if (head->right == NULL)
				{
					Node* node = new Node(number, key);
					node->parent = head;
					head->right = node;
					return;
				}
				head = head->right;
			}
			printf("%d", 3);
		}
	}

	vector<int> Traverse(TraverseOrder order) const
	{
		switch (order)
		{
			case Preorder:
			{
				vector<int> result;
				RecursivePreorder(root, result);
				return result;
			}

			case Postorder:
			{
				vector<int> result;
				RecursivePostorder(root, result);
				return result;
			}
			}

	}
};


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

	RionTree binaryTree;
	int nodeSize = nodeinfo.size();
	vector<Vector2> positions;
	for (int i = 0; i < nodeSize; i++)
	{
		positions.push_back(Vector2(nodeinfo[i][0], nodeinfo[i][1]));
	}
	sort(positions.rbegin(),positions.rend());
	for (int i = 0; i < nodeSize; i++)
	{
		binaryTree.Add(i + 1, positions[i]);
	}

	vector<vector<int>> answer;

	answer.push_back(binaryTree.Traverse(RionTree::Preorder));
	answer.push_back(binaryTree.Traverse(RionTree::Postorder));

	return answer;
}