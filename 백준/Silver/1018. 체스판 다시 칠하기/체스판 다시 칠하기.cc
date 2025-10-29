#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string BOARD[50];

string WB[8] = {
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};

string BW[8] = {
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

// 정답 보드와 현재 보드를 비교하여 틀린 색칠 갯수를 리턴
// n,m은 잘라낸 보드의 시작 좌표
int Count_WB(int n,int m)
{
	int ret = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (WB[i][j] != BOARD[i + n][j + m])
				ret++;
		}
	}
	return ret;
}

int Count_BW(int n, int m)
{
	int ret = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (BW[i][j] != BOARD[i + n][j + m])
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

	// 발견한 보드 nxm
	for (int i = 0; i < n; i++)
		cin >> BOARD[i];

	// 8*8로 자를 수 있는 보드의 모든 경우의수 = (n-8)*(m-8)개
	int moveableN = n - 8;
	int moveableM = m - 8;

	for (int i = 0; i <= moveableN; i++)
	{
		for (int j = 0; j <= moveableM; j++)
		{
			int temp;
			temp = min(Count_WB(i,j),Count_BW(i,j)); // 흑, 백으로 시작하는 두가지 경우중 최소 
			if (temp < encorrect)
				encorrect = temp;
		}
	}

	cout << encorrect;
}