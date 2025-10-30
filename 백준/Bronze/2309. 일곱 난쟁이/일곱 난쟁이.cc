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

	sort(dwarfs, dwarfs + N);


	for (int i = 0; i < N-1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (dwarfs[i] + dwarfs[j] == check)
			{
				for (int k = 0; k < N; k++)
				{
					if (k == i || k == j)
						continue;
					cout << dwarfs[k] << endl;
				}
				return 0;
			}
		}
	}

}