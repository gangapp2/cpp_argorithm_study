#include<iostream>
#include<vector>
using namespace std;

vector<string> vec;

// 범위 내 모든 값이 같냐
bool isSame(int startY, int startX, int size)
{
	char num = vec[startY][startX];

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (num != vec[startY + i][startX + j])
				return false;
		}
	}

	return true;
}

void Compress(int startY, int startX, int size)
{
	if (isSame(startY, startX, size))
	{
		char num = vec[startY][startX]; // 0 or 1
		if (num == '0')
			cout << 0;
		if (num == '1')
			cout << 1;
	}
	else
	{
		size /= 2;
		cout << '(';
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				Compress(startY + i * size, startX + j * size, size);
			}
		}
		cout << ')';
	}
}

int main()
{
	int n;
	cin >> n;

	vec.assign(n,string(n,' '));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vec[i][j];
		}
	}

	Compress(0, 0, n);

	return 0;
}