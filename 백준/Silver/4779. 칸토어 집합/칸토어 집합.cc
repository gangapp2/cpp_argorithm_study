#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string s;
int arrSize;

void Cantor(string &s, int left, int right)
{
	int arrSize = (right - left) + 1;
	arrSize /= 3;
	if (arrSize == 0)
		return;
	// 가운데 범위
	left = left + arrSize;
	right = left + arrSize - 1;

	for (int i = left; i <= right; i++)
	{
		s[i] = ' ';
	}

	if (left == right)
		return;

	left = left - 1;
	right = right + 1;

	Cantor(s, left - (arrSize - 1), left);
	Cantor(s, right, right+(arrSize - 1));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	while (cin>>n)
	{

		arrSize = pow(3, n);

		s.resize(arrSize, '-');

		Cantor(s, 0, arrSize - 1);

		for (int i = 0; i < arrSize; i++)
		{
			cout << s[i];
		}
		cout << '\n';
	}
	
}