#include<iostream>
#include<string>
using namespace std;

string BOARD[50];

string WB[8] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
};
string BW[8] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
};

// 잘라낸 보드의 시작 좌표를 입력받고 정답 보드와 비교함
int Count_WB(int y, int x)
{
	int ret = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (BOARD[i + y][j + x] != WB[i][j])
				ret++;
		}
	}
	return ret;
}

int Count_BW(int y, int x)
{
	int ret = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (BOARD[i + y][j + x] != BW[i][j])
				ret++;
		}
	}
	return ret;
}
int main()
{
	int n, m;
	int encorrect = 12345;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> BOARD[i];
	}

	int moveableN = n - 8;
	int moveableM = m - 8;
	
	for (int i = 0; i <= moveableN; i++)
	{
		for (int j = 0; j <= moveableM; j++)
		{
			int temp = min(Count_WB(i, j), Count_BW(i, j));
			if (temp < encorrect)
				encorrect = temp;
		}
	}
	cout << encorrect;
}