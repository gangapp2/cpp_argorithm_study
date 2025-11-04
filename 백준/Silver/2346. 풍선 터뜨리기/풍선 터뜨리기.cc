#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int,int>> vec(n);

	for (int i = 0; i < vec.size(); i++)
	{
		int num;
		cin >> num;
		vec[i].first = num;
		vec[i].second = i + 1;
	}

	int index = 0;
	int next;

	while (!vec.empty())
	{
		cout << vec[index].second;
		next = vec[index].first;

		if (next > 0)
			next -= 1;
		
		vec.erase(vec.begin() + index);

		int size = vec.size();

		if (size == 0)
			break;


		index += next;
		// 종이에 적힌 값이 아주 작은 음수거나 아주 큰 양수일때 그 범위를 0 ~ size-1 로 줄임
		index = (index % size + size) % size;



		cout << " ";
	}
	return 0;
}