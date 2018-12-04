#include <string>
#include <vector>

using namespace std;

enum BlockType { Rion, Muzi, Apeach, Frodo, Neo, Tube, Jay_G, Con };

struct Block {
	BlockType type;

	Block (char capital) {
		switch (capital) {
		case 'R':
		{
			type = Rion;
			break;
		}
		case 'M':
		{
			type = Muzi;
			break;
		}
		case 'A':
		{
			type = Apeach;
			break;
		}
		case 'F':
		{
			type = Frodo;
			break;
		}
		case 'N':
		{
			type = Neo;
			break;
		}
		case 'T':
		{
			type = Tube;
			break;
		}
		case 'J':
		{
			type = Jay_G;
			break;
		}
		case 'C':
		{
			type = Con;
			break;
		}
		default: {
			//Error: Not Defined Character
			break;
		}
		}
	}

};

class BoardManager {
private:
	vector<Block> * board;
	
	int height;
	int width;

public:
	BoardManager(int height, int width) {

		this->height = height;
		this->width = width; 

		for (int i = 0; i < width; i++) {
			board = new vector<Block>[width];
		}

	}
	void FillLine(string value) {
		const char* capitals = value.c_str();
		for (int i = 0; i < width; i++) 
		{
			if (board[i].size() < height)
			{
				board[i].push_back(Block(capitals[i]));
			}
		}
	}
	

	int Pang() {
		for (int i = 0; i < width-1; i++)
		{
			int maxHeight = board[i].size() < board[i + 1].size() ? board[i].size() : board[i+1].size();
			for (int j = 0; j < maxHeight - 1; j++)
			{
				if (board[i][j].type == board[i][j + 1].type && board[i][j+1].type == board[i+1][j + 1].type) 
				{

				}
				if (board[i + 1][j].type == board[i + 1][j + 1].type) 
				{
				
				}
			}
		}

	}

};

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	BoardManager boardManager(m,n);

	for (int i = board.size() - 1; i >= 0; i--) {
		boardManager.FillLine(board[i]);
	}

	int pangBlockCnt = 0;

	do {
		pangBlockCnt = boardManager.Pang();
		answer += pangBlockCnt;
	} while (!(pangBlockCnt == 0));

	return answer;
}