#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<vector<int>> vec;

int cnt_0 = 0;
int cnt_1 = 0;
int cnt_m1 = 0;

void Cut_Paper(int startY, int startX,int size)
{
	int num = vec[startY][startX]; // 0, 1, -1인지 판별

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (vec[startY + i][startX + j] != num) // 값이 하나라도 다른 경우
			{
				int nextY = 0;
				size /= 3;
				for (int a = 0; a < 3; a++)
				{
					int nextX = 0;
					for (int b = 0; b < 3; b++)
					{
						Cut_Paper(startY + nextY, startX + nextX, size);
						nextX += size;
					}
					nextY += size;
				}
				return; // 다른 값이 존재하는 경우에는 카운트할 필요 없이 리턴
			}
		}
	} // 9등분으로 가름 // 다른값이 발견되면 9등분

	// 전부 같은 값인 경우
	if (num == 0)
		cnt_0++;
	else if (num == 1)
		cnt_1++;
	else
		cnt_m1++;

	return;
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
	cout << cnt_m1 << endl << cnt_0 << endl << cnt_1;
}