#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	int i = 2;
	cin >> n;

	while (n != 1)
	{
		if (n % i == 0)
		{
			n /= i;
			cout << i << endl;
		}
		else
			i++;
	}
}