#include <iostream>
#include <vector>
using namespace std;

void Boj_2444()
{
	int n;
	cin >> n;

	// 상위 피라미드
	for (int i = 1; i <= n; i++)
	{
		for (int j = n - i; j > 0; j--)
		{
			cout << " ";
		}
		for (int j = 2 * i - 1; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}

	// 하위 피라미드
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 0; j < i; j++)
			cout << " ";
		for (int j = 2 * (n - i) - 1; j > 0; j--)
			cout << "*";

		cout << endl;
	}
}
int main()
{
	Boj_2444();
}

