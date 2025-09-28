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
				dp[i][j] = dp[i - 1][1] % MOD;
				break;
			case 9:
				dp[i][j] = dp[i - 1][8] % MOD;
				break;
			default:
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1] % MOD;
				break;
			}
		}
	}

	long long answer = 0;
	for (int i = 0; i <= 9; i++)
		answer += dp[n][i];

	// (a+b)modM = ((amodM)+(bmodM))modM
	// 각각의 숫자의 나머지를 먼저 구한후 전부 더해서 그 합의 나머지를 구한것과 : (a % m + b % m + c % m) % m
	// 모든 수를 다 더한후 한꺼번에 나눠서 나머지를 구한 것의 결과는 동일하다 : (a + b + c) % m
	cout << answer % MOD;
}