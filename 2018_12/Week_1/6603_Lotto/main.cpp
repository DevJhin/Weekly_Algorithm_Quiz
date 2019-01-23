#include<iostream>
#define _MAX_PICK_NUMBER 4

void PrintLottoNumber(int* lottoNum)
{
	for (int i = 0; i < _MAX_PICK_NUMBER; i++)
	{
		printf("%d ", lottoNum[i]);
	}
	printf("\n");
}

class Digit
{
public:
	int digits[_MAX_PICK_NUMBER];
	int maxValue;
	Digit(int maxValue) :maxValue(maxValue)
	{
		for (int i = 0; i < _MAX_PICK_NUMBER; i++)
		{
			digits[i] = 0;
		}
	}
	bool Add()
	{
		if (digits[_MAX_PICK_NUMBER - 1] == maxValue)
		{
			return false;
		}
		digits[0] += 1;
		for (int i = 0; i < _MAX_PICK_NUMBER; i++)
		{
			if (digits[i] > maxValue)
			{
				digits[i + 1] += 1;
			}
			else
			{
				for (int j = i; j >= 1; j--)
				{
					digits[j - 1] = digits[j];
				}
				break;
			}
		}
		return true;
	}

};

int main()
{
	while (true) {
		int k;
		scanf("%d", &k);
		if (k == 0)
		{
			break;
		}
		else
		{
			int S[15];
			for (int i = 0; i < k; i++)
			{
				scanf("%d", &S[i]);
			}
			Digit subIndex(k - _MAX_PICK_NUMBER);
			int lottoNum[_MAX_PICK_NUMBER];

			do {
				for (int i = 0; i < _MAX_PICK_NUMBER; i++) {
					lottoNum[i] = S[subIndex.digits[_MAX_PICK_NUMBER - 1 - i] + i];
				}
				PrintLottoNumber(lottoNum);
			} while (subIndex.Add());
			printf("\n");
		}
	}
}