#include<iostream>
using namespace std;

int cards[101];

int main()
{
	// n은 카드의 장수, m은 고른 3개 카드의 합
	int n, m;
	int ans = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> cards[i];

	// 카드 3장의 합으로 나올 수 있는 모든 경우의 수 계산
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int temp = cards[i] + cards[j] + cards[k];
				if (temp <= m && temp > ans) // m을 넘지 않으면서 최대가 되는 조건
				{
					ans = temp;
				}
			}
		}
	}

	cout << ans;
}