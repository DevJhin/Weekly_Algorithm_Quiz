#include <string>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Block
{
public:
	char type;
	bool isChecked = false;
	Block(char type) :type(type)
	{

	}

};


class Board
{
private:
	vector<Block> * blocks;

	int maxHeight;
	int maxWidth;

	list<int>* popPositions;


public:
	Board(int height, int width)
	{

		this->maxHeight = height;
		this->maxWidth = width;

		blocks = new vector<Block>[width];

	}

	void AddBlocks(string value)
	{
		const char* capitals = value.c_str();
		for (int i = 0; i < maxWidth; i++)
		{
			blocks[i].push_back(Block(capitals[i]));
		}
	}

	int CheckFourBlocks()
	{
		popPositions = new list<int>[maxWidth];
		int depth = 0;
		for (int j = 0; j < maxHeight - 1; j++)
		{
			for (int i = 0; i < maxWidth - 1; i++)
			{
				int leftHeight = blocks[i].size();
				int rightHeight = blocks[i + 1].size();
				int height = leftHeight < rightHeight ? leftHeight : rightHeight;

				if (height <= j + 1)
				{
					continue;
				}
				if (blocks[i][j].type == blocks[i][j + 1].type&&blocks[i + 1][j].type == blocks[i + 1][j + 1].type&&blocks[i][j].type == blocks[i + 1][j].type)
				{
					depth++;
					if (blocks[i][j].isChecked == false)
					{
						popPositions[i].push_back(j);
						blocks[i][j].isChecked = true;
					}
					if (blocks[i][j + 1].isChecked == false)
					{
						popPositions[i].push_back(j + 1);
						blocks[i][j + 1].isChecked = true;
					}
					if (blocks[i + 1][j].isChecked == false)
					{
						popPositions[i + 1].push_back(j);
						blocks[i + 1][j].isChecked = true;
					}
					if (blocks[i + 1][j + 1].isChecked == false)
					{
						popPositions[i + 1].push_back(j + 1);
						blocks[i + 1][j + 1].isChecked = true;
					}
				}
			}
		}
		int popBlockCount = 0;

		for (int i = 0; i < maxWidth; i++)
		{
			popBlockCount += popPositions[i].size();
		}


		return popBlockCount;
	}

	void PopFourBlocks()
	{
		for (int i = 0; i < maxWidth; i++)
		{
			int shifted = 0;
			while (!popPositions[i].empty())
			{
				int col = popPositions[i].front();
				blocks[i].erase(blocks[i].begin() + col - shifted);
				shifted++;

				popPositions[i].pop_front();
			}
		}
	}
};

int solution(int m, int n, vector<string> boardData)
{
	int answer = 0;
	Board board(m, n);

	for (int i = boardData.size() - 1; i >= 0; i--)
	{
		board.AddBlocks(boardData[i]);
	}
	int popCount;
	while ((popCount = board.CheckFourBlocks()) > 0)
	{
		answer += popCount;
		board.PopFourBlocks();
	}

	return answer;
}
