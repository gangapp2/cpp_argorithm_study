#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int p;
	cin >> p;

	while (p--)
	{
		int num, size;
		cin >> num >> size;

		vector<int> origin(size);
		vector<int> rank(size); // 정렬된 배열

		int minVal = INT_MAX;

		for (int i = 0; i < size; i++)
		{
			cin >> rank[i];
			origin[i] = rank[i];
			minVal = min(minVal, rank[i]);
		}

		sort(rank.begin(), rank.end());

		int count = 0;
		for (int i = 0; i < size; i++)
		{
			if (minVal == origin[i])
			{
				minVal = rank[++count];
			}
		}

		cout << num << " " << size - count << "\n";
	}
}