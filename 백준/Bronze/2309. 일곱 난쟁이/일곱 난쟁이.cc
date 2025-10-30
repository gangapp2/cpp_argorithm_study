#include<iostream>
#include<algorithm>
using namespace std;

const int N = 9; // 난쟁이 수
int dwarfs[9];

int main()
{
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> dwarfs[i];
		sum += dwarfs[i];
	}

	int check = sum - 100;
	bool found = false;

	for (int i = 0; i < N-1 && !found; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (dwarfs[i] + dwarfs[j] == check)
			{
				dwarfs[i] = dwarfs[j] = -1;
				found = true;
				break;
			}
		}
	}

	sort(dwarfs, dwarfs+N);

	for (int i = 0; i < N; i++)
	{
		if (dwarfs[i] != -1)
		{
			cout << dwarfs[i] << endl;
		}
	}
}