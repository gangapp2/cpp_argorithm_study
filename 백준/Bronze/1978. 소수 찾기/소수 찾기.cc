#include<iostream>
using namespace std;

int main()
{
	int n;
	int cnt = 0;
	cin >> n;

	while (n)
	{
		int factor = 0;
		int k;
		cin >> k;

		for (int i = 1; i < k + 1; i++)
		{
			if (k % i == 0)
				factor++;
		}
		if (factor == 2)
			cnt++;

		n--;
	}

	cout << cnt;
}