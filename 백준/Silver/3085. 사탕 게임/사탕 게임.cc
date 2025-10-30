#include<iostream>
using namespace std;

string Board[50];

int n;
int ans = 0;

// 스왑 후 보드에서 먹을 수 있는 최대 사탕의 갯수를 계산
void Check()
{
	char c;
	int cnt = 1;

	// 행 검사(가로)
	for (int i = 0; i < n; i++)
	{
		c = Board[i][0]; // 각 행의 첫번째 문자

		for (int j = 1; j < n; j++) // n번째 문자는 뒤에 비교할 문자가 없으므로 n-1까지만 검사
		{
			if (Board[i][j] == c) // 다음 글자가 같으면 점수 증가
				cnt++;
			else
			{
		
				cnt = 1; // 다르면 1로 초기화
			}

			if (cnt > ans)
				ans = cnt;
			c = Board[i][j]; // 다음 인접한 글자와 비교해야 하므로 c를 현재 인덱스의 값으로 초기화해줌
			
		}

		cnt = 1;
	}

	// 열 검사(세로)
	for (int i = 0; i < n; i++)
	{
		c = Board[0][i]; 
		for (int j = 1; j < n; j++) 
		{
			if (Board[j][i] == c) 
				cnt++;
			else
			{
	
				cnt = 1; // 다르면 1로 초기화
			}

			if (cnt > ans)
				ans = cnt;
			c = Board[j][i]; 
		}
		cnt = 1;
	}
}
int main()
{
	cin >> n;

	// 보드 입력
	for (int i = 0; i < n; i++)
	{
		cin >> Board[i];
	}

	 // 각 행마다 스왑할 두 값을 검사
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (Board[i][j] != Board[i][j + 1])
			{
				swap(Board[i][j], Board[i][j + 1]);
				Check();
				swap(Board[i][j], Board[i][j + 1]);
			}
		}
	}
	 // 각 열마다 스왑할 두 값을 검사
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (Board[j][i] != Board[j+1][i])
			{
				swap(Board[j][i], Board[j+1][i]);
				Check();
				swap(Board[j][i], Board[j+1][i]);
			}
		}
	}

	cout << ans;
}