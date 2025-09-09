#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	// 1. 짝수인 약수를 다 걸러냄

	while (n % 2 == 0)
	{
		n /= 2;
		cout << 2 << endl;
	}

	// 2. 홀수인 약수를 다 걸러냄
	for (int i = 3; i * i <= n; i += 2)
	{
		while (n % i == 0)
		{
			n /= i;
			cout << i << endl;
		}
	}

	if (n > 1)
		cout << n << endl;
}