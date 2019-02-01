#include <string>
#include <vector>
#include <queue>

using namespace std;

enum PatternType { Breakable, Unbreakable };

struct Position{
public:
	int row;
	int col;

	Position()
	{}
	Position(int _x, int _y) :row(_x), col(_y)
	{
	
	}
};

class Pattern
{
private:
	static const pair<int, int> breakablePatternCode[5][3];
	static const pair<int, int> emptyPositionCode[5][2];

	int patternionIndex = -1;

public:
	PatternType type;
	vector<Position> blockPositions;

	Pattern()
	{
	
	}
	Pattern(vector<Position>& positions)
	{
		int size = positions.size();
		blockPositions = positions;
		type = Unbreakable;

		vector<pair<int, int>> patternCode;
		for (int i = 0; i < size - 1; i++)
		{
			patternCode.push_back(
				make_pair(
					positions[i + 1].row - positions[i].row,
					positions[i + 1].col - positions[i].col
				));
		}

		//to specify pattern is breakable, compare its code with breakablePatternCode
		for (int i = 0; i < 5; i++)
		{
			bool hasPatternFound = true;

			for (int j = 0; j < 3; j++)
			{
				if (patternCode[j] != breakablePatternCode[i][j])
				{
					hasPatternFound = false;
					break;
				}
			}

			if (hasPatternFound)
			{
				patternionIndex = i;
				type = Breakable;
				break;
			}
		}
	}
	
	Position GetFirstEmptyPos()
	{
		return Position
		(
			blockPositions[0].row + emptyPositionCode[patternionIndex][0].first,
			blockPositions[0].col + emptyPositionCode[patternionIndex][0].second
		);
	}

	Position GetSecondEmptyPos()
	{
		return Position
		(
			blockPositions[0].row + emptyPositionCode[patternionIndex][1].first,
			blockPositions[0].col + emptyPositionCode[patternionIndex][1].second
		);
	}
};

//Codes used to specify pattern by using its blocks` relative positions
const pair<int, int> Pattern::breakablePatternCode[5][3]
{
	{make_pair(1,  0), make_pair(0,  1), make_pair(0,1)},
    {make_pair(1,  0), make_pair(1, -1), make_pair(0,1)},
	{make_pair(1, -2), make_pair(0,  1), make_pair(0,1)},
	{make_pair(1,  0), make_pair(1,  0), make_pair(0,1)},
	{make_pair(1, -1), make_pair(0,  1), make_pair(0,1)},
};

//Codes used to specify positions of empty blocks by using its blocks` relative positions
const pair<int, int> Pattern::emptyPositionCode[5][2]
{
	{make_pair(0,  1), make_pair(0,  2)},
	{make_pair(0, -1), make_pair(1, -1)},
	{make_pair(0, -1), make_pair(0, -2)},
	{make_pair(0,  1), make_pair(1,  1)},
	{make_pair(0, -1), make_pair(0,  1)}
};

//Manage blocks and specify the patterns of them
class Board
{
private:
	int N;
	vector<vector<int>> blocks;

	Pattern patterns[250];
	vector<int> patternIndex;
	vector<Position> blockPositions[250];

public:
	Board(vector<vector<int>>& blockData)
	{
		this->N = blockData.size();
		this->blocks = blockData;

		vector<Position> blockPositions[250];
		
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int blockNum = blocks[i][j];

				//If block is empty
				if (blockNum == 0)
				{
					continue;
				}

				//If the number of block is not visited before
				if (blockPositions[blockNum].size() == 0)
				{
					patternIndex.push_back(blockNum);
				}
				blockPositions[blockNum].push_back(Position(i, j));
			}
		}

		for (int i = 0; i < patternIndex.size(); i++)
		{
			int index = patternIndex[i];
			patterns[index] = Pattern(blockPositions[index]);
		}
	}

	int CountBreakableBlock()
	{
		vector<int> unbreakableRow;

			for (int col = 0; col < N; col++) 
			{
				int maxBreakableRow = -1;
				for (int row = 0; row < N; row++)
				{	
					int blockNum = blocks[row][col];
					if (blockNum > 0)
					{
						if (patterns[blockNum].type == Unbreakable)
						{
							maxBreakableRow = row;
							break;
						}
					}
				}
				unbreakableRow.push_back(maxBreakableRow);
				printf("%d/", unbreakableRow[col]);
			}
			printf("\n");
			queue<Pattern*> breakablePatterns;
			for (int i = 0; i < patternIndex.size(); i++)
			{
				int index = patternIndex[i];
				Pattern* pattern = &patterns[index];

				if (pattern->type == Breakable)
				{
					breakablePatterns.push(pattern);
				}
			}

			while (true)
			{
				bool hasChanged = false;
				for (int i = 0; i < breakablePatterns.size(); i++) {
					Pattern* pattern = breakablePatterns.front();
					breakablePatterns.pop();

					Position firstPos = pattern->GetFirstEmptyPos();
					if (unbreakableRow[firstPos.col] !=-1&&firstPos.row >= unbreakableRow[firstPos.col])
					{
						hasChanged = true;
						pattern->type = Unbreakable;
						for (int pi = 0; pi < 4; pi++)
						{
							Position blockPos = pattern->blockPositions[pi];
							if (unbreakableRow[blockPos.col] != -1) {
								unbreakableRow[blockPos.col] = min(blockPos.row, unbreakableRow[blockPos.col]);
							}
							else
							{
								unbreakableRow[blockPos.col] = blockPos.row;
							}
						}
						continue;
					}

					Position secondPos = pattern->GetSecondEmptyPos();
					if (unbreakableRow[secondPos.col] != -1 && secondPos.row >= unbreakableRow[secondPos.col])
					{
						hasChanged = true;
						pattern->type = Unbreakable;
						for (int pi = 0; pi < 4; pi++)
						{
							Position blockPos = pattern->blockPositions[pi];
							if (unbreakableRow[blockPos.col] != -1) {
								unbreakableRow[blockPos.col] = min(blockPos.row, unbreakableRow[blockPos.col]);
							}
							else
							{
								unbreakableRow[blockPos.col] = blockPos.row;
							}
						}
						continue;
					}
					breakablePatterns.push(pattern);
				}
				for (int i = 0; i < N; i++)
				{
					printf("%d/", unbreakableRow[i]);
				}
				printf("\n");
				if (!hasChanged)
				{
					break;
				}
			}

			int breakCnt = breakablePatterns.size();
			

		return breakCnt;
	}
};


int solution(vector<vector<int>> blockData) {
	Board board(blockData);
	int answer = board.CountBreakableBlock();
	return answer;
}	

int main()
{
	vector<vector<int>> data = {
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 7, 7, 7, 0, 4, 0, 0, 0},
		{0, 0, 6, 0, 7, 4, 4, 0, 0, 0},
		{0, 6, 6, 6, 3, 0, 4, 0, 0, 0},
		{0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
		{1, 2, 2, 2, 3, 3, 0, 0, 0, 5},
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 5}
	};

	printf("%d",solution(data));
}
