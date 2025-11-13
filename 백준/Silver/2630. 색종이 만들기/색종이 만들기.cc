#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> vec;

int cnt_white = 0; // 0
int cnt_blue = 0; // 1

void Cut_Paper(int startY, int startX, int size)
{
	int num = vec[startY][startX];

	// 다른 값이 존재하는지 검사
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (vec[startY + i][startX + j] != num) // 다른 값이 존재한느 경우
			{
				int nextY = 0;
				size /= 2;
				for (int a = 0; a < 2; a++) // 항상 네 구간으로 쪼개짐
				{
					int nextX = 0;
					for (int b = 0; b < 2; b++) 
					{
						Cut_Paper(startY + nextY, startX + nextX, size);
						nextX += size;
					}
					nextY += size;
				}
				return;
			}
		}
	}

	if (num == 0)
		cnt_white++;
	if(num==1)
		cnt_blue++;
}

int main()
{
	int n;
	cin >> n;

	vec.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vec[i][j];
		}
	}

	Cut_Paper(0, 0, n);

	cout << cnt_white << endl << cnt_blue;
}