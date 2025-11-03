#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	int temp;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(make_pair(temp, i + 1)); // first = 종이 값, second = 풍선 번호
	}

	int index = 0;
	int next;

	while (!v.empty())
	{
		cout << v[index].second;
		next = v[index].first;

		if (next > 0) // 종이에서 나온 값이 양수면 한칸 적게 이동해야함(인덱스가 1 줄어든 상태이므로)
			next -= 1;

		v.erase(v.begin() + index);

		int size = v.size();
		if (size == 0)
			break;
		index += next;
		
		index = (index % size + size) % size;

		cout << " ";
	}
}
