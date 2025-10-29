#include<iostream>
using namespace std;

int SumOfDigits(int m)
{
	int sum = 0;
	while (m > 0)
	{
		sum += m % 10;
		m /= 10;
	}
	return sum;
}
int main()
{
	bool find = false;
	int n;
	cin >> n;

	for (int i = 1; i < n; i++)
	{
		if (n == i + SumOfDigits(i))
		{
			cout << i;
			find = true;
			break;
		}
	}

	if (!find)
		cout << 0;
}