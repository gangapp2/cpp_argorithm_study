#include<iostream>
using namespace std;

const long long MOD = 1000000000;

int main()
{
	long long dp[101][10] = {};
	int n;

	cin >> n;

	// 한자릿수 
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			switch (j)
			{
			case 0:
				dp[i][j] = dp[i - 1][1];
				break;
			case 9:
				dp[i][j] = dp[i - 1][8];
				break;
			default:
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
				break;
			}
			dp[i][j] %= MOD;
		}
	}

	long long answer = 0;
	for (int i = 0; i <= 9; i++)
		answer += dp[n][i];

	cout << answer % MOD;
}