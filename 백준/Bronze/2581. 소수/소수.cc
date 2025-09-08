#include<iostream>
using namespace std;

int main()
{

	int m, n;
	int sum = 0;
	int min = 0;
	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		int factor = 0;
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
				factor++;
		}
		if (factor == 2)
		{
			sum += i;
			if (min == 0)
				min = i;
		}
	}

	if (sum)
		cout << sum << endl << min << endl;
	else
		cout << -1<<endl;
}