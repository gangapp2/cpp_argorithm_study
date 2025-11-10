#include<iostream>
#include<algorithm>
using namespace std;

int score[301]; // 해당 계단을 밟는 경우에 얻는 최대 점수(dp)
int stair[301]; // 계단별 점수
int main(void)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	score[1] = stair[1];
	score[2] = stair[1] + stair[2];
	score[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

	for (int i = 4; i <= n; i++) // 각 계단별 최댓값 일반화
	{
		int a = score[i - 2] + stair[i];
		int b = score[i - 3] + stair[i - 1] + stair[i];
		score[i] = max(a, b);
	}
	cout << score[n];

	return 0;
}